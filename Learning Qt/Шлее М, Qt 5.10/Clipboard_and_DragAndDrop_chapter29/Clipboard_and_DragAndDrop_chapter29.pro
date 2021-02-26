QT -= gui
QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        drag.cpp \
        drop.cpp \
        main.cpp \
        mydragclass.cpp \
        widget.cpp \
        widgetdrag.cpp \
        widgetmimedata.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    drag.h \
    drop.h \
    mydragclass.h \
    widget.h \
    widgetdrag.h \
    widgetmimedata.h

RESOURCES += \
    Images.qrc
