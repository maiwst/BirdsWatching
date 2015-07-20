#include "qchoosebird.h"
#include "ui_dlg_choosebird.h"

QChooseBird::QChooseBird(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QChooseBird)
{
    ui->setupUi(this);
}

QChooseBird::~QChooseBird()
{
    delete ui;
}
