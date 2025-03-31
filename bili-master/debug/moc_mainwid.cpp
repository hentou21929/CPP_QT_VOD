/****************************************************************************
** Meta object code from reading C++ file 'mainwid.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWid_t {
    const uint offsetsAndSize[22];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWid_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWid_t qt_meta_stringdata_MainWid = {
    {
QT_MOC_LITERAL(0, 7), // "MainWid"
QT_MOC_LITERAL(8, 10), // "SigShowMax"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 6), // "bIfMax"
QT_MOC_LITERAL(27, 14), // "SigSeekForward"
QT_MOC_LITERAL(42, 11), // "SigSeekBack"
QT_MOC_LITERAL(54, 12), // "SigAddVolume"
QT_MOC_LITERAL(67, 12), // "SigSubVolume"
QT_MOC_LITERAL(80, 14), // "SigPlayOrPause"
QT_MOC_LITERAL(95, 11), // "SigOpenFile"
QT_MOC_LITERAL(107, 11) // "strFilename"

    },
    "MainWid\0SigShowMax\0\0bIfMax\0SigSeekForward\0"
    "SigSeekBack\0SigAddVolume\0SigSubVolume\0"
    "SigPlayOrPause\0SigOpenFile\0strFilename"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWid[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       4,    0,   59,    2, 0x06,    3 /* Public */,
       5,    0,   60,    2, 0x06,    4 /* Public */,
       6,    0,   61,    2, 0x06,    5 /* Public */,
       7,    0,   62,    2, 0x06,    6 /* Public */,
       8,    0,   63,    2, 0x06,    7 /* Public */,
       9,    1,   64,    2, 0x06,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void MainWid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWid *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SigShowMax((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->SigSeekForward(); break;
        case 2: _t->SigSeekBack(); break;
        case 3: _t->SigAddVolume(); break;
        case 4: _t->SigSubVolume(); break;
        case 5: _t->SigPlayOrPause(); break;
        case 6: _t->SigOpenFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWid::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWid::SigShowMax)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWid::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWid::SigSeekForward)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWid::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWid::SigSeekBack)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWid::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWid::SigAddVolume)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWid::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWid::SigSubVolume)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWid::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWid::SigPlayOrPause)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWid::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWid::SigOpenFile)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject MainWid::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWid.offsetsAndSize,
    qt_meta_data_MainWid,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWid_t
, QtPrivate::TypeAndForceComplete<MainWid, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>



>,
    nullptr
} };


const QMetaObject *MainWid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWid::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWid.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MainWid::SigShowMax(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWid::SigSeekForward()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWid::SigSeekBack()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWid::SigAddVolume()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWid::SigSubVolume()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWid::SigPlayOrPause()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWid::SigOpenFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
