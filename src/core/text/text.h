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

# ifndef TEXT_H_
# define TEXT_H_

# include <QtCore/QObject>
# include <QtCore/QMap>
# include <QtCore/QString>
# include <QtCore/QFile>
# include <QtCore/QStringList>
# include <QtCore/QDebug>

# include "../configuration/configuration.h"
# include "../keys.h"

namespace Core
{
   class Text : public QObject
   {
      Q_OBJECT
      
      public:
         explicit Text ( Core::Configuration* new_config );
         
         QString operator[] ( const QString& key );
         
      signals:
         void updateText ( void );
         
      private:
         void fillDefault ( void );
         Core::Configuration* config;
         QMap< QString , QString > current_text;
   };
}

# endif
