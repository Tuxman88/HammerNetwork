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

# include "configdialog.h"

Gui::ConfigDialog::ConfigDialog ( Core::SharedComponents* new_shared_components )
   : QDialog ()
{
   shared_components = new_shared_components;
   
   layout_main = new QVBoxLayout ( this );
   this->setLayout ( layout_main );
   
   language_panel = new Gui::LanguagePanel ( shared_components );
   layout_main->addWidget ( language_panel );
   
   paths_panel = new Gui::PathsPanel ( shared_components );
   layout_main->addWidget ( paths_panel );
   
   files_panel = new Gui::FilesPanel ( shared_components );
   layout_main->addWidget ( files_panel );
   
   commands_panel = new Gui::CommandsPanel ( shared_components );
   layout_main->addWidget ( commands_panel );
   
   network_panel = new Gui::NetworkPanel ( shared_components );
   layout_main->addWidget ( network_panel );
   
   buttons_panel = new Gui::ButtonsPanel ( shared_components );
   layout_main->addWidget ( buttons_panel );
   
   setWindowTitle ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowTitle ) );
   setModal ( Qt::NonModal );
   
   // Ok. Connect the cancel signal from the buttons panel with the signal of reloading the config.
   connect ( buttons_panel , SIGNAL ( cancelConfig () ) , shared_components->config () , SIGNAL ( updateValues () ) );
   
   // When the user clicks on save, ask every panel to save
   connect ( buttons_panel , SIGNAL ( saveConfig () ) , language_panel , SLOT ( saveValues () ) );
   connect ( buttons_panel , SIGNAL ( saveConfig () ) , paths_panel , SLOT ( saveValues () ) );
   connect ( buttons_panel , SIGNAL ( saveConfig () ) , files_panel , SLOT ( saveValues () ) );
   connect ( buttons_panel , SIGNAL ( saveConfig () ) , commands_panel , SLOT ( saveValues () ) );
   connect ( buttons_panel , SIGNAL ( saveConfig () ) , network_panel , SLOT ( saveValues () ) );
   
   // To reset, call the reset slot from the config
   connect ( buttons_panel , SIGNAL ( resetConfig () ) , shared_components->config () , SLOT ( resetValues () ) );
   
   setWindowIcon ( QIcon ( QString ( ":/icon-main-128" ) ) );
}

