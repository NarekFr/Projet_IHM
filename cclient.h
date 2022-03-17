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

        void AjouterPrestation() {}
        void AjouterPensionnaire() {}

        void SupprimerPresation() {}
        void SupprimerPensionnaire() {}

        void ModifierPrestation() {}
        void ModifierPensionnaire() {}
};

#endif // CCLIENT_H
