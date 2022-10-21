// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// LobgPushTimer.cpp
//
// 長押しを検出してシグナルを発します。
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include <QWidget>
#include <QTimer>

#include "LongPressTimer.h"


static LongPressTimer   sLongPressTimerA;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// タイマ
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void ECF_startLongPressTimer(QWidget *Btn ,int32_t Milisec ,QObject *SlotObj ,const char *SlotName)
{
    sLongPressTimerA.start(Btn ,Milisec ,SlotObj ,SlotName);
}

LongPressTimer::LongPressTimer(QObject *Obj)
    : QObject(Obj)
    , m_Timer(new QTimer(this))
{
    m_Timer->connect(m_Timer ,SIGNAL(timeout()) ,this ,SLOT(onTimeout()));
}
LongPressTimer::~LongPressTimer()
{
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// タッチされたら呼んで
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void LongPressTimer::start(QWidget *Btn ,int32_t Milisec ,QObject *SlotObj ,const char *SlotName)
{
    connect(Btn  ,SIGNAL(released()) ,this ,SLOT(onReleased()));
    connect(this ,SIGNAL(longtouch()) ,SlotObj ,SlotName);

    m_Timer->start(Milisec);    // 長押しタイマ発動
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// リリースされたら呼ばれる
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void LongPressTimer::onReleased()
{
    m_Timer->stop();

    disconnect();
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// タイマが発動したら呼ばれる
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void LongPressTimer::onTimeout()
{
    m_Timer->stop();

    emit longtouch();
}

