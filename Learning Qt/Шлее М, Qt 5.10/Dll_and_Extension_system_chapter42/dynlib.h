#pragma once

#include <QString>

#ifdef Q_OS_WIN
    #define MY_EXPORT __declspec(dllexport)

#else
    #define MY_EXPORT
#endif

extern "C" MY_EXPORT

    QString oddUpper(const QString& str);


