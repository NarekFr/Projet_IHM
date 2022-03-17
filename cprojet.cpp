#include "cprojet.h"
#include "ui_cprojet.h"

CProjet::CProjet(QWidget *parent) : QMainWindow(parent), ui(new Ui::CProjet) {
    ui->setupUi(this);
}

CProjet::~CProjet() {
    delete ui;
}
