#ifndef REQUESTGETTER_H
#define REQUESTGETTER_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QObject>
#include <QUrl>

class RequestGetter : public QObject {
    Q_OBJECT

public:
    enum RequestType {
        HeroId,
        ItemId,
        ItemBuild,
        Heroes
    };
    Q_ENUM(RequestType)

public:
    explicit RequestGetter(QObject* parent = nullptr);

public:
    bool          getRequest(RequestType type);

    const QString getResponseStr();

private:
    bool sendRequest();

private:
    const QString          url = "https://api.opendota.com/api/";
    QString                resultStr;

    QNetworkAccessManager* manager;

    RequestType            mType;

public slots:
    void showReply(QNetworkReply* r);
};

#endif // REQUESTGETTER_H
