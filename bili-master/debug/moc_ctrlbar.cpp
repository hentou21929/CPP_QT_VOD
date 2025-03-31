/****************************************************************************
** Meta object code from reading C++ file 'ctrlbar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ctrlbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ctrlbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CtrlBar_t {
    const uint offsetsAndSize[34];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CtrlBar_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CtrlBar_t qt_meta_stringdata_CtrlBar = {
    {
QT_MOC_LITERAL(0, 7), // "CtrlBar"
QT_MOC_LITERAL(8, 21), // "SigShowOrHidePlaylist"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 11), // "SigPlaySeek"
QT_MOC_LITERAL(43, 8), // "dPercent"
QT_MOC_LITERAL(52, 13), // "SigPlayVolume"
QT_MOC_LITERAL(66, 14), // "SigPlayOrPause"
QT_MOC_LITERAL(81, 7), // "SigStop"
QT_MOC_LITERAL(89, 14), // "SigForwardPlay"
QT_MOC_LITERAL(104, 15), // "SigBackwardPlay"
QT_MOC_LITERAL(120, 11), // "SigShowMenu"
QT_MOC_LITERAL(132, 14), // "SigShowSetting"
QT_MOC_LITERAL(147, 25), // "on_PlayOrPauseBtn_clicked"
QT_MOC_LITERAL(173, 20), // "on_VolumeBtn_clicked"
QT_MOC_LITERAL(194, 18), // "on_StopBtn_clicked"
QT_MOC_LITERAL(213, 21), // "on_SettingBtn_clicked"
QT_MOC_LITERAL(235, 18) // "ConnectSignalSlots"

    },
    "CtrlBar\0SigShowOrHidePlaylist\0\0"
    "SigPlaySeek\0dPercent\0SigPlayVolume\0"
    "SigPlayOrPause\0SigStop\0SigForwardPlay\0"
    "SigBackwardPlay\0SigShowMenu\0SigShowSetting\0"
    "on_PlayOrPauseBtn_clicked\0"
    "on_VolumeBtn_clicked\0on_StopBtn_clicked\0"
    "on_SettingBtn_clicked\0ConnectSignalSlots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CtrlBar[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    1 /* Public */,
       3,    1,   99,    2, 0x06,    2 /* Public */,
       5,    1,  102,    2, 0x06,    4 /* Public */,
       6,    0,  105,    2, 0x06,    6 /* Public */,
       7,    0,  106,    2, 0x06,    7 /* Public */,
       8,    0,  107,    2, 0x06,    8 /* Public */,
       9,    0,  108,    2, 0x06,    9 /* Public */,
      10,    0,  109,    2, 0x06,   10 /* Public */,
      11,    0,  110,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,  111,    2, 0x08,   12 /* Private */,
      13,    0,  112,    2, 0x08,   13 /* Private */,
      14,    0,  113,    2, 0x08,   14 /* Private */,
      15,    0,  114,    2, 0x08,   15 /* Private */,
      16,    0,  115,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void CtrlBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CtrlBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SigShowOrHidePlaylist(); break;
        case 1: _t->SigPlaySeek((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->SigPlayVolume((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 3: _t->SigPlayOrPause(); break;
        case 4: _t->SigStop(); break;
        case 5: _t->SigForwardPlay(); break;
        case 6: _t->SigBackwardPlay(); break;
        case 7: _t->SigShowMenu(); break;
        case 8: _t->SigShowSetting(); break;
        case 9: _t->on_PlayOrPauseBtn_clicked(); break;
        case 10: _t->on_VolumeBtn_clicked(); break;
        case 11: _t->on_StopBtn_clicked(); break;
        case 12: _t->on_SettingBtn_clicked(); break;
        case 13: { bool _r = _t->ConnectSignalSlots();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CtrlBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CtrlBar::SigShowOrHidePlaylist)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CtrlBar::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CtrlBar::SigPlaySeek)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CtrlBar::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CtrlBar::SigPlayVolume)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CtrlBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CtrlBar::SigPlayOrPause)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CtrlBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CtrlBar::SigStop)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CtrlBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CtrlBar::SigForwardPlay)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CtrlBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CtrlBar::SigBackwardPlay)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CtrlBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CtrlBar::SigShowMenu)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CtrlBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CtrlBar::SigShowSetting)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject CtrlBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CtrlBar.offsetsAndSize,
    qt_meta_data_CtrlBar,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CtrlBar_t
, QtPrivate::TypeAndForceComplete<CtrlBar, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *CtrlBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CtrlBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CtrlBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CtrlBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void CtrlBar::SigShowOrHidePlaylist()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CtrlBar::SigPlaySeek(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CtrlBar::SigPlayVolume(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CtrlBar::SigPlayOrPause()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CtrlBar::SigStop()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CtrlBar::SigForwardPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void CtrlBar::SigBackwardPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void CtrlBar::SigShowMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void CtrlBar::SigShowSetting()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
