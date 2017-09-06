#include "ZegoUserConfig.h"
#include <random>
#include <QSharedPointer>


QZegoUserConfig::QZegoUserConfig()
{
	//生成ini文件,用于在本地保存用户配置信息
	m_strIniPath = QStringLiteral("Config/ZegoUserConfig.ini");

}

QZegoUserConfig::~QZegoUserConfig()
{

}

void QZegoUserConfig::LoadConfig(void)
{
	if (LoadConfigInternal())
	{
		return;
	}

	//随机生成编号为10000000-99999999的用户ID
	std::random_device rd;
	std::uniform_int_distribution<int> dist(10000000, 99999999);
	//int to QString
	m_strUserId = QString::number(dist(rd), 10);
	m_strUserName = QStringLiteral("windows-") + m_strUserId;


	if (m_pVideoSettings == nullptr)
	{
		m_pVideoSettings = QSharedPointer<QZegoSettingsModel>::create();
	}


	SaveConfig();
}

bool QZegoUserConfig::LoadConfigInternal(void)
{
	QSettings *configIni = new QSettings(m_strIniPath, QSettings::IniFormat);
	if (configIni == nullptr)
	{
		return false;
	}

	QString strUserId = configIni->value("/sUserRecords/kUserId").toString();
	QString strUserName = configIni->value("/sUserRecords/kUserName").toString();

	if (strUserId.isEmpty() || strUserName.isEmpty())
	{
		return false;
	}


	m_strUserId = strUserId;
	m_strUserName = strUserName;

	//读ini文件完毕后释放指针
	delete configIni;

	if (m_pVideoSettings == nullptr)
	{
		m_pVideoSettings = QSharedPointer<QZegoSettingsModel>::create();
	}
	
	return true;
}
void QZegoUserConfig::SaveConfig()
{
	QSettings *configIni = new QSettings(m_strIniPath, QSettings::IniFormat);
	if (m_strUserId.isEmpty() || m_strUserName.isEmpty() || m_pVideoSettings == nullptr)
	{
		return;
	}

	configIni->setValue("/sUserRecords/kUserId", m_strUserId);
	configIni->setValue("/sUserRecords/kUserName", m_strUserName);

	delete configIni;
}

QString QZegoUserConfig::GetUserId(void)
{
	return m_strUserId;
}



void QZegoUserConfig::SetUserId(QString strUserId)
{
	if (!strUserId.isEmpty())
	{
		m_strUserId = strUserId;
	}
}

QString QZegoUserConfig::GetUserName(void)
{
	return m_strUserName;
}

void QZegoUserConfig::SetUserName(QString strUserName)
{
	if (!strUserName.isEmpty())
	{
		m_strUserName = strUserName;
	}
}


SettingsPtr QZegoUserConfig::GetAudioSettings(void)
{
	return m_pVideoSettings;
}

void QZegoUserConfig::SetAudioSettings(SettingsPtr curSettings)
{
	
	m_pVideoSettings->SetMicrophoneId(curSettings->GetMircophoneId());

}

