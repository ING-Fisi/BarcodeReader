/****************************************************************************
** Meta object code from reading C++ file 'datepickerpopup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BarcodeReader/datepicker_library/source/include/datepickerpopup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datepickerpopup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatePickerPopup_t {
    QByteArrayData data[31];
    char stringdata0[435];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatePickerPopup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatePickerPopup_t qt_meta_stringdata_DatePickerPopup = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DatePickerPopup"
QT_MOC_LITERAL(1, 16, 12), // "dateSelected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "date"
QT_MOC_LITERAL(4, 35, 18), // "datePeriodSelected"
QT_MOC_LITERAL(5, 54, 5), // "begin"
QT_MOC_LITERAL(6, 60, 3), // "end"
QT_MOC_LITERAL(7, 64, 18), // "timePeriodSelected"
QT_MOC_LITERAL(8, 83, 14), // "setMinimumDate"
QT_MOC_LITERAL(9, 98, 14), // "setMaximumDate"
QT_MOC_LITERAL(10, 113, 7), // "setDate"
QT_MOC_LITERAL(11, 121, 13), // "setDatePeriod"
QT_MOC_LITERAL(12, 135, 13), // "setTimePeriod"
QT_MOC_LITERAL(13, 149, 17), // "setDatePickerType"
QT_MOC_LITERAL(14, 167, 14), // "DatePickerType"
QT_MOC_LITERAL(15, 182, 11), // "picker_type"
QT_MOC_LITERAL(16, 194, 21), // "setAllowedPickerTypes"
QT_MOC_LITERAL(17, 216, 15), // "DatePickerTypes"
QT_MOC_LITERAL(18, 232, 12), // "picker_types"
QT_MOC_LITERAL(19, 245, 15), // "setTimeEditable"
QT_MOC_LITERAL(20, 261, 2), // "on"
QT_MOC_LITERAL(21, 264, 18), // "setTimeInputFormat"
QT_MOC_LITERAL(22, 283, 6), // "format"
QT_MOC_LITERAL(23, 290, 5), // "reset"
QT_MOC_LITERAL(24, 296, 23), // "onCalendar1DateSelected"
QT_MOC_LITERAL(25, 320, 23), // "onCalendar2DateSelected"
QT_MOC_LITERAL(26, 344, 19), // "onCalendar1Scrolled"
QT_MOC_LITERAL(27, 364, 19), // "onCalendar2Scrolled"
QT_MOC_LITERAL(28, 384, 22), // "onTimeEdit1TimeChanged"
QT_MOC_LITERAL(29, 407, 4), // "time"
QT_MOC_LITERAL(30, 412, 22) // "onTimeEdit2TimeChanged"

    },
    "DatePickerPopup\0dateSelected\0\0date\0"
    "datePeriodSelected\0begin\0end\0"
    "timePeriodSelected\0setMinimumDate\0"
    "setMaximumDate\0setDate\0setDatePeriod\0"
    "setTimePeriod\0setDatePickerType\0"
    "DatePickerType\0picker_type\0"
    "setAllowedPickerTypes\0DatePickerTypes\0"
    "picker_types\0setTimeEditable\0on\0"
    "setTimeInputFormat\0format\0reset\0"
    "onCalendar1DateSelected\0onCalendar2DateSelected\0"
    "onCalendar1Scrolled\0onCalendar2Scrolled\0"
    "onTimeEdit1TimeChanged\0time\0"
    "onTimeEdit2TimeChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatePickerPopup[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       4,    2,  112,    2, 0x06 /* Public */,
       7,    2,  117,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,  122,    2, 0x0a /* Public */,
       9,    1,  125,    2, 0x0a /* Public */,
      10,    1,  128,    2, 0x0a /* Public */,
      11,    2,  131,    2, 0x0a /* Public */,
      12,    2,  136,    2, 0x0a /* Public */,
      13,    1,  141,    2, 0x0a /* Public */,
      16,    1,  144,    2, 0x0a /* Public */,
      19,    1,  147,    2, 0x0a /* Public */,
      21,    1,  150,    2, 0x0a /* Public */,
      23,    0,  153,    2, 0x0a /* Public */,
      24,    1,  154,    2, 0x08 /* Private */,
      25,    1,  157,    2, 0x08 /* Private */,
      26,    1,  160,    2, 0x08 /* Private */,
      27,    1,  163,    2, 0x08 /* Private */,
      28,    1,  166,    2, 0x08 /* Private */,
      30,    1,  169,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate,    5,    6,
    QMetaType::Void, QMetaType::QTime, QMetaType::QTime,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate,    5,    6,
    QMetaType::Void, QMetaType::QTime, QMetaType::QTime,    5,    6,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, QMetaType::QTime,   29,
    QMetaType::Void, QMetaType::QTime,   29,

       0        // eod
};

void DatePickerPopup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DatePickerPopup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dateSelected((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 1: _t->datePeriodSelected((*reinterpret_cast< const QDate(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2]))); break;
        case 2: _t->timePeriodSelected((*reinterpret_cast< const QTime(*)>(_a[1])),(*reinterpret_cast< const QTime(*)>(_a[2]))); break;
        case 3: _t->setMinimumDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 4: _t->setMaximumDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 5: _t->setDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 6: _t->setDatePeriod((*reinterpret_cast< const QDate(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2]))); break;
        case 7: _t->setTimePeriod((*reinterpret_cast< const QTime(*)>(_a[1])),(*reinterpret_cast< const QTime(*)>(_a[2]))); break;
        case 8: _t->setDatePickerType((*reinterpret_cast< DatePickerType(*)>(_a[1]))); break;
        case 9: _t->setAllowedPickerTypes((*reinterpret_cast< DatePickerTypes(*)>(_a[1]))); break;
        case 10: _t->setTimeEditable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->setTimeInputFormat((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->reset(); break;
        case 13: _t->onCalendar1DateSelected((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 14: _t->onCalendar2DateSelected((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 15: _t->onCalendar1Scrolled((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 16: _t->onCalendar2Scrolled((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 17: _t->onTimeEdit1TimeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 18: _t->onTimeEdit2TimeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DatePickerPopup::*)(const QDate & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatePickerPopup::dateSelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DatePickerPopup::*)(const QDate & , const QDate & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatePickerPopup::datePeriodSelected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DatePickerPopup::*)(const QTime & , const QTime & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatePickerPopup::timePeriodSelected)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DatePickerPopup::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_DatePickerPopup.data,
    qt_meta_data_DatePickerPopup,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DatePickerPopup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatePickerPopup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatePickerPopup.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DatePickerPopup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void DatePickerPopup::dateSelected(const QDate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DatePickerPopup::datePeriodSelected(const QDate & _t1, const QDate & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DatePickerPopup::timePeriodSelected(const QTime & _t1, const QTime & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
