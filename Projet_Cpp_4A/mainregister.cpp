#include "mainregister.h"
#include "ui_mainregister.h"
#include "login.h"

MainRegister::MainRegister(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainRegister)
{
    ui->setupUi(this);
}

MainRegister::~MainRegister()
{
    delete ui;
}


//vérification du login et connexion
void MainRegister::on_ButtonValider_clicked()
{
    login login;
    login.setModal(true);
    login.exec();
}
