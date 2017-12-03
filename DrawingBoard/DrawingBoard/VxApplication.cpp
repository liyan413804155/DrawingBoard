#include "stdafx.h"
#include "VxApplication.h"
#include "VxDatabaseManager.h"
#include "VxCommandManager.h"
#include "VxMainWindosw.h"

class VxApplicationImpl : public Impl<VxApplication>
{
public:
    VX_EMPTY_CTOR(VxApplication)

public:
    VxDatabaseManager* _dataManager;
    VxCommandManager*  _commandManager;
    VxMainWindosw*     _mainwindow;
};

VxApplication::VxApplication(int& argc, char **argv)
    : QApplication(argc, argv)
{
    VX_I(VxApplication);

    d->_dataManager = new VxDatabaseManager;
    d->_commandManager = new VxCommandManager(d->_dataManager);
    d->_mainwindow = new VxMainWindosw(d->_dataManager, d->_commandManager);

    d->_mainwindow->showMaximized();
    d->_mainwindow->show();
}

VxApplication::~VxApplication()
{
    VX_E(VxApplication);

    delete d->_dataManager;
    delete d->_commandManager;
    delete d->_mainwindow;
}