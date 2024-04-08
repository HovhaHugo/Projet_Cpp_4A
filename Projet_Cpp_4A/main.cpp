#include "login.h"
#include "mainregister.h"

#include "usermanager.h"
#include "globals.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
//#include <iostream>

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

    string PathToJson = "/Users/hugohovhannessian/Hugo/Etude_Sup/Polytech/DI4/S8/PlatLog_Cpp/test2.json";

    UserManager *userMana = new UserManager();
    userMana->parseFile(PathToJson);      //on récupère les données du json et on les met dans une variable globale
    vector<User> vectorTest = userMana->getListeUsers();
    bool haveAdmin = userMana->JsonHaveAdmin(PathToJson);

    if(haveAdmin == 0){     //Si on ne trouve pas d'admin on en crée un
        MainRegister r;
        r.setUsers(vectorTest);
        r.show();
        return a.exec();
    }else{                  //Si on trouve un admin on va directement sur le login
        login w;
        w.setUsers(vectorTest);
        w.show();
        return a.exec();
    }
}
