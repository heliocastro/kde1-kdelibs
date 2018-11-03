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

set(KHTMLW_SRCS
    jscript.cpp html.cpp htmlobj.cpp htmlfont.cpp htmlform.cpp htmltoken.cpp
    htmlframe.cpp htmlview.cpp htmlclue.cpp debug.cpp htmldata.cpp htmltable.cpp
    htmliter.cpp htmlchain.cpp
    )

set(KHTMLW_HDRS
    html.h htmlform.h htmlframe.h
	htmlobj.h htmlview.h
    )

qt1_wrap_cpp(KHTMLW_SRCS
    SOURCES
        ${KHTMLW_HDRS})

add_library(khtmlw SHARED ${KHTMLW_SRCS})

add_library(kde1::khtmlw ALIAS khtmlw)

set_target_properties(khtmlw PROPERTIES VERSION 2.0.0 SOVERSION 2)

target_link_libraries(khtmlw
    PUBLIC
        Qt::Qt1
        kde1::kdecore
        kde1::kdeui
        kde1::jscript
        kde1::kimgio
        ${X11_LIBRARIES}
    )

install(TARGETS khtmlw LIBRARY DESTINATION ${KDE1_LIBRARIES})

install(FILES jscript.h html.h htmlobj.h htmlfont.h htmlform.h
    htmltoken.h htmlframe.h htmlview.h htmlclue.h htmldata.h
    htmltable.h htmliter.h
    DESTINATION ${KDE1_INCLUDES})

install(FILES khtmlw_dnd.xpm DESTINATION ${KDE1_DATADIR}/khtmlw/pics )
