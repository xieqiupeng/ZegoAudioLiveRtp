#include "ZegoAudioDemo.h"

QZegoAudioDemoApp::QZegoAudioDemoApp()
{
	
}

//全局唯一的base对象
QZegoAudioDemoApp theApp;

QZegoBase& QZegoAudioDemoApp::GetBase()
{
	return m_base;
}

QZegoSDKSignal * GetAVSignal()
{
	return theApp.GetBase().GetAVSignal();
}