#include "login.h"
#include "ui_login.h"
#include "user.h"

login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    /*User user;
    user.setModal(true);
    user.exec();*/
    user = new User(this);
    user->show();
}

