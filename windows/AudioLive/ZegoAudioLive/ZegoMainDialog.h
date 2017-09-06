#ifndef ZEGOMAINDIALOG_H
#define ZEGOMAINDIALOG_H

#include <QtWidgets/QDialog>
#include <QStringListModel>
#include <QTime>
#include <QMessageBox>
#include "ui_ZegoMainDialog.h"
#include "ZegoUserConfig.h"
#include "ZegoStreamModel.h"
#include "ZegoBase.h"
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

public slots:
	void OnButtonClickedPublish();
	void OnCheckMute();
	void OnCheckTestEnv();
	void OnCheckManualPublish();
	void OnComboBoxValueChanged(int id);
	void OnClose();

private:
	void insertStringListModelItem(QStringListModel * model, QString name, int size);
	void removeStringListModelItem(QStringListModel * model, QString name);
	void startManualPublish();
	void addLogString(const QString& name);
	void switchBeforePublishArea(bool isEnabled);

private:
	Ui::ZegoAudioLiveClass ui;
	//用户配置
	QZegoUserConfig m_userConfig;

	//User
	QString m_strEdUserId;
	QString m_strEdUserName;

	//Devices
	QVector<QString> m_vecAudioDeviceIDs;

	//Model
	QStringListModel *m_memberListModel;
	QStringListModel *m_logListModel;

	//是否手动开播,测试环境，静音，默认不使用
	bool isManual = false;
	bool isTestEnv = false;
	bool isMute = false;

	//sessionID
	QString m_sessionID;

	//是否允许使用麦克风，默认使用
	bool m_bEnableMic = true;

	//推流流ID
	QString m_strPublishStreamID;

	//流数组
	QVector<StreamPtr> streamList;
	
	//最大流数量
	int maxCount;
	//设置
	SettingsPtr m_pCurSettings;
	
	//是否自定义模式
	bool isCustom;
};

#endif // ZEGOMAINDIALOG_H
