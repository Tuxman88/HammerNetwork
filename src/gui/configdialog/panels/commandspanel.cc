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

# include "commandspanel.h"

Gui::CommandsPanel::CommandsPanel ( Core::SharedComponents* new_shared_components )
   : QGroupBox ()
{
   shared_components = new_shared_components;
   
   layout_main = new QGridLayout ( this );
   this->setLayout ( layout_main );
   
   label_clear_command = new QLabel ();
   label_clear_limit_before_set = new QLabel ();
   label_interface_listing_command = new QLabel ();
   label_limit_command = new QLabel ();
   label_root_runner = new QLabel ();
   label_run_as_root = new QLabel ();
   label_speed_multiplier = new QLabel ();
   
   spin_speed_multiplier = new QSpinBox ();
   spin_speed_multiplier->setRange ( 1 , 100 );
   spin_speed_multiplier->setSingleStep ( 1 );
   
   check_clear_limit_before_set = new QCheckBox ();
   check_run_as_root = new QCheckBox ();
   
   line_clear_command = new QLineEdit ();
   line_interface_listing_command = new QLineEdit ();
   line_limit_command = new QLineEdit ();
   line_limit_command = new QLineEdit ();
   line_root_runner = new QLineEdit ();
   
   layout_main->addWidget ( label_clear_limit_before_set    , 0 , 0 );
   layout_main->addWidget ( label_clear_command             , 1 , 0 );
   layout_main->addWidget ( label_limit_command             , 2 , 0 );
   layout_main->addWidget ( label_speed_multiplier          , 3 , 0 );
   layout_main->addWidget ( label_root_runner               , 4 , 0 );
   layout_main->addWidget ( label_interface_listing_command , 5 , 0 );
   layout_main->addWidget ( label_run_as_root               , 6 , 0 );
   
   layout_main->addWidget ( check_clear_limit_before_set   , 0 , 1 );
   layout_main->addWidget ( line_clear_command             , 1 , 1 );
   layout_main->addWidget ( line_limit_command             , 2 , 1 );
   layout_main->addWidget ( spin_speed_multiplier          , 3 , 1 );
   layout_main->addWidget ( line_root_runner               , 4 , 1 );
   layout_main->addWidget ( line_interface_listing_command , 5 , 1 );
   layout_main->addWidget ( check_run_as_root              , 6 , 1 );
   
   updateText ();
   updateValues ();
   
   connect ( shared_components->config () , SIGNAL ( updateValues () ) , this , SLOT ( updateValues () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
}

void Gui::CommandsPanel::saveValues ( void )
{   
   shared_components->config ()->set ( Core::KeyCmdClearCommand , line_clear_command->text () );
   shared_components->config ()->set ( Core::KeyCmdInterfaceListing , line_interface_listing_command->text() );
   shared_components->config ()->set ( Core::KeyCmdLimitCommand , line_limit_command->text () );
   shared_components->config ()->set ( Core::KeyCmdRootRunner , line_root_runner->text () );
   shared_components->config ()->set ( Core::KeyCtlClearBeforeLimit , QString ( "%1" ).arg ( check_clear_limit_before_set->isChecked () ) );
   shared_components->config ()->set ( Core::KeyCtlRunWithRootRunner , QString ( "%1" ).arg ( check_run_as_root->isChecked () ) );
   shared_components->config ()->set ( Core::KeyCtlSpeedMultiplier , QString ( "%1" ).arg ( spin_speed_multiplier->value () ) );
   
   if ( !line_clear_command->text ().contains ( "%INTERFACE%" ) )
   {
      QMessageBox::warning ( this , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningConfigIncorrect ) , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningNoInterfaceInClearCommand ) );
   }
   
   if ( !line_limit_command->text ().contains ( "%INTERFACE%" ) )
   {
      QMessageBox::warning ( this , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningConfigIncorrect ) , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningNoInterfaceInLimitCommand ) );
   }
   
   if ( !line_limit_command->text ().contains ( "%USPEED%" ) )
   {
      QMessageBox::warning ( this , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningConfigIncorrect ) , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningNoUploadInLimitCommand ) );
   }
   
   if ( !line_limit_command->text ().contains ( "%DSPEED%" ) )
   {
      QMessageBox::warning ( this , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningConfigIncorrect ) , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningNoDownloadInLimitCommand ) );
   }
   
   if ( !line_root_runner->text ().contains ( "%COMMAND%" ) )
   {
      QMessageBox::warning ( this , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningConfigIncorrect ) , shared_components->text ()->operator[] ( Core::KeyTxtDialogWarningNoCommandInRootRunner ) );
   }
   
   return;
}

void Gui::CommandsPanel::updateText ( void )
{
   setTitle ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowSystemCommands ) );
   label_clear_command->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowClearCommand ) );
   label_clear_limit_before_set->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowClearLimitBeforeSet ) );
   label_limit_command->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowLimitCommand ) );
   label_speed_multiplier->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowSpeedMultiplier ) );
   label_root_runner->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowRootRunner ) );
   label_interface_listing_command->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowInterfaceListingCommand ) );
   label_run_as_root->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowRunAsRoot ) );
   
   return;
}

void Gui::CommandsPanel::updateValues ( void )
{
   line_clear_command->setText ( shared_components->config ()->operator[] ( Core::KeyCmdClearCommand ) );
   line_interface_listing_command->setText ( shared_components->config ()->operator[] ( Core::KeyCmdInterfaceListing ) );
   line_limit_command->setText ( shared_components->config ()->operator[] ( Core::KeyCmdLimitCommand ) );
   line_root_runner->setText ( shared_components->config ()->operator[] ( Core::KeyCmdRootRunner ) );
   check_clear_limit_before_set->setChecked ( shared_components->config ()->operator[] ( Core::KeyCtlClearBeforeLimit ).toInt () == 1 );   
   check_run_as_root->setChecked ( shared_components->config ()->operator[] ( Core::KeyCtlRunWithRootRunner ).toInt () == 1 );
   spin_speed_multiplier->setValue ( shared_components->config ()->operator[] ( Core::KeyCtlSpeedMultiplier ).toInt () );
   
   return;
}

