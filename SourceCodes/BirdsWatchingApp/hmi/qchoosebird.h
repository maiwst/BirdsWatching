#ifndef QCHOOSEBIRD_H
#define QCHOOSEBIRD_H

#include <QDialog>

namespace Ui {
class QChooseBird;
}

class QChooseBird : public QDialog
{
    Q_OBJECT

public:
    explicit QChooseBird(QWidget *parent = 0);
    ~QChooseBird();

private:
    Ui::QChooseBird*    ui;
    QStringList*        m_list;

signals:
    void sig_getBirdsList(QStringList* pList);
    void sig_birdChosen(QString str);

public slots:
    void slot_ready2show();
    void slot_finishReading();
};

#endif // QCHOOSEBIRD_H
