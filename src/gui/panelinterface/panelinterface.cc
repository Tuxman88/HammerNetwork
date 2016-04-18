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

# include "panelinterface.h"

Gui::PanelInterface::PanelInterface ( Core::SharedComponents* new_shared_components , const QString& new_interface_name )
   : QGroupBox ()
{
   shared_components = new_shared_components;
   interface_name = new_interface_name;
   
   old_download_bytes = 0;
   old_upload_bytes = 0;
   
   /*
    * The expected design is as follows:
    * 
    * x-------------------------Interface: lo------------------------x
    * |            Total data   Current speed  Limits                |
    * | Download:  100 MB       100 KB/s       [100] KB/s    [Apply] |
    * | Upload:    25.2 MB      23 KB/s        [32] KB/s     [Clear] |
    * x--------------------------------------------------------------x
    * 
    */
   
   // Set the title
   
   setTitle ( QString ( "%1: %2" ).arg ( shared_components->text ()->operator[] ( Core::KeyTxtInterfaceControlTitle ) ).arg ( interface_name ) );
   
   // Prepare main layout
   
   layout_main = new QHBoxLayout ( this );
   this->setLayout ( layout_main );
   
   // Prepare the info layout
   
   layout_info = new QGridLayout ();
   layout_main->addLayout ( layout_info );
   layout_main->addStretch ();
   
   // Prepare the data labels and spins
   
   label_download = new QLabel ( QString ( "%1:  " ).arg ( shared_components->text ()->operator[] ( Core::KeyTxtInterfaceDownload ) ) );
   label_upload = new QLabel ( QString ( "%1:  " ).arg ( shared_components->text ()->operator[] ( Core::KeyTxtInterfaceUpload ) ) );
   label_total_data = new QLabel ( QString ( "%1  " ).arg ( shared_components->text ()->operator[] ( Core::KeyTxtInterfaceTotalData ) ) );
   label_current_speed = new QLabel ( QString ( "%1  " ).arg ( shared_components->text ()->operator[] ( Core::KeyTxtInterfaceCurrentSpeed ) ) );
   label_limits = new QLabel ( shared_components->text ()->operator[] ( Core::KeyTxtInterfaceLimits ) );
   label_download_data = new QLabel ( QString ( "0 %1" ).arg ( shared_components->config ()->operator[] ( Core::KeyGuiDataUnits ) ) );
   label_upload_data = new QLabel ( QString ( "0 %1" ).arg ( shared_components->config ()->operator[] ( Core::KeyGuiDataUnits ) ) );
   label_download_speed = new QLabel ( QString ( "0 %1" ).arg ( shared_components->config ()->operator[] ( Core::KeyGuiSpeedUnits ) ) );
   label_upload_speed = new QLabel ( QString ( "0 %1" ).arg ( shared_components->config ()->operator[] ( Core::KeyGuiSpeedUnits ) ) );
   label_download_limit_units = new QLabel ( shared_components->config ()->operator[] ( Core::KeyGuiSpeedUnits ) );
   label_upload_limit_units = new QLabel ( shared_components->config ()->operator[] ( Core::KeyGuiSpeedUnits ) );
   spin_download_limit = new QDoubleSpinBox ();
   spin_upload_limit = new QDoubleSpinBox ();
   layout_download_limit = new QHBoxLayout ();
   layout_upload_limit = new QHBoxLayout ();
   spin_download_limit->setRange ( 0.1 , 1073741824 ); // 1073741824, in bytes, is 1 GB
   spin_upload_limit->setRange ( 0.1 , 1073741824 ); // 1073741824, in bytes, is 1 GB
   spin_download_limit->setSingleStep ( 0.1 );
   spin_upload_limit->setSingleStep ( 0.1 );
   spin_download_limit->setValue ( 100 );
   spin_upload_limit->setValue ( 100 );
   
   // Add the components to the layout
   
   layout_info->addWidget ( label_total_data , 0 , 1 );
   layout_info->addWidget ( label_current_speed , 0 , 2 );
   layout_info->addWidget ( label_limits , 0 , 3 );
   layout_info->addWidget ( label_download , 1 , 0 );
   layout_info->addWidget ( label_download_data , 1 , 1 );
   layout_info->addWidget ( label_download_speed , 1 , 2 );
   layout_info->addLayout ( layout_download_limit , 1 , 3 );
   layout_info->addWidget ( label_upload , 2 , 0 );
   layout_info->addWidget ( label_upload_data , 2 , 1 );
   layout_info->addWidget ( label_upload_speed , 2 , 2 );
   layout_info->addLayout ( layout_upload_limit , 2 , 3 );
   
   // Fill the download and upload limit layouts
   
   layout_download_limit->addWidget ( spin_download_limit );
   layout_download_limit->addStretch ();
   layout_download_limit->addWidget ( label_download_limit_units );
   layout_upload_limit->addWidget ( spin_upload_limit );
   layout_upload_limit->addStretch ();
   layout_upload_limit->addWidget ( label_upload_limit_units );  
   
   // Prepare the layout of the buttons
   
   layout_buttons = new QVBoxLayout ();
   layout_main->addLayout ( layout_buttons );
   
   // Prepare the buttons to add
   
   button_apply = new QPushButton ( shared_components->text ()->operator[] ( Core::KeyTxtInterfaceApply ) );
   button_clear = new QPushButton ( shared_components->text ()->operator[] ( Core::KeyTxtInterfaceClear ) );
   connect ( button_clear , SIGNAL ( clicked () ) , this , SLOT ( clearLimits () ) );
   connect ( button_apply , SIGNAL ( clicked () ) , this , SLOT ( applyLimits () ) );
   
   // Add the buttons to the buttons layout
   
   layout_buttons->addStretch ();
   layout_buttons->addWidget ( button_apply );
   layout_buttons->addWidget ( button_clear );
   
   // Prepare the timer
   
   timer_internal_clock = new QTimer ( this );
   connect ( timer_internal_clock , SIGNAL ( timeout () ) , this , SLOT ( updateInfo () ) );
   
   /*
    * So, the timer works with delays.
    * If the user says he wants 1 refresh per second, that means a delay of 1000 milliseconds.
    * 5 times per second means 200 milliseconds.
    * 0.5 times means 2000 milliseconds.
    * 
    * This values can be calculated by dividing 1000 millisecons between the times per second
    * the user wants a refresh.
    * 
    */
   
   double times_per_second = shared_components->config ()->operator[] ( Core::KeyGuiRefreshRate ).toDouble ();
   int milliseconds = 1000.0 / times_per_second;
   
   timer_internal_clock->start ( milliseconds );
   
   // Force a first update, since the data must not be looking so bad.
   updateInfo ();
}

