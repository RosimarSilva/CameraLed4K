#include "calendario.h"
#include <QDebug>

Calendario::Calendario(QObject *parent) :
    QObject(parent)
{
qDebug() << Q_FUNC_INFO;
}

Calendario::~Calendario()
{
   qDebug() << Q_FUNC_INFO;
}

void Calendario::setDia(const int value)
{
    if(m_day != value)
    {
        m_day = value;
        emit changedDia();
    }
}

int Calendario::dia() const
{
    return m_day;
}

void Calendario::setMes(const int value)
{
    if(m_month != value)
    {
        m_month = value;
        emit changedMes();
    }
}

int Calendario::mes() const
{
    return m_month;
}

void Calendario::setAno(const int value)
{
    if(m_year != value)
    {
        m_year = value;
        emit changedAno();
    }
}

int Calendario::ano() const
{
    return m_year;
}

void Calendario::setMinuto(const int value)
{
    if(m_minute != value)
    {
        m_minute = value;
        emit changeMinuto();
    }
}

int Calendario::minuto() const
{
    return  m_minute;
}

void Calendario::setHora(const int value)
{
    if(m_hour != value)
    {
        m_hour = value;
        emit changedHora();
    }
}

int Calendario::hora() const
{
    return  m_hour;
}

void Calendario::setDay(char sinal)
{
    switch(sinal)
    {
        case 1:
        {
            day= day += 1;
            if(day > 31) day = 1;

        }break;

        case 2:
        {
           day= day -= 1;
            if(day <= 0) day = 31;
         }break;

    }

    this->setDia(day);
}

void Calendario::setMonth(char sinal)
{
    switch(sinal)
    {
        case 3:
        {
            month= month += 1;
            if(month > 12)month =1;
        }break;

        case 4:
        {
           month= month -= 1;
            if(month <= 0)month =1;
         }break;

    }

    this->setMes(month);
}

void Calendario::setYear(char sinal)
{
    switch(sinal)
    {
        case 5:
        {
            year= year += 1;
        }break;

        case 6:
        {
           year= year -= 1;
           if(year <= 18) year = 18;
         }break;

    }

    this->setAno(year);
}

void Calendario::setHour(char sinal)
{
    switch(sinal)
    {
        case 5:
        {
            hour= hour += 1;
             if(hour >= 24)hour =0;
        }break;

        case 6:
        {
         hour= hour -= 1;
         if(hour < 0)hour =23;
         }break;

    }
    qDebug() <<hour;
    this->setHora(hour);
}

void Calendario::setminute(char sinal)
{
    switch(sinal)
    {
        case 5:
        {
            minute= minute += 1;
             if(minute >= 60)minute =0;
        }break;

        case 6:
        {
         minute= minute -= 1;
         if(minute < 0)minute =60;
         }break;

    }
 qDebug() <<minute;
    this->setMinuto(minute);
}
