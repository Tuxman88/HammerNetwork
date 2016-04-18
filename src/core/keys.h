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

# ifndef KEYS_H_
# define KEYS_H_

# include <QtCore/QString>

namespace Core
{
   /*
    * Keys about GUI configurations.
    */
   const QString KeyGuiDataUnits = "gui.data_units";
   const QString ValGuiDataUnits = "MB";
   
   const QString KeyGuiSpeedUnits = "gui.speed_units";
   const QString ValGuiSpeedUnits = "KB/s";
   
   const QString KeyGuiRefreshRate = "gui.refresh_rate";
   const QString ValGuiRefreshRate = "1";
   
   const QString KeyGuiLang = "gui.lang";
   const QString ValGuiLang = "english";
   
   /*
    * Keys about system configuration, like paths and values of those files.
    */
   
   const QString KeySysPathInterfaceStatus = "sys.path.interface_status";
   const QString ValSysPathInterfaceStatus = "/sys/class/net/%INTERFACE%/operstate";
   
   const QString KeySysPathInterfaceDownload = "sys.path.interface_download";
   const QString ValSysPathInterfaceDownload = "/sys/class/net/%INTERFACE%/statistics/rx_bytes";
   
   const QString KeySysPathInterfaceUpload = "sys.path.interface_upload";
   const QString ValSysPathInterfaceUpload = "/sys/class/net/%INTERFACE%/statistics/tx_bytes";
   
   const QString KeySysFileInterfaceUp = "sys.file.interface_up";
   const QString ValSysFileInterfaceUp = "up";
   
   const QString KeySysFileInterfaceDown = "sys.file.interface_down";
   const QString ValSysFileInterfaceDown = "down";
   
   /*
    * Keys about commands.
    */
   
   const QString KeyCmdClearCommand = "cmd.clear_command";
   const QString ValCmdClearCommand = "wondershaper -a %INTERFACE% -c";
   
   const QString KeyCmdLimitCommand = "cmd.limit_command";
   const QString ValCmdLimitCommand = "wondershaper -a %INTERFACE% -d %DSPEED% -u %USPEED%";
   
   const QString KeyCmdRootRunner = "cmd.root_runner";
   const QString ValCmdRootRunner = "kdesu %COMMAND%";
   
   const QString KeyCmdInterfaceListing = "cmd.interface_listing";
   const QString ValCmdInterfaceListing = "ip link show";
   
   /*
    * Keys about the control of the application and it's behaviour.
    */
   
   const QString KeyCtlClearBeforeLimit = "ctl.clear_before_limit";
   const QString ValCtlClearBeforeLimit = "1";
   
   const QString KeyCtlSpeedMultiplier = "ctl.speed_multiplier";
   const QString ValCtlSpeedMultiplier = "8";
   
   const QString KeyCtlRunWithRootRunner = "ctl.run_with_root_runner";
   const QString ValCtlRunWithRootRunner = "1";
   
   const QString KeyCtlInterfacesToExclude = "ctl.interfaces_to_exclude";
   const QString ValCtlInterfacesToExclude = "";
   
   /*
    * Keys about text. (there are just keys, the values are controlled in other place, in the "Text" class).
    */
   
