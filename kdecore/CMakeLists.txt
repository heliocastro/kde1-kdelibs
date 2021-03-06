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

set(KDECORE_SRCS
        kconfig.cpp
        kconfigbase.cpp
        ksimpleconfig.cpp
        kcolorgroup.cpp
        kapp.cpp
        kurl.cpp
        ksock.cpp
        drag.cpp
        kprocess.cpp
        kprocctrl.cpp
        klocale.cpp
        libintl.cpp
        fakes.cpp
        kiconloader.cpp
        kdebug.cpp
        kstdaccel.cpp
        kwm.cpp
        krootprop.cpp
        kcharsets.cpp
        kcharsetsdata.cpp
        kchartables.cpp
        kstring.cpp
        kpixmap.cpp
        dither.cpp
        kckey.cpp
        kaccel.cpp
        kglobalaccel.cpp
        kclipboard.cpp
        krect.cpp
        ksize.cpp
        kpoint.cpp
    )

set(KDECORE_HDRS
    drag.h
    kapp.h
    kclipboard.h
    kconfig.h
    kconfigbase.h
    kdebugdialog.h
    kglobalaccel.h
    kiconloader.h
    kprocctrl.h
    kprocess.h
    ksimpleconfig.h
    ksock.h
   )

qt1_wrap_cpp(KDECORE_SRCS
    SOURCES ${KDECORE_HDRS}
    )

add_library(kdecore SHARED ${KDECORE_SRCS})

add_library(kde1::kdecore ALIAS kdecore)

set_target_properties(kdecore PROPERTIES
    VERSION 2.0.0
    SOVERSION 2
    LINK_FLAGS "-Wl,--as-needed -Wl,--no-undefined"
    )

target_link_libraries(kdecore
    PRIVATE
        Qt::Qt1
        ${X11_LIBRARIES}
    )

target_include_directories(kdecore
    PUBLIC
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/kde1>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/common>
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

install(TARGETS kdecore EXPORT Kde1Targets
    LIBRARY DESTINATION ${KDE1_LIBRARIES}
    )

install(FILES charsets.config DESTINATION ${KDE1_CONFDIR} RENAME "charsets")

install(FILES kdebug.areas DESTINATION "${KDE1_CONFDIR}")

install(FILES
	kconfig.h kconfigdata.h ksimpleconfig.h kconfigbase.h
    kcolorgroup.h kapp.h kcharsets.h
    kurl.h ksock.h drag.h  ckey.h kmisc.h
    kprocess.h kprocctrl.h klocale.h kiconloader.h kdebug.h
    kstdaccel.h kwm.h krootprop.h kstring.h kpixmap.h dither.h
    kaccel.h kglobalaccel.h kckey.h kclipboard.h krect.h ksize.h
    kpoint.h
	DESTINATION ${KDE1_INCLUDES})
