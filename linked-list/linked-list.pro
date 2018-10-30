TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    LinkedList.cpp \
    main.cpp \
    Node.cpp \
    PrecondViolatedExcep.cpp


HEADERS += \
    addressItem.h \
    LinkedList.h \
    ListInterface.h \
    Node.h \
    PrecondViolatedExcep.h
