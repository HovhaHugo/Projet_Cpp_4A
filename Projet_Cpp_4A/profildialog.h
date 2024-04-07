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

    string loginUser;
    string loginProfil;

private slots:
    void affichageBDDProfil();

    void on_tableView_clicked();
    void on_ShowSQLiteButton_clicked();

    void on_pushButton_clicked();

public:
    ProfilDialog();
    ProfilDialog(QWidget *parent = nullptr);
    ~ProfilDialog();

    void setProfil(string loginUserSelect, string loginProfilSelect);
};

#endif // PROFILDIALOG_H
