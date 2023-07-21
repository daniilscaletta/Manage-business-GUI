#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtaskform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->setExpanding(true);

    db = new Database();
    db->connectToDataBase();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_New_Task_Button_triggered()
{
    AddTaskForm task_window;
    task_window.setModal(true);
    task_window.exec();

}
