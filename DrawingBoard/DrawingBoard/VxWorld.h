#pragma once

class VxWorld : public QOpenGLWidget
{
public:
    VxWorld(QWidget * parent = nullptr);
    ~VxWorld();

private:
    VX_P(VxWorld);
};
