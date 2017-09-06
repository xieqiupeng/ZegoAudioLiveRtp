#include "ZegoSettingsModel.h"



QZegoSettingsModel::QZegoSettingsModel()
{
	InitDeviceId();
}



void QZegoSettingsModel::SetMicrophoneId(const QString& microphoneId)
{
	m_strMicrophoneId = microphoneId;
}

QString QZegoSettingsModel::GetMircophoneId(void)
{
	return m_strMicrophoneId;
}



void QZegoSettingsModel::InitDeviceId(void)
{
	int nDeviceCount(0);
	AV::DeviceInfo* pDeviceList(NULL);

	pDeviceList = AUDIOROOM::GetAudioDeviceList(ZEGO::AV::AudioDevice_Input, nDeviceCount);
	if (nDeviceCount > 0 && pDeviceList != NULL)
		m_strMicrophoneId = pDeviceList[0].szDeviceId;
	AUDIOROOM::FreeDeviceList(pDeviceList);
	pDeviceList = NULL;

	
}
