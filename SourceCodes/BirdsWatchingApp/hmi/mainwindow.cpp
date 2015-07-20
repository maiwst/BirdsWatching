#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    //, dlgChooseBird(new QChooseBird(this))
{
    ui->setupUi(this);

    serviceThread = new QThread();
    qDebug()<<"main thread id = "<<QThread::currentThreadId();
    serviceObject = new QServiceObject();
    serviceObject->moveToThread(serviceThread);
    connect(serviceThread, SIGNAL(started()), serviceObject, SLOT(slotOfThread()));
    serviceObject->showObjectThreadID();
    serviceThread->start();

    connect(ui->btn_chooseBird, SIGNAL(clicked()), this, SLOT(ShowChooseBirdDlg()));
    //connect(ui->btn_chooseBird, SIGNAL(clicked()), dlgChooseBird, SLOT(show()));
    connect(this, SIGNAL(sig_getBirdsList()), serviceObject, SLOT(slot_getBirdsList()));
    connect(serviceObject, SIGNAL(sig_finishReading()), this, SLOT(slot_finishReading()));

    ui->lbl_currentBird->setText("NONE");


    qDebug()<<"before emitting, str is "<<serviceObject->m_birdKinds;
    emit sig_getBirdsList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_finishReading()
{
    qDebug()<<"MainWindow::slot_finishReading() thread id = "<<QThread::currentThreadId();
    qDebug()<<"after emitting, str is "<<serviceObject->m_birdKinds;
}

void MainWindow::ShowChooseBirdDlg()
{
    if(!dlgChooseBird)
        dlgChooseBird = new QChooseBird(this);

    dlgChooseBird->show();
}
