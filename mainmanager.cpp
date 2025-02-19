#include "mainmanager.h"

#include <QGridLayout>
#include <QPushButton>
#include <QSplitter>

#include "herolistwidget.h"

MainManagerWindow::MainManagerWindow(DataStorage* storage, QWidget* parent)
    : QWidget{parent}
    , mStorage(storage)
{
    // setFixedSize(900, 600);
    generateLayouts();
}

void MainManagerWindow::generateLayouts()
{
    int          rowCategory = 0;
    QGridLayout* grid        = new QGridLayout();

    QPushButton* heroesBtn = new QPushButton("Heroes");
    // heroesBtn->setFixedSize(100, 25);
    heroesBtn->setStyleSheet(styleButtonCategory);

    QPushButton* heroesItemsBtn = new QPushButton("Heroes items");
    //    heroesItemsBtn->setFixedSize(100, 25);
    heroesItemsBtn->setStyleSheet(styleButtonCategory);

    // настройки колонок и рядов
    grid->setColumnStretch(0, 1);
    grid->setColumnStretch(1, 1);
    grid->setColumnStretch(2, 1);

    grid->addWidget(heroesBtn, rowCategory, 0);
    grid->addWidget(heroesItemsBtn, ++rowCategory, 0);

    HeroListWidget* heroListW
        = new HeroListWidget(mStorage->getHeroNames(), this);
    grid->addWidget(heroListW, 0, 1, 4, 4);

    this->setLayout(grid);
}
