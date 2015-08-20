/****************************************************************************
** Meta object code from reading C++ file 'clientagent.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../clientagent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientagent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClientAgent[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,   12,   12,   12, 0x08,
      57,   12,   12,   12, 0x08,
      84,   12,   12,   12, 0x08,
     128,  125,   12,   12, 0x08,
     149,   12,   12,   12, 0x08,
     160,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ClientAgent[] = {
    "ClientAgent\0\0sendAgain()\0"
    "on_pushButton_connect_clicked()\0"
    "on_pushButton_tx_clicked()\0"
    "on_pushButton_client_red_green_clicked()\0"
    "ba\0onReaded(QByteArray)\0setGreen()\0"
    "setRed()\0"
};

void ClientAgent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClientAgent *_t = static_cast<ClientAgent *>(_o);
        switch (_id) {
        case 0: _t->sendAgain(); break;
        case 1: _t->on_pushButton_connect_clicked(); break;
        case 2: _t->on_pushButton_tx_clicked(); break;
        case 3: _t->on_pushButton_client_red_green_clicked(); break;
        case 4: _t->onReaded((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->setGreen(); break;
        case 6: _t->setRed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ClientAgent::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ClientAgent::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ClientAgent,
      qt_meta_data_ClientAgent, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClientAgent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClientAgent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClientAgent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientAgent))
        return static_cast<void*>(const_cast< ClientAgent*>(this));
    return QDialog::qt_metacast(_clname);
}

int ClientAgent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ClientAgent::sendAgain()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
