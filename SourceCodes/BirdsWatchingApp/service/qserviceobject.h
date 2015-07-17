#ifndef QSERVICEOBJECT_H
#define QSERVICEOBJECT_H

#include <QObject>
#include <QThread>
#include <QDebug>

class QServiceObject : public QObject
{
    Q_OBJECT
public:
    explicit QServiceObject(QObject *parent = 0);
    void showObjectThreadID();

signals:
    void again();
public slots:
    void slotOfThread();
};

#endif // QSERVICEOBJECT_H
