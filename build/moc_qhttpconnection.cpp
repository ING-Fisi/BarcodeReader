/****************************************************************************
** Meta object code from reading C++ file 'qhttpconnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qhttpconnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhttpconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QHttpConnection_t {
    QByteArrayData data[11];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QHttpConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QHttpConnection_t qt_meta_stringdata_QHttpConnection = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QHttpConnection"
QT_MOC_LITERAL(1, 16, 10), // "newRequest"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "QHttpRequest*"
QT_MOC_LITERAL(4, 42, 14), // "QHttpResponse*"
QT_MOC_LITERAL(5, 57, 15), // "allBytesWritten"
QT_MOC_LITERAL(6, 73, 12), // "parseRequest"
QT_MOC_LITERAL(7, 86, 12), // "responseDone"
QT_MOC_LITERAL(8, 99, 18), // "socketDisconnected"
QT_MOC_LITERAL(9, 118, 17), // "invalidateRequest"
QT_MOC_LITERAL(10, 136, 16) // "updateWriteCount"

    },
    "QHttpConnection\0newRequest\0\0QHttpRequest*\0"
    "QHttpResponse*\0allBytesWritten\0"
    "parseRequest\0responseDone\0socketDisconnected\0"
    "invalidateRequest\0updateWriteCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QHttpConnection[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   55,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,

       0        // eod
};

void QHttpConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QHttpConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newRequest((*reinterpret_cast< QHttpRequest*(*)>(_a[1])),(*reinterpret_cast< QHttpResponse*(*)>(_a[2]))); break;
        case 1: _t->allBytesWritten(); break;
        case 2: _t->parseRequest(); break;
        case 3: _t->responseDone(); break;
        case 4: _t->socketDisconnected(); break;
        case 5: _t->invalidateRequest(); break;
        case 6: _t->updateWriteCount((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QHttpConnection::*)(QHttpRequest * , QHttpResponse * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QHttpConnection::newRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QHttpConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QHttpConnection::allBytesWritten)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QHttpConnection::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QHttpConnection.data,
    qt_meta_data_QHttpConnection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QHttpConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHttpConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QHttpConnection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QHttpConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QHttpConnection::newRequest(QHttpRequest * _t1, QHttpResponse * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QHttpConnection::allBytesWritten()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
