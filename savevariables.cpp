#include "savevariables.h"
#include "ui_savevariables.h"

SaveVariables::SaveVariables(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaveVariables)
{
    ui->setupUi(this);
}

SaveVariables::~SaveVariables()
{
    delete ui;
}
