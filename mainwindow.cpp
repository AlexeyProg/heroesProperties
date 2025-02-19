#include "mainwindow.h"

#include <QElapsedTimer>
#include <QThread>

#include "datastorage.h"
#include "mainmanager.h"
#include "requestgetter.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    storage = new DataStorage(this);

    rGetter = new RequestGetter(storage, this);

    // заранее нужно получить список heroes в requestGetter , а потом создать по
    // ним mainwmanagerWindow, но при этом в mainmanagerWindow должен быть
    // requestGetter. тут парадокс

    // bool           res1 = rGetter->getRequest(RequestGetter::Heroes);

    // проверка успел ли request выполниться
    // connect(rGetter, &RequestGetter::requestComplete, this, [=]() {
    //     // auto a = storage->getHeroesXid();
    //     // for (auto i = a.begin(); i != a.end(); i++) {
    //     //     qDebug() << i.key() << " : " << i.value();
    //     // }
    //     if (rGetter->getStatus() == RequestGetter::RUNNING) {
    //         QThread::msleep(2000);
    //     }
    //     MainManagerWindow* mainW = new MainManagerWindow(storage, this);

    //     setCentralWidget(mainW);
    // });
    //
}

MainWindow::~MainWindow()
{
}

// TODO : доделать delaystep
bool MainWindow::createDelay(int msec)
{
    QElapsedTimer timer;
    timer.start();

    while (true) {
        int delta = msec - timer.elapsed();
        if (delta <= 5) {
            return true;
        }

        if (delta > 200) {
            QThread::msleep(50);
        }
        else {
            while (!timer.hasExpired(msec)) {
            }
            return true;
        }
        qDebug() << "delta : " << delta;
    }
    return true;
}
