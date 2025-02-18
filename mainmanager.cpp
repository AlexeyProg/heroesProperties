#include "mainmanager.h"

#include <QGridLayout>
#include <QPushButton>

MainManagerWindow::MainManagerWindow(QWidget* parent)
    : QWidget{parent}
{
    setFixedSize(400, 300);
    generateLayouts();
}

void MainManagerWindow::generateLayouts()
{
    int          rowCategory = 0;
    QGridLayout* grid        = new QGridLayout();

    QPushButton* heroesBtn = new QPushButton("Heroes");
    heroesBtn->setFixedSize(100, 25);

    QPushButton* heroesItemsBtn = new QPushButton("Heroes items");
    heroesItemsBtn->setFixedSize(100, 25);

    grid->addWidget(heroesBtn, rowCategory, 0);
    grid->addWidget(heroesItemsBtn, ++rowCategory, 0);

    this->setLayout(grid);
}
