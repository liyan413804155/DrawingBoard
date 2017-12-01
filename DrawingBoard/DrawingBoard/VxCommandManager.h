#pragma once

#include "VxDatabaseManager.h"

class VxCommandManager : public QObject
{
    Q_OBJECT
public:
    VxCommandManager(VxDatabaseManager* databaseManager);
    ~VxCommandManager();

public slots:
    void handleCommand(const QString& command);

private:
    VX_P(VxCommandManager);
};