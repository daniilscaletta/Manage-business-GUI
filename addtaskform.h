#ifndef ADDTASKFORM_H
#define ADDTASKFORM_H

#include <QDialog>
#include <QDate>
namespace Ui {
class AddTaskForm;
}

class AddTaskForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddTaskForm(QWidget *parent = 0);
    ~AddTaskForm();

    QString description() const;
    QString scppe() const;
    QDate date() const;

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::AddTaskForm *ui;
};

#endif // ADDTASKFORM_H
