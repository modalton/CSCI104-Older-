/****************************************************************************
** Meta object code from reading C++ file 'hash_win.h'
**
** Created: Fri Jul 25 10:29:36 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hash_win.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hash_win.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HashWin[] = {

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
      17,    9,    8,    8, 0x0a,
      42,    8,    8,    8, 0x0a,
      52,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HashWin[] = {
    "HashWin\0\0btnname\0add_hashtag(std::string)\0"
    "refresh()\0fill_listwidget()\0"
};

void HashWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HashWin *_t = static_cast<HashWin *>(_o);
        switch (_id) {
        case 0: _t->add_hashtag((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->refresh(); break;
        case 2: _t->fill_listwidget(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HashWin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HashWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HashWin,
      qt_meta_data_HashWin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HashWin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HashWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HashWin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HashWin))
        return static_cast<void*>(const_cast< HashWin*>(this));
    return QWidget::qt_metacast(_clname);
}

int HashWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
