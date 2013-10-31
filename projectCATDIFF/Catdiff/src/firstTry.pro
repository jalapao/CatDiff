#-------------------------------------------------
#
# Project created by QtCreator 2012-06-21T20:14:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = firstTry
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    algoStructure.cpp \
    dialogmerge.cpp \
    filters.cpp \
    FolderDiff.cpp \
    dialoghelp.cpp \
    dialogabout.cpp \
    dialogsimilarity.cpp

HEADERS  += mainwindow.h \
    algoStructure.h \
    dialogmerge.h \
    filters.h \
    FolderDiff.h \
    numberPair.h \
    dialoghelp.h \
    dialogabout.h \
    dialogsimilarity.h

FORMS    += mainwindow.ui \
    dialogmerge.ui \
    dialoghelp.ui \
    dialogabout.ui \
    dialogsimilarity.ui

OTHER_FILES += \
    blackboard-0.png
