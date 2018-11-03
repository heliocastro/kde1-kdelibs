#=============================================================================
# Copyright 2018       Helio Chissini de Castro <helio@kde.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

set(KAB_SRCS
	kabapi.cc
	AssertDialog.cpp
	AssertDialogData.cpp
	DialogBase.cpp
	DialogBaseData.cpp
	PrintDialog.cpp
	PrintDialogData.cpp
	SearchDialog.cpp
	StringListEditWidget.cpp
	StringListEditWidgetData.cpp
	StringListEditDialog.cpp
	addressbook.cc
	businesscard.cc
	datepickerdialog.cc
	editentry.cc
	searchresults.cc
	widget.cc
	configDB.cc
	sections.cc
	keyvaluemap.cc
	functions.cc
	StringListSelectOneDialog.cpp
	StringListSelectOneDialogData.cpp
	StringListSelectSetDialog.cpp
	StringListSelectAndReorderSet.cpp
	StringListSelectAndReorderSetData.cpp
	widgets.cc
	SearchDialogMainWidget.cpp
	SearchDialogMainWidgetData.cpp
    )

set(KAB_HDRS
    AssertDialog.h AssertDialogData.h DialogBase.h
	DialogBaseData.h PrintDialog.h PrintDialogData.h
	SearchDialog.h SearchDialogMainWidget.h
	SearchDialogMainWidgetData.h StringListEditDialog.h
	StringListEditWidget.h StringListEditWidgetData.h
	StringListSelectAndReorderSet.h
	StringListSelectAndReorderSetData.h
	StringListSelectOneDialog.h
	StringListSelectOneDialogData.h
	StringListSelectSetDialog.h
	businesscard.h datepickerdialog.h editentry.h
	kab.h kabapi.h searchresults.h
    )

qt1_wrap_cpp(KAB_SRCS
	SOURCES
		${KAB_HDRS}
		)

add_library(kab SHARED ${KAB_SRCS} ${MOC_FILES})

add_library(kde1::kab ALIAS kab)

set_target_properties(kab PROPERTIES VERSION 2.0.0 SOVERSION 2)

target_link_libraries(kab
	PUBLIC
		Qt::Qt1
		kde1::kdecore
		kde1::kdeui
		kde1::kfm
		kde1::kfile
		${X11_LIBRARIES}
	)

install(TARGETS kab LIBRARY DESTINATION ${KDE1_LIBRARIES})

install(FILES
	stl_headers.h
	kabapi.h
	kab.h
	addressbook.h
	configDB.h
	keyvaluemap.h
	sections.h
    DESTINATION ${KDE1_INCLUDES})

install(FILES dialog_background.jpg background_1.jpg DESTINATION ${KDE1_DATADIR}/kab/pics)

