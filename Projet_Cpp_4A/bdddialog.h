#ifndef BDDDIALOG_H
#define BDDDIALOG_H

#include <QDialog>
#include "QStandardItemModel"

namespace Ui {
class BDDDialog;
}

class BDDDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::BDDDialog *ui;

private slots:
    void AffichageSQL();
    void on_listeTables_clicked();
    void on_SQLcommandButton_clicked();

public:
    BDDDialog(QWidget *parent = nullptr);
    ~BDDDialog();
};


#endif // BDDDIALOG_H
