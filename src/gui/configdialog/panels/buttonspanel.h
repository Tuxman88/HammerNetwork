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

# ifndef BUTTONSPANEL_H_
# define BUTTONSPANEL_H_

# include <QtGui/QWidget>
# include <QtGui/QHBoxLayout>
# include <QtGui/QPushButton>

# include "../../../core/core.h"

namespace Gui
{
   class ButtonsPanel : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit ButtonsPanel ( Core::SharedComponents* new_shared_components );
         
      signals:
         void resetConfig ( void );
         void saveConfig ( void );
         void cancelConfig ( void );
         
      public slots:
         void updateText ( void );
         
      private:
         Core::SharedComponents* shared_components;
         QHBoxLayout* layout_main;
         QPushButton* button_reset;
         QPushButton* button_save;
         QPushButton* button_cancel;
   };
}

# endif