Gui::PanelInterface::~PanelInterface ( void )
{
   timer_internal_clock->stop ();
   delete timer_internal_clock;
}

void Gui::PanelInterface::commandRunner ( QString command )
{
   /*
    * The process is not complex. I need the appy command. That command can be run alone, without much changes.
    * 
    * But, wondershaper need to be run as root, so, I need to run it as root.
    * To run it as root there are two ways. One, if I'm running as a normal user, is using the "root runner" command,
    * normally kdesu. If I'm running as root, I can run the command directly.
    * 
    * Of couse, such behaviour is configurable by the user.
    */
   
   QString apply_command = command;
   QString root_runner = shared_components->config ()->operator[] ( Core::KeyCmdRootRunner ).replace ( "%COMMAND%" , apply_command );
   QString final_command;
   
   if ( shared_components->config ()->operator[] ( Core::KeyCtlRunWithRootRunner ).toInt () == 1 )
   {
      final_command = root_runner;
   }
   else
   {
      final_command = apply_command;
   }
   
   // Prepare the command to use with the QProcess component.
   QString program;
   QStringList arguments;
   QStringList command_pieces;
   
   command_pieces = final_command.split ( " " );
   
   program = command_pieces[ 0 ];
   
   for ( int i = 1; i < command_pieces.size (); i++ )
   {
      arguments << command_pieces[ i ];
   }
      
   QProcess process ( this );
   process.start ( program , arguments );
   process.waitForFinished ();
   
   return;
}

