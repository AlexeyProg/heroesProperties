#include "datastorage.h"

#include <iostream>
#include <utility>

DataStorage::DataStorage(QObject* parent)
    : QObject{parent}
{
}

QMap<QString, int> DataStorage::getHeroesXid()
{
    return heroesXid;
}

void DataStorage::setHeroesXid(QMap<QString, int>& map)
{
    heroesXid = std::move(map);
}

void DataStorage::getHeroItemsIndexes(const QString& heroName)
{
}
