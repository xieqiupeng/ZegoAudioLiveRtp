#ifndef ZEGOMAINDIALOG_H
#define ZEGOMAINDIALOG_H

#include <QtWidgets/QDialog>
#include <QStringListModel>
#include <QTime>
#include <QMessageBox>
#include "ui_ZegoMainDialog.h"
#include "Config/ZegoUserConfig.h"
#include "Model/ZegoStreamModel.h"
#include "Base/ZegoBase.h"
#include "ZegoAudioDemo.h"

class ZegoAudioLive : public QDialog
{
	Q_OBJECT

public:
	ZegoAudioLive(QWidget *parent = 0);
	~ZegoAudioLive();

	void initDialog();
	
protected:
	virtual void colseEvent(QCloseEvent *event);

protected slots:
    void OnLoginRoom(int errorCode, const QString& roomID);
    void OnDisconnect(int errorCode, const QString& roomID);
    void OnKickOut(int reason, const QString& roomID);
    void OnStreamUpdate(const QString& strRoomID, StreamPtr pStream, AUDIOROOM::ZegoStreamUpdateType type);
    void OnUserUpdate(QVector <QString> userIDs, QVector <QString> userNames, QVector <int> userFlags, QVector <int> userRoles, unsigned int userCount, AUDIOROOM::ZegoUserUpdateType type);
    void OnPublishStateUpdate(int stateCode, const QString& strStreamID, StreamPtr pStream);
    void OnPlayStateUpdate(int stateCode, StreamPtr pStream);
    void OnAudioDeviceChanged(AV::AudioDeviceType deviceType, const QString& strDeviceId, const QString& strDeviceName, AV::DeviceState state);

protected slots:
	void OnButtonClickedPublish();
	void OnCheckMute();
	void OnCheckTestEnv();
	void OnCheckManualPublish();
	void OnComboBoxValueChanged(int id);
	void OnClose();
	void OnEditedUserID();
	void OnEditedUserName();

private:
	void insertStringListModelItem(QStringListModel * model, QString name, int size);
	void removeStringListModelItem(QStringListModel * model, QString name);
	void startManualPublish();
	void addLogString(const QString& name);
	void switchBeforePublishArea(bool isEnabled);
	QVector<QString> handleStringAppSign(QString appSign);
	void startRestartPublishTimer();
	


private slots:
	void restartPublishStream();

private:
	Ui::ZegoAudioLiveClass ui;
	//�û�����
	QZegoUserConfig m_userConfig;

	//User
	QString m_strEdUserId;
	QString m_strEdUserName;

	//Devices
	QVector<QString> m_vecAudioDeviceIDs;

	//Model
	QStringListModel *m_memberListModel;
	QStringListModel *m_logListModel;

	//�Ƿ��ֶ�����,���Ի�����������Ĭ�ϲ�ʹ��
	bool isManual = false;
	bool isTestEnv = false;
	bool isMute = false;

	//sessionID
	QString m_sessionID;

	//�Ƿ�����ʹ����˷磬Ĭ��ʹ��
	bool m_bEnableMic = true;

	//������ID
	QString m_strPublishStreamID;

	//������
	QVector<StreamPtr> streamList;
	
	//���������
	int maxCount;
	//����
	SettingsPtr m_pCurSettings;
	
	//�Ƿ��Զ���ģʽ
	bool isCustom;
	//����������ʱ��
	QTimer *timer = nullptr;
	//�������������
	int publishCount=0;
	//�Ƿ��Զ���ģʽ
	bool isPrompt = true;
	
};

#endif // ZEGOMAINDIALOG_H
