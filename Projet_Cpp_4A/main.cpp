#include "login.h"
#include "mainregister.h"

#include "usermanager.h"
#include "globals.h"

#include <QCoreApplication>
#include <QFileInfo>

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
/*
    //Permet d'avoir le chemin relatif à la racine du projet (FAIS PLANTER LE PROGRAMME)
    QCoreApplication app(argc, argv);
    QString executablePath = QCoreApplication::applicationFilePath();
    QFileInfo executableInfo(executablePath);
    QString projectRootPath = executableInfo.absolutePath();

    string PathToJson = projectRootPath.toStdString() + "/test.json";
*/
    //string PathToJson = "/Users/hugohovhannessian/Hugo/Etude_Sup/Polytech/DI4/S8/PlatLog_Cpp/test2.json";
    string PathToJson = "C:/Users/benja/OneDrive/Bureau/test/test.json";

    globalUserManager.parseFile(PathToJson);      //on récupère les données du json et on les met dans une variable globale
    vector<User> vectorTest = globalUserManager.getListeUsers();
    bool haveAdmin = globalUserManager.JsonHaveAdmin(PathToJson);

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
