/****************************************************************************
** Meta object code from reading C++ file 'AdministratorApp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../AdministratorApp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AdministratorApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdministratorApp_t {
    QByteArrayData data[12];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdministratorApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdministratorApp_t qt_meta_stringdata_AdministratorApp = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AdministratorApp"
QT_MOC_LITERAL(1, 17, 16), // "RefreshUserCombo"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 7), // "AddUser"
QT_MOC_LITERAL(4, 43, 17), // "OnUserComboSelect"
QT_MOC_LITERAL(5, 61, 1), // "i"
QT_MOC_LITERAL(6, 63, 17), // "ResetFileUserList"
QT_MOC_LITERAL(7, 81, 20), // "AddUsersFromFileList"
QT_MOC_LITERAL(8, 102, 12), // "LoadUserFile"
QT_MOC_LITERAL(9, 115, 10), // "DeleteUser"
QT_MOC_LITERAL(10, 126, 8), // "OpenPort"
QT_MOC_LITERAL(11, 135, 21) // "OnSerialPortReadyRead"

    },
    "AdministratorApp\0RefreshUserCombo\0\0"
    "AddUser\0OnUserComboSelect\0i\0"
    "ResetFileUserList\0AddUsersFromFileList\0"
    "LoadUserFile\0DeleteUser\0OpenPort\0"
    "OnSerialPortReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdministratorApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    1,   61,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    0,   65,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdministratorApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdministratorApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RefreshUserCombo(); break;
        case 1: _t->AddUser(); break;
        case 2: _t->OnUserComboSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ResetFileUserList(); break;
        case 4: _t->AddUsersFromFileList(); break;
        case 5: _t->LoadUserFile(); break;
        case 6: _t->DeleteUser(); break;
        case 7: _t->OpenPort(); break;
        case 8: _t->OnSerialPortReadyRead(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AdministratorApp::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_AdministratorApp.data,
    qt_meta_data_AdministratorApp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AdministratorApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdministratorApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdministratorApp.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AdministratorApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
