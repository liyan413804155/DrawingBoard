#include "stdafx.h"
#include "VxDataBaseManager.h"

class VxDatabaseManagerImpl : public Impl<VxDatabaseManager>
{
public:
    VX_EMPTY_CTOR(VxDatabaseManager);
};


VxDatabaseManager::VxDatabaseManager()
{
    VX_I(VxDatabaseManager);
}

VxDatabaseManager::~VxDatabaseManager()
{

}
