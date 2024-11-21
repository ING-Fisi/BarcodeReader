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
    QByteArrayData data[88];
    char stringdata0[1259];
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
QT_MOC_LITERAL(20, 259, 11), // "PhoneNumber"
QT_MOC_LITERAL(21, 271, 5), // "Email"
QT_MOC_LITERAL(22, 277, 12), // "StartingDate"
QT_MOC_LITERAL(23, 290, 12), // "StartingTime"
QT_MOC_LITERAL(24, 303, 12), // "ExpiringDate"
QT_MOC_LITERAL(25, 316, 12), // "ExpiringTime"
QT_MOC_LITERAL(26, 329, 10), // "showQRcode"
QT_MOC_LITERAL(27, 340, 9), // "imagePath"
QT_MOC_LITERAL(28, 350, 16), // "updateQrCodeList"
QT_MOC_LITERAL(29, 367, 16), // "qrCodesDirectory"
QT_MOC_LITERAL(30, 384, 14), // "parseDecodedQR"
QT_MOC_LITERAL(31, 399, 9), // "decodedQR"
QT_MOC_LITERAL(32, 409, 8), // "QString&"
QT_MOC_LITERAL(33, 418, 4), // "name"
QT_MOC_LITERAL(34, 423, 7), // "surname"
QT_MOC_LITERAL(35, 431, 5), // "email"
QT_MOC_LITERAL(36, 437, 9), // "startDate"
QT_MOC_LITERAL(37, 447, 9), // "startTime"
QT_MOC_LITERAL(38, 457, 7), // "expDate"
QT_MOC_LITERAL(39, 465, 7), // "expTime"
QT_MOC_LITERAL(40, 473, 21), // "onRefreshTimerTimeout"
QT_MOC_LITERAL(41, 495, 13), // "handleRequest"
QT_MOC_LITERAL(42, 509, 13), // "QHttpRequest*"
QT_MOC_LITERAL(43, 523, 3), // "req"
QT_MOC_LITERAL(44, 527, 14), // "QHttpResponse*"
QT_MOC_LITERAL(45, 542, 4), // "resp"
QT_MOC_LITERAL(46, 547, 26), // "on_pushB_NewQrCode_clicked"
QT_MOC_LITERAL(47, 574, 24), // "on_pB_downloadQR_clicked"
QT_MOC_LITERAL(48, 599, 16), // "createReaderFile"
QT_MOC_LITERAL(49, 616, 16), // "updateReaderList"
QT_MOC_LITERAL(50, 633, 16), // "readersDirectory"
QT_MOC_LITERAL(51, 650, 33), // "on_listWidget_Readers_itemCli..."
QT_MOC_LITERAL(52, 684, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(53, 701, 4), // "item"
QT_MOC_LITERAL(54, 706, 18), // "expandReaderFolder"
QT_MOC_LITERAL(55, 725, 10), // "folderItem"
QT_MOC_LITERAL(56, 736, 20), // "collapseReaderFolder"
QT_MOC_LITERAL(57, 757, 33), // "on_listWidget_QrCodes_itemCli..."
QT_MOC_LITERAL(58, 791, 23), // "on_pB_associate_clicked"
QT_MOC_LITERAL(59, 815, 22), // "updateAssociationsFile"
QT_MOC_LITERAL(60, 838, 16), // "readerFolderPath"
QT_MOC_LITERAL(61, 855, 9), // "parseLine"
QT_MOC_LITERAL(62, 865, 4), // "line"
QT_MOC_LITERAL(63, 870, 7), // "macAddr"
QT_MOC_LITERAL(64, 878, 8), // "readerID"
QT_MOC_LITERAL(65, 887, 6), // "qrCode"
QT_MOC_LITERAL(66, 894, 26), // "on_pB_disassociate_clicked"
QT_MOC_LITERAL(67, 921, 26), // "deleteAssociationsFileLine"
QT_MOC_LITERAL(68, 948, 16), // "selectedItemPath"
QT_MOC_LITERAL(69, 965, 22), // "on_pB_deleteQR_clicked"
QT_MOC_LITERAL(70, 988, 8), // "deleteQR"
QT_MOC_LITERAL(71, 997, 13), // "updateLogFile"
QT_MOC_LITERAL(72, 1011, 9), // "EventType"
QT_MOC_LITERAL(73, 1021, 13), // "logsDirectory"
QT_MOC_LITERAL(74, 1035, 9), // "readerMAC"
QT_MOC_LITERAL(75, 1045, 26), // "on_pB_deleteReader_clicked"
QT_MOC_LITERAL(76, 1072, 12), // "deleteReader"
QT_MOC_LITERAL(77, 1085, 24), // "on_pB_remoteOpen_clicked"
QT_MOC_LITERAL(78, 1110, 17), // "on_pB_FWD_clicked"
QT_MOC_LITERAL(79, 1128, 17), // "on_pB_BWD_clicked"
QT_MOC_LITERAL(80, 1146, 17), // "openWaitingDialog"
QT_MOC_LITERAL(81, 1164, 17), // "onWaitingFinished"
QT_MOC_LITERAL(82, 1182, 12), // "onLoginValid"
QT_MOC_LITERAL(83, 1195, 9), // "loginFlag"
QT_MOC_LITERAL(84, 1205, 16), // "createQRInfoFile"
QT_MOC_LITERAL(85, 1222, 8), // "mSurname"
QT_MOC_LITERAL(86, 1231, 20), // "generateRandomString"
QT_MOC_LITERAL(87, 1252, 6) // "length"

    },
    "MainWindow\0checkDirectories\0\0"
    "checkDirectory\0directoryPath\0"
    "openAddReaderDialog\0updateMainWindow\0"
    "on_pB_addReader_clicked\0checkMAC\0"
    "receivedMacAddr\0getReaderID\0onTimerTimeout\0"
    "onDialogSaveClicked\0strMAC\0strQR\0"
    "editedStr\0checkReaderID\0onQRCodeGenerated\0"
    "Name\0Surname\0PhoneNumber\0Email\0"
    "StartingDate\0StartingTime\0ExpiringDate\0"
    "ExpiringTime\0showQRcode\0imagePath\0"
    "updateQrCodeList\0qrCodesDirectory\0"
    "parseDecodedQR\0decodedQR\0QString&\0"
    "name\0surname\0email\0startDate\0startTime\0"
    "expDate\0expTime\0onRefreshTimerTimeout\0"
    "handleRequest\0QHttpRequest*\0req\0"
    "QHttpResponse*\0resp\0on_pushB_NewQrCode_clicked\0"
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
    "openWaitingDialog\0onWaitingFinished\0"
    "onLoginValid\0loginFlag\0createQRInfoFile\0"
    "mSurname\0generateRandomString\0length"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  224,    2, 0x08 /* Private */,
       3,    1,  225,    2, 0x08 /* Private */,
       5,    0,  228,    2, 0x08 /* Private */,
       6,    0,  229,    2, 0x08 /* Private */,
       7,    0,  230,    2, 0x08 /* Private */,
       8,    1,  231,    2, 0x08 /* Private */,
      10,    1,  234,    2, 0x08 /* Private */,
      11,    0,  237,    2, 0x08 /* Private */,
      12,    3,  238,    2, 0x08 /* Private */,
      16,    1,  245,    2, 0x08 /* Private */,
      17,    8,  248,    2, 0x08 /* Private */,
      26,    1,  265,    2, 0x08 /* Private */,
      28,    1,  268,    2, 0x08 /* Private */,
      30,    8,  271,    2, 0x08 /* Private */,
      40,    0,  288,    2, 0x08 /* Private */,
      41,    2,  289,    2, 0x08 /* Private */,
      46,    0,  294,    2, 0x08 /* Private */,
      47,    0,  295,    2, 0x08 /* Private */,
      48,    2,  296,    2, 0x08 /* Private */,
      49,    1,  301,    2, 0x08 /* Private */,
      51,    1,  304,    2, 0x08 /* Private */,
      54,    1,  307,    2, 0x08 /* Private */,
      56,    1,  310,    2, 0x08 /* Private */,
      57,    1,  313,    2, 0x08 /* Private */,
      58,    0,  316,    2, 0x08 /* Private */,
      59,    2,  317,    2, 0x08 /* Private */,
      61,    4,  322,    2, 0x08 /* Private */,
      66,    0,  331,    2, 0x08 /* Private */,
      67,    1,  332,    2, 0x08 /* Private */,
      69,    0,  335,    2, 0x08 /* Private */,
      70,    0,  336,    2, 0x08 /* Private */,
      71,    5,  337,    2, 0x08 /* Private */,
      75,    0,  348,    2, 0x08 /* Private */,
      76,    0,  349,    2, 0x08 /* Private */,
      77,    0,  350,    2, 0x08 /* Private */,
      78,    0,  351,    2, 0x08 /* Private */,
      79,    0,  352,    2, 0x08 /* Private */,
      80,    0,  353,    2, 0x08 /* Private */,
      81,    0,  354,    2, 0x08 /* Private */,
      82,    1,  355,    2, 0x08 /* Private */,
      84,    8,  358,    2, 0x08 /* Private */,
      86,    1,  375,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   19,   20,   21,   22,   23,   24,   25,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 32, 0x80000000 | 32, 0x80000000 | 32, 0x80000000 | 32, 0x80000000 | 32, 0x80000000 | 32, 0x80000000 | 32,   31,   33,   34,   35,   36,   37,   38,   39,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 42, 0x80000000 | 44,   43,   45,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   15,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void, 0x80000000 | 52,   55,
    QMetaType::Void, 0x80000000 | 52,   55,
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   60,   27,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 32, 0x80000000 | 32, 0x80000000 | 32,   62,   63,   64,   65,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   72,   73,   31,   74,   64,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   85,   20,   21,   22,   23,   24,   25,
    QMetaType::QString, QMetaType::Int,   87,

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
        case 10: _t->onQRCodeGenerated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8]))); break;
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
        case 39: _t->onLoginValid((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 40: _t->createQRInfoFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8]))); break;
        case 41: { QString _r = _t->generateRandomString((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
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
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
