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
    inline virtual ~Impl(){ deinit(); }
    inline void operator ()(SELF* self){ __self__ = self; }
    inline virtual void init(){}
    inline virtual void deinit(){}
public:
    SELF* __self__;
};

#define VX_P(classname) friend class classname##Impl; QSharedPointer<classname##Impl> __impl__;
#define VX_D(classname) classname##Impl *d = __impl__.data();
#define VX_I(classname) __impl__.reset(new classname##Impl);(*__impl__)(this);VX_D(classname);d->init();
#define VX_Q(classname) classname *q = __self__;

#define VX_EMPTY_CTOR(classname) classname##Impl(){} ~classname##Impl(){} 
