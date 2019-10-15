/****************************************************************************
** Meta object code from reading C++ file 'tcpservier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tcpservier.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpservier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tcpservier_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tcpservier_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tcpservier_t qt_meta_stringdata_Tcpservier = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Tcpservier"
QT_MOC_LITERAL(1, 11, 9), // "Rect_find"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "Rect_photo"
QT_MOC_LITERAL(4, 33, 12), // "onNewConnect"
QT_MOC_LITERAL(5, 46, 13), // "onNewConnect1"
QT_MOC_LITERAL(6, 60, 17), // "onsocketReadyRead"
QT_MOC_LITERAL(7, 78, 18) // "onsocketReadyRead1"

    },
    "Tcpservier\0Rect_find\0\0Rect_photo\0"
    "onNewConnect\0onNewConnect1\0onsocketReadyRead\0"
    "onsocketReadyRead1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tcpservier[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   48,    2, 0x0a /* Public */,
       5,    0,   49,    2, 0x0a /* Public */,
       6,    0,   50,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Tcpservier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tcpservier *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Rect_find(); break;
        case 1: _t->Rect_photo((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->onNewConnect(); break;
        case 3: _t->onNewConnect1(); break;
        case 4: _t->onsocketReadyRead(); break;
        case 5: _t->onsocketReadyRead1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Tcpservier::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tcpservier::Rect_find)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Tcpservier::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tcpservier::Rect_photo)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tcpservier::staticMetaObject = { {
    &QTcpServer::staticMetaObject,
    qt_meta_stringdata_Tcpservier.data,
    qt_meta_data_Tcpservier,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tcpservier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tcpservier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tcpservier.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int Tcpservier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Tcpservier::Rect_find()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Tcpservier::Rect_photo(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
