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

# ifndef PANELINTERFACE_H_
# define PANELINTERFACE_H_

# include <QtGui/QGroupBox>
# include <QtCore/QString>
# include <QtGui/QHBoxLayout>
# include <QtGui/QGridLayout>
# include <QtGui/QVBoxLayout>
# include <QtGui/QPushButton>
# include <QtGui/QLabel>
# include <QtGui/QDoubleSpinBox>
# include <QtCore/QTimer>
# include <QtCore/QTextStream>

# include "../../core/core.h"

namespace Gui
{
   class PanelInterface : public QGroupBox
   {
      Q_OBJECT
      
      public:
         explicit PanelInterface ( Core::SharedComponents* new_shared_components , const QString& new_interface_name );
         ~PanelInterface ( void );
      
      private slots:
         void updateInfo ( void );
         void applyLimits ( void );
         void clearLimits ( void );
         
      private:
         unsigned long long loadDataAmount ( const QString& file_path );
         void displayDataInfo ( const QString& data_units , const unsigned long long& received_amount , const unsigned long long& sent_amount );
         void displaySpeedInfo ( const QString& speed_units , const unsigned long long& received_amount , const unsigned long long& sent_amount );
         void commandRunner ( QString command );
         
      private:
         Core::SharedComponents* shared_components;
         QString interface_name;
         QHBoxLayout* layout_main;
         QGridLayout* layout_info;
         QVBoxLayout* layout_buttons;
         QPushButton* button_apply;
         QPushButton* button_clear;
         QLabel* label_download;
         QLabel* label_upload;
         QLabel* label_total_data;
         QLabel* label_current_speed;
         QLabel* label_limits;
         QLabel* label_download_data;
         QLabel* label_upload_data;
         QLabel* label_download_speed;
         QLabel* label_upload_speed;
         QLabel* label_download_limit_units;
         QLabel* label_upload_limit_units;
         QDoubleSpinBox* spin_download_limit;
         QDoubleSpinBox* spin_upload_limit;
         QHBoxLayout* layout_download_limit;
         QHBoxLayout* layout_upload_limit;
         QTimer* timer_internal_clock;
         unsigned long long old_upload_bytes;
         unsigned long long old_download_bytes;
   };
}

# endif
