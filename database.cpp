#include "database.h"


QString path_db = "C:/Users/daniilscaletta/Documents/Projects_Qt/Manage_Business/";

Database::Database(QObject *parent) : QObject(parent)
{

}

void Database::connectToDataBase()
{
    if(!QFile(path_db + DATABASE_NAME).exists())
    {
        this->restoreDataBase();
    }
    else
    {
        this->openDataBase();
    }
}

bool Database::restoreDataBase()
{
    if(this->openDataBase())
    {
        if(!this->createDeviceTable())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        qDebug() << "Не удалось восстановить базу данных" << endl;
        return false;
    }
}

bool Database::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    if(db.open())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Database::closeDataBase()
{
    db.close();
}

bool Database::createDeviceTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " DEVICE " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            DEVICE_TASK              " VARCHAR(255)    NOT NULL,"
                            DEVICE_SCOPE_OF_APP      " VARCHAR(16)     NOT NULL,"
                            DEVICE_DEADLINE          " VARCHAR(18)     NOT NULL"
                        " )"
                  ))
    {
        qDebug() << "Database: error of create" << DEVICE;
        qDebug() << query.lastError().text();
        return false;
    }
    else
    {
        return true;
    }
}

bool Database::inserIntoDeviceTable(const QVariantList &data)
{
    QSqlQuery query;

    query.prepare("INSERT INTO " DEVICE " ( "
            DEVICE_TASK ", "
            DEVICE_SCOPE_OF_APP ", "
            DEVICE_DEADLINE " ) "
            "VALUES (:Task, :scope_of_app, :deadline)");

    query.bindValue(":Task",          data[0].toString());
    query.bindValue(":Scope of App",  data[1].toString());
    query.bindValue(":DeadLine",      data[2].toString()); // преобразовать в дату

    if(!query.exec()){
            qDebug() << "Error insert into " << DEVICE;
            qDebug() << query.lastError().text();
            return false;
        } else {
            return true;
        }
}





