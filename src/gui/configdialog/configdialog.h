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

# ifndef CONFIGDIALOG_H_
# define CONFIGDIALOG_H_

# include <QtGui/QDialog>
# include <QtGui/QVBoxLayout>

# include "../../core/core.h"
# include "panels/buttonspanel.h"
# include "panels/languagepanel.h"
# include "panels/pathspanel.h"
# include "panels/filespanel.h"
# include "panels/networkpanel.h"
# include "panels/commandspanel.h"

namespace Gui
{
   class ConfigDialog : public QDialog
   {
      Q_OBJECT
      
      public:
         explicit ConfigDialog ( Core::SharedComponents* new_shared_components );
         
      private:
         Core::SharedComponents* shared_components;
         QVBoxLayout* layout_main;
         Gui::ButtonsPanel* buttons_panel;
         Gui::LanguagePanel* language_panel;
         Gui::PathsPanel* paths_panel;
         Gui::FilesPanel* files_panel;
         Gui::NetworkPanel* network_panel;
         Gui::CommandsPanel* commands_panel;
   };
}

# endif
