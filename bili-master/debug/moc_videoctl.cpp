/****************************************************************************
** Meta object code from reading C++ file 'videoctl.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../videoctl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoctl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoCtl_t {
    const uint offsetsAndSize[36];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_VideoCtl_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_VideoCtl_t qt_meta_stringdata_VideoCtl = {
    {
QT_MOC_LITERAL(0, 8), // "VideoCtl"
QT_MOC_LITERAL(9, 10), // "SigPlayMsg"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 6), // "strMsg"
QT_MOC_LITERAL(28, 25), // "SigFrameDimensionsChanged"
QT_MOC_LITERAL(54, 11), // "nFrameWidth"
QT_MOC_LITERAL(66, 12), // "nFrameHeight"
QT_MOC_LITERAL(79, 20), // "SigVideoTotalSeconds"
QT_MOC_LITERAL(100, 8), // "nSeconds"
QT_MOC_LITERAL(109, 19), // "SigVideoPlaySeconds"
QT_MOC_LITERAL(129, 14), // "SigVideoVolume"
QT_MOC_LITERAL(144, 8), // "dPercent"
QT_MOC_LITERAL(153, 12), // "SigPauseStat"
QT_MOC_LITERAL(166, 7), // "bPaused"
QT_MOC_LITERAL(174, 7), // "SigStop"
QT_MOC_LITERAL(182, 15), // "SigStopFinished"
QT_MOC_LITERAL(198, 12), // "SigStartPlay"
QT_MOC_LITERAL(211, 11) // "strFileName"

    },
    "VideoCtl\0SigPlayMsg\0\0strMsg\0"
    "SigFrameDimensionsChanged\0nFrameWidth\0"
    "nFrameHeight\0SigVideoTotalSeconds\0"
    "nSeconds\0SigVideoPlaySeconds\0"
    "SigVideoVolume\0dPercent\0SigPauseStat\0"
    "bPaused\0SigStop\0SigStopFinished\0"
    "SigStartPlay\0strFileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoCtl[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,
       4,    2,   71,    2, 0x06,    3 /* Public */,
       7,    1,   76,    2, 0x06,    6 /* Public */,
       9,    1,   79,    2, 0x06,    8 /* Public */,
      10,    1,   82,    2, 0x06,   10 /* Public */,
      12,    1,   85,    2, 0x06,   12 /* Public */,
      14,    0,   88,    2, 0x06,   14 /* Public */,
      15,    0,   89,    2, 0x06,   15 /* Public */,
      16,    1,   90,    2, 0x06,   16 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void VideoCtl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoCtl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SigPlayMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->SigFrameDimensionsChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->SigVideoTotalSeconds((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->SigVideoPlaySeconds((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->SigVideoVolume((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 5: _t->SigPauseStat((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->SigStop(); break;
        case 7: _t->SigStopFinished(); break;
        case 8: _t->SigStartPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoCtl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoCtl::SigPlayMsg)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoCtl::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoCtl::SigFrameDimensionsChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VideoCtl::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoCtl::SigVideoTotalSeconds)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VideoCtl::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoCtl::SigVideoPlaySeconds)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VideoCtl::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoCtl::SigVideoVolume)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (VideoCtl::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoCtl::SigPauseStat)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (VideoCtl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoCtl::SigStop)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (VideoCtl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoCtl::SigStopFinished)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (VideoCtl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoCtl::SigStartPlay)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject VideoCtl::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_VideoCtl.offsetsAndSize,
    qt_meta_data_VideoCtl,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_VideoCtl_t
, QtPrivate::TypeAndForceComplete<VideoCtl, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>



>,
    nullptr
} };


const QMetaObject *VideoCtl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoCtl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoCtl.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VideoCtl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void VideoCtl::SigPlayMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VideoCtl::SigFrameDimensionsChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VideoCtl::SigVideoTotalSeconds(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VideoCtl::SigVideoPlaySeconds(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void VideoCtl::SigVideoVolume(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void VideoCtl::SigPauseStat(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void VideoCtl::SigStop()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void VideoCtl::SigStopFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void VideoCtl::SigStartPlay(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
