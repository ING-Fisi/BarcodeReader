/****************************************************************************
** Meta object code from reading C++ file 'datepickerpopupfooter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BarcodeReader/datepicker_library/source/include/datepickerpopupfooter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datepickerpopupfooter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatePickerPopupFooter_t {
    QByteArrayData data[10];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatePickerPopupFooter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatePickerPopupFooter_t qt_meta_stringdata_DatePickerPopupFooter = {
    {
QT_MOC_LITERAL(0, 0, 21), // "DatePickerPopupFooter"
QT_MOC_LITERAL(1, 22, 21), // "datePickerTypeChanged"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 14), // "DatePickerType"
QT_MOC_LITERAL(4, 60, 11), // "picker_type"
QT_MOC_LITERAL(5, 72, 21), // "setAllowedPickerTypes"
QT_MOC_LITERAL(6, 94, 15), // "DatePickerTypes"
QT_MOC_LITERAL(7, 110, 12), // "picker_types"
QT_MOC_LITERAL(8, 123, 5), // "reset"
QT_MOC_LITERAL(9, 129, 29) // "onDatePickerTypeButtonClicked"

    },
    "DatePickerPopupFooter\0datePickerTypeChanged\0"
    "\0DatePickerType\0picker_type\0"
    "setAllowedPickerTypes\0DatePickerTypes\0"
    "picker_types\0reset\0onDatePickerTypeButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatePickerPopupFooter[] = {

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
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   37,    2, 0x0a /* Public */,
       8,    0,   40,    2, 0x0a /* Public */,
       9,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DatePickerPopupFooter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DatePickerPopupFooter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->datePickerTypeChanged((*reinterpret_cast< DatePickerType(*)>(_a[1]))); break;
        case 1: _t->setAllowedPickerTypes((*reinterpret_cast< DatePickerTypes(*)>(_a[1]))); break;
        case 2: _t->reset(); break;
        case 3: _t->onDatePickerTypeButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DatePickerPopupFooter::*)(DatePickerType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatePickerPopupFooter::datePickerTypeChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DatePickerPopupFooter::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_DatePickerPopupFooter.data,
    qt_meta_data_DatePickerPopupFooter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DatePickerPopupFooter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatePickerPopupFooter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatePickerPopupFooter.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DatePickerPopupFooter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void DatePickerPopupFooter::datePickerTypeChanged(DatePickerType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
