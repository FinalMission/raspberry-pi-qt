/****************************************************************************
** Meta object code from reading C++ file 'mapsettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../final/mapsettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mapsettings_t {
    QByteArrayData data[6];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mapsettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mapsettings_t qt_meta_stringdata_mapsettings = {
    {
QT_MOC_LITERAL(0, 0, 11), // "mapsettings"
QT_MOC_LITERAL(1, 12, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 4), // "arg1"
QT_MOC_LITERAL(4, 49, 22), // "on_ApplyButton_clicked"
QT_MOC_LITERAL(5, 72, 24) // "on_SettingButton_clicked"

    },
    "mapsettings\0on_comboBox_currentTextChanged\0"
    "\0arg1\0on_ApplyButton_clicked\0"
    "on_SettingButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mapsettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mapsettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mapsettings *_t = static_cast<mapsettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_ApplyButton_clicked(); break;
        case 2: _t->on_SettingButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject mapsettings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_mapsettings.data,
      qt_meta_data_mapsettings,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mapsettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mapsettings::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mapsettings.stringdata0))
        return static_cast<void*>(const_cast< mapsettings*>(this));
    return QDialog::qt_metacast(_clname);
}

int mapsettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
