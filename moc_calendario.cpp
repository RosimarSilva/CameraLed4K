/****************************************************************************
** Meta object code from reading C++ file 'calendario.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "calendario.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendario.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Calendario_t {
    QByteArrayData data[18];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calendario_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calendario_t qt_meta_stringdata_Calendario = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Calendario"
QT_MOC_LITERAL(1, 11, 10), // "changedDia"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "changedMes"
QT_MOC_LITERAL(4, 34, 10), // "changedAno"
QT_MOC_LITERAL(5, 45, 11), // "changedHora"
QT_MOC_LITERAL(6, 57, 12), // "changeMinuto"
QT_MOC_LITERAL(7, 70, 6), // "setDay"
QT_MOC_LITERAL(8, 77, 5), // "sinal"
QT_MOC_LITERAL(9, 83, 8), // "setMonth"
QT_MOC_LITERAL(10, 92, 7), // "setYear"
QT_MOC_LITERAL(11, 100, 7), // "setHour"
QT_MOC_LITERAL(12, 108, 9), // "setminute"
QT_MOC_LITERAL(13, 118, 3), // "dia"
QT_MOC_LITERAL(14, 122, 3), // "mes"
QT_MOC_LITERAL(15, 126, 3), // "ano"
QT_MOC_LITERAL(16, 130, 4), // "hora"
QT_MOC_LITERAL(17, 135, 6) // "minuto"

    },
    "Calendario\0changedDia\0\0changedMes\0"
    "changedAno\0changedHora\0changeMinuto\0"
    "setDay\0sinal\0setMonth\0setYear\0setHour\0"
    "setminute\0dia\0mes\0ano\0hora\0minuto"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calendario[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       5,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    1,   69,    2, 0x02 /* Public */,
       9,    1,   72,    2, 0x02 /* Public */,
      10,    1,   75,    2, 0x02 /* Public */,
      11,    1,   78,    2, 0x02 /* Public */,
      12,    1,   81,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Char,    8,
    QMetaType::Void, QMetaType::Char,    8,
    QMetaType::Void, QMetaType::Char,    8,
    QMetaType::Void, QMetaType::Char,    8,
    QMetaType::Void, QMetaType::Char,    8,

 // properties: name, type, flags
      13, QMetaType::Int, 0x00495103,
      14, QMetaType::Int, 0x00495103,
      15, QMetaType::Int, 0x00495103,
      16, QMetaType::Int, 0x00495103,
      17, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void Calendario::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Calendario *_t = static_cast<Calendario *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changedDia(); break;
        case 1: _t->changedMes(); break;
        case 2: _t->changedAno(); break;
        case 3: _t->changedHora(); break;
        case 4: _t->changeMinuto(); break;
        case 5: _t->setDay((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 6: _t->setMonth((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 7: _t->setYear((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 8: _t->setHour((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 9: _t->setminute((*reinterpret_cast< char(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Calendario::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calendario::changedDia)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Calendario::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calendario::changedMes)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Calendario::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calendario::changedAno)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Calendario::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calendario::changedHora)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Calendario::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calendario::changeMinuto)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Calendario *_t = static_cast<Calendario *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->dia(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->mes(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->ano(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->hora(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->minuto(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Calendario *_t = static_cast<Calendario *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDia(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setMes(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setAno(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setHora(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setMinuto(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Calendario::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Calendario.data,
      qt_meta_data_Calendario,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Calendario::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calendario::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calendario.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Calendario::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Calendario::changedDia()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Calendario::changedMes()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Calendario::changedAno()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Calendario::changedHora()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Calendario::changeMinuto()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
