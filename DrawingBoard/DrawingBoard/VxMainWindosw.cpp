#include "stdafx.h"
#include "VxMainWindosw.h"
#include "VxWorld.h"

class VxMainWindoswImpl : public Impl<VxMainWindosw>
{
public:
    VX_EMPTY_CTOR(VxMainWindosw);

    virtual void init() override
    {
        VX_Q(VxMainWindosw);

        _world = new VxWorld(q);
        _input = new QLineEdit(q);
        QVBoxLayout * mainLayout = new QVBoxLayout();
        mainLayout->addWidget(_input);
        mainLayout->addWidget(_world);
        QWidget *centralWidget = new QWidget(q);
        centralWidget->setLayout(mainLayout);
        q->setCentralWidget(centralWidget);
    }

public:
    VxWorld *_world;
    QLineEdit *_input;
    VxDatabaseManager* _databaseManager;
    VxCommandManager*  _commandManager;
};

VxMainWindosw::VxMainWindosw
(
VxDatabaseManager* databaseManager, 
VxCommandManager* commandManager, 
QWidget *parent
)
: QMainWindow(parent)
{
    VX_I(VxMainWindosw);

    d->_databaseManager = databaseManager;
    d->_commandManager = commandManager;

    connect(d->_input, &QLineEdit::textEdited, d->_commandManager, &VxCommandManager::handleCommand);
}

VxMainWindosw::~VxMainWindosw()
{

}
