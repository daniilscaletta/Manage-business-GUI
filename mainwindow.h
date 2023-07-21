#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_New_Task_Button_triggered();

private:
    Ui::MainWindow  *ui;
    Database        *db;
    QSqlTableModel  *model;

private:
    void createUI(const QStringList& headers); // change "headers"
    // setup Mpdel
};

#endif // MAINWINDOW_H
