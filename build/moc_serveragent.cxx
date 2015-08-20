/****************************************************************************
** Meta object code from reading C++ file 'serveragent.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../serveragent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serveragent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerAgent[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      44,   12,   12,   12, 0x08,
      73,   12,   12,   12, 0x08,
     114,   12,   12,   12, 0x08,
     131,  128,   12,   12, 0x08,
     152,   12,   12,   12, 0x08,
     161,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ServerAgent[] = {
    "ServerAgent\0\0on_pushButton_server_clicked()\0"
    "on_pushButton_send_clicked()\0"
    "on_pushButton_switch_green_red_clicked()\0"
    "onConnected()\0ba\0onReaded(QByteArray)\0"
    "setRed()\0setGreen()\0"
};

void ServerAgent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ServerAgent *_t = static_cast<ServerAgent *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_server_clicked(); break;
        case 1: _t->on_pushButton_send_clicked(); break;
        case 2: _t->on_pushButton_switch_green_red_clicked(); break;
        case 3: _t->onConnected(); break;
        case 4: _t->onReaded((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->setRed(); break;
        case 6: _t->setGreen(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ServerAgent::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ServerAgent::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ServerAgent,
      qt_meta_data_ServerAgent, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ServerAgent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ServerAgent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ServerAgent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerAgent))
        return static_cast<void*>(const_cast< ServerAgent*>(this));
    return QDialog::qt_metacast(_clname);
}

int ServerAgent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
