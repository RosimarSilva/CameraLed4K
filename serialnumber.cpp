#include "serialnumber.h"
#include "QDebug"

SerialNumber::SerialNumber(QObject *parent) :
    QObject(parent)
{
 qDebug() << Q_FUNC_INFO;
 // flash = new SerialIke(this);
}

SerialNumber::~SerialNumber()
{
    qDebug() << Q_FUNC_INFO;
    //delete flash;
}

void SerialNumber::setSerialNumber(const int number)
{
    qDebug()<<number;
    switch (number)
    {
       case 1:
       {
            if(contSerial <= 5)
            {
                auxSerial = number;
                serialDig = serialDig*10;
                serialDig = serialDig += auxSerial;
                contSerial ++;
             }

       } break;

       case 2:
      {
        if(contSerial <= 5)
        {
            auxSerial = number;
            serialDig = serialDig*10;
            serialDig = serialDig += auxSerial;
            contSerial ++;
         }
      } break;

       case 3:
     {
        if(contSerial <= 5)
        {
            auxSerial = number;
            serialDig = serialDig*10;
            serialDig = serialDig += auxSerial;
            contSerial ++;
         }
      } break;

      case 4:
      {
        if(contSerial <= 5)
        {
            auxSerial = number;
            serialDig = serialDig*10;
            serialDig = serialDig += auxSerial;
            contSerial ++;
         }
      } break;

      case 5:
     {
        if(contSerial <= 5)
        {
            auxSerial = number;
            serialDig = serialDig*10;
            serialDig = serialDig += auxSerial;
            contSerial ++;
         }
     } break;

     case 6:
     {
        if(contSerial <= 5)
        {
            auxSerial = number;
            serialDig = serialDig*10;
            serialDig = serialDig += auxSerial;
            contSerial ++;
         }
      } break;

      case 7:
      {
        if(contSerial <= 5)
        {
            auxSerial = number;
            serialDig = serialDig*10;
            serialDig = serialDig += auxSerial;
            contSerial ++;
         }
      } break;

      case 8:
      {
        if(contSerial <= 5)
        {
            auxSerial = number;
            serialDig = serialDig*10;
            serialDig = serialDig += auxSerial;
            contSerial ++;
         }
      } break;

      case 9:
      {
        if(contSerial <= 5)
        {
            auxSerial = number;
            serialDig = serialDig*10;
            serialDig = serialDig += auxSerial;
            contSerial ++;
         }
      } break;

      case 0:
      {
        if(contSerial <= 5)
        {
            auxSerial = number;
            serialDig = serialDig*10;
            serialDig = serialDig += auxSerial;
            contSerial ++;
         }
      } break;
      case 100://tecla ok
      {
          this->writeNumberFlash();

             contSerial = 0;
             serialDig = 0;
      } break;

      case 99://tecla del
      {
         if(contSerial == 4) {serialDig = serialDig - auxSerial; serialDig = serialDig/10;}

         else if(contSerial == 3)serialDig = serialDig/10;

           else if(contSerial == 2) serialDig = serialDig/10;

         else if(contSerial == 1)serialDig = serialDig/10;

         else if(contSerial == 0) serialDig = 0;


          if(serialDig <= 0)serialDig = 0;
           contSerial --;
          if(contSerial < 0) contSerial = 0;
      } break;
    }

    this->setNumberSerie(serialDig);
}

void SerialNumber::setNumberSerie(const int serial)
{

    if(m_serial != serial)
    {
        m_serial = serial;

        emit serialChanged();
        qDebug() << serial;

    }
}

int SerialNumber::serialNumber()
{
    return serialDig;
}

void SerialNumber::writeNumberFlash()
{
    QFile escrito;

    NumberSerial[0] = serialDig;

    escrito.setFileName("/root/serialNumber"); // caminho de onde está salvo os dados de calibração
    if(!escrito.open(QIODevice::WriteOnly))
    {
        qDebug("Fallha ao abrir o arquivo");

        return;
    }
  escrito.write(NumberSerial);
   escrito.flush();
   escrito.close();
}

void SerialNumber::readNumberFlash()
{
    QFile arquivo;

    arquivo.setFileName("/root/serialNumber"); // caminho de onde está salvo os dados de calibração
    if(!arquivo.open(QIODevice::ReadOnly))
    {
        qDebug("Falaha ao abrir o arquivo");

        return;
    }
    qDebug(" abriu o arquivo");

    NumberSerial = arquivo.readAll();
    serialDig =  NumberSerial[0];

    arquivo.close();
}


