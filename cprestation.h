#ifndef CPRESTATION_H
#define CPRESTATION_H

#include <QMainWindow>

class CPrestation {
    private:
        int m_Id;
        int m_Taux;
        double m_Prix;
        QString m_Date;

    public:
        CPrestation() {}
        ~CPrestation() {}

        CPrestation(int Id, int Taux, double Prix, QString Date) {
            this->m_Id = Id;
            this->m_Taux = Taux;
            this->m_Prix = Prix;
            this->m_Date = Date;
        }

        int GetId() {
            return (this->m_Id);
        }

        int GetTaux() {
            return (this->m_Taux);
        }

        double GetPrix() {
             return (this->m_Prix);
        }

        QString GetDate() {
             return (this->m_Date);
        }

        void SetTaux(int Taux) {
            this->m_Taux = Taux;
        }

        void SetPrix(int Prix) {
            this->m_Prix = Prix;
        }

        void SetDate(QString Date) {
            this->m_Date = Date;
        }
};

#endif // CPRESTATION_H
