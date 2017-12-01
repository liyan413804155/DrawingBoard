#include "stdafx.h"
#include "VxCommandManager.h"

class VxCommandManagerImpl : public Impl<VxCommandManager>
{
public:
    VX_EMPTY_CTOR(VxCommandManager);

public:
    VxDatabaseManager* _databaseManager;
};


VxCommandManager::VxCommandManager(VxDatabaseManager* databaseManager)
{
    VX_I(VxCommandManager);

    d->_databaseManager = databaseManager;
}

VxCommandManager::~VxCommandManager()
{

}

void VxCommandManager::handleCommand(const QString& command)
{

}
