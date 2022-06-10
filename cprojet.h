#ifndef CPROJET_H
#define CPROJET_H

#include <QMainWindow>

#include "cmysql.h"
#include "cclient.h"
#include "cprestation.h"
#include "cpensionnaire.h"

namespace Ui {
    class CProjet;
}

class CProjet : public QMainWindow {
    Q_OBJECT

    public:
        explicit CProjet(QWidget *parent = nullptr);
        ~CProjet();

    private slots:
        void on_Client_textChanged(const QString &arg1);
        void on_Supprimer_clicked();
        void on_Ajouter_clicked();
        void on_Prestation_currentIndexChanged(int index);
        void on_AjouterP_clicked();
        void on_SupprimerP_clicked();
        void on_Pensionnaire_currentIndexChanged(int index);
        void on_AjouterA_clicked();
        void on_SupprimerA_clicked();

    private:
            Ui::CProjet *ui;
            CMysql Database;
            QVector<CClient> Client;
};

#endif // CPROJET_H
