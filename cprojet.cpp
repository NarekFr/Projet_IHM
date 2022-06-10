#include "cprojet.h"
#include "ui_cprojet.h"

#include <random>
#include "QDateTime"

int getRand(int min, int max){
    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<> uid(min, max);
    return uid(gen);
}

CProjet::CProjet(QWidget *parent) : QMainWindow(parent), ui(new Ui::CProjet) {
    ui->setupUi(this);

    Database.Connect("localhost", "elevage", "root", "");

    if(Database.Exec("SELECT * FROM client")) {
        while (Database.Next()) {
            Client.append(CClient(Database.ValueString(0), Database.ValueString(1)));
        }
    }

    if(Database.Exec("SELECT * FROM prestation")) {
        while (Database.Next()) {
            for (int i = 0; i < Client.size(); i++) {
                if(Client[i].GetName() == Database.ValueString(3)) {
                    Client[i].AjouterPrestation(CPrestation(Database.ValueInt(0), Database.ValueInt(1), Database.ValueInt(2), Database.ValueString(4)));
                }
            }
        }
    }

    if(Database.Exec("SELECT * FROM animaux")) {
        while (Database.Next()) {
            for (int i = 0; i < Client.size(); i++) {
                if(Client[i].GetName() == Database.ValueString(9)) {
                    Client[i].AjouterPensionnaire(CPensionnaire(Database.ValueInt(0), Database.ValueString(1), Database.ValueString(2), Database.ValueInt(3), Database.ValueInt(4), Database.ValueString(5), Database.ValueString(6), Database.ValueString(7), Database.ValueString(8), Database.ValueInt(10), Database.ValueInt(11)));
                }
            }
        }
    }
}

CProjet::~CProjet() {
    delete ui;
}

