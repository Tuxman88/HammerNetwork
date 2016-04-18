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

# include "filespanel.h"

Gui::FilesPanel::FilesPanel ( Core::SharedComponents* new_shared_components )
   : QGroupBox ()
{
   shared_components = new_shared_components;
   
   layout_main = new QGridLayout ( this );
   this->setLayout ( layout_main );
   
   line_interface_up = new QLineEdit ();
   line_interface_down = new QLineEdit ();
   label_interface_up = new QLabel (  );
   label_interface_down = new QLabel ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowInterfaceStatusDown ) );
   
   layout_main->addWidget ( label_interface_up , 0 , 0 );
   layout_main->addWidget ( label_interface_down , 1 , 0 );
   layout_main->addWidget ( line_interface_up , 0 , 1 );
   layout_main->addWidget ( line_interface_down , 1 , 1 );
   
   updateText ();
   updateValues ();
   
   connect ( shared_components->config () , SIGNAL ( updateValues () ) , this , SLOT ( updateValues () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
}

void Gui::FilesPanel::updateText ( void )
{
   label_interface_up->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowInterfaceStatusUp ) );
   label_interface_down->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowInterfaceStatusDown ) );
   setTitle ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowSystemFiles ) );
   
   return;
}

void Gui::FilesPanel::updateValues ( void )
{
   line_interface_up->setText ( shared_components->config ()->operator[] ( Core::KeySysFileInterfaceUp ) );
   line_interface_down->setText ( shared_components->config ()->operator[] ( Core::KeySysFileInterfaceDown ) );
   
   return;
}

void Gui::FilesPanel::saveValues ( void )
{
   shared_components->config ()->set ( Core::KeySysFileInterfaceUp , line_interface_up->text () );
   shared_components->config ()->set ( Core::KeySysFileInterfaceDown , line_interface_down->text () );
   
   return;
}
