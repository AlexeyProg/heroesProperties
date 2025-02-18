#include "mainwindow.h"

#include "requestgetter.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    RequestGetter* rGetter = new RequestGetter(this);

    bool           res1 = rGetter->getRequest(RequestGetter::Heroes);
    // qDebug() << "Request str : " << rGetter->getResponseStr();
}

MainWindow::~MainWindow()
{
}
