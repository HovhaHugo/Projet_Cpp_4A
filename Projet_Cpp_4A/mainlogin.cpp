#include "mainlogin.h"
#include <QMessageBox>

void MainLogin::on_ButtonValider_clicked()
{
    //On créer 2 utilisateurs pour tester si l'application fonctionne.
    User test1 = User("Test", "Do", "John", "test1234", 1);
    User test2 = User("Test2", "Smith", "James", "test", 1);

    //On récupére les lignes de saisie pour le mots de passe et l'identifiant
    QString idLine = "ui->idLine->text()";
    QString mdpLine = "ui->mdpLine->text()";

    //On verifie que le mdp et le login soit correct
    if (idLine.toStdString() == test1.getLogin() && mdpLine.toStdString() == test1.getMdp()){
        //QMessageBox::information(this,"Login","Tout est bon");
        hide();
        User user = new User(nullptr);
        user.setUser(test1.getLogin(), test1.getNom(), test1.getPrenom());
        user.setModal(true);
        user.exec();
    }else{
        if (idLine.toStdString() == test2.getLogin() && mdpLine.toStdString() == test2.getMdp()){
            //QMessageBox::information(this,"Login","Tout est bon");
            hide();
            User user = new User(nullptr);
            user.setUser(test2.getLogin(), test2.getNom(), test2.getPrenom());
            user.setModal(true);
            user.exec();
        }else{
            QMessageBox::warning(this,"Login","Le login n'est pas bon !");
        }
    }
}


