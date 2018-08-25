/****************************************************************************
** Meta object code from reading C++ file 'form_rset.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt0706/form_rset.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_rset.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Form_Rset[] = {

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
      11,   10,   10,   10, 0x08,
      41,   10,   10,   10, 0x08,
      70,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Form_Rset[] = {
    "Form_Rset\0\0But_all_ffpms_reset_clicked()\0"
    "But_just_sys_reset_clicked()\0"
    "RS_Time_Fresh()\0"
};

void Form_Rset::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Form_Rset *_t = static_cast<Form_Rset *>(_o);
        switch (_id) {
        case 0: _t->But_all_ffpms_reset_clicked(); break;
        case 1: _t->But_just_sys_reset_clicked(); break;
        case 2: _t->RS_Time_Fresh(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Form_Rset::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Form_Rset::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Form_Rset,
      qt_meta_data_Form_Rset, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Form_Rset::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Form_Rset::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Form_Rset::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Form_Rset))
        return static_cast<void*>(const_cast< Form_Rset*>(this));
    return QWidget::qt_metacast(_clname);
}

int Form_Rset::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
