#include "ZegoMainDialog.h"
#include <QDebug>
#include <qtimer.h>
ZegoAudioLive::ZegoAudioLive(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//�����С����ť
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowMinimizeButtonHint;
	flags |= Qt::WindowCloseButtonHint;
	setWindowFlags(flags);

	//���������
	maxCount = AUDIOROOM::GetMaxPlayChannelCount();

	//��sdk�ص��ź�
	connect(GetAVSignal(), &QZegoSDKSignal::sigLoginRoom, this, &ZegoAudioLive::OnLoginRoom);
	connect(GetAVSignal(), &QZegoSDKSignal::sigDisconnect, this, &ZegoAudioLive::OnDisconnect);
	connect(GetAVSignal(), &QZegoSDKSignal::sigKickOut, this, &ZegoAudioLive::OnKickOut);
	connect(GetAVSignal(), &QZegoSDKSignal::sigStreamUpdate, this, &ZegoAudioLive::OnStreamUpdate);
	connect(GetAVSignal(), &QZegoSDKSignal::sigUserUpdate, this, &ZegoAudioLive::OnUserUpdate);
	connect(GetAVSignal(), &QZegoSDKSignal::sigPublishStateUpdate, this, &ZegoAudioLive::OnPublishStateUpdate);
	connect(GetAVSignal(), &QZegoSDKSignal::sigPlayStateUpdate, this, &ZegoAudioLive::OnPlayStateUpdate);
	connect(GetAVSignal(), &QZegoSDKSignal::sigAudioDeviceChanged, this, &ZegoAudioLive::OnAudioDeviceChanged);
	
	//��ui�ص��ź�
	connect(ui.m_switchStartPublish, &QPushButton::clicked, this, &ZegoAudioLive::OnButtonClickedPublish);
	connect(ui.m_checkManual, &QCheckBox::clicked, this, &ZegoAudioLive::OnCheckManualPublish);
	connect(ui.m_checkTestEnv, &QCheckBox::clicked, this, &ZegoAudioLive::OnCheckTestEnv);
	connect(ui.m_checkMute, &QCheckBox::clicked, this, &ZegoAudioLive::OnCheckMute);
	connect(ui.m_cbAppVersion, SIGNAL(currentIndexChanged(int)), this, SLOT(OnComboBoxValueChanged(int)));
	connect(ui.m_edUserID, &QLineEdit::editingFinished, this, &ZegoAudioLive::OnEditedUserID);
	connect(ui.m_edUserName, &QLineEdit::editingFinished, this, &ZegoAudioLive::OnEditedUserName);
}

ZegoAudioLive::~ZegoAudioLive()
{
	theApp.GetBase().UninitAVSDK();
}

