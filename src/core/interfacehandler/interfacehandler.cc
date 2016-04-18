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

# include "interfacehandler.h"

Core::InterfaceHandler::InterfaceHandler ( Core::Configuration* new_config )
   : QObject ()
{
   config = new_config;
}

QList< QString > Core::InterfaceHandler::findInterfaces ( void )
{
   /* Create a process, run the listing command, read and parse the output.
    * The command should be "ip link show". The expected command output
    * will be something like this:
    * 
    * 1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN mode DEFAULT 
    *     link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    * 2: enp2s0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast state UP mode DEFAULT qlen 1000
    *     link/ether c8:60:00:5b:2c:c9 brd ff:ff:ff:ff:ff:ff
    * 3: wlp3s5: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN mode DORMANT qlen 1000
    *     link/ether b8:a3:86:08:65:c4 brd ff:ff:ff:ff:ff:ff
    * 
    * So, the idea is to read the output of the command and find the names (lo, enp2s0 and wlp3s5 in this example).
    * 
    * The way to detect such words is looking at the format. The interface names appears with a sufix: ":", so
    * analyze word by word, and take as a name those that ends with a ":". Of course, the 1, 2 and 3 numbers are
    * not interface names, so, to skip them, lets keep only those words with 2 or more characters (like "lo").
    */
   
   QProcess process ( this );
   QStringList command_pieces;
   command_pieces = config->operator[] ( Core::KeyCmdInterfaceListing ).split ( " " );
   
   QString command = command_pieces[ 0 ];
   QStringList arguments;
   
   for ( int i = 1; i < command_pieces.size (); i++ )
   {
      arguments << command_pieces[ i ];
   }
   
   process.start ( command , arguments );
   process.waitForFinished ();
   
   // I have the command output. Now, I need to check if I must skip some interfaces.
   QString str_interfaces_to_exclude = config->operator[] ( Core::KeyCtlInterfacesToExclude );
   QStringList interfaces_to_exclude_list = str_interfaces_to_exclude.split ( "," ); // Split using commas. The list is in this format: "interface1,myinterface,my other interface,other,etc"
   
   // Load output, word by word
   QString total_output;
   total_output = process.readAll ();
   
   QTextStream stream ( &total_output );
   QList< QString > interface_names;
   
   while ( !stream.atEnd () )
   {
      QString word;
      
      stream >> word;
      
      if ( word.endsWith ( ":" ) && word.size () > 2 )
      {
         // Is an interface name
         word = word.left ( word.size () - 1 );
         
         if ( !interfaces_to_exclude_list.contains ( word ) )
         {
            interface_names.append ( word );
            qDebug () << "Core::InterfaceHandler::findInterfaces: Interface found: " << word;
         }
         else
         {
            qDebug () << "Core::InterfaceHandler::findInterfaces: Interface " << word << " not used. Modify configuration to not exclude it.";
         }
      }
   }
   
   return ( interface_names );
}
