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

# include "sharedcomponents.h" 

Core::SharedComponents::SharedComponents ( void )
   : QObject ()
{
   shared_configuration = new Core::Configuration ();
   shared_text = new Core::Text ( shared_configuration );
   shared_interface_handler = new Core::InterfaceHandler ( shared_configuration );
}

Core::SharedComponents::~SharedComponents ( void )
{
   delete shared_configuration;
   delete shared_text;
}

Core::Configuration* Core::SharedComponents::config ( void )
{
   return ( shared_configuration );
}

Core::Text* Core::SharedComponents::text ( void )
{
   return ( shared_text );
}

Core::InterfaceHandler* Core::SharedComponents::interfaceHandler ( void )
{
   return ( shared_interface_handler );
}
