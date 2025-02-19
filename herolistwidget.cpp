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
    int rowBtn = 0;
    int colBtn = 0;
    grid       = new QGridLayout(this);
    for (auto& it: mHeroesList) {
        QPushButton* btn = new QPushButton(it);

        connect(btn, &QPushButton::clicked, this, [=]() {
            emit btnHeroPressed(it);
        });

        grid->addWidget(btn, rowBtn, colBtn++);
        if (colBtn % 6 == 0) {
            rowBtn++;
            colBtn = 0;
        }
        heroesBtns.insert(it, btn);
    }
}
