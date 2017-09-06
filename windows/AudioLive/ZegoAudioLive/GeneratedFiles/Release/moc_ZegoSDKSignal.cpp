/****************************************************************************
** Meta object code from reading C++ file 'ZegoSDKSignal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Signal/ZegoSDKSignal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZegoSDKSignal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QZegoSDKSignal_t {
    QByteArrayData data[34];
    char stringdata0[445];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QZegoSDKSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QZegoSDKSignal_t qt_meta_stringdata_QZegoSDKSignal = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QZegoSDKSignal"
QT_MOC_LITERAL(1, 15, 12), // "sigLoginRoom"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 9), // "errorCode"
QT_MOC_LITERAL(4, 39, 6), // "roomID"
QT_MOC_LITERAL(5, 46, 13), // "sigDisconnect"
QT_MOC_LITERAL(6, 60, 10), // "sigKickOut"
QT_MOC_LITERAL(7, 71, 6), // "reason"
QT_MOC_LITERAL(8, 78, 15), // "sigStreamUpdate"
QT_MOC_LITERAL(9, 94, 9), // "strRoomID"
QT_MOC_LITERAL(10, 104, 9), // "StreamPtr"
QT_MOC_LITERAL(11, 114, 7), // "pStream"
QT_MOC_LITERAL(12, 122, 31), // "AUDIOROOM::ZegoStreamUpdateType"
QT_MOC_LITERAL(13, 154, 4), // "type"
QT_MOC_LITERAL(14, 159, 13), // "sigUserUpdate"
QT_MOC_LITERAL(15, 173, 16), // "QVector<QString>"
QT_MOC_LITERAL(16, 190, 7), // "userIDs"
QT_MOC_LITERAL(17, 198, 9), // "userNames"
QT_MOC_LITERAL(18, 208, 12), // "QVector<int>"
QT_MOC_LITERAL(19, 221, 9), // "userFlags"
QT_MOC_LITERAL(20, 231, 9), // "userRoles"
QT_MOC_LITERAL(21, 241, 9), // "userCount"
QT_MOC_LITERAL(22, 251, 29), // "AUDIOROOM::ZegoUserUpdateType"
QT_MOC_LITERAL(23, 281, 21), // "sigPublishStateUpdate"
QT_MOC_LITERAL(24, 303, 9), // "stateCode"
QT_MOC_LITERAL(25, 313, 11), // "strStreamID"
QT_MOC_LITERAL(26, 325, 18), // "sigPlayStateUpdate"
QT_MOC_LITERAL(27, 344, 21), // "sigAudioDeviceChanged"
QT_MOC_LITERAL(28, 366, 19), // "AV::AudioDeviceType"
QT_MOC_LITERAL(29, 386, 10), // "deviceType"
QT_MOC_LITERAL(30, 397, 11), // "strDeviceId"
QT_MOC_LITERAL(31, 409, 13), // "strDeviceName"
QT_MOC_LITERAL(32, 423, 15), // "AV::DeviceState"
QT_MOC_LITERAL(33, 439, 5) // "state"

    },
    "QZegoSDKSignal\0sigLoginRoom\0\0errorCode\0"
    "roomID\0sigDisconnect\0sigKickOut\0reason\0"
    "sigStreamUpdate\0strRoomID\0StreamPtr\0"
    "pStream\0AUDIOROOM::ZegoStreamUpdateType\0"
    "type\0sigUserUpdate\0QVector<QString>\0"
    "userIDs\0userNames\0QVector<int>\0userFlags\0"
    "userRoles\0userCount\0AUDIOROOM::ZegoUserUpdateType\0"
    "sigPublishStateUpdate\0stateCode\0"
    "strStreamID\0sigPlayStateUpdate\0"
    "sigAudioDeviceChanged\0AV::AudioDeviceType\0"
    "deviceType\0strDeviceId\0strDeviceName\0"
    "AV::DeviceState\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QZegoSDKSignal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       5,    2,   59,    2, 0x06 /* Public */,
       6,    2,   64,    2, 0x06 /* Public */,
       8,    3,   69,    2, 0x06 /* Public */,
      14,    6,   76,    2, 0x06 /* Public */,
      23,    3,   89,    2, 0x06 /* Public */,
      26,    2,   96,    2, 0x06 /* Public */,
      27,    4,  101,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    7,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10, 0x80000000 | 12,    9,   11,   13,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 18, 0x80000000 | 18, QMetaType::UInt, 0x80000000 | 22,   16,   17,   19,   20,   21,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 10,   24,   25,   11,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 10,   24,   11,
    QMetaType::Void, 0x80000000 | 28, QMetaType::QString, QMetaType::QString, 0x80000000 | 32,   29,   30,   31,   33,

       0        // eod
};

void QZegoSDKSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QZegoSDKSignal *_t = static_cast<QZegoSDKSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigLoginRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->sigDisconnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->sigKickOut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->sigStreamUpdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< StreamPtr(*)>(_a[2])),(*reinterpret_cast< AUDIOROOM::ZegoStreamUpdateType(*)>(_a[3]))); break;
        case 4: _t->sigUserUpdate((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3])),(*reinterpret_cast< QVector<int>(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< AUDIOROOM::ZegoUserUpdateType(*)>(_a[6]))); break;
        case 5: _t->sigPublishStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< StreamPtr(*)>(_a[3]))); break;
        case 6: _t->sigPlayStateUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StreamPtr(*)>(_a[2]))); break;
        case 7: _t->sigAudioDeviceChanged((*reinterpret_cast< AV::AudioDeviceType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< AV::DeviceState(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            case 3:
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QZegoSDKSignal::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QZegoSDKSignal::sigLoginRoom)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QZegoSDKSignal::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QZegoSDKSignal::sigDisconnect)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QZegoSDKSignal::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QZegoSDKSignal::sigKickOut)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QZegoSDKSignal::*_t)(const QString & , StreamPtr , AUDIOROOM::ZegoStreamUpdateType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QZegoSDKSignal::sigStreamUpdate)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QZegoSDKSignal::*_t)(QVector<QString> , QVector<QString> , QVector<int> , QVector<int> , unsigned int , AUDIOROOM::ZegoUserUpdateType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QZegoSDKSignal::sigUserUpdate)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QZegoSDKSignal::*_t)(int , const QString & , StreamPtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QZegoSDKSignal::sigPublishStateUpdate)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (QZegoSDKSignal::*_t)(int , StreamPtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QZegoSDKSignal::sigPlayStateUpdate)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (QZegoSDKSignal::*_t)(AV::AudioDeviceType , const QString & , const QString & , AV::DeviceState );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QZegoSDKSignal::sigAudioDeviceChanged)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject QZegoSDKSignal::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QZegoSDKSignal.data,
      qt_meta_data_QZegoSDKSignal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QZegoSDKSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QZegoSDKSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QZegoSDKSignal.stringdata0))
        return static_cast<void*>(const_cast< QZegoSDKSignal*>(this));
    if (!strcmp(_clname, "AUDIOROOM::IAudioRoomCallback"))
        return static_cast< AUDIOROOM::IAudioRoomCallback*>(const_cast< QZegoSDKSignal*>(this));
    if (!strcmp(_clname, "AUDIOROOM::IAudioEngineCallback"))
        return static_cast< AUDIOROOM::IAudioEngineCallback*>(const_cast< QZegoSDKSignal*>(this));
    if (!strcmp(_clname, "AUDIOROOM::IAudioLivePublisherCallback"))
        return static_cast< AUDIOROOM::IAudioLivePublisherCallback*>(const_cast< QZegoSDKSignal*>(this));
    if (!strcmp(_clname, "AUDIOROOM::IAudioLivePlayerCallback"))
        return static_cast< AUDIOROOM::IAudioLivePlayerCallback*>(const_cast< QZegoSDKSignal*>(this));
    if (!strcmp(_clname, "AV::IZegoDeviceStateCallback"))
        return static_cast< AV::IZegoDeviceStateCallback*>(const_cast< QZegoSDKSignal*>(this));
    if (!strcmp(_clname, "AV::IZegoAudioRecordCallback"))
        return static_cast< AV::IZegoAudioRecordCallback*>(const_cast< QZegoSDKSignal*>(this));
    if (!strcmp(_clname, "AV::IZegoLiveEventCallback"))
        return static_cast< AV::IZegoLiveEventCallback*>(const_cast< QZegoSDKSignal*>(this));
    return QObject::qt_metacast(_clname);
}

int QZegoSDKSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QZegoSDKSignal::sigLoginRoom(int _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QZegoSDKSignal::sigDisconnect(int _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QZegoSDKSignal::sigKickOut(int _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QZegoSDKSignal::sigStreamUpdate(const QString & _t1, StreamPtr _t2, AUDIOROOM::ZegoStreamUpdateType _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QZegoSDKSignal::sigUserUpdate(QVector<QString> _t1, QVector<QString> _t2, QVector<int> _t3, QVector<int> _t4, unsigned int _t5, AUDIOROOM::ZegoUserUpdateType _t6)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QZegoSDKSignal::sigPublishStateUpdate(int _t1, const QString & _t2, StreamPtr _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QZegoSDKSignal::sigPlayStateUpdate(int _t1, StreamPtr _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QZegoSDKSignal::sigAudioDeviceChanged(AV::AudioDeviceType _t1, const QString & _t2, const QString & _t3, AV::DeviceState _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
