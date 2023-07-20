#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define DATABASE_HOSTNAME   "DataBase_MB"
#define DATABASE_NAME       "DataBase.db"

#define DEVICE                  "DeviceTable"
#define DEVICE_TASK             "Task"
#define DEVICE_SCOPE_OF_APP     "Scope of application"
#define DEVICE_DEADLINE         "Deadline"


class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);

    void connectToDataBase();
    bool inserIntoDeviceTable(const QVariantList &data);

private:
    QSqlDatabase db;

private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createDeviceTable();
};

#endif // DATABASE_H
