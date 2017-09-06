#pragma once

#include "ZegoSettingsModel.h"
#include <QSharedPointer>
#include <QFile>
#include <QSettings>

class QZegoUserConfig
{
public:
	QZegoUserConfig();
	~QZegoUserConfig();

	void LoadConfig(void);
	void SaveConfig(void);

	QString GetUserId(void);
	void SetUserId(const QString strUserId);
	
	QString GetUserName(void);
	void SetUserName(const QString strUserName);

	SettingsPtr GetAudioSettings(void);
	void SetAudioSettings(SettingsPtr curSettings);

private:
	bool LoadConfigInternal(void);

private:
	QString m_strIniPath;

	QString m_strUserId;
	QString m_strUserName;

	SettingsPtr m_pVideoSettings;
};