void ZegoAudioLive::initDialog()
{
	//�趨���ڴ�С���ɸı�
	setFixedSize(this->width(), this->height());

	//�û������û�ID���ɸ�
	//ui.m_edUserID->setEnabled(false);
	//ui.m_edUserName->setEnabled(false);

	//��Ա�б�ģ�ͳ�ʼ��
	m_memberListModel = new QStringListModel(this);
	ui.m_memberList->setModel(m_memberListModel);
	ui.m_memberList->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//��־�б�ģ�ͳ�ʼ��
	m_logListModel = new QStringListModel(this);
	ui.m_logList->setModel(m_logListModel);
	ui.m_logList->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//����ʹ����˷磬������
	AUDIOROOM::EnableMic(m_bEnableMic);
	AUDIOROOM::EnableSpeaker(!isMute);

	//���û������ļ��ж�ȡ������Ϣ�����Ҳ������½������ļ�
	m_userConfig.LoadConfig();

	m_strEdUserId = m_userConfig.GetUserId();
	m_strEdUserName = m_userConfig.GetUserName();

	ui.m_edUserID->setText(m_strEdUserId);
	ui.m_edUserName->setText(m_strEdUserName);
	ui.m_edAppID->setText(QStringLiteral("%1").arg(theApp.GetBase().GetAppID()));
	if (theApp.GetBase().getKey() == 0 || theApp.GetBase().getKey() == 1 || theApp.GetBase().getKey() == 2)
	{
		ui.m_edAppSign->setText(QStringLiteral("Demo�����,��������"));
		ui.m_edAppID->setEnabled(false);
		ui.m_edAppSign->setEnabled(false);
	}

	//����AudioSettings��˵������ֻ��userID��userName��mircoPhoneID
	m_pCurSettings = m_userConfig.GetAudioSettings();

	//comboBox
	ui.m_cbAppVersion->addItem(QStringLiteral("���ڰ�"));
	ui.m_cbAppVersion->addItem(QStringLiteral("���ʰ�"));
	ui.m_cbAppVersion->addItem(QStringLiteral("�Զ���"));
	ui.m_cbAppVersion->setCurrentIndex(theApp.GetBase().getKey());

	//����
	this->setWindowTitle(QStringLiteral("ZegoAudioLive(%1) | �汾: %2").arg(ui.m_cbAppVersion->currentText()).arg(AUDIOROOM::GetSDKVersion()));


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

	ui.m_edUserID->setEnabled(isEnabled);
	ui.m_edUserName->setEnabled(isEnabled);

}

//sdk�ص�
void ZegoAudioLive::OnLoginRoom(int errorCode, const QString& roomID)
{
	if (errorCode == 0)
	{
		addLogString(QStringLiteral("����session�ɹ�"));

		if (isManual){

			ui.m_switchStartPublish->setText(QStringLiteral("��ʼֱ��"));
			ui.m_switchStartPublish->setEnabled(true);
		}
	}
	else
	{
		addLogString(QStringLiteral("����sessionʧ��: %1").arg(errorCode));
		switchBeforePublishArea(true);
		ui.m_switchStartPublish->setEnabled(true);
	}
}

void ZegoAudioLive::OnDisconnect(int errorCode, const QString& roomID)
{
	if (roomID == m_sessionID)
	{
		addLogString(QStringLiteral("���ӷ���ʧ��"));

		QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("���ѵ���"));
		OnClose();
	}
}

void ZegoAudioLive::OnKickOut(int reason, const QString& roomID)
{
	if (roomID == m_sessionID)
	{
		addLogString(QStringLiteral("�ӷ����б�����"));

		QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("���ѱ��߳�����"));
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
			addLogString(QStringLiteral("������:%1").arg(pStream->getStreamId()));
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
				addLogString(QStringLiteral("ɾ����:%1").arg(pStream->getStreamId()));
				break;
			}
		}
	}
}

void ZegoAudioLive::OnUserUpdate(QVector <QString> userIDs, QVector <QString> userNames, QVector <int> userFlags, QVector <int> userRoles, unsigned int userCount, AUDIOROOM::ZegoUserUpdateType type)
{

	if (type == AUDIOROOM::ZegoUserUpdateType::UPDATE_TOTAL)
		addLogString(QStringLiteral("�û��б���ȫ������"));
	else if (type == AUDIOROOM::ZegoUserUpdateType::UPDATE_INCREASE)
		addLogString(QStringLiteral("�û��б�����������"));

	for (int i = 0; i < userCount; i++)
	{
		if (userFlags[i] == AUDIOROOM::ZegoUserUpdateFlag::USER_ADDED)
			addLogString(QStringLiteral("%1 �û����뷿��").arg(userIDs[i]));
		else if (userFlags[i] == AUDIOROOM::ZegoUserUpdateFlag::USER_DELETED)
			addLogString(QStringLiteral("%1 �û��뿪����").arg(userIDs[i]));
	}
}

