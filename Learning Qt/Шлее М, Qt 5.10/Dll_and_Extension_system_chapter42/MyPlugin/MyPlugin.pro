QT -= gui

TEMPLATE = lib
DEFINES += MYPLUGIN_LIBRARY

CONFIG += plugin
mac{
DESTDIR = ../MyApplication.app/Contents/plugins
}
else
{
DESTDIR = ../plugins
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    myplugin.cpp

HEADERS += \
    myplugin.h

TARGET = myplugin

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
