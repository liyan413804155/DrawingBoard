#include "stdafx.h"
#include "VxWorld.h"

class VxWorldImpl : public Impl<VxWorld>
{
public:
    VX_EMPTY_CTOR(VxWorld);
};

VxWorld::VxWorld(QWidget *parent)
    : QOpenGLWidget(parent)
{
    VX_I(VxWorld);
}

VxWorld::~VxWorld()
{

}