QT -= gui
QT += widgets
QT += concurrent #38.11-38.12

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        myprogressbar.cpp \
        mythread.cpp \
        mythread2.cpp \
        myworker.cpp \
        progressevent.cpp \
        shell.cpp \
        threadsafestringstack.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    myprogressbar.h \
    mythread.h \
    mythread2.h \
    myworker.h \
    progressevent.h \
    shell.h \
    threadsafestringstack.h
