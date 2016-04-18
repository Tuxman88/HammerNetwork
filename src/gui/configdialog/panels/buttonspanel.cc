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

# include "buttonspanel.h"

Gui::ButtonsPanel::ButtonsPanel ( Core::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   
   layout_main = new QHBoxLayout ( this );
   this->setLayout ( layout_main );
   
   button_reset = new QPushButton ();
   button_save = new QPushButton ();
   button_cancel = new QPushButton ();
   
   layout_main->addWidget ( button_reset );
   layout_main->addStretch ();
   layout_main->addWidget ( button_cancel );
   layout_main->addWidget ( button_save );
   
   updateText ();
   
   connect ( button_reset , SIGNAL ( clicked () ) , this , SIGNAL ( resetConfig () ) );
   connect ( button_save , SIGNAL ( clicked () ) , this , SIGNAL ( saveConfig () ) );
   connect ( button_cancel , SIGNAL ( clicked () ) , this , SIGNAL ( cancelConfig () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
}

void Gui::ButtonsPanel::updateText ( void )
{
   button_reset->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowReset ) );
   button_save->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowSave ) );
   button_cancel->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowCancel ) );
   
   return;
}
