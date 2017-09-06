#pragma once

#include <QObject>
#include "AVDefines.h"
#include "AudioRoom.h"

using namespace ZEGO;

class QZegoSettingsModel
{
public:
	QZegoSettingsModel();

	QString GetMircophoneId(void);
	void SetMicrophoneId(const QString& microphoneId);

	void InitDeviceId(void);

private:

	QString m_strMicrophoneId;
};

using SettingsPtr = QSharedPointer< QZegoSettingsModel >;