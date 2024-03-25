#include "mainwindow.h"
#include "usermanager.h"
#include "login.h"

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

    //UserManager u = UserManager();
    //u.parseFile("/Users/hugohovhannessian/Hugo/Etude_Sup/Polytech/DI4/S8/PlatLog_Cpp/Projet_Cpp_4A/listUser.txt");
    //User user = u.searchAdmin();
    //User user = NULL;
    MainWindow w;
    w.show();
    return a.exec();
}
