#ifndef CMYSQL_H
#define CMYSQL_H

#include <QtSql>

class CMysql {
    private:
        QSqlDatabase m_DB;
        QSqlQuery *m_Query;

    public:
        CMysql() {}
        ~CMysql() {}

        void Connect(QString Host, QString Database, QString User, QString Password) {
            this->m_DB = QSqlDatabase::addDatabase("QMYSQL");
            this->m_DB.setHostName(Host);
            this->m_DB.setDatabaseName(Database);
            this->m_DB.setUserName(User);
            this->m_DB.setPassword(Password);
            if(this->m_DB.open()) {
                this->m_Query = new QSqlQuery(this->m_DB);
            }
        }

        void Disconnect() {
            delete this->m_Query;
            this->m_DB.close();
        }

        bool Exec(QString Req) {
            return (this->m_Query->exec(Req));
        }

        bool Next() {
            return (this->m_Query->next());
        }

        QString ValueString(int Index) {
            return (this->m_Query->value(Index).toString());
        }

        int ValueInt(int Index) {
            return (this->m_Query->value(Index).toInt());
        }
};

#endif // CMYSQL_H
