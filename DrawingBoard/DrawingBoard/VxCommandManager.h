#pragma once

#include "VxDatabaseManager.h"

class VxCommandManager
{
public:
    VxCommandManager(VxDatabaseManager* databaseManager);
    ~VxCommandManager();

public:
    void handleCommand(const QString& command);

private:
    VX_P(VxCommandManager);
};