#include "cprojet.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CProjet w;
    w.show();

    return a.exec();
}
