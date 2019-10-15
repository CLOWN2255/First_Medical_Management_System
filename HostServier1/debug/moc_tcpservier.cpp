/****************************************************************************
** Meta object code from reading C++ file 'tcpservier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpservier.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpservier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tcpservier_t {
    QByteArrayData data[7];
    char stringdata0[86];
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
QT_MOC_LITERAL(3, 22, 12), // "onNewConnect"
QT_MOC_LITERAL(4, 35, 13), // "onNewConnect1"
QT_MOC_LITERAL(5, 49, 17), // "onsocketReadyRead"
QT_MOC_LITERAL(6, 67, 18) // "onsocketReadyRead1"

    },
    "Tcpservier\0Rect_find\0\0onNewConnect\0"
    "onNewConnect1\0onsocketReadyRead\0"
    "onsocketReadyRead1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tcpservier[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

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
        Tcpservier *_t = static_cast<Tcpservier *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Rect_find(); break;
        case 1: _t->onNewConnect(); break;
        case 2: _t->onNewConnect1(); break;
        case 3: _t->onsocketReadyRead(); break;
        case 4: _t->onsocketReadyRead1(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Tcpservier::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tcpservier::Rect_find)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Tcpservier::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_Tcpservier.data,
      qt_meta_data_Tcpservier,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Tcpservier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tcpservier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tcpservier.stringdata0))
        return static_cast<void*>(const_cast< Tcpservier*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int Tcpservier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Tcpservier::Rect_find()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
