#ifndef INIT_H
#define INIT_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class Init:public QObject
{
     Q_OBJECT

public:
    Init(QObject* parent = nullptr);
    ~Init();
    Q_INVOKABLE void setTime(void);
    Q_INVOKABLE void setTime4(void);
    Q_INVOKABLE void setTime5(void);
    Q_INVOKABLE void setTime6(void);
    Q_INVOKABLE void setTime7(void);
    Q_INVOKABLE void setTime8(void);
    Q_INVOKABLE void setTime9(void);
    Q_INVOKABLE void setTime10(void);


public slots:
    void setInit(void);
     void setinit_3(void);
      void setinit_4(void);
       void setinit_5(void);
        void setinit_6(void);
        void setinit_7(void);
         void setinit_8(void);
          void setinit_9(void);
           void setinit_10(void);

signals:
    void init_2(void);
     void init_3(void);
     void init_4(void);
     void init_5(void);
     void init_6(void);
     void init_7(void);
     void init_8(void);
     void init_9(void);
     void init_10(void);

private:

    QTimer *tempoInit;
     QTimer *tempoInit3;
      QTimer *tempoInit4;

      QTimer *tempoInit5;
       QTimer *tempoInit6;
        QTimer *tempoInit7;

        QTimer *tempoInit8;
         QTimer *tempoInit9;
          QTimer *tempoInit10;

};

#endif // INIT_H
