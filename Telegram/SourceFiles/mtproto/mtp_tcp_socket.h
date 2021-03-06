/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "mtproto/mtp_abstract_socket.h"

namespace MTP {
namespace internal {

class TcpSocket final : public AbstractSocket {
public:
	TcpSocket(not_null<QThread*> thread, const QNetworkProxy &proxy);

	void connectToHost(const QString &address, int port) override;
	void timedOut() override;
	bool isConnected() override;
	bool hasBytesAvailable() override;
	int64 read(bytes::span buffer) override;
	void write(bytes::const_span prefix, bytes::const_span buffer) override;

	int32 debugState() override;

	static void LogError(int errorCode, const QString &errorText);

private:
	void handleError(int errorCode);

	QTcpSocket _socket;

};

} // namespace internal
} // namespace MTP
