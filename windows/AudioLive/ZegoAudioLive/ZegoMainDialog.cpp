#include "ZegoMainDialog.h"
#include <QDebug>
ZegoAudioLive::ZegoAudioLive(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//添加最小化按钮
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowMinimizeButtonHint;
	flags |= Qt::WindowCloseButtonHint;
	setWindowFlags(flags);

	//最大流数量
	maxCount = AUDIOROOM::GetMaxPlayChannelCount();

	//绑定sdk回调信号
	connect(GetAVSignal(), &QZegoSDKSignal::sigLoginRoom, this, &ZegoAudioLive::OnLoginRoom);
	connect(GetAVSignal(), &QZegoSDKSignal::sigDisconnect, this, &ZegoAudioLive::OnDisconnect);
	connect(GetAVSignal(), &QZegoSDKSignal::sigKickOut, this, &ZegoAudioLive::OnKickOut);
	connect(GetAVSignal(), &QZegoSDKSignal::sigStreamUpdate, this, &ZegoAudioLive::OnStreamUpdate);
	connect(GetAVSignal(), &QZegoSDKSignal::sigUserUpdate, this, &ZegoAudioLive::OnUserUpdate);
	connect(GetAVSignal(), &QZegoSDKSignal::sigPublishStateUpdate, this, &ZegoAudioLive::OnPublishStateUpdate);
	connect(GetAVSignal(), &QZegoSDKSignal::sigPlayStateUpdate, this, &ZegoAudioLive::OnPlayStateUpdate);
	connect(GetAVSignal(), &QZegoSDKSignal::sigAudioDeviceChanged, this, &ZegoAudioLive::OnAudioDeviceChanged);
	
	//绑定ui回调信号
	connect(ui.m_switchStartPublish, &QPushButton::clicked, this, &ZegoAudioLive::OnButtonClickedPublish);
	connect(ui.m_checkManual, &QCheckBox::clicked, this, &ZegoAudioLive::OnCheckManualPublish);
	connect(ui.m_checkTestEnv, &QCheckBox::clicked, this, &ZegoAudioLive::OnCheckTestEnv);
	connect(ui.m_checkMute, &QCheckBox::clicked, this, &ZegoAudioLive::OnCheckMute);
	connect(ui.m_cbAppVersion, SIGNAL(currentIndexChanged(int)), this, SLOT(OnComboBoxValueChanged(int)));
}

ZegoAudioLive::~ZegoAudioLive()
{
	theApp.GetBase().UninitAVSDK();
}

void ZegoAudioLive::initDialog()
{
	//设定窗口大小不可改变
	setFixedSize(this->width(), this->height());

	//用户名和用户ID不可改
	ui.m_edUserID->setEnabled(false);
	ui.m_edUserName->setEnabled(false);

	//成员列表模型初始化
	m_memberListModel = new QStringListModel(this);
	ui.m_memberList->setModel(m_memberListModel);
	ui.m_memberList->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//日志列表模型初始化
	m_logListModel = new QStringListModel(this);
	ui.m_logList->setModel(m_logListModel);
	ui.m_logList->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//允许使用麦克风，扬声器
	AUDIOROOM::EnableMic(m_bEnableMic);
	AUDIOROOM::EnableSpeaker(!isMute);

	//从用户配置文件中读取配置信息，若找不到则新建配置文件
	m_userConfig.LoadConfig();

	m_strEdUserId = m_userConfig.GetUserId();
	m_strEdUserName = m_userConfig.GetUserName();

	ui.m_edUserID->setText(m_strEdUserId);
	ui.m_edUserName->setText(m_strEdUserName);
	ui.m_edAppID->setText(QStringLiteral("%1").arg(theApp.GetBase().GetAppID()));
	if (theApp.GetBase().getKey() == 0 || theApp.GetBase().getKey() == 1 || theApp.GetBase().getKey() == 2)
	{
		ui.m_edAppSign->setText(QStringLiteral("Demo已添加,无需设置"));
		ui.m_edAppID->setEnabled(false);
		ui.m_edAppSign->setEnabled(false);
	}

	//对于AudioSettings来说，属性只有userID，userName和mircoPhoneID
	m_pCurSettings = m_userConfig.GetAudioSettings();

	//comboBox
	ui.m_cbAppVersion->addItem(QStringLiteral("国内版"));
	ui.m_cbAppVersion->addItem(QStringLiteral("国际版"));
	ui.m_cbAppVersion->addItem(QStringLiteral("自定义"));
	ui.m_cbAppVersion->setCurrentIndex(theApp.GetBase().getKey());

	//标题
	this->setWindowTitle(QStringLiteral("ZegoAudioLive(%1) | 版本: %2").arg(ui.m_cbAppVersion->currentText()).arg(AUDIOROOM::GetSDKVersion()));


	if (m_pCurSettings != nullptr)
	{
		theApp.GetBase().InitAVSDK(m_pCurSettings, m_strEdUserId, m_strEdUserName);
	}
}

