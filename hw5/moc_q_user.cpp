/****************************************************************************
** Meta object code from reading C++ file 'q_user.h'
**
** Created: Thu Jul 10 13:52:17 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "q_user.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'q_user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_q_user[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,    8,    7,    7, 0x0a,
      36,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_q_user[] = {
    "q_user\0\0text\0new_tweet(std::string)\0"
    "following_new()\0"
};

void q_user::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        q_user *_t = static_cast<q_user *>(_o);
        switch (_id) {
        case 0: _t->new_tweet((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->following_new(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData q_user::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject q_user::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_q_user,
      qt_meta_data_q_user, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &q_user::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *q_user::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *q_user::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_q_user))
        return static_cast<void*>(const_cast< q_user*>(this));
    return QObject::qt_metacast(_clname);
}

int q_user::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
