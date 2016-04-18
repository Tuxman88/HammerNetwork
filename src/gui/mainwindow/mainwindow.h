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

# ifndef MAINWINDOW_H_
# define MAINWINDOW_H_

# include <QtGui/QMainWindow>
# include <QtGui/QIcon>

# include "../../core/core.h"
# include "../panelmain/panelmain.h"
# include "../configdialog/configdialog.h"

namespace Gui
{
   class MainWindow : public QMainWindow
   {
      Q_OBJECT
      
      public:
         explicit MainWindow ( Core::SharedComponents* new_shared_components );
         ~MainWindow ( void );
         
      private slots:
         void displayConfig ( void );
         
      private:
         Core::SharedComponents* shared_components;
         Gui::PanelMain* panel_main;
         Gui::ConfigDialog* config_dialog;
   };
}

# endif
