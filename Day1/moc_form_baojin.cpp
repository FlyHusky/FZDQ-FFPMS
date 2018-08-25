/****************************************************************************
** Meta object code from reading C++ file 'form_baojin.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt0706/form_baojin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_baojin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Form_Baojin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   12,   12,   12, 0x08,
      59,   12,   12,   12, 0x08,
      83,   12,   12,   12, 0x08,
     105,   12,   12,   12, 0x08,
     131,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Form_Baojin[] = {
    "Form_Baojin\0\0back_to_main_singal()\0"
    "Form_Baojin_Timer_Out()\0But_Print_Today_Click()\0"
    "But_Print_All_Click()\0on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
};

void Form_Baojin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Form_Baojin *_t = static_cast<Form_Baojin *>(_o);
        switch (_id) {
        case 0: _t->back_to_main_singal(); break;
        case 1: _t->Form_Baojin_Timer_Out(); break;
        case 2: _t->But_Print_Today_Click(); break;
        case 3: _t->But_Print_All_Click(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Form_Baojin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Form_Baojin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Form_Baojin,
      qt_meta_data_Form_Baojin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Form_Baojin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Form_Baojin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Form_Baojin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Form_Baojin))
        return static_cast<void*>(const_cast< Form_Baojin*>(this));
    return QWidget::qt_metacast(_clname);
}

int Form_Baojin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Form_Baojin::back_to_main_singal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
