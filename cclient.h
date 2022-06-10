#ifndef CCLIENT_H
#define CCLIENT_H

#include <QMainWindow>
#include <QVector>

#include "cprestation.h"
#include "cpensionnaire.h"

class CClient {
    private:
        QString m_Name;
        QString m_Mail;
        QVector<CPrestation> m_Prestation;
        QVector<CPensionnaire> m_Pensionnaire;

    public:
        CClient() {}
        ~CClient() {}

        CClient(QString Name, QString Mail) {
            this->m_Name = Name;
            this->m_Mail = Mail;
        }

        QString GetName() {
            return(this->m_Name);
        }

        QString GetMail() {
            return(this->m_Mail);
        }

        void SetName(QString Name) {
            this->m_Name = Name;
        }

        void SetMail(QString Mail) {
            this->m_Mail = Mail;
        }

        void AjouterPrestation(CPrestation Prestation) {
            this->m_Prestation.append(Prestation);
        }

        void AjouterPensionnaire(CPensionnaire Pensionnaire) {
            this->m_Pensionnaire.append(Pensionnaire);
        }

        void SupprimerPresation(int Index) {
            this->m_Prestation.removeAt(Index);
        }

        void SupprimerPensionnaire(int Index) {
            this->m_Pensionnaire.removeAt(Index);
        }

        void ModifierPrestation(int Index) {
            this->m_Prestation[Index];
        }

        void ModifierPensionnaire(int Index) {
            this->m_Pensionnaire[Index];
        }

        CPrestation GetPrestation(int Index) {
            return (this->m_Prestation[Index]);
        }

        CPensionnaire GetPensionnaire(int Index) {
            return (this->m_Pensionnaire[Index]);
        }

        int GetPrestationSize() {
            return (this->m_Prestation.size());
        }

        int GetPensionnaireSize() {
            return (this->m_Pensionnaire.size());
        }
};

#endif // CCLIENT_H
