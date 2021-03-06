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

# ifndef SHAREDCOMPONENTS_H_
# define SHAREDCOMPONENTS_H_

# include <QtCore/QObject>

# include "../configuration/configuration.h"
# include "../text/text.h"
# include "../interfacehandler/interfacehandler.h"

namespace Core
{
   class SharedComponents : public QObject
   {
      Q_OBJECT
      
      public:
         explicit SharedComponents ( void );
         ~SharedComponents ( void );
         
         Core::Configuration* config ( void );
         Core::Text* text ( void );
         Core::InterfaceHandler* interfaceHandler ( void );
         
      private:
         Core::Configuration* shared_configuration;
         Core::Text* shared_text;
         Core::InterfaceHandler* shared_interface_handler;
   };
}

# endif
