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

# include "paneltitle.h"

Gui::PanelTitle::PanelTitle ( Core::SharedComponents* new_shared_components )
   : QWidget ()
{
   shared_components = new_shared_components;
   
   /*
    * This panel has this design:
    * 
    * 1: Bottom layout (layout_main)
    * i: Image to display (label_application_icon)
    * 2: Application text layout (layout_text)
    * t: Application text (label_aplication_name and label_application_catchphrase)
    * 3: Layout of the button (layout_button)
    * b: Button (button_config)
    * 
    * 11111111111111111111111111111111111111111
    * 1iiiiiii122222222222222213333333333333331
    * 1iiiiiii12ttttttttttttt213333333333333331
    * 1iiiiiii12ttttttttttttt21333bbbbbbbbbbb31
    * 1iiiiiii122222222222222213333333333333331
    * 11111111111111111111111111111111111111111
    * 
    * This can be seen as:
    * 
    *           ttttttttttttt   bbbbbbbbbbbbb
    *  iiiiiii 222222222222222 333333333333333
    * 11111111111111111111111111111111111111111
    */
   
   // Prepare main layout
   
   layout_main = new QHBoxLayout ( this );
   this->setLayout ( layout_main );
   
   // Prepare the application icon
   
   QPixmap pixmap ( ":/icon-main-128" );
   
   label_application_icon = new QLabel ();
   label_application_icon->setPixmap ( pixmap );
   layout_main->addWidget ( label_application_icon );
   layout_main->addStretch ();
   
   // Prepare the application text layout
   
   layout_text = new QVBoxLayout ();
   layout_main->addLayout ( layout_text );
   layout_main->addStretch ();
   
   // Prepare the application text
   
   label_application_name = new QLabel ( QString ( "%1 %2" ).arg ( shared_components->text ()->operator[] ( Core::KeyTxtApplicationName ) )
                                                            .arg ( shared_components->text ()->operator[] ( Core::KeyTxtApplicationVersion ) ) );
   QFont font = label_application_name->font ();
   font.setPointSize ( 20 );
   font.setBold ( true );
   label_application_name->setFont ( font );
   label_application_catchphrase = new QLabel ( shared_components->text ()->operator[] ( Core::KeyTxtApplicationCatchPhrase ) );
   font = label_application_catchphrase->font ();
   font.setItalic ( true );
   label_application_catchphrase->setFont ( font );
   layout_text->addWidget ( label_application_name );
   layout_text->addWidget ( label_application_catchphrase );
   layout_text->addStretch ();
   
   // Prepare the button layout
   
   layout_button = new QVBoxLayout ();
   layout_main->addLayout ( layout_button );
   
   // Prepare the button
   
   button_config = new QPushButton ( shared_components->text ()->operator[] ( Core::KeyTxtMainPanelConfigProgram ) );
   layout_button->addStretch ();
   layout_button->addWidget ( button_config );
   layout_button->addStretch ();
   connect ( button_config , SIGNAL ( clicked () ) , this , SIGNAL ( displayConfig () ) );
}

