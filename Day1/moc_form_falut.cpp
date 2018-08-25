/****************************************************************************
** Meta object code from reading C++ file 'form_falut.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt0706/form_falut.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_falut.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Form_Falut[] = {

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
      12,   11,   11,   11, 0x08,
      35,   11,   11,   11, 0x08,
      55,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Form_Falut[] = {
    "Form_Falut\0\0Form_Falut_Timer_Out()\0"
    "FA_Pre_Page_Click()\0FA_Next_Page_Click()\0"
};

void Form_Falut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Form_Falut *_t = static_cast<Form_Falut *>(_o);
        switch (_id) {
        case 0: _t->Form_Falut_Timer_Out(); break;
        case 1: _t->FA_Pre_Page_Click(); break;
        case 2: _t->FA_Next_Page_Click(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Form_Falut::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Form_Falut::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Form_Falut,
      qt_meta_data_Form_Falut, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Form_Falut::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Form_Falut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Form_Falut::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Form_Falut))
        return static_cast<void*>(const_cast< Form_Falut*>(this));
    return QWidget::qt_metacast(_clname);
}

int Form_Falut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