void ZegoAudioLive::OnPublishStateUpdate(int stateCode, const QString& strStreamID, StreamPtr pStream)
{
	if (stateCode == 0)
	{
		//�߼��������ָ���ť
		ui.m_switchStartPublish->setText(QStringLiteral("ֹͣ"));
		ui.m_switchStartPublish->setEnabled(true);

		addLogString(QStringLiteral("�����ɹ�: %1").arg(m_strPublishStreamID));
		
		bool alreadyHave = true;
		for (auto stream : streamList)
		{
			if (stream->getStreamId() == m_strPublishStreamID)
			{
				alreadyHave = false;
				break;
			}
		}
		if (alreadyHave) {
			StreamPtr pStream(new QZegoStreamModel(m_strPublishStreamID, m_strEdUserId, m_strEdUserName, ""));
			streamList.push_back(pStream);
			//���������뵽��Ա�б���
			insertStringListModelItem(m_memberListModel, m_strPublishStreamID, m_memberListModel->rowCount());
		}
		//�������ɹ���,�����������
		publishCount = 0;
		isPrompt = true;
	}
	else
	{
		addLogString(QStringLiteral("����ʧ��: %1, error: %2").arg(m_strPublishStreamID).arg(stateCode));

		startRestartPublishTimer();
	}

}

void ZegoAudioLive::startRestartPublishTimer() {
	if (publishCount<10) {
		addLogString(QStringLiteral("��������������ʱ��"));
		if (timer != nullptr) {
			timer->stop();
			delete timer;
			timer = nullptr;
		}
		timer = new QTimer(this);
		connect(timer, SIGNAL(timeout()), this, SLOT(restartPublishStream()));
		timer->setSingleShot(true);
		timer->start(6000);
		++publishCount;
	}
	else if(isPrompt){
		//ֻ��ʾһ��
		isPrompt = false;
		addLogString(QStringLiteral("�������������������� publishCount:%1").arg(publishCount));
	}
}


void ZegoAudioLive::restartPublishStream() {
	addLogString(QStringLiteral("������������"));
	AUDIOROOM::RestartPublishStream();
}


void ZegoAudioLive::OnPlayStateUpdate(int stateCode, StreamPtr pStream)
{
	if (stateCode == 0)
	{
		addLogString(QStringLiteral("�����ɹ�: %1").arg(pStream->getStreamId()));
	}
	else
	{
		addLogString(QStringLiteral("����ʧ��: %1, error: %2").arg(pStream->getStreamId()).arg(stateCode));
	}
}

