TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
	ArrayQueue.cpp \
	PrecondViolatedExcep.cpp



HEADERS += \
	ArrayQueue.h \
	PrecondViolatedExcep.h \
	QueueInterface.h

