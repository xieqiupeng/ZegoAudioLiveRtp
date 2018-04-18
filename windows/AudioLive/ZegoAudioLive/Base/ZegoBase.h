#pragma once

#include <QObject>
#include <QVector>
#include "Signal/ZegoSDKSignal.h"
#include "AudioRoom.h"
#include "AudioRoomDefines.h"
#include "AudioRoomDefines-IM.h"
#include "AudioRoom-Publisher.h"
#include "AudioRoom-Player.h"
#include "RoomDefines.h"
#include "AVDefines.h"
#include "AudioRoom-Volume.h"
#include "Settings/ZegoSettingsModel.h"

//demo版本的枚举类型
typedef enum _Version
{
	ZEGO_PROTOCOL_UDP = 0,
	ZEGO_PROTOCOL_UDP_INTERNATIONAL = 1,
	ZEGO_PROTOCOL_CUSTOM = 2
}Version;

class QZegoBase
{
public :
	QZegoBase();
	~QZegoBase();

	bool InitAVSDK(SettingsPtr pSetting, QString userID, QString userName);
	void UninitAVSDK(void);
	bool IsAVSdkInited(void);
	void setKey(int pKey);
	int getKey();
	void setIsTestEnv(bool isTest);

	QZegoSDKSignal* GetAVSignal(void);
	unsigned long GetAppID(void);
	unsigned char* GetAppSign();
private :
	typedef enum _INIT_MASK {
		INIT_NONE = 0,
		INIT_AVSDK = 1,
		INIT_CRSDK = 2,
		INIT_ALL = INIT_AVSDK | INIT_CRSDK,
	}INIT_MASK;

	unsigned long m_dwInitedMask;
	QString m_strLogPathUTF8;

	QZegoSDKSignal* m_pAVSignal;

	//默认不使用测试环境
	bool isTestEnv = false;

	//appid、appsign默认为UDP版本
	int key = Version::ZEGO_PROTOCOL_UDP;

	QVector <unsigned int> appIDs;
	QVector <unsigned char *> appSigns;


};