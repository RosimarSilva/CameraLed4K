#include "init.h"
#include "QTimer"

Init::Init(QObject *parent): QObject(parent)
{
    tempoInit = new QTimer();
     tempoInit3 = new QTimer();
     tempoInit4 = new QTimer();

     tempoInit5 = new QTimer();
      tempoInit6 = new QTimer();
      tempoInit7 = new QTimer();

      tempoInit8= new QTimer();
       tempoInit9 = new QTimer();
       tempoInit10 = new QTimer();
qDebug() << Q_FUNC_INFO;

    tempoInit->start(1000);
    connect(tempoInit,SIGNAL(timeout()),this,SLOT(setInit()));


      connect(tempoInit3,SIGNAL(timeout()),this,SLOT(setinit_3()));

      connect(tempoInit4,SIGNAL(timeout()),this,SLOT(setinit_4()));

       connect(tempoInit5,SIGNAL(timeout()),this,SLOT(setinit_5()));

       connect(tempoInit6,SIGNAL(timeout()),this,SLOT(setinit_6()));

        connect(tempoInit7,SIGNAL(timeout()),this,SLOT(setinit_7()));

        connect(tempoInit8,SIGNAL(timeout()),this,SLOT(setinit_8()));

         connect(tempoInit9,SIGNAL(timeout()),this,SLOT(setinit_9()));

            connect(tempoInit10,SIGNAL(timeout()),this,SLOT(setinit_10()));

}

Init::~Init()
{
    delete tempoInit;
    qDebug() << Q_FUNC_INFO;
}

void Init::setTime()
{
    tempoInit3->start(2000);
}

void Init::setTime4()
{
   tempoInit4->start(2000);

}

void Init::setTime5()
{
     tempoInit5->start(2000);
}
void Init::setTime6()
{
     tempoInit6->start(2000);
}
void Init::setTime7()
{
     tempoInit7->start(2000);
}
void Init::setTime8()
{
     tempoInit8->start(2000);
}
void Init::setTime9()
{
     tempoInit9->start(2000);
}
void Init::setTime10()
{
     tempoInit10->start(2000);
}

void Init::setInit(void)
{
    emit init_2();
    delete tempoInit;
}

void Init::setinit_3()
{
    emit init_3();
      delete tempoInit3;

}

void Init::setinit_4()
{
    emit init_4();
     delete tempoInit4;
}

void Init::setinit_5()
{
    emit init_5();
    delete tempoInit5;
}

void Init::setinit_6()
{
    emit init_6();
    delete tempoInit6;
}

void Init::setinit_7()
{
    emit init_7();
    delete tempoInit7;
}
void Init::setinit_8()
{
    emit init_8();
    delete tempoInit8;
}
void Init::setinit_9()
{
    emit init_9();
    delete tempoInit9;
}

void Init::setinit_10()
{
    emit init_10();
    delete tempoInit10;
}