void ZegoAudioLive::addLogString(const QString& name)
{
	int row = 0;
	m_logListModel->insertRows(row, 1);
	QModelIndex index = m_logListModel->index(row);

	QTime curTime = QTime::currentTime();
	QString log = QStringLiteral("%1-%2-%3:%4: ").arg(curTime.hour()).arg(curTime.minute()).arg(curTime.second()).arg(curTime.msec()) + name;
	m_logListModel->setData(index, log);
}

void ZegoAudioLive::insertStringListModelItem(QStringListModel * model, QString name, int size)
{
	int row = size;
	model->insertRows(row, 1);
	QModelIndex index = model->index(row);
	model->setData(index, name);
}

void ZegoAudioLive::removeStringListModelItem(QStringListModel * model, QString name)
{
	if (model->rowCount() > 0)
	{
		int curIndex = -1;
		QStringList list = model->stringList();
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i] == name)
				curIndex = i;
		}

		model->removeRows(curIndex, 1);
	}
}

void ZegoAudioLive::startManualPublish()
{

}
void ZegoAudioLive::switchBeforePublishArea(bool isEnabled)
{
     
	if (isEnabled && !isCustom){

		ui.m_cbAppVersion->setEnabled(isEnabled);
		ui.m_checkManual->setEnabled(isEnabled);
		ui.m_checkTestEnv->setEnabled(isEnabled);
	}
	else
	{
		ui.m_edAppID->setEnabled(isEnabled);
		ui.m_edAppSign->setEnabled(isEnabled);
		ui.m_cbAppVersion->setEnabled(isEnabled);
		ui.m_checkManual->setEnabled(isEnabled);
		ui.m_checkTestEnv->setEnabled(isEnabled);
	}

}

//sdk回调
void ZegoAudioLive::OnLoginRoom(int errorCode, const QString& roomID)
{
	if (errorCode == 0)
	{
		addLogString(QStringLiteral("加入session成功"));

		if (isManual){

			ui.m_switchStartPublish->setText(QStringLiteral("开始直播"));
			ui.m_switchStartPublish->setEnabled(true);
		}
	}
	else
	{
		addLogString(QStringLiteral("加入session失败: %1").arg(errorCode));
		switchBeforePublishArea(true);
		ui.m_switchStartPublish->setEnabled(true);
	}
}

void ZegoAudioLive::OnDisconnect(int errorCode, const QString& roomID)
{
	if (roomID == m_sessionID)
	{
		addLogString(QStringLiteral("连接房间失败"));

		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("您已掉线"));
		OnClose();
	}
}

void ZegoAudioLive::OnKickOut(int reason, const QString& roomID)
{
	if (roomID == m_sessionID)
	{
		addLogString(QStringLiteral("从房间中被踢走"));

		QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("您已被踢出房间"));
		OnClose();
	}
}

void ZegoAudioLive::OnStreamUpdate(const QString& strRoomID, StreamPtr pStream, AUDIOROOM::ZegoStreamUpdateType type)
{
	
	if (type == AUDIOROOM::ZegoStreamUpdateType::StreamAdded)
	{
		bool alreadyHave = false;
		for (auto stream : streamList)
		{
			if (stream->getStreamId() == pStream->getStreamId())
			{
				alreadyHave = true;
				break;
			}
		}

		if (!alreadyHave)
		{
			streamList.push_back(pStream);
			addLogString(QStringLiteral("新增流:%1").arg(pStream->getStreamId()));
			insertStringListModelItem(m_memberListModel, QStringLiteral("%1").arg(pStream->getStreamId()), m_memberListModel->rowCount());
		}
	}

	else
	{

		for (int i = 0; i < streamList.size(); i++)
		{
			qDebug() << "currentStreamID = " << streamList[i]->getStreamId();

			if (pStream != nullptr)
				qDebug() << "deleteStreamID = " << pStream->getStreamId();
			if (streamList[i]->getStreamId() == pStream->getStreamId())
			{
				streamList.remove(i);
				removeStringListModelItem(m_memberListModel, QStringLiteral("%1").arg(pStream->getStreamId()));
				addLogString(QStringLiteral("删除流:%1").arg(pStream->getStreamId()));
				break;
			}
		}
	}
}

