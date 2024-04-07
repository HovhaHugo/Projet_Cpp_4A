#include "sqlitewindow.h"
#include "qtableview.h"
#include "ui_sqlitewindow.h"

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QStringListModel>
#include <QMessageBox>


SQLiteWindow::SQLiteWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SQLiteWindow)
{
    ui->setupUi(this);

    AffichageSQL();
}

SQLiteWindow::~SQLiteWindow()
{
    delete ui;
}

/**
 * @brief SQLiteWindow::AffichageSQL
 * Ouvre la base de données et affiche les différentes tables dans la QListView
 */
void SQLiteWindow::AffichageSQL(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/benja/OneDrive/Bureau/test/test.SQLite");
    if (!db.open()) {
        QMessageBox::warning(this,"BDD","Erreur: Impossible d'ouvrir la base de données");
        return;
    }

    QSqlQuery query;
    query.exec("SELECT name FROM sqlite_master WHERE type='table'");
    QStringList tableNames;
    while (query.next()) {
        QString tableName = query.value(0).toString();
        tableNames.append(tableName);
    }

    QStringListModel *model = new QStringListModel(tableNames);
    ui->listeTables->setModel(model);
}

/**
 * @brief SQLiteWindow::on_listeTables_clicked
 * Affiche dans la QTableViewle contenu de la table sélectionnée dans la QListView
 */
void SQLiteWindow::on_listeTables_clicked(){
    QModelIndex selectedIndex = ui->listeTables->currentIndex();
    QString selectedTable = selectedIndex.data().toString();

    QSqlQueryModel *model = new QSqlQueryModel;
    QString query = "SELECT * FROM " + selectedTable;
    model->setQuery(query);
    ui->tableView->setModel(model);
}
