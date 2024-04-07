#include "bdddialog.h"
#include "qtableview.h"
#include "ui_bdddialog.h"

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QStringListModel>
#include <QMessageBox>

using namespace std;


BDDDialog::BDDDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BDDDialog)
{
    ui->setupUi(this);

    AffichageSQL();
}

BDDDialog::~BDDDialog()
{
    delete ui;
}

/**
 * @brief BDDDialog::AffichageSQL
 * Ouvre la base de données et affiche les différentes tables dans la QListView
 */
void BDDDialog::AffichageSQL(){
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
 * @brief BDDDialog::on_listeTables_clicked
 * Affiche dans la QTableViewle contenu de la table sélectionnée dans la QListView
 */
void BDDDialog::on_listeTables_clicked(){
    QModelIndex selectedIndex = ui->listeTables->currentIndex();
    QString selectedTable = selectedIndex.data().toString();

    QSqlQueryModel *model = new QSqlQueryModel;
    QString query = "SELECT * FROM " + selectedTable;
    model->setQuery(query);
    ui->tableView->setModel(model);
}

void BDDDialog::on_SQLcommandButton_clicked(){
    QString SQLrequest = ui->SQLcommandLineEdit->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(SQLrequest);
    ui->SQLresultTableView->setModel(model);
}
