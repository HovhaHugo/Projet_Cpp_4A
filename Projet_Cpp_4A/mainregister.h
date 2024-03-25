#ifndef MAINREGISTER_H
#define MAINREGISTER_H

#include <QMainWindow>

namespace Ui {
class MainRegister;
}

class MainRegister : public QMainWindow
{
    Q_OBJECT

public:
    MainRegister(QWidget *parent = nullptr);
    ~MainRegister();

private slots:
    void on_ButtonValider_clicked();

private:
    Ui::MainRegister *ui;
};

#endif // MAINREGISTER_H
