#include "requestgetter.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QNetworkReply>

RequestGetter::RequestGetter(DataStorage* storage, QObject* parent)
    : QObject{parent}
    , mStorage(storage)
{
    manager = new QNetworkAccessManager(this);

    connect(manager,
            SIGNAL(finished(QNetworkReply*)),
            this,
            SLOT(showReply(QNetworkReply*)));

    // сразу запросим список героев
    getRequest(RequestType::Heroes);
}

bool RequestGetter::getRequest(RequestType type)
{
    QString response;
    mType = type;
    switch (type) {
        case RequestType::HeroId: {
            response = "HeroId";
            break;
        }
        case RequestType::ItemBuild: {
            response = "ItemBuild";
            break;
        }
        case RequestType::ItemId: {
            response = "ItemId";
            break;
        }
        case RequestType::Heroes: {
            response = url + "heroes";
            break;
        }
        default:
            response = "Invalid request";
            break;
    }
    QUrl            curUrl(response);
    QNetworkRequest req(curUrl);
    // qDebug() << " response str : " << response;
    manager->get(QNetworkRequest(req));

    return true;
}

const QString RequestGetter::getResponseStr()
{
    return resultStr;
}

RequestGetter::Status RequestGetter::getStatus() const
{
    return status;
}

void RequestGetter::setStatus(Status newStatus)
{
    status = newStatus;
}

void RequestGetter::showReply(QNetworkReply* r)
{
    setStatus(Status::RUNNING);
    QByteArray    response     = r->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response);

    if (jsonResponse.isArray()) {
        QJsonArray jsonArray = jsonResponse.array();
        if (mType == RequestType::Heroes) {
            QMap<QString, int> mp;
            QStringList        heroesNames;
            for (const QJsonValue& it: jsonArray) {
                QJsonObject jsonObj  = it.toObject();
                QString     heroName = jsonObj["localized_name"].toString();
                int         heroId   = jsonObj["id"].toInt();
                mp.insert(heroName, heroId);
                heroesNames.push_back(heroName);
            }
            // вывод полученного массива
            // for (auto i = mp.begin(); i != mp.end(); i++) {
            //     qDebug() << i.key() << " : " << i.value();
            // }
            mStorage->setHeroesXid(mp);
            mStorage->setHeroesNames(heroesNames);
        }

        r->deleteLater(); // Освобождаем ресурсы

        setStatus(Status::SUCCESS);
        emit requestComplete();
    }
}
