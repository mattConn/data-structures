TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
        LinkedList.cpp \
        ch09-linkedList-driver(2).cpp \
        Node(2).cpp \
        PrecondViolatedExcep(2).cpp

HEADERS += \
        LinkedList.h \
        addressItem.h \
        ch09-linkedList-driver(2).cpp \
        ListInterface(2).h \
        Node(2).h \
        PrecondViolatedExcep(3).h
