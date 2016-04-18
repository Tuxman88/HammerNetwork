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

# include "languagepanel.h"

Gui::LanguagePanel::LanguagePanel ( Core::SharedComponents* new_shared_components )
   : QGroupBox ()
{
   shared_components = new_shared_components;
   
   layout_main = new QGridLayout ( this );
   this->setLayout ( layout_main );
   
   label_language = new QLabel ();
   combo_languages = new QComboBox ();
   
   layout_main->addWidget ( label_language , 0 , 0 );
   layout_main->addWidget ( combo_languages , 0 , 1 );
   
   combo_languages->addItem ( QString ( "English" ) );
   combo_languages->addItem ( QString::fromUtf8 ( "Spanish" ) );
   
   updateText ();
   updateValues ();
   
   connect ( shared_components->config () , SIGNAL ( updateValues () ) , this , SLOT ( updateValues () ) );
   connect ( shared_components->text () , SIGNAL ( updateText () ) , this , SLOT ( updateText () ) );
}

void Gui::LanguagePanel::saveValues ( void )
{
   shared_components->config ()->set ( Core::KeyGuiLang , combo_languages->currentText ().toLower () );
   
   return;
}

void Gui::LanguagePanel::updateText ( void )
{
   label_language->setText ( shared_components->text ()->operator[] ( Core::KeyTxtConfigWindowInterfaceLanguage ).toLower () );
   
   return;
}

void Gui::LanguagePanel::updateValues ( void )
{
   combo_languages->setCurrentIndex ( languageIndex ( shared_components->config ()->operator[] ( Core::KeyGuiLang ) ) );
   
   return;
}

int Gui::LanguagePanel::languageIndex ( const QString& language )
{
   if ( language == QString ( "english" ) )
      return ( 0 );
   
   return ( 1 );
}
