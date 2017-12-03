#include "stdafx.h"
#include "VxMainWindosw.h"
#include "VxWorld.h"

class VxMainWindoswImpl : public Impl<VxMainWindosw>
{
public:
    VX_EMPTY_CTOR(VxMainWindosw);

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

    d->_world = new VxWorld(this);
    d->_input = new QLineEdit(this);
    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->addWidget(d->_input);
    mainLayout->addWidget(d->_world);
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(d->_input, &QLineEdit::returnPressed, this, &VxMainWindosw::sendcommand);
}

VxMainWindosw::~VxMainWindosw()
{

}

void VxMainWindosw::sendcommand()
{
    d->_commandManager->handleCommand(d->_input->text());
}
