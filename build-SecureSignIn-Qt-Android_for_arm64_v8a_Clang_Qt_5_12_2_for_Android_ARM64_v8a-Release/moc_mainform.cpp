/****************************************************************************
** Meta object code from reading C++ file 'mainform.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SecureSignIn-Qt/mainform.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainform.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainForm_t {
    QByteArrayData data[13];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainForm_t qt_meta_stringdata_MainForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainForm"
QT_MOC_LITERAL(1, 9, 18), // "password_encrypted"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "password_changed"
QT_MOC_LITERAL(4, 46, 11), // "key_changed"
QT_MOC_LITERAL(5, 58, 15), // "compact_changed"
QT_MOC_LITERAL(6, 74, 15), // "encrypt_clicked"
QT_MOC_LITERAL(7, 90, 12), // "copy_clicked"
QT_MOC_LITERAL(8, 103, 5), // "clear"
QT_MOC_LITERAL(9, 109, 15), // "cipher_password"
QT_MOC_LITERAL(10, 125, 8), // "password"
QT_MOC_LITERAL(11, 134, 3), // "key"
QT_MOC_LITERAL(12, 138, 7) // "compact"

    },
    "MainForm\0password_encrypted\0\0"
    "password_changed\0key_changed\0"
    "compact_changed\0encrypt_clicked\0"
    "copy_clicked\0clear\0cipher_password\0"
    "password\0key\0compact"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       4,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::QString, 0x00495003,
      10, QMetaType::QString, 0x00495003,
      11, QMetaType::QString, 0x00495003,
      12, QMetaType::Bool, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void MainForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->password_encrypted(); break;
        case 1: _t->password_changed(); break;
        case 2: _t->key_changed(); break;
        case 3: _t->compact_changed(); break;
        case 4: _t->encrypt_clicked(); break;
        case 5: _t->copy_clicked(); break;
        case 6: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainForm::password_encrypted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainForm::password_changed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainForm::key_changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainForm::compact_changed)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MainForm *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->get_cipher_password(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->get_password(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->get_key(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->get_compact(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MainForm *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_cipher_password(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->set_password(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->set_key(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->set_compact(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainForm::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MainForm.data,
    qt_meta_data_MainForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainForm.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MainForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MainForm::password_encrypted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainForm::password_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainForm::key_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainForm::compact_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
