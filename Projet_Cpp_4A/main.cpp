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
    //cout << "Admin bool: " << haveAdmin << endl;

    if(haveAdmin == 0){     //Si on ne trouve pas d'admin on en crée un
        MainRegister r;
        r.show();
        return a.exec();
    }else{                  //Si on trouve un admin on va directement sur le login
        login w;
        w.show();
        return a.exec();
    }
}