void ZegoAudioLive::OnUserUpdate(QVector <QString> userIDs, QVector <QString> userNames, QVector <int> userFlags, QVector <int> userRoles, unsigned int userCount, AUDIOROOM::ZegoUserUpdateType type)
{

	if (type == AUDIOROOM::ZegoUserUpdateType::UPDATE_TOTAL)
		addLogString(QStringLiteral("用户列表已全量更新"));
	else if (type == AUDIOROOM::ZegoUserUpdateType::UPDATE_INCREASE)
		addLogString(QStringLiteral("用户列表已增量更新"));

	for (int i = 0; i < userCount; i++)
	{
		if (userFlags[i] == AUDIOROOM::ZegoUserUpdateFlag::USER_ADDED)
			addLogString(QStringLiteral("%1 用户进入房间").arg(userIDs[i]));
		else if (userFlags[i] == AUDIOROOM::ZegoUserUpdateFlag::USER_DELETED)
			addLogString(QStringLiteral("%1 用户离开房间").arg(userIDs[i]));
	}
}

void ZegoAudioLive::OnPublishStateUpdate(int stateCode, const QString& strStreamID, StreamPtr pStream)
{
	if (stateCode == 0)
	{
		//逻辑结束，恢复按钮
		ui.m_switchStartPublish->setText(QStringLiteral("停止"));
		ui.m_switchStartPublish->setEnabled(true);

		addLogString(QStringLiteral("推流成功: %1").arg(m_strPublishStreamID));

		StreamPtr pStream(new QZegoStreamModel(m_strPublishStreamID, m_strEdUserId, m_strEdUserName, ""));
		streamList.push_back(pStream);
		//将该流加入到成员列表中
		insertStringListModelItem(m_memberListModel, m_strPublishStreamID, m_memberListModel->rowCount());
	}
	else
	{
		addLogString(QStringLiteral("推流失败: %1, error: %2").arg(m_strPublishStreamID).arg(stateCode));
	}

}
void ZegoAudioLive::OnPlayStateUpdate(int stateCode, StreamPtr pStream)
{
	if (stateCode == 0)
	{
		addLogString(QStringLiteral("拉流成功: %1").arg(pStream->getStreamId()));
	}
	else
	{
		addLogString(QStringLiteral("拉流失败: %1, error: %2").arg(pStream->getStreamId()).arg(stateCode));
	}
}

void ZegoAudioLive::OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
{
	//针对麦克风
	if (deviceType == AV::AudioDeviceType::AudioDevice_Output)
		return;

	if (state == AV::DeviceState::Device_Added)
	{
		m_vecAudioDeviceIDs.push_back(strDeviceId);

		if (m_vecAudioDeviceIDs.size() == 1)
		{
			AUDIOROOM::SetAudioDevice(AV::AudioDevice_Input, m_vecAudioDeviceIDs[0].toStdString().c_str());
			m_pCurSettings->SetMicrophoneId(m_vecAudioDeviceIDs[0]);
			
		}
	}
	else if (state == AV::DeviceState::Device_Deleted)
	{
		for (int i = 0; i < m_vecAudioDeviceIDs.size(); i++)
		{
			if (m_vecAudioDeviceIDs[i] != strDeviceId)
				continue;

			m_vecAudioDeviceIDs.erase(m_vecAudioDeviceIDs.begin() + i);


			
				//如果删除之后还有能播放的设备存在，则默认选择第一个音频设备
				if (m_vecAudioDeviceIDs.size() > 0)
				{
					AUDIOROOM::SetAudioDevice(AV::AudioDevice_Input, m_vecAudioDeviceIDs[0].toStdString().c_str());
					m_pCurSettings->SetMicrophoneId(m_vecAudioDeviceIDs[0]);
				}
				else
				{
					AUDIOROOM::SetAudioDevice(AV::AudioDevice_Input, NULL);
					m_pCurSettings->SetMicrophoneId("");
				}
			break;
		}
	}
}

