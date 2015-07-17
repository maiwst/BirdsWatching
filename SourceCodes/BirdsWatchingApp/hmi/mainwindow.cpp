#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serviceThread = new QThread();
    qDebug()<<"main thread id = "<<QThread::currentThreadId();
    serviceObject = new QServiceObject();
    serviceObject->moveToThread(serviceThread);
    connect(serviceThread, SIGNAL(started()), serviceObject, SLOT(slotOfThread()));
    serviceObject->showObjectThreadID();
    serviceThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
