#-------------------------------------------------
#
# Project created by QtCreator 2014-08-05T22:45:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = finalprojcs3a
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    token_definition.cpp \
    parser.cpp \
    mixedNumber.cpp \
    fraction.cpp \
    util_calc_funcs.cpp

HEADERS  += mainwindow.h \
    token_definition.h \
    parser.h \
    mixedNumber.h \
    fraction.h \
    util_calc_funcs.h

FORMS    += mainwindow.ui
