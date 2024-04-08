QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bdd.cpp \
    bdddialog.cpp \
    globals.cpp \
    login.cpp \
    main.cpp \
    mainregister.cpp \
    profil.cpp \
    profildialog.cpp \
    user.cpp \
    userdialog.cpp \
    usereditordialog.cpp \
    usermanager.cpp

HEADERS += \
    bdd.h \
    bdddialog.h \
    globals.h \
    json.hpp \
    login.h \
    mainregister.h \
    profil.h \
    profildialog.h \
    user.h \
    userdialog.h \
    usereditordialog.h \
    usermanager.h

FORMS += \
    bdddialog.ui \
    login.ui \
    mainregister.ui \
    profildialog.ui \
    userdialog.ui \
    usereditordialog.ui

TRANSLATIONS += \
    Projet_Platlog_Cpp_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
