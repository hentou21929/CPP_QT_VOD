/****************************************************************************
** Meta object code from reading C++ file 'show.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../show.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'show.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Show_t {
    const uint offsetsAndSize[28];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Show_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Show_t qt_meta_stringdata_Show = {
    {
QT_MOC_LITERAL(0, 4), // "Show"
QT_MOC_LITERAL(5, 11), // "SigOpenFile"
QT_MOC_LITERAL(17, 0), // ""
QT_MOC_LITERAL(18, 11), // "strFileName"
QT_MOC_LITERAL(30, 7), // "SigPlay"
QT_MOC_LITERAL(38, 7), // "strFile"
QT_MOC_LITERAL(46, 13), // "SigFullScreen"
QT_MOC_LITERAL(60, 14), // "SigPlayOrPause"
QT_MOC_LITERAL(75, 7), // "SigStop"
QT_MOC_LITERAL(83, 11), // "SigShowMenu"
QT_MOC_LITERAL(95, 14), // "SigSeekForward"
QT_MOC_LITERAL(110, 11), // "SigSeekBack"
QT_MOC_LITERAL(122, 12), // "SigAddVolume"
QT_MOC_LITERAL(135, 12) // "SigSubVolume"

    },
    "Show\0SigOpenFile\0\0strFileName\0SigPlay\0"
    "strFile\0SigFullScreen\0SigPlayOrPause\0"
    "SigStop\0SigShowMenu\0SigSeekForward\0"
    "SigSeekBack\0SigAddVolume\0SigSubVolume"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Show[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    1,   77,    2, 0x06,    3 /* Public */,
       6,    0,   80,    2, 0x06,    5 /* Public */,
       7,    0,   81,    2, 0x06,    6 /* Public */,
       8,    0,   82,    2, 0x06,    7 /* Public */,
       9,    0,   83,    2, 0x06,    8 /* Public */,
      10,    0,   84,    2, 0x06,    9 /* Public */,
      11,    0,   85,    2, 0x06,   10 /* Public */,
      12,    0,   86,    2, 0x06,   11 /* Public */,
      13,    0,   87,    2, 0x06,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Show::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Show *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SigOpenFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->SigPlay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->SigFullScreen(); break;
        case 3: _t->SigPlayOrPause(); break;
        case 4: _t->SigStop(); break;
        case 5: _t->SigShowMenu(); break;
        case 6: _t->SigSeekForward(); break;
        case 7: _t->SigSeekBack(); break;
        case 8: _t->SigAddVolume(); break;
        case 9: _t->SigSubVolume(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Show::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Show::SigOpenFile)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Show::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Show::SigPlay)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Show::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Show::SigFullScreen)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Show::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Show::SigPlayOrPause)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Show::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Show::SigStop)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Show::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Show::SigShowMenu)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Show::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Show::SigSeekForward)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Show::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Show::SigSeekBack)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Show::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Show::SigAddVolume)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Show::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Show::SigSubVolume)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject Show::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Show.offsetsAndSize,
    qt_meta_data_Show,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Show_t
, QtPrivate::TypeAndForceComplete<Show, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *Show::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Show::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Show.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Show::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Show::SigOpenFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Show::SigPlay(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Show::SigFullScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Show::SigPlayOrPause()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Show::SigStop()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Show::SigShowMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Show::SigSeekForward()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Show::SigSeekBack()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Show::SigAddVolume()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Show::SigSubVolume()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