void Gui::PanelInterface::applyLimits ( void )
{
   // Should I clear before applying?
   if ( shared_components->config ()->operator[] ( Core::KeyCtlClearBeforeLimit ).toInt () == 1 )
   {
      clearLimits ();
   }
   
   QString apply_command = shared_components->config ()->operator[] ( Core::KeyCmdLimitCommand ).replace ( "%INTERFACE%" , interface_name );
   
   // Ok, get the limits, convert them to kilobytes and multiply them by the multiplication factor.
   
   double download_limit;
   double upload_limit;
   QString speed_units;
   
   download_limit = spin_download_limit->value ();
   upload_limit = spin_upload_limit->value ();
   speed_units = shared_components->config ()->operator[] ( Core::KeyGuiSpeedUnits );
   
   // First, turn the speed limit to kilobytes
   if ( speed_units == QString ( "B/s" ) )
   {
      download_limit /= 1024;
      upload_limit /= 1024;
   }
   else if ( speed_units == QString ( "MB/s" ) )
   {
      download_limit *= 1024;
      upload_limit *= 1024;
   }
   else if ( speed_units == QString ( "GB/s" ) )
   {
      download_limit *= 1024;
      download_limit *= 1024;
      upload_limit *= 1024;
      upload_limit *= 1024;
   }
   
   // Multiply by 8, by default
   download_limit *= shared_components->config ()->operator[] ( Core::KeyCtlSpeedMultiplier ).toDouble ();
   upload_limit *= shared_components->config ()->operator[] ( Core::KeyCtlSpeedMultiplier ).toDouble ();
   
   apply_command.replace ( "%USPEED%" , QString::number ( (unsigned long long)upload_limit ) );
   apply_command.replace ( "%DSPEED%" , QString::number ( (unsigned long long)download_limit ) );
   
   commandRunner ( apply_command );
   
   return;
}

void Gui::PanelInterface::clearLimits ( void )
{
   QString clear_command = shared_components->config ()->operator[] ( Core::KeyCmdClearCommand ).replace ( "%INTERFACE%" , interface_name );
   commandRunner ( clear_command );
   
   return;
}

unsigned long long Gui::PanelInterface::loadDataAmount ( const QString& file_path )
{
   QFile file ( file_path );
   unsigned long int amount = 0;
   
   if ( !file.open ( QIODevice::ReadOnly | QIODevice::Text ) )
   {
      qDebug () << "Gui::PanelInterface::updateInfo (" << interface_name << "): Can't open file: " << file_path;
   }
   else
   {
      QTextStream amount_stream ( &file );
      amount_stream >> amount;
   }
   
   return ( amount );
}

void Gui::PanelInterface::displayDataInfo ( const QString& data_units , const unsigned long long& received_amount , const unsigned long long& sent_amount )
{
   double down = received_amount;
   double up = sent_amount;
   
   if ( data_units == QString ( "B" ) )
   {
      label_download_data->setText ( QString ( "%1 %2" ).arg ( QString::number ( down , 'f' , 2 ) ).arg ( data_units ) );
      label_upload_data->setText ( QString ( "%1 %2" ).arg ( QString::number ( up , 'f' , 2 ) ).arg ( data_units ) );
   }
   else if ( data_units == QString ( "KB" ) )
   {
      label_download_data->setText ( QString ( "%1 %2" ).arg ( QString::number ( down / 1024.0 , 'f' , 2 ) ).arg ( data_units ) );
      label_upload_data->setText ( QString ( "%1 %2" ).arg ( QString::number ( up / 1024.0 , 'f' , 2 ) ).arg ( data_units ) );
   }
   else if ( data_units == QString ( "MB" ) )
   {
      label_download_data->setText ( QString ( "%1 %2" ).arg ( QString::number ( ( down / 1024.0 ) / 1024.0 , 'f' , 2 ) ).arg ( data_units ) );
      label_upload_data->setText ( QString ( "%1 %2" ).arg ( QString::number ( ( up / 1024.0 ) / 1024.0 , 'f' , 2 ) ).arg ( data_units ) );
   }
   else if ( data_units == QString ( "GB" ) )
   {
      label_download_data->setText ( QString ( "%1 %2" ).arg ( QString::number ( ( ( down / 1024.0 ) / 1024.0 ) / 1024.0 , 'f' , 2 ) ).arg ( data_units ) );
      label_upload_data->setText ( QString ( "%1 %2" ).arg ( QString::number ( ( ( up / 1024.0 ) / 102.0 ) / 1024.0 , 'f' , 2 ) ).arg ( data_units ) );
   }
   
   return;
}

