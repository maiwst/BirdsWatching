#include "qserviceobject.h"
#include "dummy_data.h"


QServiceObject::QServiceObject(QObject *parent)
    : QObject(parent)
{
    m_birdKinds.clear();
}

void QServiceObject::showObjectThreadID()
{
    qDebug()<<"# QServiceObject thread id = "<<QThread::currentThreadId();
}

void QServiceObject::slotOfThread()
{
    qDebug()<<" QServiceObject slot thread id = "<<QThread::currentThreadId();
}

void QServiceObject::slot_getBirdsList(QStringList* pList)
{
    /****************************/
    // call API of DB
    /****************************/
    qDebug()<<" QServiceObject::slot_getBirdsList thread id = "<<QThread::currentThreadId();
    pList->clear();
    for(int i = 0; i < (int)(sizeof(BIRDS_DATA) / sizeof(BIRDS_DATA[0])); i++)
    {
        QString temp = QString(BIRDS_DATA[i][1]);
        if(!pList->contains(temp))
            pList->append(QString(BIRDS_DATA[i][1]));
    }

    emit sig_finishReading();
}
