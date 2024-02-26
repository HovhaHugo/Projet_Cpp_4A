#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "user.h"

login::login(QWidget *parent): QDialog(parent), ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_ButtonValider_clicked()
{
    /*User test = new User();
    test.setAdmin(1);
    test.setLogin("Oui");
    test.setMdp("test1234");
    test.setNom("Do");
    test.setPrenom("John");*/
    QString idLine = ui->idLine->text();
    QString mdpLine = ui->mdpLine->text();
    if (idLine == "John" && mdpLine == "test1234"){
        QMessageBox::information(this,"Login","Tout est bon");
        hide();
        User user = new User(nullptr);
        user.setModal(true);
        user.exec();
    }else{
        QMessageBox::warning(this,"Login","Le login n'est pas bon !");
    }
}