void ZegoAudioLive::OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state)
{
	//�����˷�
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


			
				//���ɾ��֮�����ܲ��ŵ��豸���ڣ���Ĭ��ѡ���һ����Ƶ�豸
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

QVector<QString> ZegoAudioLive::handleStringAppSign(QString appSign)
{
	QVector<QString> vecAppSign;
	appSign = appSign.simplified();
	appSign.remove(",");
	appSign.remove(" ");
	qDebug() << "appSign = " << appSign;

	for (int i = 0; i < appSign.size(); i += 4)
	{
		//qDebug() << "curString = " << appSign.mid(i, 4);
		QString hexSign = appSign.mid(i, 4);
		hexSign.remove("0x");
		hexSign.toUpper();
		vecAppSign.append(hexSign);
	}
	qDebug() << vecAppSign;
	return vecAppSign;
}

//ui�ص�
void ZegoAudioLive::OnButtonClickedPublish()
{
	if (ui.m_switchStartPublish->text() == QStringLiteral("����"))
	{
		if (ui.m_edSessionID->text() == QStringLiteral(""))
		{
			QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("SessionID����Ϊ��"));
			return;
		}

		if (ui.m_edAppID->text() == QStringLiteral(""))
		{
			QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("AppID����Ϊ��"));
			return;
		}

		if (ui.m_edAppSign->toPlainText() == QStringLiteral(""))
		{
			QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("AppSign����Ϊ��"));
			return;
		}
		
		if (streamList.size() == maxCount)
		{
			QMessageBox::information(NULL, QStringLiteral("����ʧ��"), QStringLiteral("ֱ������������"));
			return;
		}

		//����ǰ���¼��UserID��UserName
		if (m_strEdUserId.simplified().isEmpty() || m_strEdUserName.simplified().isEmpty())
		{
			QMessageBox::information(NULL, QStringLiteral("����ʧ��"), QStringLiteral("�û�ID���û�������Ϊ��"));
			return;
		}

		//����ֱ��������������򲻿���
		switchBeforePublishArea(false);

		AUDIOROOM::SetUser(m_strEdUserId.toStdString().c_str(), m_strEdUserName.toStdString().c_str());

		if (isCustom)
		{

			AUDIOROOM::UnInitSDK();

			unsigned int appId = ui.m_edAppID->text().toUInt();
			QString strAppSign = ui.m_edAppSign->toPlainText();
			QVector<QString>vecAppSign = handleStringAppSign(strAppSign);
			if (vecAppSign.size() != 32)
			{
				QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("AppSign ����Ϊ32λ"));
				switchBeforePublishArea(true);
				return;
			}

			unsigned char *appSign = new unsigned char[32];
			for (int i = 0; i < 32; i++)
			{
				bool ok;
				appSign[i] = (unsigned char)vecAppSign[i].toInt(&ok, 16);
			}

			if (!AUDIOROOM::InitSDK(appId, appSign, 32))
			{
				QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("��ʼ��SDKʧ��"));
				AUDIOROOM::InitSDK(theApp.GetBase().GetAppID(), theApp.GetBase().GetAppSign(), 32);
				return;
			}
		}

		//�����ظ����
		ui.m_switchStartPublish->setEnabled(false);

		//��ȡSessionID
		m_sessionID = ui.m_edSessionID->text();
        
		//�Ե�ǰʱ��ȥ������ID
		QTime currentTime = QTime::currentTime();
		int ms = currentTime.msec();
		QString strStreamId;
		strStreamId = QString(QStringLiteral("s-windows-%1-%2")).arg(m_strEdUserId).arg(ms);
		m_strPublishStreamID = strStreamId;

		AUDIOROOM::LoginRoom(m_sessionID.toStdString().c_str());
		AUDIOROOM::SetManualPublish(isManual);
		addLogString(QStringLiteral("��ʼ����session: %1").arg(m_sessionID));

		
	
	}
	else if (ui.m_switchStartPublish->text() == QStringLiteral("ֹͣ"))
	{
		//�����ظ����
		ui.m_switchStartPublish->setEnabled(false);

		//�˳�����
		AUDIOROOM::LogoutRoom();
		//������б�
		m_memberListModel->removeRows(0, m_memberListModel->rowCount());
		streamList.clear();

		addLogString(QStringLiteral("%1 �û�ֱֹͣ��").arg(m_strEdUserId));

		//ֱֹͣ���������������ָ�����
		switchBeforePublishArea(true);

		//�߼��������ָ���ť
		ui.m_switchStartPublish->setText(QStringLiteral("����"));
		ui.m_switchStartPublish->setEnabled(true);
	}
	else if (ui.m_switchStartPublish->text() == QStringLiteral("��ʼֱ��"))
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

	//����������
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
		ui.m_edAppSign->setText(QStringLiteral("Demo�����,��������"));
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
	//����
	this->setWindowTitle(QStringLiteral("ZegoAudioLive(%1) | �汾: %2").arg(ui.m_cbAppVersion->currentText()).arg(AUDIOROOM::GetSDKVersion()));
}

void ZegoAudioLive::OnEditedUserID()
{
	QString userID = ui.m_edUserID->text();
	m_strEdUserId = userID.simplified();
	m_userConfig.SetUserId(m_strEdUserId);
	m_userConfig.SaveConfig();
}

void ZegoAudioLive::OnEditedUserName()
{
	QString userName = ui.m_edUserName->text();
	m_strEdUserName = userName.simplified();
	m_userConfig.SetUserName(m_strEdUserName);
	m_userConfig.SaveConfig();
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