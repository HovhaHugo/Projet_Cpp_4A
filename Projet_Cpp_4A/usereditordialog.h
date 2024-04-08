#ifndef USEREDITORDIALOG_H
#define USEREDITORDIALOG_H

#include <QDialog>
#include "QStandardItemModel"
#include "user.h"

namespace Ui {
class UserEditorDialog;
}

class UserEditorDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::UserEditorDialog *ui;
    QStandardItemModel *modele;

private slots:
    void affichageProfilsUser();

    void on_tableView_clicked();
    void on_AddUserButton_clicked();
    void on_EditUserButton_clicked();
    void on_DeleteUserButton_clicked();


public:
    explicit UserEditorDialog(QWidget *parent = nullptr);
    ~UserEditorDialog();
};

#endif // USEREDITORDIALOG_H

//AddUserButton
