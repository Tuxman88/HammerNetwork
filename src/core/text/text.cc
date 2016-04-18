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

# include "text.h"

Core::Text::Text ( Core::Configuration* new_config )
   : QObject ()
{
   config = new_config;
   
   // Open and load the resource file of the text for the application
   QFile resource_file ( QString ( ":/lang-%1" ).arg ( config->operator[] ( Core::KeyGuiLang ) ) );
   
   if ( !resource_file.open ( QIODevice::ReadOnly | QIODevice::Text ) )
   {
      qDebug () << "Core::Text::Text: ERROR: Can't open resource file " << QString ( ":/lang-%1" ).arg ( config->operator[] ( Core::KeyGuiLang ) );
      qDebug () << "                         Fallback to default english.";
      
      fillDefault ();
   }
   else
   {
      while ( !resource_file.atEnd () )
      {
         QByteArray raw_line = resource_file.readLine ();
         QString line ( raw_line );
         QStringList components;
         
         components = line.split ( "=" );
         current_text[ components[ 0 ] ] = components[ 1 ].simplified ();
      }
   }
}

void Core::Text::fillDefault ( void )
{
   current_text[ QString ( "txt.window_title" ) ] = QString ( "Hammer Network" );
   current_text[ QString ( "txt.application_name" ) ] = QString ( "Hammer Network" );
   current_text[ QString ( "txt.application_catch_phrase" ) ] = QString ( "Your network under control" );
   current_text[ QString ( "txt.application_version" ) ] = QString ( "0.1.0" );
   current_text[ QString ( "txt.interface_control_title" ) ] = QString ( "Interface" );
   current_text[ QString ( "txt.interface_download" ) ] = QString ( "Download" );
   current_text[ QString ( "txt.interface_upload" ) ] = QString ( "Upload" );
   current_text[ QString ( "txt.interface_total_data" ) ] = QString ( "Total data" );
   current_text[ QString ( "txt.interface_current_speed" ) ] = QString ( "Current speed" );
   current_text[ QString ( "txt.interface_limits" ) ] = QString ( "Limits" );
   current_text[ QString ( "txt.interface_apply" ) ] = QString ( "Apply" );
   current_text[ QString ( "txt.interface_clear" ) ] = QString ( "Clear" );
   current_text[ QString ( "txt.main_panel_config_program" ) ] = QString ( "Configure application" );
   current_text[ QString ( "txt.config_window_title" ) ] = QString ( "Hammer Network Configuration" );
   current_text[ QString ( "txt.config_window_reset" ) ] = QString ( "Reset values" );
   current_text[ QString ( "txt.config_window_save" ) ] = QString ( "Save values" );
   current_text[ QString ( "txt.config_window_interface_language" ) ] = QString ( "Interface language" );
   current_text[ QString ( "txt.config_window_system_paths" ) ] = QString ( "System paths" );
   current_text[ QString ( "txt.config_window_interface_status" ) ] = QString ( "Interface status" );
   current_text[ QString ( "txt.config_window_interface_download_bytes" ) ] = QString ( "Interface downloaded bytes" );
   current_text[ QString ( "txt.config_window_system_files" ) ] = QString ( "System files" );
   current_text[ QString ( "txt.config_window_interface_status_up" ) ] = QString ( "Interface status up" );
   current_text[ QString ( "txt.config_window_interface_status_down" ) ] = QString ( "Interface status down" );
   current_text[ QString ( "txt.config_window_network_interfaces_information" ) ] = QString ( "Network interfaces information" );
   current_text[ QString ( "txt.config_window_refresh_rate" ) ] = QString ( "Refresh rate" );
   current_text[ QString ( "txt.config_window_speed_units" ) ] = QString ( "Speed units" );
   current_text[ QString ( "txt.config_window_data_units" ) ] = QString ( "Data units" );
   current_text[ QString ( "txt.config_window_list_of_interfaces_to_exclude" ) ] = QString ( "List of interfaces to exclude" );
   current_text[ QString ( "txt.config_window_times_per_second" ) ] = QString ( "times per second" );
   current_text[ QString ( "txt.config_window_system_commands" ) ] = QString ( "System comands" );
   current_text[ QString ( "txt.config_window_clear_limit_before_set" ) ] = QString ( "Clear limit before set" );
   current_text[ QString ( "txt.config_window_clear_command" ) ] = QString ( "Clear command" );
   current_text[ QString ( "txt.config_window_limit_command" ) ] = QString ( "Limit command" );
   current_text[ QString ( "txt.config_window_speed_multiplier" ) ] = QString ( "Speed multiplier" );
   current_text[ QString ( "txt.config_window_root_runner" ) ] = QString ( "Root runner" );
   current_text[ QString ( "txt.config_window_interface_listing_command" ) ] = QString ( "Interface listing command" );
   current_text[ QString ( "txt.config_window_run_as_root" ) ] = QString ( "Run as root" );
   current_text[ QString ( "txt.config_window_cancel" ) ] = QString ( "Cancel" );
   current_text[ QString ( "txt.dialog_warning_config_incorrect" ) ] = QString ( "Incorrect configuration found" );
   current_text[ QString ( "txt.dialog_warning_no_interface_in_clear_command" ) ] = QString ( "No \"%INTERFACE%\" keyword found in the clear command. The command might not work." );
   current_text[ QString ( "txt.dialog_warning_no_interface_in_limit_command" ) ] = QString ( "No \"%INTERFACE%\" keyword found in the limit command. The command might not work." );
   current_text[ QString ( "txt.dialog_warning_no_command_in_root_runner" ) ] = QString ( "No \"%INTERFACE%\" keyword found in the root runner command. The command might not work." );
   current_text[ QString ( "txt.dialog_warning_no_download_in_limit_command" ) ] = QString ( "No \"%DSPEED%\" keyword found in the limit command. The command might not work." );
   current_text[ QString ( "txt.dialog_warning_no_upload_in_limit_command" ) ] = QString ( "No \"%USPEED%\" keyword found in the limit command. The command might not work." );
   current_text[ QString ( "txt.dialog_warning_no_interface_in_state_path" ) ] = QString ( "No \"%INTERFACE%\" keyword found in the interface state path. The interface state detection might not work." );
   current_text[ QString ( "txt.dialog_warning_no_interface_in_downloaded_path" ) ] = QString ( "No \"%INTERFACE%\" keywork found in the interface downloaded bytes path. The interface download speed and data amount downloaded detection might not work." );
   current_text[ QString ( "txt.dialog_warning_no_interface_in_uploaded_path" ) ] = QString ( "No \"%INTERFACE%\" keywork found in the interface uploaded bytes path. The interface upload speed and data amount uploaded detection might not work." );
   
   return;
}

QString Core::Text::operator[] ( const QString& key )
{
   return ( current_text[ key ] );
}

