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
    Ui::QChooseBird *ui;
};

#endif // QCHOOSEBIRD_H
