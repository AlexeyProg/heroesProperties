#ifndef MAINMANAGER_H
#define MAINMANAGER_H

#include <QWidget>

#include "datastorage.h"

class QPushButton;

class MainManagerWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainManagerWindow(DataStorage* storage, QWidget* parent = nullptr);

    void generateLayouts();

private:
    QString styleButtonCategory
        = "QPushButton {"
          "   background-color: #4CAF50; /* Цвет фона */"
          "   border: 2px solid #45a049; /* Граница */"
          "   border-radius: 15px; /* Радиус скругления углов */"
          "   padding: 10px; /* Отступ внутри кнопки */"
          "   color: white; /* Цвет текста */"
          "}"
          "QPushButton:hover {"
          "   background-color: #45a049; /* Цвет фона при наведении */"
          "}"
          "QPushButton:pressed {"
          "   background-color: #3d8b40; /* Цвет фона при нажатии */"
          "}";

private:
    QList<QPushButton*> categoryButtons;
    DataStorage*        mStorage = nullptr;
signals:
};

#endif // MAINMANAGER_H
