QT += gui
QT += widgets
QT += opengl        #23.1
QT += openglwidgets #23.1

LIBS += -lopengl32  #23.1 Без этого не робит

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        oglpyramid.cpp \
        oglquad.cpp \
        qgldraw.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    oglpyramid.h \
    oglquad.h \
    qgldraw.h
