#pragma once

class VxApplication : public QApplication
{
public:
    VxApplication(int& argc, char **argv);
    ~VxApplication();

private:
    VX_P(VxApplication);
};