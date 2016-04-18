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

# ifndef PATHSPANEL_H_
# define PATHSPANEL_H_

# include <QtGui/QGroupBox>
# include <QtGui/QGridLayout>
# include <QtGui/QLabel>
# include <QtGui/QLineEdit>
# include <QtGui/QMessageBox>

# include "../../../core/core.h"

namespace Gui
{
   class PathsPanel : public QGroupBox
   {
      Q_OBJECT
      
      public:
         explicit PathsPanel ( Core::SharedComponents* new_shared_components );
         
      public slots:
         void updateText ( void );
         void updateValues ( void );
         void saveValues ( void );
         
      private:
         Core::SharedComponents* shared_components;
         QGridLayout* layout_main;
         QLabel* label_interface_status;
         QLabel* label_interface_download_bytes;
         QLabel* label_interface_upload_bytes;
         QLineEdit* line_interface_status;
         QLineEdit* line_interface_download_bytes;
         QLineEdit* line_interface_upload_bytes;
   };
}

# endif
