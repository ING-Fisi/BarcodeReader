/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BarcodeReader/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[81];
    char stringdata0[1170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "checkDirectories"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "checkDirectory"
QT_MOC_LITERAL(4, 44, 13), // "directoryPath"
QT_MOC_LITERAL(5, 58, 19), // "openAddReaderDialog"
QT_MOC_LITERAL(6, 78, 16), // "updateMainWindow"
QT_MOC_LITERAL(7, 95, 23), // "on_pB_addReader_clicked"
QT_MOC_LITERAL(8, 119, 8), // "checkMAC"
QT_MOC_LITERAL(9, 128, 15), // "receivedMacAddr"
QT_MOC_LITERAL(10, 144, 11), // "getReaderID"
QT_MOC_LITERAL(11, 156, 14), // "onTimerTimeout"
QT_MOC_LITERAL(12, 171, 19), // "onDialogSaveClicked"
QT_MOC_LITERAL(13, 191, 6), // "strMAC"
QT_MOC_LITERAL(14, 198, 5), // "strQR"
QT_MOC_LITERAL(15, 204, 9), // "editedStr"
QT_MOC_LITERAL(16, 214, 13), // "checkReaderID"
QT_MOC_LITERAL(17, 228, 17), // "onQRCodeGenerated"
QT_MOC_LITERAL(18, 246, 4), // "Name"
QT_MOC_LITERAL(19, 251, 7), // "Surname"
QT_MOC_LITERAL(20, 259, 5), // "Email"
QT_MOC_LITERAL(21, 265, 12), // "StartingDate"
QT_MOC_LITERAL(22, 278, 12), // "StartingTime"
QT_MOC_LITERAL(23, 291, 12), // "ExpiringDate"
QT_MOC_LITERAL(24, 304, 12), // "ExpiringTime"
QT_MOC_LITERAL(25, 317, 10), // "showQRcode"
QT_MOC_LITERAL(26, 328, 9), // "imagePath"
QT_MOC_LITERAL(27, 338, 16), // "updateQrCodeList"
QT_MOC_LITERAL(28, 355, 16), // "qrCodesDirectory"
QT_MOC_LITERAL(29, 372, 14), // "parseDecodedQR"
QT_MOC_LITERAL(30, 387, 9), // "decodedQR"
QT_MOC_LITERAL(31, 397, 8), // "QString&"
QT_MOC_LITERAL(32, 406, 4), // "name"
QT_MOC_LITERAL(33, 411, 7), // "surname"
QT_MOC_LITERAL(34, 419, 5), // "email"
QT_MOC_LITERAL(35, 425, 9), // "startDate"
QT_MOC_LITERAL(36, 435, 9), // "startTime"
QT_MOC_LITERAL(37, 445, 7), // "expDate"
QT_MOC_LITERAL(38, 453, 7), // "expTime"
QT_MOC_LITERAL(39, 461, 21), // "onRefreshTimerTimeout"
QT_MOC_LITERAL(40, 483, 13), // "handleRequest"
QT_MOC_LITERAL(41, 497, 13), // "QHttpRequest*"
QT_MOC_LITERAL(42, 511, 3), // "req"
QT_MOC_LITERAL(43, 515, 14), // "QHttpResponse*"
QT_MOC_LITERAL(44, 530, 4), // "resp"
QT_MOC_LITERAL(45, 535, 26), // "on_pushB_NewQrCode_clicked"
QT_MOC_LITERAL(46, 562, 24), // "on_pB_downloadQR_clicked"
QT_MOC_LITERAL(47, 587, 16), // "createReaderFile"
QT_MOC_LITERAL(48, 604, 16), // "updateReaderList"
QT_MOC_LITERAL(49, 621, 16), // "readersDirectory"
QT_MOC_LITERAL(50, 638, 33), // "on_listWidget_Readers_itemCli..."
QT_MOC_LITERAL(51, 672, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(52, 689, 4), // "item"
QT_MOC_LITERAL(53, 694, 18), // "expandReaderFolder"
QT_MOC_LITERAL(54, 713, 10), // "folderItem"
QT_MOC_LITERAL(55, 724, 20), // "collapseReaderFolder"
QT_MOC_LITERAL(56, 745, 33), // "on_listWidget_QrCodes_itemCli..."
QT_MOC_LITERAL(57, 779, 23), // "on_pB_associate_clicked"
QT_MOC_LITERAL(58, 803, 22), // "updateAssociationsFile"
QT_MOC_LITERAL(59, 826, 16), // "readerFolderPath"
QT_MOC_LITERAL(60, 843, 9), // "parseLine"
QT_MOC_LITERAL(61, 853, 4), // "line"
QT_MOC_LITERAL(62, 858, 7), // "macAddr"
QT_MOC_LITERAL(63, 866, 8), // "readerID"
QT_MOC_LITERAL(64, 875, 6), // "qrCode"
QT_MOC_LITERAL(65, 882, 26), // "on_pB_disassociate_clicked"
QT_MOC_LITERAL(66, 909, 26), // "deleteAssociationsFileLine"
QT_MOC_LITERAL(67, 936, 16), // "selectedItemPath"
QT_MOC_LITERAL(68, 953, 22), // "on_pB_deleteQR_clicked"
QT_MOC_LITERAL(69, 976, 8), // "deleteQR"
QT_MOC_LITERAL(70, 985, 13), // "updateLogFile"
QT_MOC_LITERAL(71, 999, 9), // "EventType"
QT_MOC_LITERAL(72, 1009, 13), // "logsDirectory"
QT_MOC_LITERAL(73, 1023, 9), // "readerMAC"
QT_MOC_LITERAL(74, 1033, 26), // "on_pB_deleteReader_clicked"
QT_MOC_LITERAL(75, 1060, 12), // "deleteReader"
QT_MOC_LITERAL(76, 1073, 24), // "on_pB_remoteOpen_clicked"
QT_MOC_LITERAL(77, 1098, 17), // "on_pB_FWD_clicked"
QT_MOC_LITERAL(78, 1116, 17), // "on_pB_BWD_clicked"
QT_MOC_LITERAL(79, 1134, 17), // "openWaitingDialog"
QT_MOC_LITERAL(80, 1152, 17) // "onWaitingFinished"

    },
    "MainWindow\0checkDirectories\0\0"
    "checkDirectory\0directoryPath\0"
    "openAddReaderDialog\0updateMainWindow\0"
    "on_pB_addReader_clicked\0checkMAC\0"
    "receivedMacAddr\0getReaderID\0onTimerTimeout\0"
    "onDialogSaveClicked\0strMAC\0strQR\0"
    "editedStr\0checkReaderID\0onQRCodeGenerated\0"
    "Name\0Surname\0Email\0StartingDate\0"
    "StartingTime\0ExpiringDate\0ExpiringTime\0"
    "showQRcode\0imagePath\0updateQrCodeList\0"
    "qrCodesDirectory\0parseDecodedQR\0"
    "decodedQR\0QString&\0name\0surname\0email\0"
    "startDate\0startTime\0expDate\0expTime\0"
    "onRefreshTimerTimeout\0handleRequest\0"
    "QHttpRequest*\0req\0QHttpResponse*\0resp\0"
    "on_pushB_NewQrCode_clicked\0"
    "on_pB_downloadQR_clicked\0createReaderFile\0"
    "updateReaderList\0readersDirectory\0"
    "on_listWidget_Readers_itemClicked\0"
    "QListWidgetItem*\0item\0expandReaderFolder\0"
    "folderItem\0collapseReaderFolder\0"
    "on_listWidget_QrCodes_itemClicked\0"
    "on_pB_associate_clicked\0updateAssociationsFile\0"
    "readerFolderPath\0parseLine\0line\0macAddr\0"
    "readerID\0qrCode\0on_pB_disassociate_clicked\0"
    "deleteAssociationsFileLine\0selectedItemPath\0"
    "on_pB_deleteQR_clicked\0deleteQR\0"
    "updateLogFile\0EventType\0logsDirectory\0"
    "readerMAC\0on_pB_deleteReader_clicked\0"
    "deleteReader\0on_pB_remoteOpen_clicked\0"
    "on_pB_FWD_clicked\0on_pB_BWD_clicked\0"
    "openWaitingDialog\0onWaitingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  209,    2, 0x08 /* Private */,
       3,    1,  210,    2, 0x08 /* Private */,
       5,    0,  213,    2, 0x08 /* Private */,
       6,    0,  214,    2, 0x08 /* Private */,
       7,    0,  215,    2, 0x08 /* Private */,
       8,    1,  216,    2, 0x08 /* Private */,
      10,    1,  219,    2, 0x08 /* Private */,
      11,    0,  222,    2, 0x08 /* Private */,
      12,    3,  223,    2, 0x08 /* Private */,
      16,    1,  230,    2, 0x08 /* Private */,
      17,    7,  233,    2, 0x08 /* Private */,
      25,    1,  248,    2, 0x08 /* Private */,
      27,    1,  251,    2, 0x08 /* Private */,
      29,    8,  254,    2, 0x08 /* Private */,
      39,    0,  271,    2, 0x08 /* Private */,
      40,    2,  272,    2, 0x08 /* Private */,
      45,    0,  277,    2, 0x08 /* Private */,
      46,    0,  278,    2, 0x08 /* Private */,
      47,    2,  279,    2, 0x08 /* Private */,
      48,    1,  284,    2, 0x08 /* Private */,
      50,    1,  287,    2, 0x08 /* Private */,
      53,    1,  290,    2, 0x08 /* Private */,
      55,    1,  293,    2, 0x08 /* Private */,
      56,    1,  296,    2, 0x08 /* Private */,
      57,    0,  299,    2, 0x08 /* Private */,
      58,    2,  300,    2, 0x08 /* Private */,
      60,    4,  305,    2, 0x08 /* Private */,
      65,    0,  314,    2, 0x08 /* Private */,
      66,    1,  315,    2, 0x08 /* Private */,
      68,    0,  318,    2, 0x08 /* Private */,
      69,    0,  319,    2, 0x08 /* Private */,
      70,    5,  320,    2, 0x08 /* Private */,
      74,    0,  331,    2, 0x08 /* Private */,
      75,    0,  332,    2, 0x08 /* Private */,
      76,    0,  333,    2, 0x08 /* Private */,
      77,    0,  334,    2, 0x08 /* Private */,
      78,    0,  335,    2, 0x08 /* Private */,
      79,    0,  336,    2, 0x08 /* Private */,
      80,    0,  337,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    9,
    QMetaType::QString, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,   14,   15,
    QMetaType::Bool, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   19,   20,   21,   22,   23,   24,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 31, 0x80000000 | 31, 0x80000000 | 31, 0x80000000 | 31, 0x80000000 | 31, 0x80000000 | 31, 0x80000000 | 31,   30,   32,   33,   34,   35,   36,   37,   38,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 41, 0x80000000 | 43,   42,   44,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   15,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void, 0x80000000 | 51,   52,
    QMetaType::Void, 0x80000000 | 51,   54,
    QMetaType::Void, 0x80000000 | 51,   54,
    QMetaType::Void, 0x80000000 | 51,   52,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   59,   26,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 31, 0x80000000 | 31, 0x80000000 | 31,   61,   62,   63,   64,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   67,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   71,   72,   30,   73,   63,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkDirectories(); break;
        case 1: _t->checkDirectory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->openAddReaderDialog(); break;
        case 3: _t->updateMainWindow(); break;
        case 4: _t->on_pB_addReader_clicked(); break;
        case 5: { bool _r = _t->checkMAC((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getReaderID((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->onTimerTimeout(); break;
        case 8: _t->onDialogSaveClicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 9: { bool _r = _t->checkReaderID((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->onQRCodeGenerated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7]))); break;
        case 11: _t->showQRcode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->updateQrCodeList((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: { bool _r = _t->parseDecodedQR((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->onRefreshTimerTimeout(); break;
        case 15: _t->handleRequest((*reinterpret_cast< QHttpRequest*(*)>(_a[1])),(*reinterpret_cast< QHttpResponse*(*)>(_a[2]))); break;
        case 16: _t->on_pushB_NewQrCode_clicked(); break;
        case 17: _t->on_pB_downloadQR_clicked(); break;
        case 18: _t->createReaderFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 19: _t->updateReaderList((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->on_listWidget_Readers_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 21: _t->expandReaderFolder((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 22: _t->collapseReaderFolder((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 23: _t->on_listWidget_QrCodes_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 24: _t->on_pB_associate_clicked(); break;
        case 25: _t->updateAssociationsFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 26: { bool _r = _t->parseLine((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->on_pB_disassociate_clicked(); break;
        case 28: { bool _r = _t->deleteAssociationsFileLine((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 29: _t->on_pB_deleteQR_clicked(); break;
        case 30: _t->deleteQR(); break;
        case 31: _t->updateLogFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 32: _t->on_pB_deleteReader_clicked(); break;
        case 33: _t->deleteReader(); break;
        case 34: _t->on_pB_remoteOpen_clicked(); break;
        case 35: _t->on_pB_FWD_clicked(); break;
        case 36: _t->on_pB_BWD_clicked(); break;
        case 37: _t->openWaitingDialog(); break;
        case 38: _t->onWaitingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QHttpRequest* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QHttpResponse* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
