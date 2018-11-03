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

set(KFILE_SRCS
    kfilebookmark.cpp kfiledialogconf.cpp kcombiview.cpp
	kdir.cpp kfileinfo.cpp kremotefile.cpp kdirlistbox.cpp
	kfiledetaillist.cpp kfiledialog.cpp booktoken.cpp
	kfileinfocontents.cpp kfilesimpleview.cpp kpreview.cpp
	kfilepreview.cpp xview.cpp kfilefilter.cpp
    )

set(KFILE_HDRS
    kcombiview.h kdir.h kdirlistbox.h
	kfilebookmark.h kfiledetaillist.h kfiledialog.h
	kfiledialogconf.h kfilefilter.h kfileinfocontents.h
	kfilepreview.h kfilesimpleview.h kpreview.h
    )

qt1_wrap_cpp(KFILE_SRCS
    SOURCES
        ${KFILE_HDRS}
    )

add_library(kfile SHARED ${KFILE_SRCS})

add_library(kde1::kfile ALIAS kfile)

set_target_properties(kfile PROPERTIES VERSION 2.0.0 SOVERSION 2)

target_link_libraries(kfile
    PUBLIC
        Qt::Qt1
        kde1::kdecore
        kde1::kdeui
        kde1::kfm
        ${X11_LIBRARIES}
    )

target_include_directories(kdecore
    PUBLIC
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/kde1>
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

install(TARGETS kfile LIBRARY DESTINATION ${KDE1_LIBRARIES})

install(FILES kfiledialog.h kfileinfo.h kfilebookmark.h
	kremotefile.h kdir.h kdirlistbox.h kfileinfocontents.h
	booktoken.h kfiledetaillist.h kcombiview.h kpreview.h kfilepreview.h
    xview.h kfilesimpleview.h kfilefilter.h
    DESTINATION ${KDE1_INCLUDES})

install(FILES configure.xpm DESTINATION ${KDE1_TOOLBARDIR})

