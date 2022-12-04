#include "QTWidgetsApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTWidgetsApp w;
    w.show();
    return a.exec();
}
