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

    QStringList m_birdKinds;

signals:
    void sig_finishReading();

public slots:
    void slotOfThread();
    void slot_getBirdsList();
};

#endif // QSERVICEOBJECT_H
