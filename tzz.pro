TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        filenode.cpp \
        globalstorage.cpp \
        main.cpp

LIBS += -lstdc++fs

HEADERS += \
    filenode.h \
    globalstorage.h
