#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//vérification du login et connexion
void MainWindow::on_ButtonValider_clicked()
{
    login login;
    login.setModal(true);
    login.exec();
}
