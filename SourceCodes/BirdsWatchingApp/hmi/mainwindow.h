#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "service/qserviceobject.h"
#include "qchoosebird.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow*     ui;
    QThread*            serviceThread;
    QServiceObject*     serviceObject;
    QChooseBird*        dlgChooseBird;
    QString             currentBird;

public slots:
    void slot_setCurrentBird(QString str);
};

#endif // MAINWINDOW_H
