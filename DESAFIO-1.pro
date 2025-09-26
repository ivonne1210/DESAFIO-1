QT       -= core gui

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    LZ78_comp.cpp \
    Lectura.cpp \
    main.cpp \
    Busqueda.cpp \
    Encriptado.cpp \
    D_Encriptado.cpp \
    RLE_com.cpp \
    RLE_descom.cpp

HEADERS += \
    Busqueda.h \
    Encriptado.h \
    D_Encriptado.h \
    LZ78_comp.h \
    Lectura.h \
    RLE_com.h \
    RLE_descom.h
