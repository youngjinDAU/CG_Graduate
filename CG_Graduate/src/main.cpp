#include "CG_Graduate.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CG_Graduate w;
    w.show();
    return a.exec();
}
