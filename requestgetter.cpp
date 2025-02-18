#include "requestgetter.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QNetworkReply>

RequestGetter::RequestGetter(QObject* parent)
    : QObject{parent}
{
    manager = new QNetworkAccessManager(this);

    connect(manager,
            SIGNAL(finished(QNetworkReply*)),
            this,
            SLOT(showReply(QNetworkReply*)));
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
            break;
    }
    QUrl            curUrl(response);
    QNetworkRequest req(curUrl);
    qDebug() << " response str : " << response;
    manager->get(QNetworkRequest(req));

    return true;
}

const QString RequestGetter::getResponseStr()
{
    return resultStr;
}

void RequestGetter::showReply(QNetworkReply* r)
{
    qDebug() << "at build time " << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << QSslSocket::supportsSsl();
    qDebug() << "sslLibraryVersionString : "
             << QSslSocket::sslLibraryVersionString();
    qDebug() << "SHOW REPLY WORKS";

    QByteArray    response     = r->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response);

    qDebug() << " JsonRepsonse null ? :  " << jsonResponse.isNull();

    if (jsonResponse.isArray()) {
        QJsonArray jsonArray = jsonResponse.array();
        if (mType == RequestType::Heroes) {
            QMap<QString, int> mp;
            for (const QJsonValue& it: jsonArray) {
                QJsonObject jsonObj  = it.toObject();
                QString     heroName = jsonObj["localized_name"].toString();
                int         heroId   = jsonObj["id"].toInt();
                mp.insert(heroName, heroId);
            }
            for (auto& it: mp) {
                qDebug() << it;
            }
        }
    }
}
