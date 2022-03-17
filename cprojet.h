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

    private:
        Ui::CProjet *ui;
};

#endif // CPROJET_H
