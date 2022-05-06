#include "QtWidgetsApplication5.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
        qDebug() << driver;
    QtWidgetsApplication5 w;
    w.show();
    return a.exec();
}
