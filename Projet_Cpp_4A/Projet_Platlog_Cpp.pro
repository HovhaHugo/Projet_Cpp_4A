QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bdd.cpp \
    jsonparser.cpp\
    database.cpp \
    login.cpp \
    main.cpp \
    mainregister.cpp \
    mainwindow.cpp \
    profil.cpp \
    user.cpp \
    usermanager.cpp

HEADERS += \
    bdd.h \
    json.hpp \
    jsonparser.h \
    database.h \
    login.h \
    mainregister.h \
    mainwindow.h \
    profil.h \
    user.h \
    usermanager.h

FORMS += \
    database.ui \
    login.ui \
    mainregister.ui \
    mainwindow.ui \
    profil.ui \
    user.ui

TRANSLATIONS += \
    Projet_Platlog_Cpp_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
