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

# ifndef PANELTITLE_H_
# define PANELTITLE_H_

# include <QtGui/QWidget>
# include <QtGui/QHBoxLayout>
# include <QtGui/QVBoxLayout>
# include <QtGui/QLabel>
# include <QtGui/QPushButton>
# include <QtGui/QPixmap>
# include <QtGui/QFont>

# include "../../core/core.h"

namespace Gui
{
   class PanelTitle : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit PanelTitle ( Core::SharedComponents* new_shared_components );
         
      signals:
         void displayConfig ( void );
         
      private:
         Core::SharedComponents* shared_components;
         QHBoxLayout* layout_main;
         QVBoxLayout* layout_text;
         QVBoxLayout* layout_button;
         QLabel* label_application_icon;
         QLabel* label_application_name;
         QLabel* label_application_catchphrase;
         QPushButton* button_config;
   };
}

# endif
