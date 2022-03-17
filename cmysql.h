#ifndef CMYSQL_H
#define CMYSQL_H

#include <QtSql>

class CMysql {
    private:
        QSqlDatabase DB;
        QSqlQuery *Query;

    public:
        CMysql() {}
        ~CMysql() {}

        void Connect(QString Host, QString Database, QString User, QString Password) {
            this->DB = QSqlDatabase::addDatabase("QMYSQL");
            this->DB.setHostName(Host);
            this->DB.setDatabaseName(Database);
            this->DB.setUserName(User);
            this->DB.setPassword(Password);
            this->DB.open();

            this->Query = new QSqlQuery(this->DB);
        }

        void Disconnect() {
            delete this->Query;
            this->DB.close();
        }

};

#endif // CMYSQL_H
