QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bdd.cpp \
    globals.cpp \
    login.cpp \
    main.cpp \
    mainregister.cpp \
    mainwindow.cpp \
    profil.cpp \
    sqlitewindow.cpp \
    user.cpp \
    usermanager.cpp \
    userwindow.cpp

HEADERS += \
    bdd.h \
    globals.h \
    json.hpp \
    login.h \
    mainregister.h \
    mainwindow.h \
    profil.h \
    sqlitewindow.h \
    user.h \
    usermanager.h \
    userwindow.h

FORMS += \
    login.ui \
    mainregister.ui \
    mainwindow.ui \
    profil.ui \
    sqlitewindow.ui \
    userwindow.ui

TRANSLATIONS += \
    Projet_Platlog_Cpp_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