void CProjet::on_Client_textChanged(const QString &arg1) {
    ui->Ajouter->setEnabled(false);
    ui->Supprimer->setEnabled(false);
    ui->Prestation->setEnabled(false);
    ui->Pensionnaire->setEnabled(false);

    ui->PrixHT->setEnabled(false);
    ui->TauxTVA->setEnabled(false);
    ui->Calendrier->setEnabled(false);

    ui->AjouterP->setEnabled(false);
    ui->SupprimerP->setEnabled(false);

    ui->AjouterA->setEnabled(false);
    ui->SupprimerA->setEnabled(false);

    ui->Type->setEnabled(false);
    ui->Race->setEnabled(false);
    ui->Nom->setEnabled(false);
    ui->Prix->setEnabled(false);
    ui->Puce->setEnabled(false);
    ui->Portee->setEnabled(false);
    ui->DateDispo->setEnabled(false);
    ui->Vermifuge->setEnabled(false);

    ui->Prestation->clear();
    ui->Pensionnaire->clear();
    ui->PrixHT->clear();
    ui->TauxTVA->clear();
    ui->Calendrier->clear();

    ui->Type->clear();
    ui->Race->clear();
    ui->Nom->clear();
    ui->Prix->clear();
    ui->Puce->clear();
    ui->Portee->clear();
    ui->DateDispo->clear();
    ui->Vermifuge->clear();

    ui->PrixHT->setReadOnly(true);
    ui->TauxTVA->setReadOnly(true);
    ui->Calendrier->setReadOnly(true);

    ui->Type->setReadOnly(true);
    ui->Race->setReadOnly(true);
    ui->Nom->setReadOnly(true);
    ui->Prix->setReadOnly(true);
    ui->Puce->setReadOnly(true);
    ui->Portee->setReadOnly(true);
    ui->DateDispo->setReadOnly(true);
    ui->Vermifuge->setReadOnly(true);

    if(!ui->Client->text().isEmpty()) {
        for (int i = 0; i < Client.size(); i++) {
            if(Client[i].GetName() == ui->Client->text()) {
                ui->Ajouter->setEnabled(false);
                ui->Supprimer->setEnabled(true);

                for (int i = 0; i < Client.size(); i++) {
                    if(Client[i].GetName() == ui->Client->text()) {
                        for (int j = 0; j < Client[i].GetPrestationSize(); j++) {
                            ui->Prestation->addItem(QString::number(Client[i].GetPrestation(j).GetId()));
                        }
                        for (int j = 0; j < Client[i].GetPensionnaireSize(); j++) {
                            ui->Pensionnaire->addItem(QString::number(Client[i].GetPensionnaire(j).GetId()));
                        }
                    }
                }

                if(!ui->Prestation->currentText().isEmpty()) {
                    ui->Prestation->setEnabled(true);
                    ui->PrixHT->setEnabled(true);
                    ui->TauxTVA->setEnabled(true);
                    ui->Calendrier->setEnabled(true);
                    ui->AjouterP->setEnabled(false);
                    ui->SupprimerP->setEnabled(true);
                } else {
                    ui->PrixHT->setEnabled(true);
                    ui->TauxTVA->setEnabled(true);
                    ui->Calendrier->setEnabled(true);
                    ui->PrixHT->setReadOnly(false);
                    ui->TauxTVA->setReadOnly(false);
                    ui->Calendrier->setReadOnly(false);
                    ui->AjouterP->setEnabled(true);
                }

                if(!ui->Pensionnaire->currentText().isEmpty()) {
                    ui->Pensionnaire->setEnabled(true);
                    ui->AjouterA->setEnabled(false);
                    ui->SupprimerA->setEnabled(true);
                    ui->Type->setEnabled(true);
                    ui->Race->setEnabled(true);
                    ui->Nom->setEnabled(true);
                    ui->Prix->setEnabled(true);
                    ui->Puce->setEnabled(true);
                    ui->Portee->setEnabled(true);
                    ui->DateDispo->setEnabled(true);
                    ui->Vermifuge->setEnabled(true);
                } else {
                    ui->AjouterA->setEnabled(true);
                    ui->Type->setReadOnly(false);
                    ui->Race->setReadOnly(false);
                    ui->Nom->setReadOnly(false);
                    ui->Prix->setReadOnly(false);
                    ui->Puce->setReadOnly(false);
                    ui->Portee->setReadOnly(false);
                    ui->DateDispo->setReadOnly(false);
                    ui->Vermifuge->setReadOnly(false);
                    ui->Type->setEnabled(true);
                    ui->Race->setEnabled(true);
                    ui->Nom->setEnabled(true);
                    ui->Prix->setEnabled(true);
                    ui->Puce->setEnabled(true);
                    ui->Portee->setEnabled(true);
                    ui->DateDispo->setEnabled(true);
                    ui->Vermifuge->setEnabled(true);
                }

                break;
            } else {
                ui->Ajouter->setEnabled(true);
                ui->Supprimer->setEnabled(false);
                ui->Prestation->setEnabled(false);
                ui->Pensionnaire->setEnabled(false);
                ui->PrixHT->setEnabled(false);
                ui->TauxTVA->setEnabled(false);
                ui->Calendrier->setEnabled(false);
                ui->AjouterP->setEnabled(false);
                ui->SupprimerP->setEnabled(false);
                ui->AjouterA->setEnabled(false);
                ui->SupprimerA->setEnabled(false);
                ui->Type->setEnabled(false);
                ui->Race->setEnabled(false);
                ui->Nom->setEnabled(false);
                ui->Prix->setEnabled(false);
                ui->Puce->setEnabled(false);
                ui->Portee->setEnabled(false);
                ui->DateDispo->setEnabled(false);
                ui->Vermifuge->setEnabled(false);
            }
        }
    }
}

void CProjet::on_Supprimer_clicked() {
    for (int i = 0; i < Client.size(); i++) {
        if(Client[i].GetName() == ui->Client->text()) {
            Client.removeAt(i);
            Database.Exec("DELETE FROM prestation WHERE Client = '" + ui->Client->text() + "'");
            Database.Exec("DELETE FROM animaux WHERE Proprietaire = '" + ui->Client->text() + "'");
            Database.Exec("DELETE FROM facture WHERE Client = '" + ui->Client->text() + "'");
            Database.Exec("DELETE FROM client WHERE Nom = '" + ui->Client->text() + "'");
            ui->Client->textChanged(ui->Client->text());
            break;
        }
    }
}

void CProjet::on_Ajouter_clicked() {
    Client.append(CClient(ui->Client->text(), "Inconnu"));
    Database.Exec("INSERT INTO client VALUES ('" + ui->Client->text() + "', 'Inconnu')");
    ui->Client->textChanged(ui->Client->text());
}

void CProjet::on_Prestation_currentIndexChanged(int index) {
    for (int i = 0; i < Client.size(); i++) {
       if(Client[i].GetName() == ui->Client->text()) {
           ui->PrixHT->setText(QString::number(Client[i].GetPrestation(index).GetPrix()) + " $");
           ui->TauxTVA->setText(QString::number(Client[i].GetPrestation(index).GetTaux()) + " %");
           ui->Calendrier->setText(Client[i].GetPrestation(index).GetDate());
       }
    }
}

