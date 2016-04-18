//  This file is part of Hammer Network. Hammer Network is free software: you can
//  redistribute it and/or modify it under the terms of the GNU General Public
//  License as published by the Free Software Foundation, version 2.
// 
//  This program is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
//  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
//  details.
// 
//  You should have received a copy of the GNU General Public License along with
//  this program; if not, write to the Free Software Foundation, Inc., 51
//  Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

# include "panelmain.h"

Gui::PanelMain::PanelMain ( Core::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   
   // Prepare layout
   
   layout_main = new QVBoxLayout ( this );
   this->setLayout ( layout_main );
   
   // Prepare the title panel
   
   panel_title = new Gui::PanelTitle ( shared_components );
   layout_main->addWidget ( panel_title );
   connect ( panel_title , SIGNAL ( displayConfig () ) , this , SIGNAL ( displayConfig () ) );
   
   // Add interfaces
   
   QList< QString > interface_names;
   interface_names = shared_components->interfaceHandler ()->findInterfaces ();
   
   for ( int i = 0; i < interface_names.size (); i++ )
   {
      Gui::PanelInterface* panel_interface;
      panel_interface = new Gui::PanelInterface ( shared_components , interface_names[ i ] );
      layout_main->addWidget ( panel_interface );
      panels_interfaces.append ( panel_interface );
   }
   
   // Add a final stretcher
   
   layout_main->addStretch ();
}
