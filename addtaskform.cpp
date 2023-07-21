#include "addtaskform.h"
#include "ui_addtaskform.h"

AddTaskForm::AddTaskForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTaskForm)
{
    ui->setupUi(this);
    ui->plainTextEdit_descript->setPlaceholderText("Enter the text...");
    ui->lineEdit_scope_of_app->setPlaceholderText("Enter the scope of app...");
    ui->lineEdit_deadline->setPlaceholderText("{dd-mm-yyyy}");


}

AddTaskForm::~AddTaskForm()
{
    delete ui;
}

void AddTaskForm::on_pushButton_add_clicked()
{

}

void AddTaskForm::on_pushButton_cancel_clicked()
{
    this->close();
}
