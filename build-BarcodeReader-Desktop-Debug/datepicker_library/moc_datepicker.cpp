/****************************************************************************
** Meta object code from reading C++ file 'datepicker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BarcodeReader/datepicker_library/source/include/datepicker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datepicker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatePicker_t {
    QByteArrayData data[24];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatePicker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatePicker_t qt_meta_stringdata_DatePicker = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DatePicker"
QT_MOC_LITERAL(1, 11, 15), // "editingFinished"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "setEditable"
QT_MOC_LITERAL(4, 40, 2), // "on"
QT_MOC_LITERAL(5, 43, 21), // "setAllowedPickerTypes"
QT_MOC_LITERAL(6, 65, 15), // "DatePickerTypes"
QT_MOC_LITERAL(7, 81, 12), // "picker_types"
QT_MOC_LITERAL(8, 94, 15), // "setTimeEditable"
QT_MOC_LITERAL(9, 110, 18), // "setTimeInputFormat"
QT_MOC_LITERAL(10, 129, 6), // "format"
QT_MOC_LITERAL(11, 136, 14), // "setMinimumDate"
QT_MOC_LITERAL(12, 151, 4), // "date"
QT_MOC_LITERAL(13, 156, 14), // "setMaximumDate"
QT_MOC_LITERAL(14, 171, 8), // "setRange"
QT_MOC_LITERAL(15, 180, 7), // "minimum"
QT_MOC_LITERAL(16, 188, 7), // "maximum"
QT_MOC_LITERAL(17, 196, 7), // "setDate"
QT_MOC_LITERAL(18, 204, 13), // "setDatePeriod"
QT_MOC_LITERAL(19, 218, 5), // "begin"
QT_MOC_LITERAL(20, 224, 3), // "end"
QT_MOC_LITERAL(21, 228, 13), // "setTimePeriod"
QT_MOC_LITERAL(22, 242, 17), // "setDateTimePeriod"
QT_MOC_LITERAL(23, 260, 24) // "onShowPopupButtonClicked"

    },
    "DatePicker\0editingFinished\0\0setEditable\0"
    "on\0setAllowedPickerTypes\0DatePickerTypes\0"
    "picker_types\0setTimeEditable\0"
    "setTimeInputFormat\0format\0setMinimumDate\0"
    "date\0setMaximumDate\0setRange\0minimum\0"
    "maximum\0setDate\0setDatePeriod\0begin\0"
    "end\0setTimePeriod\0setDateTimePeriod\0"
    "onShowPopupButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatePicker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   80,    2, 0x0a /* Public */,
       5,    1,   83,    2, 0x0a /* Public */,
       8,    1,   86,    2, 0x0a /* Public */,
       9,    1,   89,    2, 0x0a /* Public */,
      11,    1,   92,    2, 0x0a /* Public */,
      13,    1,   95,    2, 0x0a /* Public */,
      14,    2,   98,    2, 0x0a /* Public */,
      17,    1,  103,    2, 0x0a /* Public */,
      18,    2,  106,    2, 0x0a /* Public */,
      21,    2,  111,    2, 0x0a /* Public */,
      22,    2,  116,    2, 0x0a /* Public */,
      23,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QDate,   12,
    QMetaType::Void, QMetaType::QDate,   12,
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate,   15,   16,
    QMetaType::Void, QMetaType::QDate,   12,
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate,   19,   20,
    QMetaType::Void, QMetaType::QTime, QMetaType::QTime,   19,   20,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime,   19,   20,
    QMetaType::Void,

       0        // eod
};

void DatePicker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DatePicker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->editingFinished(); break;
        case 1: _t->setEditable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setAllowedPickerTypes((*reinterpret_cast< DatePickerTypes(*)>(_a[1]))); break;
        case 3: _t->setTimeEditable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setTimeInputFormat((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setMinimumDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 6: _t->setMaximumDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 7: _t->setRange((*reinterpret_cast< const QDate(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2]))); break;
        case 8: _t->setDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 9: _t->setDatePeriod((*reinterpret_cast< const QDate(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2]))); break;
        case 10: _t->setTimePeriod((*reinterpret_cast< const QTime(*)>(_a[1])),(*reinterpret_cast< const QTime(*)>(_a[2]))); break;
        case 11: _t->setDateTimePeriod((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2]))); break;
        case 12: _t->onShowPopupButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DatePicker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatePicker::editingFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DatePicker::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_DatePicker.data,
    qt_meta_data_DatePicker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DatePicker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatePicker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatePicker.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DatePicker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void DatePicker::editingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
