#pragma once

#include "VxDatabaseManager.h"
#include "VxCommandManager.h"

class VxMainWindosw : public QMainWindow
{
    Q_OBJECT

public:
    VxMainWindosw(VxDatabaseManager* databaseManager, VxCommandManager* commandManager, QWidget *parent = nullptr);
    ~VxMainWindosw();

private:
    VX_P(VxMainWindosw);
};
