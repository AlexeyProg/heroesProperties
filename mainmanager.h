#ifndef MAINMANAGER_H
#define MAINMANAGER_H

#include <QWidget>

class QPushButton;

class MainManagerWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainManagerWindow(QWidget* parent = nullptr);

    void generateLayouts();

private:
    QList<QPushButton*> categoryButtons;
signals:
};

#endif // MAINMANAGER_H
