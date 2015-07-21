#include "qchoosebird.h"
#include "ui_dlg_choosebird.h"
#include <QDebug>
#include <QThread>


QChooseBird::QChooseBird(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QChooseBird)
    , m_list(new QStringList)
{
    ui->setupUi(this);
}

QChooseBird::~QChooseBird()
{
    delete ui;
}

void QChooseBird::slot_ready2show()
{
    emit sig_getBirdsList(m_list);
}

void QChooseBird::slot_finishReading()
{
    qDebug()<<"MainWindow::slot_finishReading() thread id = "<<QThread::currentThreadId();
    qDebug()<<"birds list is "<<*m_list;

    ui->lw_birdKindsListWidget->addItems(*m_list);
    if(this->exec() == QDialog::Accepted)
        emit sig_birdChosen(ui->lw_birdKindsListWidget->currentItem()->text());

}

