#include "mainwindow.h"

#include "datastorage.h"
#include "mainmanager.h"
#include "requestgetter.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    DataStorage*       storage = new DataStorage(this);

    RequestGetter*     rGetter = new RequestGetter(storage, this);

    bool               res1 = rGetter->getRequest(RequestGetter::Heroes);

    QMap<QString, int> mapHeroes = storage->getHeroesXid();

    // проверка успел ли request выполниться
    connect(rGetter, &RequestGetter::requestComplete, this, [=]() {
        auto a = storage->getHeroesXid();
        for (auto i = a.begin(); i != a.end(); i++) {
            qDebug() << i.key() << " : " << i.value();
        }
    });
    //

    MainManagerWindow* mainW = new MainManagerWindow(this);

    setCentralWidget(mainW);
}

MainWindow::~MainWindow()
{
}
