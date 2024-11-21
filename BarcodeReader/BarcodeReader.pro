QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addreader.cpp \
    barcodereaderserver.cpp \
    editdialog.cpp \
    errormessage.cpp \
    errormessage2.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    newqrcodedialog.cpp \
    passwordeditor.cpp \
    qrcode.cpp \
    qrcodereader.cpp \
    waitingdialog.cpp

HEADERS += \
    addreader.h \
    barcodereaderserver.h \
    editdialog.h \
    errormessage.h \
    errormessage2.h \
    logindialog.h \
    mainwindow.h \
    newqrcodedialog.h \
    passwordeditor.h \
    qrcode.h \
    qrcodereader.h \
    waitingdialog.h

FORMS += \
    addreader.ui \
    editdialog.ui \
    errormessage.ui \
    errormessage2.ui \
    logindialog.ui \
    mainwindow.ui \
    newqrcodedialog.ui \
    passwordeditor.ui \
    waitingdialog.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = $${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src


#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/release/ -lqhttpserver
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/debug/ -lqhttpserver
#else:unix: LIBS += -L$$PWD/lib/ -lqhttpserver


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/release/ -lqhttpserver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/debug/ -lqhttpserver
else:unix: LIBS += -L$$PWD/../lib/ -lqhttpserver

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../datepicker_library/source/lib/release/ -ldatepicker
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../datepicker_library/source/lib/debug/ -ldatepicker
else:unix: LIBS += -L$$PWD/../datepicker_library/source/lib/ -ldatepicker

INCLUDEPATH += $$PWD/../datepicker_library/source/include
DEPENDPATH += $$PWD/../datepicker_library/source/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../datepicker_library/source/lib/release/libdatepicker.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../datepicker_library/source/lib/debug/libdatepicker.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../datepicker_library/source/lib/release/datepicker.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../datepicker_library/source/lib/debug/datepicker.lib
else:unix: PRE_TARGETDEPS += $$PWD/../datepicker_library/source/lib/libdatepicker.a
