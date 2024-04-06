#include "login.h"
#include "mainregister.h"

#include "usermanager.h"

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

    string PathToJson = "C:/Users/benja/OneDrive/Bureau/test/test.json";

    UserManager UM = UserManager();
    UM.parseFile(PathToJson);
    bool haveAdmin = UM.JsonHaveAdmin(PathToJson);


    cout << haveAdmin;

    /*if(haveAdmin == 1){
        MainRegister r;
        r.show();
    }else{
        login w;
        w.show();
    }*/

    login w;
    w.show();
    return a.exec();
}
