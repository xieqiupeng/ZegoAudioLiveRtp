/********************************************************************************
** Form generated from reading UI file 'ZegoMainDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEGOMAINDIALOG_H
#define UI_ZEGOMAINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZegoAudioLiveClass
{
public:
    QHBoxLayout *horizontalLayout_7;
    QWidget *m_AreaBeforePublish;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *m_lbUserID;
    QLineEdit *m_edUserID;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout_3;
    QLabel *m_lbUserName;
    QLineEdit *m_edUserName;
    QSpacerItem *verticalSpacer_2;
    QFormLayout *formLayout_2;
    QLabel *m_lbAppID;
    QLineEdit *m_edAppID;
    QSpacerItem *verticalSpacer_5;
    QFormLayout *formLayout_4;
    QLabel *m_lbAppSign;
    QTextEdit *m_edAppSign;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QComboBox *m_cbAppVersion;
    QSpacerItem *horizontalSpacer;
    QCheckBox *m_checkTestEnv;
    QCheckBox *m_checkManual;
    QCheckBox *m_checkMute;
    QSpacerItem *verticalSpacer_4;
    QListView *m_logList;
    QSpacerItem *verticalSpacer_7;
    QFrame *m_line;
    QWidget *m_AreaAfterPublish;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QListView *m_memberList;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *m_edSessionID;
    QPushButton *m_switchStartPublish;

    void setupUi(QDialog *ZegoAudioLiveClass)
    {
        if (ZegoAudioLiveClass->objectName().isEmpty())
            ZegoAudioLiveClass->setObjectName(QStringLiteral("ZegoAudioLiveClass"));
        ZegoAudioLiveClass->resize(1048, 700);
        horizontalLayout_7 = new QHBoxLayout(ZegoAudioLiveClass);
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        m_AreaBeforePublish = new QWidget(ZegoAudioLiveClass);
        m_AreaBeforePublish->setObjectName(QStringLiteral("m_AreaBeforePublish"));
        verticalLayout_3 = new QVBoxLayout(m_AreaBeforePublish);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, 0);
        verticalSpacer_6 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(27);
        formLayout->setVerticalSpacing(9);
        m_lbUserID = new QLabel(m_AreaBeforePublish);
        m_lbUserID->setObjectName(QStringLiteral("m_lbUserID"));
        m_lbUserID->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 16px;"));

        formLayout->setWidget(0, QFormLayout::LabelRole, m_lbUserID);

        m_edUserID = new QLineEdit(m_AreaBeforePublish);
        m_edUserID->setObjectName(QStringLiteral("m_edUserID"));
        m_edUserID->setMinimumSize(QSize(508, 32));
        m_edUserID->setMaximumSize(QSize(508, 32));
        m_edUserID->setFocusPolicy(Qt::ClickFocus);

        formLayout->setWidget(0, QFormLayout::FieldRole, m_edUserID);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setHorizontalSpacing(28);
        formLayout_3->setVerticalSpacing(9);
        m_lbUserName = new QLabel(m_AreaBeforePublish);
        m_lbUserName->setObjectName(QStringLiteral("m_lbUserName"));
        m_lbUserName->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 16px;"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, m_lbUserName);

        m_edUserName = new QLineEdit(m_AreaBeforePublish);
        m_edUserName->setObjectName(QStringLiteral("m_edUserName"));
        m_edUserName->setMinimumSize(QSize(508, 32));
        m_edUserName->setMaximumSize(QSize(508, 32));
        m_edUserName->setFocusPolicy(Qt::ClickFocus);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, m_edUserName);


        verticalLayout->addLayout(formLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setHorizontalSpacing(25);
        formLayout_2->setVerticalSpacing(0);
        m_lbAppID = new QLabel(m_AreaBeforePublish);
        m_lbAppID->setObjectName(QStringLiteral("m_lbAppID"));
        m_lbAppID->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 16px;"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, m_lbAppID);

        m_edAppID = new QLineEdit(m_AreaBeforePublish);
        m_edAppID->setObjectName(QStringLiteral("m_edAppID"));
        m_edAppID->setMinimumSize(QSize(508, 32));
        m_edAppID->setMaximumSize(QSize(508, 32));
        m_edAppID->setFocusPolicy(Qt::ClickFocus);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, m_edAppID);


        verticalLayout_2->addLayout(formLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_5);

        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setHorizontalSpacing(10);
        formLayout_4->setVerticalSpacing(0);
        m_lbAppSign = new QLabel(m_AreaBeforePublish);
        m_lbAppSign->setObjectName(QStringLiteral("m_lbAppSign"));
        m_lbAppSign->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 16px;"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, m_lbAppSign);

        m_edAppSign = new QTextEdit(m_AreaBeforePublish);
        m_edAppSign->setObjectName(QStringLiteral("m_edAppSign"));
        m_edAppSign->setMinimumSize(QSize(508, 158));
        m_edAppSign->setMaximumSize(QSize(508, 158));
        m_edAppSign->setFocusPolicy(Qt::ClickFocus);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, m_edAppSign);


        verticalLayout_2->addLayout(formLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_cbAppVersion = new QComboBox(m_AreaBeforePublish);
        m_cbAppVersion->setObjectName(QStringLiteral("m_cbAppVersion"));
        m_cbAppVersion->setMinimumSize(QSize(128, 32));
        m_cbAppVersion->setMaximumSize(QSize(128, 32));

        horizontalLayout->addWidget(m_cbAppVersion);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_checkTestEnv = new QCheckBox(m_AreaBeforePublish);
        m_checkTestEnv->setObjectName(QStringLiteral("m_checkTestEnv"));
        m_checkTestEnv->setMinimumSize(QSize(127, 25));
        m_checkTestEnv->setMaximumSize(QSize(127, 25));
        m_checkTestEnv->setFocusPolicy(Qt::ClickFocus);
        m_checkTestEnv->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 16px;"));

        horizontalLayout->addWidget(m_checkTestEnv);

        m_checkManual = new QCheckBox(m_AreaBeforePublish);
        m_checkManual->setObjectName(QStringLiteral("m_checkManual"));
        m_checkManual->setMinimumSize(QSize(127, 25));
        m_checkManual->setMaximumSize(QSize(127, 25));
        m_checkManual->setFocusPolicy(Qt::ClickFocus);
        m_checkManual->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 16px;"));

        horizontalLayout->addWidget(m_checkManual);

        m_checkMute = new QCheckBox(m_AreaBeforePublish);
        m_checkMute->setObjectName(QStringLiteral("m_checkMute"));
        m_checkMute->setMinimumSize(QSize(128, 25));
        m_checkMute->setMaximumSize(QSize(128, 25));
        m_checkMute->setFocusPolicy(Qt::ClickFocus);
        m_checkMute->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 16px;"));

        horizontalLayout->addWidget(m_checkMute);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        m_logList = new QListView(m_AreaBeforePublish);
        m_logList->setObjectName(QStringLiteral("m_logList"));
        m_logList->setMinimumSize(QSize(588, 158));
        m_logList->setMaximumSize(QSize(588, 16777215));
        m_logList->setStyleSheet(QLatin1String("border-radius: 5px;\n"
"border: 1px solid gray;"));

        verticalLayout_2->addWidget(m_logList);

        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_7);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_7->addWidget(m_AreaBeforePublish);

        m_line = new QFrame(ZegoAudioLiveClass);
        m_line->setObjectName(QStringLiteral("m_line"));
        m_line->setStyleSheet(QLatin1String("margin-top: 13px;\n"
"margin-bottom: 13px;"));
        m_line->setFrameShape(QFrame::VLine);
        m_line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(m_line);

        m_AreaAfterPublish = new QWidget(ZegoAudioLiveClass);
        m_AreaAfterPublish->setObjectName(QStringLiteral("m_AreaAfterPublish"));
        verticalLayout_7 = new QVBoxLayout(m_AreaAfterPublish);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, -1, -1, 20);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(30);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        m_memberList = new QListView(m_AreaAfterPublish);
        m_memberList->setObjectName(QStringLiteral("m_memberList"));
        m_memberList->setMinimumSize(QSize(380, 0));
        m_memberList->setStyleSheet(QLatin1String("border-radius: 5px;\n"
"border: 1px solid gray;"));

        verticalLayout_4->addWidget(m_memberList);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(20);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        m_edSessionID = new QLineEdit(m_AreaAfterPublish);
        m_edSessionID->setObjectName(QStringLiteral("m_edSessionID"));
        m_edSessionID->setMinimumSize(QSize(246, 27));
        m_edSessionID->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 16px;"));

        horizontalLayout_6->addWidget(m_edSessionID);

        m_switchStartPublish = new QPushButton(m_AreaAfterPublish);
        m_switchStartPublish->setObjectName(QStringLiteral("m_switchStartPublish"));
        m_switchStartPublish->setMinimumSize(QSize(112, 34));
        m_switchStartPublish->setStyleSheet(QString::fromUtf8("font-family: \345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size: 16px;"));

        horizontalLayout_6->addWidget(m_switchStartPublish);


        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_7->addLayout(verticalLayout_4);


        horizontalLayout_7->addWidget(m_AreaAfterPublish);

        horizontalLayout_7->setStretch(0, 3);
        horizontalLayout_7->setStretch(2, 2);

        retranslateUi(ZegoAudioLiveClass);

        QMetaObject::connectSlotsByName(ZegoAudioLiveClass);
    } // setupUi

    void retranslateUi(QDialog *ZegoAudioLiveClass)
    {
        ZegoAudioLiveClass->setWindowTitle(QApplication::translate("ZegoAudioLiveClass", "ZegoAudioLive", Q_NULLPTR));
        m_lbUserID->setText(QApplication::translate("ZegoAudioLiveClass", "\347\224\250\346\210\267ID", Q_NULLPTR));
        m_lbUserName->setText(QApplication::translate("ZegoAudioLiveClass", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        m_lbAppID->setText(QApplication::translate("ZegoAudioLiveClass", "App ID", Q_NULLPTR));
        m_edAppID->setPlaceholderText(QApplication::translate("ZegoAudioLiveClass", "\350\257\267\350\276\223\345\205\245AppID", Q_NULLPTR));
        m_lbAppSign->setText(QApplication::translate("ZegoAudioLiveClass", "App Sign", Q_NULLPTR));
        m_edAppSign->setPlaceholderText(QApplication::translate("ZegoAudioLiveClass", "\350\257\267\350\276\223\345\205\245AppSign", Q_NULLPTR));
        m_checkTestEnv->setText(QApplication::translate("ZegoAudioLiveClass", "\346\265\213\350\257\225\347\216\257\345\242\203", Q_NULLPTR));
        m_checkManual->setText(QApplication::translate("ZegoAudioLiveClass", "\346\211\213\345\212\250\345\274\200\346\222\255", Q_NULLPTR));
        m_checkMute->setText(QApplication::translate("ZegoAudioLiveClass", "\351\235\231\351\237\263", Q_NULLPTR));
        m_edSessionID->setPlaceholderText(QApplication::translate("ZegoAudioLiveClass", "\350\257\267\350\276\223\345\205\245SessionID", Q_NULLPTR));
        m_switchStartPublish->setText(QApplication::translate("ZegoAudioLiveClass", "\350\277\233\345\205\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ZegoAudioLiveClass: public Ui_ZegoAudioLiveClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEGOMAINDIALOG_H