void CProjet::on_AjouterP_clicked() {
    if(!ui->PrixHT->text().isEmpty() && !ui->TauxTVA->text().isEmpty() && !ui->Calendrier->text().isEmpty()){
        for (int i = 0; i < Client.size(); i++) {
            if(Client[i].GetName() == ui->Client->text()) {
                int id = Client[i].GetPrestationSize() + 1;
                Client[i].AjouterPrestation(CPrestation(id, ui->TauxTVA->text().toInt(), ui->PrixHT->text().toDouble(), ui->Calendrier->text()));
                Database.Exec("INSERT INTO prestation (`id`, `TauxTVA`, `Prix`, `Client`, `Date`) VALUES ('" + QString::number(id) + "', '" + ui->TauxTVA->text() + "', '" + ui->PrixHT->text() + "', '" + ui->Client->text() + "', '" + ui->Calendrier->text() + "')");
                ui->Client->setText("");
                ui->Client->setText(Client[i].GetName());
            }
        }
    }
}

void CProjet::on_SupprimerP_clicked() {
    for (int i = 0; i < Client.size(); i++) {
        if(Client[i].GetName() == ui->Client->text()) {
            Database.Exec("DELETE FROM prestation WHERE id = '" + QString::number(Client[i].GetPrestation(ui->Prestation->currentIndex()).GetId()) + "'");
            Client[i].SupprimerPresation(ui->Prestation->currentIndex());
            ui->Client->setText("");
            ui->Client->setText(Client[i].GetName());
        }
    }
}

void CProjet::on_Pensionnaire_currentIndexChanged(int index) {
    for (int i = 0; i < Client.size(); i++) {
       if(Client[i].GetName() == ui->Client->text()) {
           ui->Type->setText(Client[i].GetPensionnaire(index).GetType());
           ui->Race->setText(Client[i].GetPensionnaire(index).GetRace());
           ui->Nom->setText(Client[i].GetPensionnaire(index).GetName());
           ui->Prix->setText(QString::number(Client[i].GetPensionnaire(index).GetPrix()));
           ui->Puce->setText(QString::number(Client[i].GetPensionnaire(index).GetPuce()));
           ui->Portee->setText(QString::number(Client[i].GetPensionnaire(index).GetPortee()));
           ui->DateDispo->setText(Client[i].GetPensionnaire(index).GetDate());
           ui->Vermifuge->setText(Client[i].GetPensionnaire(index).GetVermifuge());
       }
    }
}


void CProjet::on_AjouterA_clicked() {
    if(!ui->Type->text().isEmpty() && !ui->Race->text().isEmpty() && !ui->Nom->text().isEmpty() && !ui->Prix->text().isEmpty() && !ui->Puce->text().isEmpty() && !ui->Portee->text().isEmpty() && !ui->DateDispo->text().isEmpty() && !ui->Vermifuge->text().isEmpty()){
        for (int i = 0; i < Client.size(); i++) {
            if(Client[i].GetName() == ui->Client->text()) {
                Client[i].AjouterPensionnaire(CPensionnaire(5, ui->Type->text(), ui->Race->text(), ui->Portee->text().toInt(), ui->Puce->text().toInt(), ui->Portee->text(), ui->Vermifuge->text(), ui->DateDispo->text(), ui->Nom->text(), 0, ui->Prix->text().toDouble()));
                Database.Exec("INSERT INTO animaux (Type, Race, Portee, Puce, Vermifuge, Date_dispo, Nom, Proprietaire, Prix) VALUES ('" + ui->Type->text() + "', '" + ui->Race->text() + "', '" + ui->Portee->text() + "', '" + ui->Puce->text() + "', '" + ui->Vermifuge->text() + "', '" + ui->DateDispo->text() + "', '" + ui->Nom->text() + "', '" + Client[i].GetName() + "', '" + ui->Prix->text() + "')");
                ui->Client->setText("");
                ui->Client->setText(Client[i].GetName());
            }
        }
    }
}

void CProjet::on_SupprimerA_clicked() {
    for (int i = 0; i < Client.size(); i++) {
        if(Client[i].GetName() == ui->Client->text()) {
            Database.Exec("DELETE FROM animaux WHERE id = '" + QString::number(Client[i].GetPensionnaire(ui->Pensionnaire->currentIndex()).GetId()) + "'");
            Client[i].SupprimerPensionnaire(ui->Pensionnaire->currentIndex());
            ui->Client->setText("");
            ui->Client->setText(Client[i].GetName());
        }
    }
}
