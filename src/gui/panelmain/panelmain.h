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

# ifndef PANELMAIN_H_
# define PANELMAIN_H_

# include <QtGui/QWidget>
# include <QtGui/QVBoxLayout>
# include <QtCore/QList>
# include <QtCore/QString>

# include "../../core/core.h"
# include "../paneltitle/paneltitle.h"
# include "../panelinterface/panelinterface.h"

namespace Gui
{
   class PanelMain : public QWidget
   {
      Q_OBJECT
      
      public:
         explicit PanelMain ( Core::SharedComponents* new_shared_components );
         
      signals:
         void displayConfig ( void );
         
      private:
         Core::SharedComponents* shared_components;
         QVBoxLayout* layout_main;
         Gui::PanelTitle* panel_title;
         QList< Gui::PanelInterface* > panels_interfaces;
   };
}

# endif
