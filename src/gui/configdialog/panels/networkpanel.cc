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

# include "networkpanel.h"

Gui::NetworkPanel::NetworkPanel ( Core::SharedComponents* new_shared_components )
   : QGroupBox ()
{
   shared_components = new_shared_components;
   
   layout_main = new QGridLayout ( this );
   this->setLayout ( layout_main );
   
   label_data_units = new QLabel ();
   label_interfaces_excluded = new QLabel ();
   label_refresh_rate = new QLabel ();
   label_speed_units = new QLabel ();
   label_times_per_second = new QLabel ();
   line_interfaces_excluded = new QLineEdit ();
   spin_refresh_rate = new QDoubleSpinBox ();
   combo_data_units = new QComboBox ();
   combo_speed_units = new QComboBox ();

   spin_refresh_rate->setRange ( 0.1 , 100 );
   spin_refresh_rate->setSingleStep ( 0.1 );
   
   combo_data_units->addItem ( QString ( "B" ) );
   combo_data_units->addItem ( QString ( "KB" ) );
   combo_data_units->addItem ( QString ( "MB" ) );
   combo_data_units->addItem ( QString ( "GB" ) );
   combo_speed_units->addItem ( QString ( "B/s" ) );
   combo_speed_units->addItem ( QString ( "KB/s" ) );
   combo_speed_units->addItem ( QString ( "MB/s" ) );
   combo_speed_units->addItem ( QString ( "GB/s" ) );
   
   layout_refresh_rate = new QHBoxLayout ();
   
   layout_main->addWidget ( label_refresh_rate , 0 , 0 );
   layout_main->addWidget ( label_speed_units , 1 , 0 );
   layout_main->addWidget ( label_data_units , 2 , 0 );
   layout_main->addWidget ( label_interfaces_excluded , 3 , 0 );
   layout_main->addLayout ( layout_refresh_rate , 0 , 1 );
   layout_main->addWidget ( combo_speed_units , 1 , 1 );
   layout_main->addWidget ( combo_data_units , 2 , 1 );
   layout_main->addWidget ( line_interfaces_excluded , 3 , 1 );
   
   layout_refresh_rate->addWidget ( spin_refresh_rate );
   layout_refresh_rate->addWidget ( label_times_per_second );
   
   updateText ();
   updateValues ();
   
   connect ( shared_components->config () , SIGNAL ( updateValues () ) , this , SLOT ( updateValues () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
}

void Gui::NetworkPanel::updateText ( void )
{
   setTitle ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowNetworkInterfacesInformation ) );
   label_data_units->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowDataUnits ) );
   label_speed_units->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowSpeedUnits ) );
   label_interfaces_excluded->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowListOfInterfacesToExclude ) );
   label_refresh_rate->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowRefreshRate ) );
   label_times_per_second->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowTimesPerSecond ) );
   
   return;
}

void Gui::NetworkPanel::updateValues ( void )
{
   combo_data_units->setCurrentIndex ( dataIndex ( shared_components->config ()->operator[] ( Core::KeyGuiDataUnits ) ) );
   combo_speed_units->setCurrentIndex ( speedIndex ( shared_components->config ()->operator[] ( Core::KeyGuiSpeedUnits ) ) );
   spin_refresh_rate->setValue ( shared_components->config ()->operator[] ( Core::KeyGuiRefreshRate ).toDouble () );
   line_interfaces_excluded->setText ( shared_components->config ()->operator[] ( Core::KeyCtlInterfacesToExclude ) );
   
   return;
}

void Gui::NetworkPanel::saveValues ( void )
{
   shared_components->config ()->set ( Core::KeyGuiDataUnits , combo_data_units->currentText () );
   shared_components->config ()->set ( Core::KeyGuiSpeedUnits , combo_speed_units->currentText () );
   shared_components->config ()->set ( Core::KeyGuiRefreshRate , QString ( "%1" ).arg ( spin_refresh_rate->value () ) );
   
   QString line;
   QString final_list;
   
   line = line_interfaces_excluded->text ();
   QStringList pieces = line.split ( "," );
   
   for ( int i = 0; i < pieces.size (); i++ )
   {
      QString name;
      name = pieces[ i ].trimmed ();
      
      if ( !name.isEmpty () )
      {
         if ( final_list.isEmpty () )
         {
            final_list = name;
         }
         else
         {
            final_list += ",";
            final_list += name;
         }
      }
   }
   
   shared_components->config ()->set ( Core::KeyCtlInterfacesToExclude , final_list );
   
   return;
}

int Gui::NetworkPanel::dataIndex ( const QString& data_units )
{
   if ( data_units == QString ( "B" ) )
      return ( 0 );
   
   if ( data_units == QString ( "KB" ) )
      return ( 1 );
   
   if ( data_units == QString ( "MB" ) )
      return ( 2 );
   
   // GB
   return ( 3 );
}

int Gui::NetworkPanel::speedIndex ( const QString& speed_units )
{
   if ( speed_units == QString ( "B/s" ) )
      return ( 0 );
   
   if ( speed_units == QString ( "KB/s" ) )
      return ( 1 );
   
   if ( speed_units == QString ( "MB/s" ) )
      return ( 2 );
   
   // GB/s
   return ( 3 );
}
