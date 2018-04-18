#pragma once

#include "Base/ZegoBase.h"


class QZegoAudioDemoApp
{
public:
	QZegoAudioDemoApp();

public:
	QZegoBase &GetBase();

private:
	QZegoBase m_base;
};

extern QZegoAudioDemoApp theApp;

QZegoSDKSignal * GetAVSignal(void);