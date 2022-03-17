#ifndef CPROJET_H
#define CPROJET_H

#include <QMainWindow>

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