   const QString KeyTxtWindowTitle = "txt.window_title";
   const QString KeyTxtApplicationName = "txt.application_name";
   const QString KeyTxtApplicationCatchPhrase = "txt.application_catch_phrase";
   const QString KeyTxtApplicationVersion = "txt.application_version";
   const QString KeyTxtInterfaceControlTitle = "txt.interface_control_title";
   const QString KeyTxtInterfaceDownload = "txt.interface_download";
   const QString KeyTxtInterfaceUpload = "txt.interface_upload";
   const QString KeyTxtInterfaceTotalData = "txt.interface_total_data";
   const QString KeyTxtInterfaceCurrentSpeed = "txt.interface_current_speed";
   const QString KeyTxtInterfaceLimits = "txt.interface_limits";
   const QString KeyTxtInterfaceApply = "txt.interface_apply";
   const QString KeyTxtInterfaceClear = "txt.interface_clear";
   const QString KeyTxtMainPanelConfigProgram = "txt.main_panel_config_program";
   const QString KeyTxtConfigWindowTitle = "txt.config_window_title";
   const QString KeyTxtConfigWindowReset = "txt.config_window_reset";
   const QString KeyTxtConfigWindowSave = "txt.config_window_save";
   const QString KeyTxtConfigWindowInterfaceLanguage = "txt.config_window_interface_language";
   const QString KeyTxtConfigWindowSystemPaths = "txt.config_window_system_paths";
   const QString KeyTxtConfigWindowInterfaceStatus = "txt.config_window_interface_status";
   const QString KeyTxtConfigWindowInterfaceDownloadBytes = "txt.config_window_interface_download_bytes";
   const QString KeyTxtConfigWindowInterfaceUploadBytes = "txt.config_window_interface_upload_bytes";
   const QString KeyTxtConfigWindowSystemFiles = "txt.config_window_system_files";
   const QString KeyTxtConfigWindowInterfaceStatusUp = "txt.config_window_interface_status_up";
   const QString KeyTxtConfigWindowInterfaceStatusDown = "txt.config_window_interface_status_down";
   const QString KeyTxtConfigWindowNetworkInterfacesInformation = "txt.config_window_network_interfaces_information";
   const QString KeyTxtConfigWindowRefreshRate = "txt.config_window_refresh_rate";
   const QString KeyTxtConfigWindowSpeedUnits = "txt.config_window_speed_units";
   const QString KeyTxtConfigWindowDataUnits = "txt.config_window_data_units";
   const QString KeyTxtConfigWindowListOfInterfacesToExclude = "txt.config_window_list_of_interfaces_to_exclude";
   const QString KeyTxtConfigWindowTimesPerSecond = "txt.config_window_times_per_second";
   const QString KeyTxtConfigWindowSystemCommands = "txt.config_window_system_commands";
   const QString KeyTxtConfigWindowClearLimitBeforeSet = "txt.config_window_clear_limit_before_set";
   const QString KeyTxtConfigWindowClearCommand = "txt.config_window_clear_command";
   const QString KeyTxtConfigWindowLimitCommand = "txt.config_window_limit_command";
   const QString KeyTxtConfigWindowSpeedMultiplier = "txt.config_window_speed_multiplier";
   const QString KeyTxtConfigWindowRootRunner = "txt.config_window_root_runner";
   const QString KeyTxtConfigWindowInterfaceListingCommand = "txt.config_window_interface_listing_command";
   const QString KeyTxtConfigWindowRunAsRoot = "txt.config_window_run_as_root";
   const QString KeyTxtConfigWindowCancel = "txt.config_window_cancel";
   const QString KeyTxtDialogWarningConfigIncorrect = "txt.dialog_warning_config_incorrect";
   const QString KeyTxtDialogWarningNoInterfaceInClearCommand = "txt.dialog_warning_no_interface_in_clear_command";
   const QString KeyTxtDialogWarningNoInterfaceInLimitCommand = "txt.dialog_warning_no_interface_in_limit_command";
   const QString KeyTxtDialogWarningNoDownloadInLimitCommand = "txt.dialog_warning_no_download_in_limit_command";
   const QString KeyTxtDialogWarningNoUploadInLimitCommand = "txt.dialog_warning_no_upload_in_limit_command";   
   const QString KeyTxtDialogWarningNoCommandInRootRunner = "txt.dialog_warning_no_command_in_root_runner";
   const QString KeyTxtDialogWarningNoInterfaceInStatePath = "txt.dialog_warning_no_interface_in_state_path";
   const QString KeyTxtDialogWarningNoInterfaceInDownloadPath = "txt.dialog_warning_no_interface_in_downloaded_path";
   const QString KeyTxtDialogWarningNoInterfaceInUploadPath = "txt.dialog_warning_no_interface_in_uploaded_path";
}

# endif
