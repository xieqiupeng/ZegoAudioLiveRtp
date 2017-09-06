#pragma once

#include "ZegoStreamModel.h"
#include "AudioRoomCallback.h"
#include "AudioRoomCallback-Player.h"
#include "AudioRoomCallback-Publisher.h"
#include <QObject>
#include <QVector>

using namespace ZEGO;

class QZegoSDKSignal : public QObject,
	public AUDIOROOM::IAudioRoomCallback,
	public AUDIOROOM::IAudioEngineCallback,
	public AUDIOROOM::IAudioLivePublisherCallback,
	public AUDIOROOM::IAudioLivePlayerCallback,
	public AV::IZegoDeviceStateCallback,
	public AV::IZegoAudioRecordCallback,
	public AV::IZegoLiveEventCallback
{
    Q_OBJECT

public:
	QZegoSDKSignal();
	~QZegoSDKSignal();

signals:
	void sigLoginRoom(int errorCode, const QString& roomID);
	void sigDisconnect(int errorCode, const QString& roomID);
	void sigKickOut(int reason, const QString& roomID);
	void sigStreamUpdate(const QString& strRoomID, StreamPtr pStream, AUDIOROOM::ZegoStreamUpdateType type);
	void sigUserUpdate(QVector <QString> userIDs, QVector <QString> userNames, QVector <int> userFlags, QVector <int> userRoles, unsigned int userCount, AUDIOROOM::ZegoUserUpdateType type);
	void sigPublishStateUpdate(int stateCode, const QString& strStreamID, StreamPtr pStream);
	void sigPlayStateUpdate(int stateCode, StreamPtr pStream);
	void sigAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state);

protected:
	//IAudioRoomCallback
	void OnLoginRoom(int errorCode, const char *pszRoomID);
	void OnLogoutRoom(int errorCode, const char *pszRoomID){}
	void OnKickout(int reason, const char *pszRoomID);
    void OnDisconnect(int errorCode, const char *pszRoomID);
	void OnStreamUpdate(AUDIOROOM::ZegoStreamUpdateType type, const AUDIOROOM::ZegoStreamInfo& pStreamInfo, const char *pszRoomID);
	void OnUserUpdate(const AUDIOROOM::ZegoUserInfo *pUserInfo, unsigned int userCount, AUDIOROOM::ZegoUserUpdateType type);

	//IAudioEngineCallback
	//void OnAudioEngineStop() = 0;
	void OnAudioEngineStop(){};

	//IAudioLivePublisherCallback
	void OnPublishStateUpdate(int stateCode, const char *pszStreamID, const AUDIOROOM::ZegoPublishingStreamInfo& oStreamInfo);
	void OnAuxCallback(unsigned char *pData, int *pDataLen, int *pSampleRate, int *pNumChannels) {}

	//IAudioLivePlayerCallback
	void OnPlayStateUpdate(int stateCode, const AUDIOROOM::ZegoStreamInfo& pStreamInfo);

	//IZegoDeviceStateCallback
	void OnAudioDeviceStateChanged(AV::AudioDeviceType deviceType, AV::DeviceInfo *deviceInfo, AV::DeviceState state);
	void OnAudioVolumeChanged(AV::AudioDeviceType deviceType, const char *deviceId, AV::VolumeType volumeType, unsigned int volume, bool bMuted) {}
    void OnDeviceError(const char* deviceName, int errorCode) {}

	//IZegoAudioRecordCallback
	//录制结果回调
	void OnAudioRecordCallback(const unsigned char *pData, int data_len, int sample_rate, int num_channels, int bit_depth, unsigned int type) {}
	//录制回调
    void OnAudioRecordCallback(const unsigned char *pData, int data_len, int sample_rate, int num_channels, int bit_depth) {}

	//IZegoLiveEventCallback
	//void OnAVKitEvent(int event, EventInfo* pInfo) = 0;
	void OnAVKitEvent(int event, AV::EventInfo* pInfo){};
};