//ui回调
void ZegoAudioLive::OnButtonClickedPublish()
{
	if (ui.m_switchStartPublish->text() == QStringLiteral("进入"))
	{
		if (ui.m_edSessionID->text() == QStringLiteral(""))
		{
			QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("SessionID不能为空"));
			return;
		}

		if (ui.m_edAppID->text() == QStringLiteral(""))
		{
			QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("AppID不能为空"));
			return;
		}

		if (ui.m_edAppSign->toPlainText() == QStringLiteral(""))
		{
			QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("AppSign不能为空"));
			return;
		}
		
		if (streamList.size() == maxCount)
		{
			QMessageBox::information(NULL, QStringLiteral("开播失败"), QStringLiteral("直播流超过上限"));
			return;
		}

		//进入直播后左边设置区域不可用
		switchBeforePublishArea(false);

		if (isCustom)
		{

			AUDIOROOM::UnInitSDK();

			unsigned int appId = ui.m_edAppID->text().toUInt();
			QString strAppSign = ui.m_edAppSign->toPlainText();
			unsigned char *appSign = new unsigned char[32];

			for (int i = 0; i < 32; i++)
				appSign[i] = strAppSign.at(i).unicode();

			if (!AUDIOROOM::InitSDK(appId, appSign, 32))
			{
				QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("初始化SDK失败"));
				AUDIOROOM::InitSDK(theApp.GetBase().GetAppID(), theApp.GetBase().GetAppSign(), 32);
				return;
			}
		}

		//不能重复点击
		ui.m_switchStartPublish->setEnabled(false);

		//获取SessionID
		m_sessionID = ui.m_edSessionID->text();
        
		//以当前时间去生成流ID
		QTime currentTime = QTime::currentTime();
		int ms = currentTime.msec();
		QString strStreamId;
		strStreamId = QString(QStringLiteral("s-windows-%1-%2")).arg(m_strEdUserId).arg(ms);
		m_strPublishStreamID = strStreamId;

		AUDIOROOM::LoginRoom(m_sessionID.toStdString().c_str());
		AUDIOROOM::SetManualPublish(isManual);
		addLogString(QStringLiteral("开始加入session: %1").arg(m_sessionID));

		
	
	}
	else if (ui.m_switchStartPublish->text() == QStringLiteral("停止"))
	{
		//不能重复点击
		ui.m_switchStartPublish->setEnabled(false);

		//退出房间
		AUDIOROOM::LogoutRoom();
		//清空流列表
		m_memberListModel->removeRows(0, m_memberListModel->rowCount());
		streamList.clear();

		addLogString(QStringLiteral("%1 用户停止直播").arg(m_strEdUserId));

		//停止直播后左边设置区域恢复可用
		switchBeforePublishArea(true);

		//逻辑结束，恢复按钮
		ui.m_switchStartPublish->setText(QStringLiteral("进入"));
		ui.m_switchStartPublish->setEnabled(true);
	}
	else if (ui.m_switchStartPublish->text() == QStringLiteral("开始直播"))
	{
		AUDIOROOM::StartPublish();
		ui.m_switchStartPublish->setEnabled(false);
	}

}

void ZegoAudioLive::OnCheckMute()
{
	if (ui.m_checkMute->isChecked())
		isMute = true;

	else
		isMute = false;

	//扬声器静音
	AUDIOROOM::EnableSpeaker(!isMute);
}

void ZegoAudioLive::OnCheckTestEnv()
{
	if (ui.m_checkTestEnv->isChecked())
		isTestEnv = true;

	else
		isTestEnv = false;

	theApp.GetBase().setIsTestEnv(isTestEnv);
	theApp.GetBase().UninitAVSDK();
	theApp.GetBase().InitAVSDK(m_pCurSettings, m_strEdUserId, m_strEdUserName);

}

void ZegoAudioLive::OnCheckManualPublish()
{
	if (ui.m_checkManual->isChecked())
		isManual = true;
		
	else
		isManual = false;
		
}

void ZegoAudioLive::OnComboBoxValueChanged(int id)
{

	ui.m_cbAppVersion->setCurrentIndex(id);

	if (id == ZEGO_PROTOCOL_UDP || id == ZEGO_PROTOCOL_UDP_INTERNATIONAL){

		isCustom = false;
		theApp.GetBase().setKey(id);
		ui.m_edAppID->setText(QStringLiteral("%1").arg(theApp.GetBase().GetAppID()));
		ui.m_edAppSign->setText(QStringLiteral("Demo已添加,无需设置"));
		ui.m_edAppID->setEnabled(false);
		ui.m_edAppSign->setEnabled(false);

		theApp.GetBase().UninitAVSDK();
		theApp.GetBase().InitAVSDK(m_pCurSettings, m_strEdUserId, m_strEdUserName);

	}
	else
	{
		isCustom = true;
		ui.m_edAppID->setText(QStringLiteral(""));
		ui.m_edAppSign->setText(QStringLiteral(""));
		ui.m_edAppID->setEnabled(true);
		ui.m_edAppSign->setEnabled(true);
	}
	//标题
	this->setWindowTitle(QStringLiteral("ZegoAudioLive(%1)").arg(ui.m_cbAppVersion->currentText()));
}

void ZegoAudioLive::OnClose()
{
	streamList.clear();
	AUDIOROOM::LogoutRoom();
	this->close();
}

void ZegoAudioLive::colseEvent(QCloseEvent *event)
{
	OnClose();
}