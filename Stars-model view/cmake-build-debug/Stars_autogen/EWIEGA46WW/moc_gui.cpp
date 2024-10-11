/****************************************************************************
** Meta object code from reading C++ file 'gui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gui.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSguiENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSguiENDCLASS = QtMocHelpers::stringData(
    "gui",
    "showConstellationsFiltered",
    "",
    "addStar",
    "populateFilteredList",
    "drawConst",
    "filterConstellations"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSguiENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[4];
    char stringdata1[27];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[21];
    char stringdata5[10];
    char stringdata6[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSguiENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSguiENDCLASS_t qt_meta_stringdata_CLASSguiENDCLASS = {
    {
        QT_MOC_LITERAL(0, 3),  // "gui"
        QT_MOC_LITERAL(4, 26),  // "showConstellationsFiltered"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 7),  // "addStar"
        QT_MOC_LITERAL(40, 20),  // "populateFilteredList"
        QT_MOC_LITERAL(61, 9),  // "drawConst"
        QT_MOC_LITERAL(71, 20)   // "filterConstellations"
    },
    "gui",
    "showConstellationsFiltered",
    "",
    "addStar",
    "populateFilteredList",
    "drawConst",
    "filterConstellations"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSguiENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   45,    2, 0x0a,    2 /* Public */,
       4,    0,   46,    2, 0x0a,    3 /* Public */,
       5,    0,   47,    2, 0x0a,    4 /* Public */,
       6,    0,   48,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject gui::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSguiENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSguiENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSguiENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<gui, std::true_type>,
        // method 'showConstellationsFiltered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addStar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'populateFilteredList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'drawConst'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'filterConstellations'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void gui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<gui *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showConstellationsFiltered(); break;
        case 1: _t->addStar(); break;
        case 2: _t->populateFilteredList(); break;
        case 3: _t->drawConst(); break;
        case 4: _t->filterConstellations(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *gui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSguiENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int gui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
