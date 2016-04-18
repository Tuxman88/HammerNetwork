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

# include "mainwindow.h" 

Gui::MainWindow::MainWindow ( Core::SharedComponents* new_shared_components )
   : QMainWindow ()
{
   shared_components = new_shared_components;
   
   this->setWindowTitle ( shared_components->text ()->operator[] ( Core::KeyTxtWindowTitle ) );
   
   panel_main = new Gui::PanelMain ( shared_components );  
   config_dialog = new Gui::ConfigDialog ( shared_components );
   
   connect ( panel_main , SIGNAL ( displayConfig () ) , this , SLOT ( displayConfig () ) );
   
   setCentralWidget ( panel_main );
   
   setWindowIcon ( QIcon ( QString ( ":/icon-main-128" ) ) );
}

Gui::MainWindow::~MainWindow ( void )
{
   delete config_dialog;
}

void Gui::MainWindow::displayConfig ( void )
{
   config_dialog->show ();
   
   return;
}
