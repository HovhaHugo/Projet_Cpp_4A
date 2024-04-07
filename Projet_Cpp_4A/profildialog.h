#ifndef PROFILDIALOG_H
#define PROFILDIALOG_H

#include <QDialog>
#include "QStandardItemModel"
#include "bdd.h"

namespace Ui {
class ProfilDialog;
}

class ProfilDialog :public QDialog
{
    Q_OBJECT

private:
    Ui::ProfilDialog *ui;
    QStandardItemModel *modele;

private slots:
    void affichageBDDProfil();

    void on_ShowSQLiteButton_clicked();

public:
    ProfilDialog();
    ProfilDialog(QWidget *parent = nullptr);
    ~ProfilDialog();

    void setProfil(string login, string label);
};

#endif // PROFILDIALOG_H
