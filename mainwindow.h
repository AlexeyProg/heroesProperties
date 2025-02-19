#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class DataStorage;
class RequestGetter;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    bool createDelay(int msec);

private:
    RequestGetter* rGetter = nullptr;
    DataStorage*   storage = nullptr;
};
#endif // MAINWINDOW_H
