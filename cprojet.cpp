#include "cprojet.h"
#include "ui_cprojet.h"

CProjet::CProjet(QWidget *parent) : QMainWindow(parent), ui(new Ui::CProjet) {
    ui->setupUi(this);

    CMysql Database;

    Database.Connect("localhost", "elevage", "root", "");

    if(Database.Exec("SELECT * FROM client")) {
        while (Database.Next()) {

        }
    }

    if(Database.Exec("SELECT * FROM prestation")) {
        while (Database.Next()) {

        }
    }
}

CProjet::~CProjet() {
    delete ui;
}
