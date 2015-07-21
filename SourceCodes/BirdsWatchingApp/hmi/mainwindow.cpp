#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "windows.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serviceThread(new QThread())
    , serviceObject(new QServiceObject())
    , dlgChooseBird(new QChooseBird(this))

{
    ui->setupUi(this);
    ui->lbl_currentBird->setText("NONE");

    connect(serviceThread, SIGNAL(started()), serviceObject, SLOT(slotOfThread()));
    connect(ui->btn_chooseBird, SIGNAL(clicked()), dlgChooseBird, SLOT(slot_ready2show()));
    connect(dlgChooseBird, SIGNAL(sig_getBirdsList(QStringList*)), serviceObject, SLOT(slot_getBirdsList(QStringList*)));
    connect(serviceObject, SIGNAL(sig_finishReading()), dlgChooseBird, SLOT(slot_finishReading()));
    connect(dlgChooseBird, SIGNAL(sig_birdChosen(QString)), this, SLOT(slot_setCurrentBird(QString)));

    qDebug()<<"main thread id = "<<QThread::currentThreadId();
    serviceObject->moveToThread(serviceThread);
    serviceObject->showObjectThreadID();
    serviceThread->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_setCurrentBird(QString str)
{
    currentBird = str;
    ui->lbl_currentBird->setText(currentBird);
}