void Gui::PanelInterface::displaySpeedInfo ( const QString& speed_units , const unsigned long long& received_amount , const unsigned long long& sent_amount )
{
   double down = received_amount;
   double up = sent_amount;
   double current_sent = up - (double)old_upload_bytes;
   double current_received = down - (double)old_download_bytes;
   
   // To get the real speed I need to perform some calculations.
   // If the refresh rate is 1, the curent bytes are correct.
   // If the refresh rate is 5, the current bytes represent the bytes sent in a fifth of a second, so, to get the
   // speed in seconds, I need to multiply by 5.
   // If the refresh rate is 0.5, the current bytes represent the bytes sent in two seconds, so, to represent the
   // speed in seconds, I need to multiply by 0.5
   
   double refresh_rate = shared_components->config ()->operator[] ( Core::KeyGuiRefreshRate ).toDouble ();
   current_sent *= refresh_rate;
   current_received *= refresh_rate;
   
   if ( speed_units == QString ( "B/s" ) )
   {
      label_download_speed->setText ( QString ( "%1 %2" ).arg ( QString::number ( current_received , 'f' , 2 ) ).arg ( speed_units ) );
      label_upload_speed->setText ( QString ( "%1 %2" ).arg ( QString::number ( current_sent , 'f' , 2 ) ).arg ( speed_units ) );
   }
   else if ( speed_units == QString ( "KB/s" ) )
   {
      label_download_speed->setText ( QString ( "%1 %2" ).arg ( QString::number ( current_received / 1024.0 , 'f' , 2 ) ).arg ( speed_units ) );
      label_upload_speed->setText ( QString ( "%1 %2" ).arg ( QString::number ( current_sent / 1024.0 , 'f' , 2 ) ).arg ( speed_units ) );
   }
   else if ( speed_units == QString ( "MB/s" ) )
   {
      label_download_speed->setText ( QString ( "%1 %2" ).arg ( QString::number ( ( current_received / 1024.0 ) / 1024.0 , 'f' , 2 ) ).arg ( speed_units ) );
      label_upload_speed->setText ( QString ( "%1 %2" ).arg ( QString::number ( ( current_sent / 1024.0 ) / 1024.0 , 'f' , 2 ) ).arg ( speed_units ) );
   }
   else if ( speed_units == QString ( "GB/s" ) )
   {
      label_download_speed->setText ( QString ( "%1 %2" ).arg ( QString::number ( ( ( current_received / 1024.0 ) / 1024.0 ) / 1024.0 , 'f' , 2 ) ).arg ( speed_units ) );
      label_upload_speed->setText ( QString ( "%1 %2" ).arg ( QString::number ( ( ( current_sent / 1024.0 ) / 1024.0 ) / 1024.0 , 'f' , 2 ) ).arg ( speed_units ) );
   }
   
   old_download_bytes = received_amount;
   old_upload_bytes = sent_amount;
   
   return;
}

void Gui::PanelInterface::updateInfo ( void )
{
   // Load the sent bytes (upload)
   QString sent_path = shared_components->config ()->operator[] ( Core::KeySysPathInterfaceUpload ).replace ( "%INTERFACE%" , interface_name );
   QString received_path = shared_components->config ()->operator[] ( Core::KeySysPathInterfaceDownload ).replace ( "%INTERFACE%" , interface_name );
   
   unsigned long long sent_amount = loadDataAmount ( sent_path );
   unsigned long long received_amount = loadDataAmount ( received_path );
   
   // I have the amounts. Those amounts are in bytes, transform into the units expected.
   
   QString data_units;
   QString speed_units;
   
   data_units = shared_components->config ()->operator[] ( Core::KeyGuiDataUnits );
   speed_units = shared_components->config ()->operator[] ( Core::KeyGuiSpeedUnits );
   
   displayDataInfo ( data_units , received_amount , sent_amount );
   displaySpeedInfo ( speed_units , received_amount , sent_amount );
   
   return;
}
