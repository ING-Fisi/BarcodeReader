/****************************************************************************
** Meta object code from reading C++ file 'datepickercalendarnavigator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BarcodeReader/datepicker_library/source/include/datepickercalendarnavigator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datepickercalendarnavigator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatePickerCalendarNavigator_t {
    QByteArrayData data[14];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatePickerCalendarNavigator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatePickerCalendarNavigator_t qt_meta_stringdata_DatePickerCalendarNavigator = {
    {
QT_MOC_LITERAL(0, 0, 27), // "DatePickerCalendarNavigator"
QT_MOC_LITERAL(1, 28, 11), // "viewChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 14), // "DatePickerView"
QT_MOC_LITERAL(4, 56, 4), // "view"
QT_MOC_LITERAL(5, 61, 10), // "toPrevious"
QT_MOC_LITERAL(6, 72, 6), // "toNext"
QT_MOC_LITERAL(7, 79, 7), // "setView"
QT_MOC_LITERAL(8, 87, 7), // "setDate"
QT_MOC_LITERAL(9, 95, 4), // "date"
QT_MOC_LITERAL(10, 100, 5), // "reset"
QT_MOC_LITERAL(11, 106, 23), // "onPreviousButtonClicked"
QT_MOC_LITERAL(12, 130, 19), // "onNextButtonClicked"
QT_MOC_LITERAL(13, 150, 22) // "onCurrentButtonClicked"

    },
    "DatePickerCalendarNavigator\0viewChanged\0"
    "\0DatePickerView\0view\0toPrevious\0toNext\0"
    "setView\0setDate\0date\0reset\0"
    "onPreviousButtonClicked\0onNextButtonClicked\0"
    "onCurrentButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatePickerCalendarNavigator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   64,    2, 0x0a /* Public */,
       8,    1,   67,    2, 0x0a /* Public */,
      10,    0,   70,    2, 0x0a /* Public */,
      11,    0,   71,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QDate,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DatePickerCalendarNavigator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DatePickerCalendarNavigator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->viewChanged((*reinterpret_cast< DatePickerView(*)>(_a[1]))); break;
        case 1: _t->toPrevious(); break;
        case 2: _t->toNext(); break;
        case 3: _t->setView((*reinterpret_cast< DatePickerView(*)>(_a[1]))); break;
        case 4: _t->setDate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 5: _t->reset(); break;
        case 6: _t->onPreviousButtonClicked(); break;
        case 7: _t->onNextButtonClicked(); break;
        case 8: _t->onCurrentButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DatePickerCalendarNavigator::*)(DatePickerView );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatePickerCalendarNavigator::viewChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DatePickerCalendarNavigator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatePickerCalendarNavigator::toPrevious)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DatePickerCalendarNavigator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatePickerCalendarNavigator::toNext)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DatePickerCalendarNavigator::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_DatePickerCalendarNavigator.data,
    qt_meta_data_DatePickerCalendarNavigator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DatePickerCalendarNavigator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatePickerCalendarNavigator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatePickerCalendarNavigator.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DatePickerCalendarNavigator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DatePickerCalendarNavigator::viewChanged(DatePickerView _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DatePickerCalendarNavigator::toPrevious()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DatePickerCalendarNavigator::toNext()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
