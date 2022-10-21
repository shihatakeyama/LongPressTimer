// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// LobgPushTimer.h
//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#ifndef LONGPLESSTIMER_H
#define LONGPLESSTIMER_H

#include <QObject>

class QTimer;

class LongPressTimer
    : private QObject
{
    Q_OBJECT
public:
    LongPressTimer(QObject *Obj = nullptr);
    ~LongPressTimer();

    void start(QWidget *Btn ,int32_t Milisec ,QObject *SlotObj ,const char *SlotName);

signals:
    void longtouch();

private slots:
    void onReleased();
    void onTimeout();

private:
    QTimer *m_Timer;
};

#endif // LONGPLESSTIMER_H

