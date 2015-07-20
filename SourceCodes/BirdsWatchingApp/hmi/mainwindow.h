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
    Ui::MainWindow *ui;
    QChooseBird *dlgChooseBird;
    QThread *serviceThread;
    QServiceObject *serviceObject;

signals:
    void sig_getBirdsList();

public slots:
    void slot_finishReading();

private slots:
    void ShowChooseBirdDlg();
};

#endif // MAINWINDOW_H
