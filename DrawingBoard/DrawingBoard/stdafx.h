#include <QtCore/QScopedPointer>
#include <QtCore/QSharedPointer>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QtWidgets>

template<typename SELF>
class Impl
{
public:
    inline Impl(){}
    inline ~Impl(){}
public:
    SELF* q;
};

#define VX_P(classname) friend class classname##Impl; classname##Impl *d;
#define VX_I(classname) d = new classname##Impl; d->q = this;
#define VX_E(classname) QScopedPointer<classname##Impl> __E__(d);

#define VX_EMPTY_CTOR(classname) classname##Impl(){} ~classname##Impl(){} 
