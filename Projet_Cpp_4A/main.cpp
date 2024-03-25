#include "mainwindow.h"
#include "mainregister.h"

#include "jsonparser.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Projet_Platlog_Cpp_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    JsonParser j = JsonParser();
    j.JsonGetUser();

    bool haveAdmin = j.JsonGetAdmin();
    cout << haveAdmin;

    if(haveAdmin == 1){
        MainRegister r;
        r.show();
    }else{
        MainWindow w;
        w.show();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
