/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Kurs_qt/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 34), // "on_listTextFiles_currentRowCh..."
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 10), // "currentRow"
QT_MOC_LITERAL(4, 58, 4), // "init"
QT_MOC_LITERAL(5, 63, 5), // "alert"
QT_MOC_LITERAL(6, 69, 3), // "msg"
QT_MOC_LITERAL(7, 73, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(8, 94, 17), // "on_btnAdd_clicked"
QT_MOC_LITERAL(9, 112, 30), // "on_listTexts_currentRowChanged"
QT_MOC_LITERAL(10, 143, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(11, 162, 20), // "on_btnDelete_clicked"
QT_MOC_LITERAL(12, 183, 20), // "on_btnCommit_clicked"
QT_MOC_LITERAL(13, 204, 22), // "on_btnCheckout_clicked"
QT_MOC_LITERAL(14, 227, 19) // "on_btnMerge_clicked"

    },
    "MainWindow\0on_listTextFiles_currentRowChanged\0"
    "\0currentRow\0init\0alert\0msg\0"
    "on_btnCancel_clicked\0on_btnAdd_clicked\0"
    "on_listTexts_currentRowChanged\0"
    "on_btnSave_clicked\0on_btnDelete_clicked\0"
    "on_btnCommit_clicked\0on_btnCheckout_clicked\0"
    "on_btnMerge_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    0,   72,    2, 0x08 /* Private */,
       5,    1,   73,    2, 0x08 /* Private */,
       7,    0,   76,    2, 0x08 /* Private */,
       8,    0,   77,    2, 0x08 /* Private */,
       9,    1,   78,    2, 0x08 /* Private */,
      10,    0,   81,    2, 0x08 /* Private */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
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
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_listTextFiles_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->init(); break;
        case 2: _t->alert((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_btnCancel_clicked(); break;
        case 4: _t->on_btnAdd_clicked(); break;
        case 5: _t->on_listTexts_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_btnSave_clicked(); break;
        case 7: _t->on_btnDelete_clicked(); break;
        case 8: _t->on_btnCommit_clicked(); break;
        case 9: _t->on_btnCheckout_clicked(); break;
        case 10: _t->on_btnMerge_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
