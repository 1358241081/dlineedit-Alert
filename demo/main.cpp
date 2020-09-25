#include "mainwindow.h"
#include <QApplication>
#include <DWidgetUtil>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
