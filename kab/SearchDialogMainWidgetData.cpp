/**********************************************************************

	--- Qt Architect generated file ---

	File: SearchDialogMainWidgetData.cpp
	Last generated: Sat Oct 10 20:32:25 1998

	DO NOT EDIT!!!  This file will be automatically
	regenerated by qtarch.  All changes will be lost.

 *********************************************************************/

#include "SearchDialogMainWidgetData.h"

#define Inherited QWidget

#include <qlayout.h>

SearchDialogMainWidgetData::SearchDialogMainWidgetData
(
	QWidget* parent,
	const char* name
)
	:
	Inherited( parent, name, 0 )
{
	comboSelector = new QComboBox( FALSE, this, "ComboBoxSelector" );
	comboSelector->setGeometry( 0, 0, 250, 33 );
	comboSelector->setMinimumSize( 10, 10 );
	comboSelector->setMaximumSize( 32767, 32767 );
	comboSelector->setSizeLimit( 10 );
	comboSelector->setAutoResize( FALSE );

	labelMatches = new QLabel( this, "LabelMatches" );
	labelMatches->setGeometry( 0, 33, 250, 23 );
	labelMatches->setMinimumSize( 10, 10 );
	labelMatches->setMaximumSize( 32767, 32767 );
	labelMatches->setText( "matches" );
	labelMatches->setAlignment( 292 );
	labelMatches->setMargin( -1 );

	lePattern = new QLineEdit( this, "LineEditPattern" );
	lePattern->setGeometry( 0, 56, 250, 24 );
	lePattern->setMinimumSize( 10, 10 );
	lePattern->setMaximumSize( 32767, 32767 );
	lePattern->setText( "*" );
	lePattern->setMaxLength( 32767 );
	lePattern->setEchoMode( QLineEdit::Normal );
	lePattern->setFrame( TRUE );

	QBoxLayout* dlgedit_layout_1 = new QBoxLayout( this, QBoxLayout::TopToBottom, 0, 0, 0L );
	dlgedit_layout_1->addStrut( 0 );
	QBoxLayout* dlgedit_layout_1_1 = new QBoxLayout( QBoxLayout::TopToBottom, 0, 0L );
	dlgedit_layout_1->addLayout( dlgedit_layout_1_1, 1 );
	dlgedit_layout_1_1->addStrut( 0 );
	dlgedit_layout_1_1->addWidget( comboSelector, 5, 36 );
	dlgedit_layout_1_1->addWidget( labelMatches, 3, 36 );
	dlgedit_layout_1_1->addWidget( lePattern, 3, 36 );


	resize( 250,80 );
	setMinimumSize( 0, 0 );
	setMaximumSize( 32767, 32767 );
}


SearchDialogMainWidgetData::~SearchDialogMainWidgetData()
{
}
