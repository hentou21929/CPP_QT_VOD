/****************************************************************************
** Meta object code from reading C++ file 'upload.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../upload.h"
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'upload.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_upload_t {
    const uint offsetsAndSize[16];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_upload_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_upload_t qt_meta_stringdata_upload = {
    {
QT_MOC_LITERAL(0, 6), // "upload"
QT_MOC_LITERAL(7, 20), // "on_uploadimg_clicked"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 22), // "on_uploadvideo_clicked"
QT_MOC_LITERAL(52, 19), // "on_upload_2_clicked"
QT_MOC_LITERAL(72, 11), // "uploadToOSS"
QT_MOC_LITERAL(84, 5), // "title"
QT_MOC_LITERAL(90, 21) // "on_pushButton_clicked"

    },
    "upload\0on_uploadimg_clicked\0\0"
    "on_uploadvideo_clicked\0on_upload_2_clicked\0"
    "uploadToOSS\0title\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_upload[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    1,   47,    2, 0x08,    4 /* Private */,
       7,    0,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void upload::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<upload *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_uploadimg_clicked(); break;
        case 1: _t->on_uploadvideo_clicked(); break;
        case 2: _t->on_upload_2_clicked(); break;
        case 3: { int _r = _t->uploadToOSS((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject upload::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_upload.offsetsAndSize,
    qt_meta_data_upload,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_upload_t
, QtPrivate::TypeAndForceComplete<upload, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *upload::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *upload::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_upload.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int upload::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
