/****************************************************************************
** Meta object code from reading C++ file 'ffpmmainw.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt0706/ffpmmainw.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ffpmmainw.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FFPMMainW[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      30,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   10,   10,   10, 0x08,
      73,   10,   10,   10, 0x08,
      96,   10,   10,   10, 0x08,
     114,   10,   10,   10, 0x08,
     129,   10,   10,   10, 0x08,
     144,   10,   10,   10, 0x08,
     170,   10,   10,   10, 0x08,
     194,   10,   10,   10, 0x08,
     213,   10,   10,   10, 0x08,
     232,   10,   10,   10, 0x08,
     251,   10,   10,   10, 0x08,
     270,   10,   10,   10, 0x08,
     289,   10,   10,   10, 0x08,
     308,   10,   10,   10, 0x08,
     327,   10,   10,   10, 0x08,
     346,   10,   10,   10, 0x08,
     363,   10,   10,   10, 0x08,
     389,   10,   10,   10, 0x08,
     415,   10,   10,   10, 0x08,
     441,   10,   10,   10, 0x08,
     458,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FFPMMainW[] = {
    "FFPMMainW\0\0key_enter_presss()\0"
    "Key_Updown_Press()\0on_pushButton_clicked()\0"
    "Form_BJ_but1_clicked()\0Date_Time_Fresh()\0"
    "Date_Time_Re()\0Date_Time_Ts()\0"
    "on_pushButton_2_clicked()\0"
    "on_p_but_open_clicked()\0But_SSXX_clicked()\0"
    "But_DQGZ_clicked()\0But_DQBJ_clicked()\0"
    "But_LSBJ_clicked()\0But_XTFW_clicked()\0"
    "But_CSSZ_clicked()\0But_SYBZ_clicked()\0"
    "But_XTZJ_clicked()\0Show_Next_Page()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0on_gao_clicked()\0"
    "on_di_clicked()\0"
};

void FFPMMainW::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FFPMMainW *_t = static_cast<FFPMMainW *>(_o);
        switch (_id) {
        case 0: _t->key_enter_presss(); break;
        case 1: _t->Key_Updown_Press(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->Form_BJ_but1_clicked(); break;
        case 4: _t->Date_Time_Fresh(); break;
        case 5: _t->Date_Time_Re(); break;
        case 6: _t->Date_Time_Ts(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->on_p_but_open_clicked(); break;
        case 9: _t->But_SSXX_clicked(); break;
        case 10: _t->But_DQGZ_clicked(); break;
        case 11: _t->But_DQBJ_clicked(); break;
        case 12: _t->But_LSBJ_clicked(); break;
        case 13: _t->But_XTFW_clicked(); break;
        case 14: _t->But_CSSZ_clicked(); break;
        case 15: _t->But_SYBZ_clicked(); break;
        case 16: _t->But_XTZJ_clicked(); break;
        case 17: _t->Show_Next_Page(); break;
        case 18: _t->on_pushButton_3_clicked(); break;
        case 19: _t->on_pushButton_4_clicked(); break;
        case 20: _t->on_pushButton_5_clicked(); break;
        case 21: _t->on_gao_clicked(); break;
        case 22: _t->on_di_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FFPMMainW::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FFPMMainW::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FFPMMainW,
      qt_meta_data_FFPMMainW, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FFPMMainW::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FFPMMainW::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FFPMMainW::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FFPMMainW))
        return static_cast<void*>(const_cast< FFPMMainW*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FFPMMainW::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void FFPMMainW::key_enter_presss()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FFPMMainW::Key_Updown_Press()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
