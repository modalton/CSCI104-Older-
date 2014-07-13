/****************************************************************************
** Meta object code from reading C++ file 'user_win.h'
**
** Created: Sun Jul 13 13:29:36 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "user_win.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user_win.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_user_win[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      24,    9,    9,    9, 0x08,
      45,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_user_win[] = {
    "user_win\0\0tweet_Click()\0chng_feed_2mention()\0"
    "chng_feed_2feed()\0"
};

void user_win::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        user_win *_t = static_cast<user_win *>(_o);
        switch (_id) {
        case 0: _t->tweet_Click(); break;
        case 1: _t->chng_feed_2mention(); break;
        case 2: _t->chng_feed_2feed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData user_win::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject user_win::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_user_win,
      qt_meta_data_user_win, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &user_win::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *user_win::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *user_win::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_user_win))
        return static_cast<void*>(const_cast< user_win*>(this));
    return QWidget::qt_metacast(_clname);
}

int user_win::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
