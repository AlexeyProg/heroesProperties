#ifndef REQUESTGETTER_H
#define REQUESTGETTER_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QObject>
#include <QUrl>

#include "datastorage.h"

class RequestGetter : public QObject {
    Q_OBJECT

public:
    enum Status {
        SUCCESS,
        RUNNING
    };
    Q_ENUM(Status)

    enum RequestType {
        HeroId,
        ItemId,
        ItemBuild,
        Heroes
    };
    Q_ENUM(RequestType)

public:
    explicit RequestGetter(DataStorage* storage, QObject* parent = nullptr);

public:
    bool          getRequest(RequestType type);

    const QString getResponseStr();

    Status        getStatus() const;
    void          setStatus(Status newStatus);
    ~RequestGetter() = default;

private:
    bool sendRequest();

private:
    Status                 status;

    const QString          url = "https://api.opendota.com/api/";
    QString                resultStr;

    QNetworkAccessManager* manager = nullptr;

    RequestType            mType;
    DataStorage*           mStorage = nullptr;

public slots:
    void showReply(QNetworkReply* r);

signals:
    void requestComplete();
};

#endif // REQUESTGETTER_H
