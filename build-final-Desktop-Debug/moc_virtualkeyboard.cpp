/****************************************************************************
** Meta object code from reading C++ file 'virtualkeyboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../final/virtualkeyboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'virtualkeyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VirtualKeyboard_t {
    QByteArrayData data[16];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VirtualKeyboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VirtualKeyboard_t qt_meta_stringdata_VirtualKeyboard = {
    {
QT_MOC_LITERAL(0, 0, 15), // "VirtualKeyboard"
QT_MOC_LITERAL(1, 16, 14), // "on_One_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "on_Two_clicked"
QT_MOC_LITERAL(4, 47, 16), // "on_Three_clicked"
QT_MOC_LITERAL(5, 64, 15), // "on_Four_clicked"
QT_MOC_LITERAL(6, 80, 15), // "on_Five_clicked"
QT_MOC_LITERAL(7, 96, 14), // "on_Six_clicked"
QT_MOC_LITERAL(8, 111, 16), // "on_Seven_clicked"
QT_MOC_LITERAL(9, 128, 16), // "on_Eight_clicked"
QT_MOC_LITERAL(10, 145, 15), // "on_Nine_clicked"
QT_MOC_LITERAL(11, 161, 14), // "on_Dot_clicked"
QT_MOC_LITERAL(12, 176, 15), // "on_Zero_clicked"
QT_MOC_LITERAL(13, 192, 20), // "on_Backspace_clicked"
QT_MOC_LITERAL(14, 213, 21), // "on_DoneButton_clicked"
QT_MOC_LITERAL(15, 235, 16) // "on_Minus_clicked"

    },
    "VirtualKeyboard\0on_One_clicked\0\0"
    "on_Two_clicked\0on_Three_clicked\0"
    "on_Four_clicked\0on_Five_clicked\0"
    "on_Six_clicked\0on_Seven_clicked\0"
    "on_Eight_clicked\0on_Nine_clicked\0"
    "on_Dot_clicked\0on_Zero_clicked\0"
    "on_Backspace_clicked\0on_DoneButton_clicked\0"
    "on_Minus_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VirtualKeyboard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VirtualKeyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VirtualKeyboard *_t = static_cast<VirtualKeyboard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_One_clicked(); break;
        case 1: _t->on_Two_clicked(); break;
        case 2: _t->on_Three_clicked(); break;
        case 3: _t->on_Four_clicked(); break;
        case 4: _t->on_Five_clicked(); break;
        case 5: _t->on_Six_clicked(); break;
        case 6: _t->on_Seven_clicked(); break;
        case 7: _t->on_Eight_clicked(); break;
        case 8: _t->on_Nine_clicked(); break;
        case 9: _t->on_Dot_clicked(); break;
        case 10: _t->on_Zero_clicked(); break;
        case 11: _t->on_Backspace_clicked(); break;
        case 12: _t->on_DoneButton_clicked(); break;
        case 13: _t->on_Minus_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject VirtualKeyboard::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VirtualKeyboard.data,
      qt_meta_data_VirtualKeyboard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VirtualKeyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VirtualKeyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VirtualKeyboard.stringdata0))
        return static_cast<void*>(const_cast< VirtualKeyboard*>(this));
    return QDialog::qt_metacast(_clname);
}

int VirtualKeyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
