/**********************************************************************

	--- Qt Architect generated file ---

	File: StringListSelectOneDialogData.cpp
	Last generated: Fri Sep 25 15:16:29 1998

	DO NOT EDIT!!!  This file will be automatically
	regenerated by qtarch.  All changes will be lost.

 *********************************************************************/

#include "StringListSelectOneDialogData.h"

#define Inherited QDialog


StringListSelectOneDialogData::StringListSelectOneDialogData
(
	QWidget* parent,
	const char* name
)
	:
	Inherited( parent, name, TRUE, 0 )
{
	frameBase = new QFrame( this, "Frame_2" );
	frameBase->setGeometry( 5, 5, 210, 110 );
	frameBase->setMinimumSize( 10, 10 );
	frameBase->setMaximumSize( 32767, 32767 );
	frameBase->setFrameStyle( 34 );

	buttonOK = new QPushButton( this, "PushButton_1" );
	buttonOK->setGeometry( 10, 80, 100, 30 );
	buttonOK->setMinimumSize( 10, 10 );
	buttonOK->setMaximumSize( 32767, 32767 );
	connect( buttonOK, SIGNAL(pressed()), SLOT(accept()) );
	buttonOK->setText( "" );
	buttonOK->setAutoRepeat( FALSE );
	buttonOK->setAutoResize( FALSE );

	buttonCancel = new QPushButton( this, "PushButton_2" );
	buttonCancel->setGeometry( 110, 80, 100, 30 );
	buttonCancel->setMinimumSize( 10, 10 );
	buttonCancel->setMaximumSize( 32767, 32767 );
	connect( buttonCancel, SIGNAL(pressed()), SLOT(reject()) );
	buttonCancel->setText( "" );
	buttonCancel->setAutoRepeat( FALSE );
	buttonCancel->setAutoResize( FALSE );

	frameInner = new QFrame( this, "Frame_3" );
	frameInner->setGeometry( 10, 10, 200, 65 );
	frameInner->setMinimumSize( 10, 10 );
	frameInner->setMaximumSize( 32767, 32767 );
	frameInner->setFrameStyle( 50 );

	comboStrings = new QComboBox( FALSE, this, "ComboBox_1" );
	comboStrings->setGeometry( 15, 40, 190, 30 );
	comboStrings->setMinimumSize( 10, 10 );
	comboStrings->setMaximumSize( 32767, 32767 );
	comboStrings->setSizeLimit( 10 );
	comboStrings->setAutoResize( FALSE );

	labelHeadline = new QLabel( this, "Label_1" );
	labelHeadline->setGeometry( 15, 15, 190, 20 );
	labelHeadline->setMinimumSize( 10, 10 );
	labelHeadline->setMaximumSize( 32767, 32767 );
	labelHeadline->setText( "Select one of the strings:" );
	labelHeadline->setAlignment( 268 );
	labelHeadline->setMargin( -1 );

	resize( 220,120 );
	setMinimumSize( 0, 0 );
	setMaximumSize( 32767, 32767 );
}


StringListSelectOneDialogData::~StringListSelectOneDialogData()
{
}
