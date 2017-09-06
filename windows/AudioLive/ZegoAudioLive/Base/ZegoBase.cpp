#include <QSharedPointer>
#include "ZegoBase.h"
#include <QDebug>

//#define  ZEGO_PROTOCOL_UDP
//#ifdef ZEGO_PROTOCOL_UDP
static unsigned int g_dwAppID_Udp = 1739272706;

static unsigned char g_bufSignKey_Udp[] =
{
	0x1e, 0xc3, 0xf8, 0x5c, 0xb2, 0xf2, 0x13, 0x70,
	0x26, 0x4e, 0xb3, 0x71, 0xc8, 0xc6, 0x5c, 0xa3,
	0x7f, 0xa3, 0x3b, 0x9d, 0xef, 0xef, 0x2a, 0x85,
	0xe0, 0xc8, 0x99, 0xae, 0x82, 0xc0, 0xf6, 0xf8
};
//#else
/*static unsigned int g_dwAppID_Rtmp = 1;
static BYTE g_bufSignKey_Rtmp[] =
{
	0x91, 0x93, 0xcc, 0x66, 0x2a, 0x1c, 0x0e, 0xc1,
	0x35, 0xec, 0x71, 0xfb, 0x07, 0x19, 0x4b, 0x38,
	0x41, 0xd4, 0xad, 0x83, 0x78, 0xf2, 0x59, 0x90,
	0xe0, 0xa4, 0x0c, 0x7f, 0xf4, 0x28, 0x41, 0xf7
};
*/
static unsigned int g_dwAppID_International = 3322882036;
static unsigned char g_bufSignKey_International[] =
{
	 0x5d, 0xe6, 0x83, 0xac, 0xa4, 0xe5, 0xad, 0x43, 
	 0xe5, 0xea, 0xe3, 0x70, 0x6b, 0xe0, 0x77, 0xa4,
	 0x18, 0x79, 0x38, 0x31, 0x2e, 0xcc, 0x17, 0x19, 
	 0x32, 0xd2, 0xfe, 0x22, 0x5b, 0x6b, 0x2b, 0x2f
};

QZegoBase::QZegoBase(void) : m_dwInitedMask(INIT_NONE)
{
	//日志存放的路径
	m_strLogPathUTF8 = "ZegoLog/";

	appIDs.push_back(g_dwAppID_Udp);
	appIDs.push_back(g_dwAppID_International);

	appSigns.push_back(g_bufSignKey_Udp);
	appSigns.push_back(g_bufSignKey_International);

	m_pAVSignal = new QZegoSDKSignal;
	
	//默认UDP
	key = 0;

	
}

QZegoBase::~QZegoBase(void)
{
	UninitAVSDK();

	delete m_pAVSignal;

}

bool QZegoBase::InitAVSDK(SettingsPtr pCurSetting, QString userID, QString userName)
{
	if (!IsAVSdkInited())
	{
		qDebug() << "initSDK";
		//Qstring对象.toLocal8Bit().data()用于将QString转为const char*
		AUDIOROOM::SetLogDir(m_strLogPathUTF8.toStdString().c_str());
		AUDIOROOM::SetVerbose(true);
		AUDIOROOM::SetBusinessType(2);
		AUDIOROOM::SetUser(userID.toStdString().data(), userName.toStdString().data());
		AUDIOROOM::SetUseTestEnv(isTestEnv);
		// ToDo: 需要通过代码获取网络类型
		AUDIOROOM::SetNetType(2);
	
		AUDIOROOM::SetAudioRoomCallback(m_pAVSignal);
		AUDIOROOM::SetAudioLivePublisherCallback(m_pAVSignal);
		AUDIOROOM::SetAudioLivePlayerCallback(m_pAVSignal);
		AUDIOROOM::SetAudioDeviceStateCallback(m_pAVSignal);
		AUDIOROOM::SetAudioEngineCallback(m_pAVSignal);
		AUDIOROOM::SetAudioLiveEventCallback(m_pAVSignal);
		AUDIOROOM::SetAudioRecordCallback(m_pAVSignal);

		//默认UDP
		AUDIOROOM::InitSDK(appIDs[key], appSigns[key], 32);
		

		
	}

	//为了调用OnUserUpdate
	AUDIOROOM::SetUserStateUpdate(true);

	AUDIOROOM::EnableAux(false);
	AUDIOROOM::SetPlayVolume(100);
	if (!pCurSetting->GetMircophoneId().isEmpty())
	{
		AUDIOROOM::SetAudioDevice(AV::AudioDevice_Input, pCurSetting->GetMircophoneId().toStdString().data());
	}
	
	m_dwInitedMask |= INIT_AVSDK;
	return true;
}

void QZegoBase::UninitAVSDK(void)
{
	if (IsAVSdkInited())
	{
		qDebug()<< "uninitSDK";
		AUDIOROOM::SetAudioRoomCallback(nullptr);
		AUDIOROOM::SetAudioLivePublisherCallback(nullptr);
		AUDIOROOM::SetAudioLivePlayerCallback(nullptr);
		AUDIOROOM::SetAudioDeviceStateCallback(nullptr);
		AUDIOROOM::SetAudioEngineCallback(nullptr);
		AUDIOROOM::SetAudioLiveEventCallback(nullptr);
		AUDIOROOM::SetAudioRecordCallback(nullptr);

		AUDIOROOM::UnInitSDK();

		unsigned long dwNegation = ~(unsigned long)INIT_AVSDK;
		m_dwInitedMask &= dwNegation;
	}
}

bool QZegoBase::IsAVSdkInited(void)
{
	return (m_dwInitedMask & INIT_AVSDK) == INIT_AVSDK;
}

QZegoSDKSignal* QZegoBase::GetAVSignal(void)
{
	return m_pAVSignal;
}

unsigned long QZegoBase::GetAppID(void)
{
	return appIDs[key];
}

void QZegoBase::setKey(int pKey)
{
	key = pKey;

}

int QZegoBase::getKey()
{
	return key;
}

unsigned char* QZegoBase::GetAppSign()
{
	return appSigns[key];
}

void QZegoBase::setIsTestEnv(bool isTest)
{
	isTestEnv = isTest;
}
