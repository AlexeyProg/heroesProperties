#ifndef HEROLISTWIDGET_H
#define HEROLISTWIDGET_H

#include <QWidget>

class QPushButton;
class QGridLayout;

class HeroListWidget : public QWidget {
    Q_OBJECT
public:
    explicit HeroListWidget(QStringList heroes, QWidget* parent = nullptr);

public:
    void generateWidget();

private:
    QStringList                 mHeroesList;
    QMap<QString, QPushButton*> heroesBtns;
    QGridLayout*                grid = nullptr;

signals:
};

#endif // HEROLISTWIDGET_H
