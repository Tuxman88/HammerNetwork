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

# include "configuration.h"

Core::Configuration::Configuration ( void )
   : QObject ()
{
   settings = new QSettings ( tr ( "TuxmanSoft" ) , tr ( "Hammer Network 0.1.0" ) );
   
   // Validate the information of the configuration. Check if all the needed keys exists.
   
   if ( !settings->contains ( Core::KeyGuiDataUnits ) )
      settings->setValue ( Core::KeyGuiDataUnits , Core::ValGuiDataUnits );
   
   if ( !settings->contains ( Core::KeyGuiSpeedUnits ) )
      settings->setValue ( Core::KeyGuiSpeedUnits , Core::ValGuiSpeedUnits );
   
   if ( !settings->contains ( Core::KeyGuiRefreshRate ) )
      settings->setValue ( Core::KeyGuiRefreshRate , Core::ValGuiRefreshRate );
   
   if ( !settings->contains ( Core::KeyGuiLang ) )
      settings->setValue ( Core::KeyGuiLang , Core::ValGuiLang );
   
   if ( !settings->contains ( Core::KeySysPathInterfaceStatus ) )
      settings->setValue ( Core::KeySysPathInterfaceStatus , Core::ValSysPathInterfaceStatus );
   
   if ( !settings->contains ( Core::KeySysPathInterfaceDownload ) )
      settings->setValue ( Core::KeySysPathInterfaceDownload , Core::ValSysPathInterfaceDownload );
   
   if ( !settings->contains ( Core::KeySysPathInterfaceUpload ) )
      settings->setValue ( Core::KeySysPathInterfaceUpload , Core::ValSysPathInterfaceUpload );
   
   if ( !settings->contains ( Core::KeySysFileInterfaceUp ) )
      settings->setValue ( Core::KeySysFileInterfaceUp , Core::ValSysFileInterfaceUp );
   
   if ( !settings->contains ( Core::KeySysFileInterfaceDown ) )
      settings->setValue ( Core::KeySysFileInterfaceDown , Core::ValSysFileInterfaceDown );
   
   if ( !settings->contains ( Core::KeyCmdClearCommand ) )
      settings->setValue ( Core::KeyCmdClearCommand , Core::ValCmdClearCommand );
   
   if ( !settings->contains ( Core::KeyCmdLimitCommand ) )
      settings->setValue ( Core::KeyCmdLimitCommand , Core::ValCmdLimitCommand );
   
   if ( !settings->contains ( Core::KeyCmdRootRunner ) )
      settings->setValue ( Core::KeyCmdRootRunner , Core::ValCmdRootRunner );
   
   if ( !settings->contains ( Core::KeyCtlClearBeforeLimit ) )
      settings->setValue ( Core::KeyCtlClearBeforeLimit , Core::ValCtlClearBeforeLimit );
   
   if ( !settings->contains ( Core::KeyCtlSpeedMultiplier ) )
      settings->setValue ( Core::KeyCtlSpeedMultiplier , Core::ValCtlSpeedMultiplier );
   
   if ( !settings->contains ( Core::KeyCtlRunWithRootRunner ) )
      settings->setValue ( Core::KeyCtlRunWithRootRunner , Core::ValCtlRunWithRootRunner );
   
   if ( !settings->contains ( Core::KeyCmdInterfaceListing ) )
      settings->setValue ( Core::KeyCmdInterfaceListing , Core::ValCmdInterfaceListing );
   
   if ( !settings->contains ( Core::KeyCtlInterfacesToExclude ) )
      settings->setValue ( Core::KeyCtlInterfacesToExclude , Core::ValCtlInterfacesToExclude );
}

Core::Configuration::~Configuration ( void )
{
   delete settings;
}

void Core::Configuration::resetValues ( void )
{
   settings->setValue ( Core::KeyGuiDataUnits , Core::ValGuiDataUnits );
   settings->setValue ( Core::KeyGuiSpeedUnits , Core::ValGuiSpeedUnits );
   settings->setValue ( Core::KeyGuiRefreshRate , Core::ValGuiRefreshRate );
   settings->setValue ( Core::KeyGuiLang , Core::ValGuiLang );
   settings->setValue ( Core::KeySysPathInterfaceStatus , Core::ValSysPathInterfaceStatus );
   settings->setValue ( Core::KeySysPathInterfaceDownload , Core::ValSysPathInterfaceDownload );
   settings->setValue ( Core::KeySysPathInterfaceUpload , Core::ValSysPathInterfaceUpload );
   settings->setValue ( Core::KeySysFileInterfaceUp , Core::ValSysFileInterfaceUp );
   settings->setValue ( Core::KeySysFileInterfaceDown , Core::ValSysFileInterfaceDown );
   settings->setValue ( Core::KeyCmdClearCommand , Core::ValCmdClearCommand );
   settings->setValue ( Core::KeyCmdLimitCommand , Core::ValCmdLimitCommand );
   settings->setValue ( Core::KeyCmdRootRunner , Core::ValCmdRootRunner );
   settings->setValue ( Core::KeyCtlClearBeforeLimit , Core::ValCtlClearBeforeLimit );
   settings->setValue ( Core::KeyCtlSpeedMultiplier , Core::ValCtlSpeedMultiplier );
   settings->setValue ( Core::KeyCtlRunWithRootRunner , Core::ValCtlRunWithRootRunner );
   settings->setValue ( Core::KeyCmdInterfaceListing , Core::ValCmdInterfaceListing );
   settings->setValue ( Core::KeyCtlInterfacesToExclude , Core::ValCtlInterfacesToExclude );
   
   emit updateValues ();
   
   return;
}

void Core::Configuration::set ( const QString& key , const QString& value )
{
   settings->setValue ( key , value );
   
   return;
}

QString Core::Configuration::operator[] ( const QString& key )
{
   return ( settings->value ( key ).toString () );
}

