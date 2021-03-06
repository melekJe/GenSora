#ifndef SERVER_H
#define SERVER_H
#include <QtNetwork>
#include <iostream>
#include "database.h"
#include "../common/message.h"
#include "../common/user.h"

class Server: public QObject {
	Q_OBJECT

public:
	Server();


private slots:
	void newConnectionSlot();
	void receivedData();
	void disconnectedClient();
	
private:
	QTcpServer *server;
	QList<QTcpSocket *> clients;
	QMap<QString, QTcpSocket *> authClients;
	quint16 mSize;
	
	void sendMsg(const QString &, QTcpSocket *);
	void traitMsg(const QString &, QTcpSocket *);
};
#endif
