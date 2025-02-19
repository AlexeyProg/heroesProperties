#ifndef HEROLISTWIDGET_H
#define HEROLISTWIDGET_H

#include <QWidget>

class HeroListWidget : public QWidget {
    Q_OBJECT
public:
    explicit HeroListWidget(QStringList heroes, QWidget* parent = nullptr);

public:
    void generateWidget();

private:
    QStringList mHeroesList;

signals:
};

#endif // HEROLISTWIDGET_H
