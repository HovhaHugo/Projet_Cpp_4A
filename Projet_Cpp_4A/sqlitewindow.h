#ifndef SQLITEWINDOW_H
#define SQLITEWINDOW_H

#include <QDialog>
#include "QStandardItemModel"

namespace Ui {
class SQLiteWindow;
}

class SQLiteWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::SQLiteWindow *ui;

private slots:
    void AffichageSQL();
    void on_listeTables_clicked();
    void on_SQLcommandButton_clicked();

public:
    SQLiteWindow(QWidget *parent = nullptr);
    ~SQLiteWindow();
};


#endif // SQLITEWINDOW_H
