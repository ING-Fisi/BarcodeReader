/****************************************************************************
** Meta object code from reading C++ file 'newqrcodedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BarcodeReader/newqrcodedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newqrcodedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewQrCodeDialog_t {
    QByteArrayData data[16];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewQrCodeDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewQrCodeDialog_t qt_meta_stringdata_NewQrCodeDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NewQrCodeDialog"
QT_MOC_LITERAL(1, 16, 15), // "QRCodeGenerated"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "Name"
QT_MOC_LITERAL(4, 38, 7), // "Surname"
QT_MOC_LITERAL(5, 46, 11), // "PhoneNumber"
QT_MOC_LITERAL(6, 58, 5), // "Email"
QT_MOC_LITERAL(7, 64, 12), // "StartingDate"
QT_MOC_LITERAL(8, 77, 12), // "StartingTime"
QT_MOC_LITERAL(9, 90, 12), // "ExpiringDate"
QT_MOC_LITERAL(10, 103, 12), // "ExpiringTime"
QT_MOC_LITERAL(11, 116, 24), // "on_pB_generateQR_clicked"
QT_MOC_LITERAL(12, 141, 11), // "checkFormat"
QT_MOC_LITERAL(13, 153, 4), // "text"
QT_MOC_LITERAL(14, 158, 25), // "on_calendarWidget_clicked"
QT_MOC_LITERAL(15, 184, 4) // "date"

    },
    "NewQrCodeDialog\0QRCodeGenerated\0\0Name\0"
    "Surname\0PhoneNumber\0Email\0StartingDate\0"
    "StartingTime\0ExpiringDate\0ExpiringTime\0"
    "on_pB_generateQR_clicked\0checkFormat\0"
    "text\0on_calendarWidget_clicked\0date"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewQrCodeDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    8,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   51,    2, 0x08 /* Private */,
      12,    1,   52,    2, 0x08 /* Private */,
      14,    1,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,    9,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QDate,   15,

       0        // eod
};

void NewQrCodeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewQrCodeDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->QRCodeGenerated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8]))); break;
        case 1: _t->on_pB_generateQR_clicked(); break;
        case 2: { QString _r = _t->checkFormat((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->on_calendarWidget_clicked((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NewQrCodeDialog::*)(const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NewQrCodeDialog::QRCodeGenerated)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NewQrCodeDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_NewQrCodeDialog.data,
    qt_meta_data_NewQrCodeDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NewQrCodeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewQrCodeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewQrCodeDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int NewQrCodeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void NewQrCodeDialog::QRCodeGenerated(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QString & _t5, const QString & _t6, const QString & _t7, const QString & _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
