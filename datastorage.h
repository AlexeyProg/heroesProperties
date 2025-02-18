#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <QMap>
#include <QObject>

// Класс, хранящий основные данные с запросов по api

class DataStorage : public QObject {
    Q_OBJECT
public:
    explicit DataStorage(QObject* parent = nullptr);

public:
private:
    // мап 'hero : heroId'
    QMap<QString, int> heroesXid;
};

#endif // DATASTORAGE_H
