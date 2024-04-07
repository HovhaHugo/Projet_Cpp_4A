#ifndef BDDDIALOG_H
#define BDDDIALOG_H

#include <QDialog>
#include "QStandardItemModel"

using namespace std;

namespace Ui {
class BDDDialog;
}

class BDDDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::BDDDialog *ui;

    string pathBDD;

private slots:
    void AffichageSQL();

    void on_listeTables_clicked();
    void on_SQLcommandButton_clicked();

public:
    BDDDialog(QWidget *parent = nullptr);
    ~BDDDialog();

    void setPath(string pathBDDSelected);
};


#endif // BDDDIALOG_H
