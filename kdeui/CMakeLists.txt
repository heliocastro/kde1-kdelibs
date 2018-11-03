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

set(KDEUI_SRCS
        kledlamp.cpp kprogress.cpp kpanner.cpp kcolordlg.cpp
		kselect.cpp kdatepik.cpp kdatetbl.cpp
		kfontdialog.cpp kmsgbox.cpp kpopmenu.cpp ktabctl.cpp
		ktreelist.cpp kstatusbar.cpp ktopwidget.cpp ktmainwindow.cpp
		kmenubar.cpp ktoolbar.cpp kbutton.cpp kslider.cpp
		kseparator.cpp klined.cpp kcombo.cpp krestrictedline.cpp
		kintegerline.cpp kspinbox.cpp kcontrol.cpp
		kcolorbtn.cpp kiconloaderdialog.cpp kwmmapp.cpp
		kbuttonbox.cpp ktablistbox.cpp knewpanner.cpp
		keditcl1.cpp keditcl2.cpp ktoolboxmgr.cpp kled.cpp
		kdbtn.cpp knotebook.cpp ktabbar.cpp kwizard.cpp kcontainer.cpp
		kkeydialog.cpp kurllabel.cpp kruler.cpp kquickhelp.cpp kcursor.cpp)

set(KDEUI_HDRS
    kbutton.h kbuttonbox.h kcolorbtn.h
	kcolordlg.h kcombo.h kcontainer.h kcontrol.h kdatepik.h
	kdatetbl.h kdbtn.h keditcl.h kfontdialog.h
	kiconloaderdialog.h kintegerline.h kkeydialog.h kled.h
	kledlamp.h klined.h kmenubar.h kmsgbox.h knewpanner.h
	knotebook.h kpanner.h kpopmenu.h kprogress.h
	kquickhelp.h krestrictedline.h kruler.h kselect.h
	kslider.h kspinbox.h kstatusbar.h ktabbar.h ktabctl.h
	ktablistbox.h ktmainwindow.h ktoolbar.h ktoolboxmgr.h
	ktopwidget.h ktreelist.h kurllabel.h kwizard.h kwmmapp.h)

qt1_wrap_cpp(KDEUI_SRCS
	SOURCES
		${KDEUI_HDRS}
		)

add_library(kdeui SHARED ${KDEUI_SRCS})

add_library(kde1::kdeui ALIAS kdeui)

set_target_properties(kdeui PROPERTIES VERSION 2.0.0 SOVERSION 2)

target_link_libraries(kdeui
	PUBLIC
		Qt::Qt1
		kde1::kdecore
		${X11_LIBRARIES}
	)

target_include_directories(kdeui
    PUBLIC
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/kde1>
	INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

install(TARGETS kdeui LIBRARY DESTINATION ${KDE1_LIBRARIES})

install(FILES
        kledlamp.h kprogress.h kpanner.h kcolordlg.h kselect.h
		kdatepik.h kdatetbl.h
		kfontdialog.h kmsgbox.h kpopmenu.h ktabctl.h
		ktreelist.h kstatusbar.h ktopwidget.h ktmainwindow.h
		ktoolbar.h kmenubar.h kbutton.h kslider.h kseparator.h
		klined.h kcombo.h krestrictedline.h kintegerline.h
		kspinbox.h kcolorbtn.h kiconloaderdialog.h
		kwmmapp.h kbuttonbox.h ktablistbox.h kcontainer.h
		knewpanner.h kcontrol.h keditcl.h ktoolboxmgr.h kled.h
		kdbtn.h knotebook.h ktabbar.h kwizard.h kkeydialog.h
		kurllabel.h kruler.h kquickhelp.h kcursor.h
        DESTINATION ${KDE1_INCLUDES})

install(FILES
    error.xpm exclamation.xpm info.xpm stopsign.xpm question.xpm
    arrow_up.xbm arrow_down.xbm arrow_left.xbm arrow_right.xbm
    DESTINATION ${KDE1_DATADIR}/kde/pics)
