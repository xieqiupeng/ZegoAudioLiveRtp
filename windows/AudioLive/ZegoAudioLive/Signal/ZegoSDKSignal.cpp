#include "ZegoSDKSignal.h"
#include <QMetaType>
#include <QDebug>
QZegoSDKSignal::QZegoSDKSignal()
{
	qRegisterMetaType<AUDIOROOM::ZegoStreamUpdateType>("AUDIOROOM::ZegoStreamUpdateType");
	qRegisterMetaType<StreamPtr>("StreamPtr");
	qRegisterMetaType<AV::AudioDeviceType>("AV::AudioDeviceType");
	qRegisterMetaType<AV::DeviceState>("AV::DeviceState");
	qRegisterMetaType<QVector <QString>>("QVector <QString>");
	qRegisterMetaType<QVector <int>>("QVector <int>");
	qRegisterMetaType<AUDIOROOM::ZegoUserUpdateType>("AUDIOROOM::ZegoUserUpdateType");
}

QZegoSDKSignal::~QZegoSDKSignal()
{

}

void QZegoSDKSignal::OnLoginRoom(int errorCode, const char *pszRoomID)
{
	QString strRoomID = pszRoomID ? pszRoomID : "";

	emit sigLoginRoom(errorCode, strRoomID);
}

void QZegoSDKSignal::OnKickout(int reason, const char *pszRoomID)
{
	QString strRoomID = pszRoomID ? pszRoomID : "";

	emit sigDisconnect(reason, strRoomID);
}
void QZegoSDKSignal::OnDisconnect(int errorCode, const char *pszRoomID)
{
	QString strRoomID = pszRoomID ? pszRoomID : "";

	emit sigKickOut(errorCode, strRoomID);
}

void QZegoSDKSignal::OnStreamUpdate(AUDIOROOM::ZegoStreamUpdateType type, const AUDIOROOM::ZegoStreamInfo& pStreamInfo, const char *pszRoomID)
{
	
	QString strRoomID = pszRoomID ? pszRoomID : "";

	AUDIOROOM::ZegoStreamInfo zegoStreamInfo = pStreamInfo;
	QString streamID = zegoStreamInfo.szStreamId;
	QString userID = zegoStreamInfo.szUserId;
	QString userName = zegoStreamInfo.szUserName;
	QString ExtraInfo = zegoStreamInfo.szExtraInfo;

	StreamPtr pStream(new QZegoStreamModel(streamID, userID, userName, ExtraInfo));
	
	emit sigStreamUpdate(strRoomID, pStream, type);
}

void QZegoSDKSignal::OnUserUpdate(const AUDIOROOM::ZegoUserInfo *pUserInfo, unsigned int userCount, AUDIOROOM::ZegoUserUpdateType type)
{
	//qDebug() << "userUpdate";
	QVector<QString> userIDs;
	QVector<QString> userNames;
	QVector<int> userFlags;
	QVector<int> userRoles;

	for (int i = 0; i < userCount; i++)
	{
		QString strUserId = pUserInfo[i].szUserId;
		QString strUserName = pUserInfo[i].szUserName;
		userIDs.push_back(strUserId);
		userNames.push_back(strUserName);
		userFlags.push_back(pUserInfo[i].udapteFlag);
		userRoles.push_back(pUserInfo[i].role);
	}

	emit sigUserUpdate(userIDs, userNames, userFlags, userRoles, userCount, type);
}



void QZegoSDKSignal::OnPublishStateUpdate(int stateCode, const char *pszStreamID, const AUDIOROOM::ZegoPublishingStreamInfo& oStreamInfo)
{
	QString strStreamID = pszStreamID ? pszStreamID : "";

	StreamPtr pStream(new QZegoStreamModel(strStreamID, "", "", "", true));

	for (unsigned int i = 0; i < oStreamInfo.uiRtmpURLCount; i++)
	{
		pStream->m_vecRtmpUrls.push_back(oStreamInfo.arrRtmpURLs[i]);
	}

	for (unsigned int i = 0; i < oStreamInfo.uiFlvURLCount; i++)
	{
		pStream->m_vecFlvUrls.push_back(oStreamInfo.arrFlvURLs[i]);
	}

	for (unsigned int i = 0; i < oStreamInfo.uiHlsURLCount; i++)
	{
		pStream->m_vecHlsUrls.push_back(oStreamInfo.arrHlsURLs[i]);
	}

	emit sigPublishStateUpdate(stateCode, strStreamID, pStream);
}


void QZegoSDKSignal::OnPlayStateUpdate(int stateCode, const AUDIOROOM::ZegoStreamInfo& pStreamInfo)
{
	AUDIOROOM::ZegoStreamInfo zegoStreamInfo = pStreamInfo;
	QString streamID = zegoStreamInfo.szStreamId;
	QString userID = zegoStreamInfo.szUserId;
	QString userName = zegoStreamInfo.szUserName;
	QString ExtraInfo = zegoStreamInfo.szExtraInfo;

	StreamPtr pStream(new QZegoStreamModel(streamID, userID, userName, ExtraInfo));

	emit sigPlayStateUpdate(stateCode, pStream);
}


void QZegoSDKSignal::OnAudioDeviceStateChanged(AV::AudioDeviceType deviceType, AV::DeviceInfo *deviceInfo, AV::DeviceState state)
{
	if (deviceInfo == nullptr)
		return;

	QString strDeviceId = deviceInfo->szDeviceId;
	QString strDeviceName = deviceInfo->szDeviceName;

	emit sigAudioDeviceChanged(deviceType, strDeviceId, strDeviceName, state);
}