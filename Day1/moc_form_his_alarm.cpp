/****************************************************************************
** Meta object code from reading C++ file 'form_his_alarm.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt0706/form_his_alarm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_his_alarm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_form_his_alarm[] = {

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
      16,   15,   15,   15, 0x08,
      33,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_form_his_alarm[] = {
    "form_his_alarm\0\0Pre_Page_Click()\0"
    "Next_Page_Click()\0"
};

void form_his_alarm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        form_his_alarm *_t = static_cast<form_his_alarm *>(_o);
        switch (_id) {
        case 0: _t->Pre_Page_Click(); break;
        case 1: _t->Next_Page_Click(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData form_his_alarm::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject form_his_alarm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_form_his_alarm,
      qt_meta_data_form_his_alarm, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &form_his_alarm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *form_his_alarm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *form_his_alarm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_form_his_alarm))
        return static_cast<void*>(const_cast< form_his_alarm*>(this));
    return QWidget::qt_metacast(_clname);
}

int form_his_alarm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
