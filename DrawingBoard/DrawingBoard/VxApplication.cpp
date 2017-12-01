#include "stdafx.h"
#include "VxApplication.h"
#include "VxDatabaseManager.h"
#include "VxCommandManager.h"
#include "VxMainWindosw.h"

class VxApplicationImpl : public Impl<VxApplication>
{
public:
    VX_EMPTY_CTOR(VxApplication)

    virtual void init()override
    {
        _dataManager.reset(new VxDatabaseManager);

        _commandManager.reset(new VxCommandManager(_dataManager.data()));

        _mainwindow.reset(new VxMainWindosw(_dataManager.data(), _commandManager.data()));
        _mainwindow->showMaximized();
    }

public:
    QSharedPointer<VxDatabaseManager> _dataManager;
    QSharedPointer<VxCommandManager>  _commandManager;
    QSharedPointer<VxMainWindosw>     _mainwindow;
};

VxApplication::VxApplication(int& argc, char **argv)
    : QApplication(argc, argv)
{
    VX_I(VxApplication);

    d->_mainwindow->show();
}

VxApplication::~VxApplication()
{

}