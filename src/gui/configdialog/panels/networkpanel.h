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

# ifndef NETWORKPANEL_H_
# define NETWORKPANEL_H_

# include <QtGui/QGroupBox>
# include <QtGui/QGridLayout>
# include <QtGui/QLabel>
# include <QtGui/QHBoxLayout>
# include <QtGui/QDoubleSpinBox>
# include <QtGui/QComboBox>
# include <QtGui/QLineEdit>
# include <QtCore/QStringList>

# include "../../../core/core.h"

namespace Gui
{
   class NetworkPanel : public QGroupBox
   {
      Q_OBJECT
      
      public:
         explicit NetworkPanel ( Core::SharedComponents* new_shared_components );
         
      public slots:
         void updateText ( void );
         void updateValues ( void );
         void saveValues ( void );
         
      private:
         int speedIndex ( const QString& speed_units );
         int dataIndex ( const QString& data_units );
         
      private:
         Core::SharedComponents* shared_components;
         QGridLayout* layout_main;
         QHBoxLayout* layout_refresh_rate;
         QLabel* label_refresh_rate;
         QLabel* label_times_per_second;
         QDoubleSpinBox* spin_refresh_rate;
         QLabel* label_speed_units;
         QComboBox* combo_speed_units;
         QLabel* label_data_units;
         QComboBox* combo_data_units;
         QLabel* label_interfaces_excluded;
         QLineEdit* line_interfaces_excluded;
   };
}

# endif
