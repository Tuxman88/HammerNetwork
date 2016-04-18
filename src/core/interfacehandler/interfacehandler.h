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

# ifndef INTERFACEHANDLER_H_
# define INTERFACEHANDLER_H_

# include <QtCore/QObject>
# include <QtCore/QString>
# include <QtCore/QList>
# include <QtCore/QStringList>
# include <QtCore/QProcess>
# include <QtCore/QTextStream>
# include <QtCore/QDebug>

# include "../configuration/configuration.h"

namespace Core
{
   class InterfaceHandler : public QObject
   {
      Q_OBJECT
      
      public:
         explicit InterfaceHandler ( Core::Configuration* new_config );
         
         QList< QString > findInterfaces ( void ); 
         
      private:
         Core::Configuration* config;
   };
}

# endif
