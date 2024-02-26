#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "usermanager.h"
#include "iostream"

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
    /*UserManager UserList = UserManager();
    UserList.parseFile("C:/Github/Projet_Cpp_4A/Projet_Cpp_4A/listuser.txt");
    vector<Users> vecteur = UserList.getListeUsers();
    for (Users u : vecteur) {
        std::cout << u.getNom() << " " << u.getPrenom();
    }*/
    login.setModal(true);
    login.exec();
}
