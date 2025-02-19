#include "herolistwidget.h"

#include <QGridLayout>
#include <QPushButton>

HeroListWidget::HeroListWidget(QStringList heroes, QWidget* parent)
    : QWidget{parent}
    , mHeroesList(heroes)
{
    generateWidget();
}

void HeroListWidget::generateWidget()
{
    int          rowBtn = 0;
    int          colBtn = 0;
    QGridLayout* grid   = new QGridLayout(this);
    for (auto& it: mHeroesList) {
        QPushButton* btn = new QPushButton(it);

        grid->addWidget(btn, rowBtn, colBtn++);
        if (colBtn % 6 == 0) {
            rowBtn++;
            colBtn = 0;
        }
    }
}
