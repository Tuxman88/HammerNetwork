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

# ifndef COMMANDSPANEL_H_
# define COMMANDSPANEL_H_

# include <QtGui/QGridLayout>
# include <QtGui/QGroupBox>
# include <QtGui/QLineEdit>
# include <QtGui/QCheckBox>
# include <QtGui/QLabel>
# include <QtGui/QSpinBox>
# include <QtGui/QMessageBox>

# include "../../../core/core.h"

namespace Gui
{
   class CommandsPanel : public QGroupBox
   {
      Q_OBJECT
      
      public:
         explicit CommandsPanel ( Core::SharedComponents* new_shared_components );
      
      public slots:
         void updateText ( void );
         void updateValues ( void );
         void saveValues ( void );
            
      private:
         Core::SharedComponents* shared_components;
         QGridLayout* layout_main;
         QLabel* label_clear_limit_before_set;
         QLabel* label_clear_command;
         QLabel* label_limit_command;
         QLabel* label_speed_multiplier;
         QLabel* label_root_runner;
         QLabel* label_interface_listing_command;
         QLabel* label_run_as_root;
         QCheckBox* check_clear_limit_before_set;
         QLineEdit* line_clear_command;
         QLineEdit* line_limit_command;
         QSpinBox* spin_speed_multiplier;
         QLineEdit* line_root_runner;
         QLineEdit* line_interface_listing_command;
         QCheckBox* check_run_as_root;
   };
}

# endif
