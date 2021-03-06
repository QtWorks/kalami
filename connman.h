#ifndef CONNMAN_H
#define CONNMAN_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtCore/QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(ConnmanLog)

class ConnmanPrivate;

class Connman : public QObject
{
    Q_OBJECT
public:
    explicit Connman(QObject *parent = 0);
    void start();
    void updateKnownWifis(QJsonArray &list);

signals:
    void availableWifisUpdated(const QJsonArray &list);
    void connectedWifiChanged(const QJsonObject &wifi);
    void goneOnline();

private slots:
    void iterateServices();
    void connectToKnownWifi();
    void agentPassphraseRequested();
    void sendConnectedService();

private:
    ConnmanPrivate *d_ptr;
    Q_DECLARE_PRIVATE(Connman);
};

#endif // CONNMAN_H
