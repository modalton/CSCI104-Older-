/****************************************************************************
** Meta object code from reading C++ file 'one_more_class.h'
**
** Created: Fri Jul 11 19:24:51 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "one_more_class.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'one_more_class.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_one_more_class[] = {

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
      16,   15,   15,   15, 0x0a,
      31,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_one_more_class[] = {
    "one_more_class\0\0add_follower()\0"
    "make_feed()\0"
};

void one_more_class::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        one_more_class *_t = static_cast<one_more_class *>(_o);
        switch (_id) {
        case 0: _t->add_follower(); break;
        case 1: _t->make_feed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData one_more_class::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject one_more_class::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_one_more_class,
      qt_meta_data_one_more_class, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &one_more_class::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *one_more_class::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *one_more_class::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_one_more_class))
        return static_cast<void*>(const_cast< one_more_class*>(this));
    return QWidget::qt_metacast(_clname);
}

int one_more_class::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
