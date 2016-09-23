TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    engine.cpp \
    netacceptor.cpp \
    netconnector.cpp \
    table.cpp \
    player.cpp \
    chair.cpp \
    gamelogicloader.cpp \
    buffer.cpp \
    pool.cpp \
    dboperator.cpp \
    itable.cpp \
    igamelogic.cpp

HEADERS += \
    engine.h \
    netacceptor.h \
    netconnector.h \
    table.h \
    player.h \
    chair.h \
    gamelogicloader.h \
    buffer.h \
    pool.h \
    dboperator.h \
    playerdata.h \
    itable.h \
    common.h \
    platform.h \
    nmdefs.h \
    igamelogic.h
