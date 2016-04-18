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

# include "pathspanel.h"

Gui::PathsPanel::PathsPanel ( Core::SharedComponents* new_shared_components )
   : QGroupBox ()
{
   shared_components = new_shared_components;
   
   layout_main = new QGridLayout ( this );
   this->setLayout ( layout_main );
   
   label_interface_status = new QLabel ();
   label_interface_download_bytes = new QLabel ();
   label_interface_upload_bytes = new QLabel ();
   
   line_interface_status = new QLineEdit ();
   line_interface_download_bytes = new QLineEdit ();
   line_interface_upload_bytes = new QLineEdit ();
   
   layout_main->addWidget ( label_interface_status , 0 , 0 );
   layout_main->addWidget ( label_interface_download_bytes , 1 , 0 );
   layout_main->addWidget ( label_interface_upload_bytes , 2 , 0 );
   layout_main->addWidget ( line_interface_status , 0 , 1 );
   layout_main->addWidget ( line_interface_download_bytes , 1 , 1 );
   layout_main->addWidget ( line_interface_upload_bytes , 2 , 1 );
   
   updateText ();
   updateValues ();
   
   connect ( shared_components->config () , SIGNAL ( updateValues () ) , this , SLOT ( updateValues () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
}

void Gui::PathsPanel::saveValues ( void )
{
   shared_components->config ()->set ( Core::KeySysPathInterfaceStatus , line_interface_status->text () );
   shared_components->config ()->set ( Core::KeySysPathInterfaceDownload , line_interface_download_bytes->text () );
   shared_components->config ()->set ( Core::KeySysPathInterfaceUpload , line_interface_upload_bytes->text () );
   
   if ( !line_interface_status->text ().contains ( "%INTERFACE%" ) )
   {
      QMessageBox::warning ( this , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningConfigIncorrect ) , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningNoInterfaceInStatePath ) );
   }
   
   if ( !line_interface_download_bytes->text ().contains ( "%INTERFACE%" ) )
   {
      QMessageBox::warning ( this , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningConfigIncorrect ) , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningNoInterfaceInDownloadPath ) );
   }
   
   if ( !line_interface_upload_bytes->text ().contains ( "%INTERFACE%" ) )
   {
      QMessageBox::warning ( this , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningConfigIncorrect ) , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningNoInterfaceInUploadPath ) );
   }
   
   return;
}

void Gui::PathsPanel::updateText ( void )
{
   setTitle ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowSystemPaths ) );
   label_interface_status->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowInterfaceStatus ) );
   label_interface_download_bytes->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowInterfaceDownloadBytes ) );
   label_interface_upload_bytes->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowInterfaceUploadBytes ) );
   
   return;
}

void Gui::PathsPanel::updateValues ( void )
{
   line_interface_status->setText ( shared_components->config ()->operator[] ( Core::KeySysPathInterfaceStatus ) );
   line_interface_download_bytes->setText ( shared_components->config ()->operator[] ( Core::KeySysPathInterfaceDownload ) );
   line_interface_upload_bytes->setText ( shared_components->config ()->operator[] ( Core::KeySysPathInterfaceUpload ) );
   
   return;
}
