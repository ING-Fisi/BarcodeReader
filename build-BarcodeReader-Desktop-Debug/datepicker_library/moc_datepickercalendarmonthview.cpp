/****************************************************************************
** Meta object code from reading C++ file 'datepickercalendarmonthview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BarcodeReader/datepicker_library/source/include/datepickercalendarmonthview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datepickercalendarmonthview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatePickerCalendarMonthView_t {
    QByteArrayData data[9];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatePickerCalendarMonthView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatePickerCalendarMonthView_t qt_meta_stringdata_DatePickerCalendarMonthView = {
    {
QT_MOC_LITERAL(0, 0, 27), // "DatePickerCalendarMonthView"
QT_MOC_LITERAL(1, 28, 11), // "dateClicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 4), // "date"
QT_MOC_LITERAL(4, 46, 7), // "setDate"
QT_MOC_LITERAL(5, 54, 9), // "setPeriod"
QT_MOC_LITERAL(6, 64, 5), // "begin"
QT_MOC_LITERAL(7, 70, 3), // "end"
QT_MOC_LITERAL(8, 74, 11) // "shows_begin"

    },
    "DatePickerCalendarMonthView\0dateClicked\0"
    "\0date\0setDate\0setPeriod\0begin\0end\0"
    "shows_begin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatePickerCalendarMonthView[] = {

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
       4,    1,   37,    2, 0x0a /* Public */,
       5,    3,   40,    2, 0x0a /* Public */,
       5,    2,   47,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDate,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate, QMetaType::Bool,    6,    7,    8,
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate,    6,    7,

       0        // eod
};

void DatePickerCalendarMonthView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DatePickerCalendarMonthView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dateClicked((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 1: _t->setDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 2: _t->setPeriod((*reinterpret_cast< const QDate(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->setPeriod((*reinterpret_cast< const QDate(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DatePickerCalendarMonthView::*)(const QDate & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatePickerCalendarMonthView::dateClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DatePickerCalendarMonthView::staticMetaObject = { {
    &QCalendarWidget::staticMetaObject,
    qt_meta_stringdata_DatePickerCalendarMonthView.data,
    qt_meta_data_DatePickerCalendarMonthView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DatePickerCalendarMonthView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatePickerCalendarMonthView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatePickerCalendarMonthView.stringdata0))
        return static_cast<void*>(this);
    return QCalendarWidget::qt_metacast(_clname);
}

int DatePickerCalendarMonthView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCalendarWidget::qt_metacall(_c, _id, _a);
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
void DatePickerCalendarMonthView::dateClicked(const QDate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
