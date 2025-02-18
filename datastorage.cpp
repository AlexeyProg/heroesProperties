#include "datastorage.h"

DataStorage::DataStorage(QObject* parent)
    : QObject{parent}
{
}

QMap<QString, int> DataStorage::getHeroesXid()
{
    return heroesXid;
}

void DataStorage::setHeroesXid(const QMap<QString, int>& map)
{
    heroesXid = map;
    auto it   = 0;
}
