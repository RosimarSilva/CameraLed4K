#include "serialike.h"



SerialIke::SerialIke(QObject *parent): QObject(parent)
{   port = new QSerialPort();
    out_ = new QByteArray();

     t1 = new QTimer;
     t2 = new QTimer;
    // t3 = new QTimer;
    //  t4 = new QTimer;
     // timeGravando = new QTimer;

       // pergunte.stop();
        qDebug() << Q_FUNC_INFO;


    // connect(this,&SerialIke::setscreen,this,&SerialIke::goTela);

   //  connect(t3,&QTimer::timeout,this,&SerialIke::initEquip);
    // t3->start(100);

     connect(this,&SerialIke::setWhiteNeg,this,&SerialIke::negaWhite);

      connect(this,&SerialIke::setWhiteAcept,this,&SerialIke::aceptWhite);

      connect(t1,&QTimer::timeout,this,&SerialIke::piscWhiteBlance);
      t1->start(800);

      connect(t2,&QTimer::timeout,this,&SerialIke::piscWbNegval);
      t1->start(800);

     // connect(port, SIGNAL(readyRead()),this, SLOT(readBytes()));

     //  connect(&pergunte, SIGNAL(timeout()),this, SLOT(perguntas()));


       // connect(&timeError, SIGNAL(timeout()),this, SLOT(perguntaMidia()));


       //  connect(timeGravando, SIGNAL(timeout()),this, SLOT(perguntaMidia()));

        //  connect(&clearRec, SIGNAL(timeout()),this, SLOT(recClear()));


       init(1);

}

SerialIke::~SerialIke()
{
    delete port;
    delete t1;
    delete t2;
 //   delete t3;
     //delete t4;
    delete timeGravando;

    timeError.stop();
    pergunte.stop();
qDebug() << Q_FUNC_INFO;

    delete out_;
}


bool SerialIke::openSerial(const QString &name)  //abrea serial
{
   port->close();
    port->setPortName(name);
    open_ = port->open(QIODevice::ReadWrite);
    return open_;
}

bool SerialIke::isopen()  //fala se a serial esta aberta ou não
{
    return open_;
}

bool SerialIke::paramSet(const QString &name, const QString &value)
{
    if (!isopen()) return false;

    if (name == "baud")        return port->setBaudRate(value.toInt());
    else if (name == "bits")   return port->setDataBits((QSerialPort::DataBits)value.toInt());
    else if (name == "parity") return port->setParity(
        value.startsWith("n") ? QSerialPort::NoParity :
        value.startsWith("e") ? QSerialPort::EvenParity :
        value.startsWith("o") ? QSerialPort::OddParity :
        value.startsWith("s") ? QSerialPort::SpaceParity :
        value.startsWith("m") ? QSerialPort::MarkParity :
        QSerialPort::UnknownParity
    );
    else if (name == "stops") return port->setStopBits((QSerialPort::StopBits)value.toInt());
    else if (name == "rts")   return port->setRequestToSend((bool)value.toInt());
    else if (name == "dtr")   return port->setDataTerminalReady((bool)value.toInt());
    else return false;
}
// recebe o comando e eo envia
int SerialIke::writeBytes(const QList<int> &l, const int resp)
{
    QList<int> *d = new QList<int>();
     QList<int> *bytes = new QList<int>();

     QList<int> *b = new QList<int>();
     QSerialPort serial;
     char data;
     QByteArray buf;

     bytes = 0;
    if (isopen()){
        if (!l.size()) return true;
        out_->resize(l.size());
        for (int i=0; i<l.size(); i++) out_->data()[i] = l[i];
    }

    comando = resp;

    port->write(*out_) > 0;

    port->clearError();

   // port->reset();
    return true;
}

void SerialIke::cahngeTela()
{
    this ->setscreen();
}
//muda para a tela menu
void SerialIke::changedMenu()
{
    this->setScreenMenu();
}
void SerialIke::setScreenMenu()  // muda para a tela menu
{
    emit menuChanged();
}

//muda da tela menu para a tela principal
void SerialIke::requestmenu_TelaPrincipal()
{
    this->setMenu_telaPrincipal();
}

void SerialIke::displayOff()
{
    QFile pathBacklightPower("/sys/class/graphics/fb0/blank");
    if(pathBacklightPower.exists() && pathBacklightPower.open(QIODevice::WriteOnly | QIODevice::Text)) {
        pathBacklightPower.write("4");
        pathBacklightPower.close();
    }
}

void SerialIke::displayOn()
{
    QFile pathBacklightPower("/sys/class/graphics/fb0/blank");
    if(pathBacklightPower.exists() && pathBacklightPower.open(QIODevice::WriteOnly | QIODevice::Text)) {
        pathBacklightPower.write("0");
        pathBacklightPower.close();
    }
}

void SerialIke::displayBrightness(const int luz)
{
    QFile pathBacklightBrightness("/sys/class/backlight/pwm-backlight.0/brightness");
    if(pathBacklightBrightness.exists() && pathBacklightBrightness.open(QIODevice::WriteOnly| QIODevice::Text)) {

        pathBacklightBrightness.write(QByteArray::number(luz));
        pathBacklightBrightness.close();
}
}
/*desliga o equipamento
void SerialIke::powerOff()
{
   // qDebug() << Q_FUNC_INFO;

#ifdef Q_PROCESSOR_ARM
    QProcess::startDetached("poweroff");
#endif

#ifdef Q_PROCESSOR_X86
    qInfo() << "Recurso não suportado ou desabilitado";
#endif
}

*/

void SerialIke::init(int comander)
{

    openSerial("ttymxc0");


   if(isopen())
   {
      paramSet("baud", "19200");
      paramSet("bits", "8");
      paramSet("parity", "n");
       paramSet("stops", "1");

        paramSet("dtr", "1");
      paramSet("rts", "1");
    }

       readFlash();
        trocaUser(1);

        openSerial("ttymxc0");
          writeBytes({0xA5,0x06,0x0a,0x00,0xc4,0x49},1);// habilita o drive do led
         // t4->setInterval(100);
          setIntensidadeLed(1);
         //  t4->setInterval(100);

           openSerial("ttymxc0");
           writeBytes({0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x20,0x20,
                                0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x6b},0);
         //  t4->setInterval(200);
            openSerial("ttymxc0");
           writeBytes({0xA5,0x07,0x09,0x0A,0x00,0xbf,0xcf},0);
          // mensagens(80,0);
           //mensagens(800,0);
          // t4->setInterval(10000);
         //  trocaUser(3);

        //   mensagens(13,1);

}
/****************************************************************************************
 * chama os comandos requisitados pelo Qml********************************************/
void SerialIke::setComandoIke(int comando_)
{
    int i =0;
    int tamanho,aux_enh,auxVideo;

     ikeenv[0] = 0x7A;ikeenv[1] = 0x13;ikeenv[2] = 0x00;
   switch(comando_)
   {
       case 1:  // comando correspondente do white balance
       {
          whiteBalance = true;
          ikeenv[3] = 0x04; ikeenv[4] = 0x19; ikeenv[5] = 0x09; ikeenv[6] = 0x00;// comando[7] = 0x07;

          ikeenv[7] = bcc(6);

           tamanho = 7;

           comando = 1;
        } break;

        case 2:  // chama o user Menu
        {
             ikeenv[3] = 0x07;ikeenv[4] = 0x14;

             ikeenv[5] = 0x81;ikeenv[6] = 0x67; ikeenv[7] = 0x10;ikeenv[8] = 0x80;ikeenv[9] = 0x00;

             ikeenv[10] = bcc(9);

             comando = 1;

             tamanho = 10; // tamanho do frame

        }break;

         case 3:  // sai fora do user Menu
        {
             ikeenv[3] = 0x07;ikeenv[4] = 0x14;

             ikeenv[5] = 0x81;ikeenv[6] = 0x67; ikeenv[7] = 0x90;ikeenv[8] = 0x80;ikeenv[9] = 0x00;

             ikeenv[10] = bcc(9);

             comando = 0;

            tamanho = 10; // tamanho do frame

       }break;

   case 4:  // CHAMA O ZOOM
  {

       switch(zoom)
       {
           case 16 : zoom = 21;break;
           case 21: zoom = 26;  break;
           case 26: zoom = 31; break;
           case 31: zoom = 16; break;
       }


       ikeenv[3] = 0x07;ikeenv[4] = 0x14;

       ikeenv[5] = 0x8F;ikeenv[6] = 0x6F; ikeenv[7] = zoom;ikeenv[8] = 0x80;ikeenv[9] = 0x00;

       ikeenv[10] = bcc(9);

       comando = 0;

      tamanho = 10; // tamanho do frame
      //qDebug() <<zoom;

 }break;

   case 5:  // manda o enhancement para a ikegami
   {

       if(user != 3)
       {
          if(enhancement == enhancementHigh)
         {
           enhancement = enhancementMed;

           this->setEnhanceMed();
           // qDebug() << enhancement;
        }

         else if(enhancement == enhancementLow) {
           enhancement = enhancementHigh;
           this->setEnhanceHigh();
           // qDebug() << enhancement;
         }

         else if(enhancement == enhancementMed)
         {
            enhancement = enhancementLow;

            this->setEnhanceLow();
           // qDebug() << enhancement;
         }
       }
       else {
            enhancement = 0;

            this->setEnhanceOff();
         }

       ikeenv[3] = 0x06;ikeenv[4] = 0x1D;ikeenv[5] = 0x7D;

       ikeenv[8] = 0x00;

       aux_enh = enhancement*16; //multiplica por 16 para mandar para a ikegami

       if(aux_enh < 0) aux_enh = 0xFFFF + aux_enh +1; // calcula o complemento de 1


       ikeenv[6] = aux_enh/256 ;ikeenv[7] = aux_enh%256;

       ikeenv[9] = bcc(8);

       comando = 0;

      tamanho = 9; // tamanho do frame
   }break;

   case 6: //SET AUTO FOLDER
   {
       ikeenv[3] = 0x06;ikeenv[4] = 0x14;ikeenv[5] = 0x8F;ikeenv[6] = 0x31; ikeenv[7] = 0x80;

      ikeenv[8] = 0x00;ikeenv[9] = bcc(8);
      comando = 6;
      tamanho = 9;
   }break;

   case 50:// pergunta o enhancement que esta no user correspondente
   {
       ikeenv[3] = 0x04;ikeenv[4] = 0x25;ikeenv[5] = 0x7D;

       ikeenv[6] = 0x00;   ikeenv[7] = bcc(6);

        comando = 50;

        tamanho = 7;
   }break;

   case 24:// pergunta qual é o vídeo level
   {
       ikeenv[3] = 0x06;ikeenv[4] = 0x25;ikeenv[5] = 0x8F;ikeenv[6] = 0x11; ikeenv[7] = 0x80;

      ikeenv[8] = 0x00;ikeenv[9] = bcc(8);

      comando = 24;

      tamanho = 9;
    }break;

   case 12:// manda o ganho para a ikegami
   {
       if(videoLevel == videoLevelLow)
       {
           videoLevel = videoLevelHigh;
          this->setGanhoMed();// atualiza a figura no display
        }

       else if(videoLevel == videoLevelHigh)
       {
            videoLevel = videoLevelHigh2;

            this->setGanhoHigh();// atualiza a figura no display
        }

       else if(videoLevel == videoLevelHigh2)
       {
           videoLevel = videoLevelLow;

           this->setGanhoLow(); // atualiza a figura no display
        }

       ikeenv[3] = 0x0C;ikeenv[4] = 0x1D;ikeenv[5] = 0x8F;ikeenv[6] = 0x8F; ikeenv[7] = 0x8F;

      ikeenv[8] = 0x11; ikeenv[11] = 0x80;ikeenv[12] = 0x80; ikeenv[13] = 0x8F;ikeenv[14] = 0x00;

      auxVideo = videoLevel*32; //multiplica por 32 para mandar para a ikegami

      if(auxVideo < 0) auxVideo = 0xFFFF + auxVideo + 1; // calcula o complemento de 1

      ikeenv[9] = auxVideo/256;     ikeenv[10] = auxVideo%256;

       ikeenv[15] = bcc(14);

       comando = 0;

       tamanho = 15;


   }break;

   case 157://troca de user
   {
       ikeenv[3] = 0x05;ikeenv[4] = 0x16;ikeenv[5] = 0x11;

       ikeenv[6] = user + 0x10; ikeenv[7] = 0x00;

       ikeenv[8] = bcc(7);

       comando = 0;
       tamanho = 8;
   }break;

   case 40:  //escreve o zoom nomonitor
   {
      // switch(zoom)
      // {
         if(zoom == 16)//apaga o zoom
       {
            ikeenv[3] = 0x0C;ikeenv[4] = 0x30;ikeenv[5] = 0x10;ikeenv[6] = 0x20; ikeenv[7] = 0x3E;

           ikeenv[8] = 0x11;ikeenv[9] = 0x27;ikeenv[10] = 0x20;ikeenv[11] = 0x20;ikeenv[12] = 0x20;

           ikeenv[13] = 0x20;ikeenv[14] = 0x00;ikeenv[15] = bcc(14);


           comando = 0;
           tamanho = 15;
       }

     else if(zoom ==21)//x:1,5
       {
             ikeenv[3] = 0x0C;ikeenv[4] = 0x30;ikeenv[5] = 0x10;ikeenv[6] = 0x20; ikeenv[7] = 0x3E;

            ikeenv[8] = 0x11;ikeenv[9] = 0x27;ikeenv[10] = 0x78;ikeenv[11] = 0x31;ikeenv[12] = 0x2E;

            ikeenv[13] = 0x35;ikeenv[14] = 0x00;ikeenv[15] = bcc(14);

          comando = 0;
          tamanho = 15;

       }

         if(zoom == 26)//x:2,0
       {
             ikeenv[3] = 0x0C;ikeenv[4] = 0x30;ikeenv[5] = 0x10;ikeenv[6] = 0x20; ikeenv[7] = 0x3E;

            ikeenv[8] = 0x11;ikeenv[9] = 0x27;ikeenv[10] = 0x78;ikeenv[11] = 0x32;ikeenv[12] = 0x2E;

            ikeenv[13] = 0x30;ikeenv[14] = 0x00;ikeenv[15] = bcc(14);

            comando = 0;
            tamanho = 15;


       }

     else if(zoom ==31)//x:2,5
         {
           ikeenv[3] = 0x0C;ikeenv[4] = 0x30;ikeenv[5] = 0x10;ikeenv[6] = 0x20; ikeenv[7] = 0x3E;

          ikeenv[8] = 0x11;ikeenv[9] = 0x27;ikeenv[10] = 0x78;ikeenv[11] = 0x32;ikeenv[12] = 0x2E;

          ikeenv[13] = 0x35;ikeenv[14] = 0x00;ikeenv[15] = bcc(14);

          comando = 0;
          tamanho = 15;

         }

    }break;

   case 167: //manda enhancement para a ikegami
   {
       ikeenv[3] = 0x07;ikeenv[4] = 0x14;ikeenv[5] = 0x8F;ikeenv[6] = 0x6A; ikeenv[7] = 0x12;

      ikeenv[8] = 0x80;ikeenv[9] = 0x00;ikeenv[10] = bcc(9);

      comando = 5;
      tamanho = 10;
   }break;

      case 30://ESCREVE ENHANCEMENT OFF
     {
       ikeenv[3] = 0x1A;ikeenv[4] = 0x30;ikeenv[5] = 0x10;ikeenv[6] = 0x2A; ikeenv[7] = 0x3E;ikeenv[8] = 0x11;ikeenv[9] = 0x27;

       ikeenv[10] = 0x45;ikeenv[11] = 0x4E;ikeenv[12] = 0x48;ikeenv[13] = 0x41; ikeenv[14] = 0x4E;ikeenv[15] = 0x43;ikeenv[16] = 0x45;

       ikeenv[17] = 0x4D;ikeenv[18] = 0x45; ikeenv[19] = 0x4E;ikeenv[20] = 0x54;ikeenv[21] = 0x20; ikeenv[22] = 0x4F;ikeenv[23] = 0x46;

       ikeenv[24] = 0x46; ikeenv[25] = 0x20;ikeenv[26] = 0x20;ikeenv[27] = 0x20;ikeenv[28] = 0x00;

       ikeenv[29] = bcc (28);

       comando = 0;
       tamanho = 29;

      }break;

   case 1001://manda parar a gravação
   {
       ikeenv[3] = 0x05;ikeenv[4] = 0x14;ikeenv[5] = 0x71;ikeenv[6] = 0x10; ikeenv[7] = 0x00;

       ikeenv[8] = bcc(7);

       comando = 1001;
       tamanho = 8;
        qDebug("mandei parar");

   }break;

   case 1002://manda iniciar a gravção
   {
       ikeenv[3] = 0x05;ikeenv[4] = 0x14;ikeenv[5] = 0x71;ikeenv[6] = 0x11; ikeenv[7] = 0x00;

       ikeenv[8] = bcc(7);

       comando = 1002;
       tamanho = 8;
       // qDebug("mandei gravar");
       //  pergunte.start(300);

   }break;

   case 1003://pergunta se esta em gravação ou não
   {
       ikeenv[3] = 0x06;ikeenv[4] = 0x24;ikeenv[5] = 0x82;ikeenv[6] = 0x7E; ikeenv[7] = 0x80;ikeenv[8] = 0x00;

       ikeenv[9] = bcc(8);

       comando = 1003;
       tamanho = 9;
      //  qDebug("ta gravando ? ou não");
//          pergunte.stop();

   }break;

   case 1004://manda iniciar a placa de gravação
   {
       ikeenv[3] = 0x06;ikeenv[4] = 0x14;ikeenv[5] = 0x8F;ikeenv[6] = 0x30; ikeenv[7] = 0x80;ikeenv[8] = 0x00;

       ikeenv[9] = bcc(8);

       comando = 1004;
       tamanho = 9;
        qDebug("mandei inicializar");

   }break;

   case 1005://pergunta se gravação  já esta no ar
   {
       ikeenv[3] = 0x06;ikeenv[4] = 0x24;ikeenv[5] = 0x8F;ikeenv[6] = 0x30; ikeenv[7] = 0x80;ikeenv[8] = 0x00;

       ikeenv[9] = bcc(8);

       comando = 1005;
       tamanho = 9;
        qDebug("perguntei se está no ar");

   }break;


   case 1012://pergunta se gravação  já esta no ar
   {
       ikeenv[3] = 0x06;ikeenv[4] = 0x14;ikeenv[5] = 0x8F;ikeenv[6] = 0xB3; ikeenv[7] = 0x80;ikeenv[8] = 0x00;

       ikeenv[9] = bcc(8);

       comando = 1005;
       tamanho = 9;
        qDebug("ppendrive prioridade");

   }break;

   case 1014://manda formatar
   {
       ikeenv[3] = 0x06;ikeenv[4] = 0x14;ikeenv[5] = 0x8F;ikeenv[6] = 0x34; ikeenv[7] = 0x80;ikeenv[8] = 0x00;

       ikeenv[9] = bcc(8);

       comando = 1014;
       tamanho = 9;
        qDebug("mandei formatar");

  }break;

   case 1015://manda formatar
   {
       ikeenv[3] = 0x06;ikeenv[4] = 0x24;ikeenv[5] = 0x8F;ikeenv[6] = 0x34; ikeenv[7] = 0x80;ikeenv[8] = 0x00;

       ikeenv[9] = bcc(8);

       comando = 1014;
       tamanho = 9;
        qDebug("pergunta se esta formatando");

  }break;

   case 1019://tem placa de gravação?
   {
       ikeenv[3] = 0x06;ikeenv[4] = 0x24;ikeenv[5] = 0x8F;ikeenv[6] = 0xE4; ikeenv[7] = 0x80;ikeenv[8] = 0x00;

       ikeenv[9] = bcc(8);

       comando = 3;
       tamanho = 9;


   }break;

   case 1020://pergunta o estado da midia
   {
      ikeenv[3] = 0x06;ikeenv[4] = 0x24;ikeenv[5] = 0x8F;ikeenv[6] = 0xE4; ikeenv[7] = 0x80;ikeenv[8] = 0x00;

       ikeenv[9] = bcc(8);

       comando = 1020;
       tamanho = 9;


   }break;


   }

   this->openSerial("ttymxc0");
   for(int i = 0;i<=tamanho;i++)
   {
    this->writeBytes({ikeenv[i]},comando);
   }
    readResp();

  //port->clear(QSerialPort::AllDirections);
 //  port->clearError();
  // port->close();

}

void SerialIke::perguntaMidia()
{
    if(whiteBalance == false)
    {
         qDebug("no ar");
         setComandoIke(1020);
         timeError.stop();
    }

}
//aqui você encontrará todas a mensagens que serão exibidas no monitor
void SerialIke::mensagens(int message, int cor)
{
     int tamanho,aux_enh,auxVideo;


    if(cor == 0) ikeenv[9] = 0x27;
    else if(cor == 1) ikeenv[9] = 0x25;//ikeenv[9] = 0x23;
    else if(cor == 2)ikeenv[9] = 0x22;


     ikeenv[0] = 0x7A;ikeenv[1] = 0x13;ikeenv[2] = 0x00; ikeenv[4] = 0x30;ikeenv[5] = 0x10;ikeenv[8] = 0x11;
   switch(message)
   {
        case 1: // escreve quais users estão na tela
        {

            if(user == 1){
                 ikeenv[6] = 0x20 + 27; ikeenv[7] = 0x20 + 29;

                  ikeenv[3] = 12+8;

                 ikeenv[10] = 'L';ikeenv[11] = 'A';ikeenv[12] = 'P';ikeenv[13] ='A'; ikeenv[14] = 'R';ikeenv[15] ='O';ikeenv[16] = ' ';

                 ikeenv[17] = '0';ikeenv[18] = '1';ikeenv[19] = ' ';ikeenv[20] = ' '; ikeenv[21] = ' '; ikeenv[22] = 0x00;ikeenv[23] = bcc(22);

                 comando = 0;
                 tamanho = 23;


            }
           else if(user == 2){
                 ikeenv[6] = 0x20 + 27; ikeenv[7] = 0x20 + 29;

                  ikeenv[3] = 12+8;

                 ikeenv[10] = 'L';ikeenv[11] = 'A';ikeenv[12] = 'P';ikeenv[13] ='A'; ikeenv[14] = 'R';ikeenv[15] ='O';ikeenv[16] = ' ';

                 ikeenv[17] = '0';ikeenv[18] = '2'; ikeenv[19] = ' ';ikeenv[20] = ' '; ikeenv[21] = ' '; ikeenv[22] = 0x00;ikeenv[23] = bcc(22);

                 comando = 0;
                 tamanho = 23;

            }

          else  if(user == 3){
                 ikeenv[6] = 0x20 + 27; ikeenv[7] = 0x20 + 29;

                  ikeenv[3] = 12+8;

                 ikeenv[10] = 'E';ikeenv[11] = 'N';ikeenv[12] = 'D';ikeenv[13] ='O'; ikeenv[14] = 'F';ikeenv[15] ='L';ikeenv[16] = 'E';

                 ikeenv[17] = 'X';ikeenv[18] = 'I';  ikeenv[19] = 'V';ikeenv[20] = 'E'; ikeenv[21] = 'L'; ikeenv[22] = 0x00;ikeenv[23] = bcc(22);

                 comando = 0;
                 tamanho = 23;
            }

          else  if(user == 4){
                 ikeenv[6] = 0x20 + 27; ikeenv[7] = 0x20 + 29;

                  ikeenv[3] = 12+8;

                 ikeenv[10] = 'H';ikeenv[11] = 'I';ikeenv[12] = 'S';ikeenv[13] ='T'; ikeenv[14] = 'E';ikeenv[15] ='R';ikeenv[16] = 'O';

                 ikeenv[17] = '/';ikeenv[18] = 'U';  ikeenv[19] = 'R';ikeenv[20] = 'O'; ikeenv[21] = ' ';ikeenv[22] = 0x00;ikeenv[23] = bcc(22);

                 comando = 0;
                 tamanho = 23;
            }

        }break;
         case 101: // apaga a escrita do láparo
         {
            ikeenv[6] = 0x20 + 26; ikeenv[7] = 0x20 + 29;

             ikeenv[3] = 13+8;

             ikeenv[10] = ' ';ikeenv[11] = ' ';ikeenv[12] = ' ';ikeenv[13] =' '; ikeenv[14] = ' ';ikeenv[15] =' ';ikeenv[16] = ' ';

             ikeenv[17] = ' ';ikeenv[18] = ' ';  ikeenv[19] = ' ';ikeenv[20] = ' '; ikeenv[21] = ' ';ikeenv[22] = ' ';ikeenv[23] = 0x00;ikeenv[24] = bcc(23);

             comando = 0;
            tamanho = 24;
         }break;

        case 5:// escreve enhancemente na tela
        {
            ikeenv[10] = 'E';ikeenv[11] = 'N';ikeenv[12] = 'H';ikeenv[13] ='A'; ikeenv[14] = 'N';ikeenv[15] ='C';ikeenv[16] = 'E';

             ikeenv[17] = 'M';ikeenv[18] = 'E'; ikeenv[19] = 'N';ikeenv[20] = 'T';ikeenv[21] = ' ';
            if(enhancement == enhancementLow)
             {
                    ikeenv[6] = 0x20 + 10; ikeenv[7] = 0x20 + 29;

                    ikeenv[3] = 16+8;

                     ikeenv[22] = 'L';ikeenv[23] = 'O';ikeenv[24] = 'W';ikeenv[25] = ' ';

                     ikeenv[26] = 0x00;ikeenv[27] = bcc(26);

                     //ikeenv[27] = 0x20;ikeenv[28] = 0x00;

                     comando = 0;
                     tamanho = 27;

             }

          else if(enhancement == enhancementMed)
             {
                    ikeenv[6] = 0x20 + 10; ikeenv[7] = 0x20 + 29;

                    ikeenv[3] = 16+8;

                     ikeenv[22] = 'M';ikeenv[23] = 'E';ikeenv[24] = 'D';ikeenv[25] = ' ';

                     ikeenv[26] = 0x00;ikeenv[27] = bcc(26);

                     //ikeenv[27] = 0x20;ikeenv[28] = 0x00;

                     comando = 0;
                     tamanho = 27;
             }

           else if(enhancement == enhancementHigh)
             {
                    ikeenv[6] = 0x20 + 10; ikeenv[7] = 0x20 + 29;

                    ikeenv[3] = 16+8;

                     ikeenv[22] = 'H';ikeenv[23] = 'I';ikeenv[24] = 'G';ikeenv[25] = 'H';

                     ikeenv[26] = 0x00;ikeenv[27] = bcc(26);

                     //ikeenv[27] = 0x20;ikeenv[28] = 0x00;

                     comando = 0;
                     tamanho = 27;
             }

          else if(enhancement == 0)
             {
                    ikeenv[6] = 0x20 + 10; ikeenv[7] = 0x20 + 29;

                    ikeenv[3] = 16+8;

                     ikeenv[22] = 'O';ikeenv[23] = 'F';ikeenv[24] = 'F';ikeenv[25] = ' ';

                     ikeenv[26] = 0x00;ikeenv[27] = bcc(26);

                     //ikeenv[27] = 0x20;ikeenv[28] = 0x00;

                     comando = 0;
                     tamanho = 27;
             }

        }break;

        case 1000:
        {
             ikeenv[10] = ' ';ikeenv[11] = ' ';ikeenv[12] = ' ';ikeenv[13] =' '; ikeenv[14] = ' ';ikeenv[15] =' ';ikeenv[16] = ' ';

             ikeenv[17] = ' ';ikeenv[18] = ' '; ikeenv[19] = ' ';ikeenv[20] = ' ';ikeenv[21] = ' ';

             ikeenv[6] = 0x20 + 10; ikeenv[7] = 0x20 + 29;

             ikeenv[3] = 16+8;

              ikeenv[22] = ' ';ikeenv[23] = ' ';ikeenv[24] = ' ';ikeenv[25] = ' ';

              ikeenv[26] = 0x00;ikeenv[27] = bcc(26);

              //ikeenv[27] = 0x20;ikeenv[28] = 0x00;

              comando = 0;
              tamanho = 27;
        }break;
        case 12:
         {
            if(videoLevel == videoLevelLow)
            {
                 ikeenv[6] = 0x20 + 6; ikeenv[7] = 0x20 + 30;

                ikeenv[3] = 2+8;

                ikeenv[10] = ' ';ikeenv[11] = ' '; ikeenv[12] = 0x00;  ikeenv[13] = bcc(12);

                comando = 0;
                tamanho = 13;

            }

            if(videoLevel == videoLevelHigh2)
            {
                 ikeenv[6] = 0x20 + 6; ikeenv[7] = 0x20 + 30;

                ikeenv[3] = 2+8;

                ikeenv[10] = 'G';ikeenv[11] = 'G'; ikeenv[12] = 0x00;  ikeenv[13] = bcc(12);

                comando = 0;
                tamanho = 13;

            }

            if(videoLevel == videoLevelHigh)
            {
                 ikeenv[6] = 0x20 + 6; ikeenv[7] = 0x20 + 30;

                ikeenv[3] = 2+8;

                ikeenv[10] = 'G';ikeenv[11] = ' '; ikeenv[12] = 0x00;  ikeenv[13] = bcc(12);

                comando = 0;
                tamanho = 13;

            }
         }break;
          case 13:
          {
              ikeenv[6] = 0x20 + 10; ikeenv[7] = 0x20 + 29;

              ikeenv[3] = 16+8;

              ikeenv[10] = 'N';ikeenv[11] = 'O';ikeenv[12] = ' ';ikeenv[13] = 'V'; ikeenv[14] = 'I';ikeenv[15] = 'D';ikeenv[16] = 'E';ikeenv[17] = 'O';

               ikeenv[18] = 'R';ikeenv[19] = 'E';ikeenv[20] = 'C';ikeenv[21] = 'O'; ikeenv[22] = 'R';ikeenv[23] = 'D';ikeenv[24] = 'E';ikeenv[25] = 'R';

             ikeenv[26] = 0x00;ikeenv[27] = bcc(26);

           //ikeenv[27] = 0x20;ikeenv[28] = 0x00;

             comando = 0;
            tamanho = 27;
          }break;

          case 80:
          {
                 ikeenv[6] = 0x20 + 4; ikeenv[7] = 0x20 + 1;

                   ikeenv[3] = 26+8;

                  ikeenv[10] = 'A';ikeenv[11] = 'S';ikeenv[12] = 'T';ikeenv[13] ='U'; ikeenv[14] = 'S';ikeenv[15] =' ';ikeenv[16] = 'M';

                   ikeenv[17] = 'E';ikeenv[18] = 'D';  ikeenv[19] = 'I';ikeenv[20] = 'C'; ikeenv[21] = 'A'; ikeenv[22] = 'L';

                   ikeenv[23] = ' ';ikeenv[24] = 'E';ikeenv[25] = 'D';ikeenv[26] ='G'; ikeenv[27] = 'E';ikeenv[28] =' ';ikeenv[29] = 'L';

                    ikeenv[30] = 'C';ikeenv[31] = ' ';  ikeenv[32] = 'P';ikeenv[33] = 'L'; ikeenv[34] = 'U'; ikeenv[35] = 'S';ikeenv[36] = 0x00;ikeenv[37] = bcc(36);

                    comando = 0;
                    tamanho = 37;
           }break;

           case 800:
          {
             ikeenv[6] = 0x20 + 4; ikeenv[7] = 0x20 + 1;

             ikeenv[3] = 26+8;

             ikeenv[10] = ' ';ikeenv[11] = ' ';ikeenv[12] = ' ';ikeenv[13] =' '; ikeenv[14] = ' ';ikeenv[15] =' ';ikeenv[16] = ' ';

            ikeenv[17] = ' ';ikeenv[18] = ' ';  ikeenv[19] = ' ';ikeenv[20] = ' '; ikeenv[21] = ' '; ikeenv[22] = ' ';

            ikeenv[23] = ' ';ikeenv[24] = ' ';ikeenv[25] = ' ';ikeenv[26] =' '; ikeenv[27] = ' ';ikeenv[28] =' ';ikeenv[29] = ' ';

             ikeenv[30] = ' ';ikeenv[31] = ' ';  ikeenv[32] = ' ';ikeenv[33] = ' '; ikeenv[34] = ' '; ikeenv[35] = ' ';ikeenv[36] = 0x00;ikeenv[37] = bcc(36);

             comando = 0;
             tamanho = 37;
       }break;
         case 1002://ESCREVE REC
         {
             ikeenv[6] = 0x20 + 35; ikeenv[7] = 0x20 + 1;

             ikeenv[3] = 3+8;

           ikeenv[10] = 'R';ikeenv[11] = 'E';ikeenv[12] = 'C';ikeenv[13] = 0x00; ikeenv[14] = bcc(13);

             comando = 0;
             tamanho = 14;

        }break;
   case 1001://APAGA REC
   {
       ikeenv[6] = 0x20 + 35; ikeenv[7] = 0x20 + 1;

       ikeenv[3] = 3+8;

       ikeenv[10] = ' ';ikeenv[11] = ' ';ikeenv[12] = ' ';ikeenv[13] = 0x00;ikeenv[14] = bcc(13);

       comando = 0;
       tamanho = 14;

  }break;




   }
   this->openSerial("ttymxc0");
   for(int i = 0;i<=tamanho;i++)
   {
    this->writeBytes({ikeenv[i]},comando);
   }
   //port->clear(QSerialPort::AllDirections);
 //  port->clearError();
//  port->close();
  // readResp();

}


void SerialIke::setUser(int scene)
{
    if(scene != user)
    {
        user = scene;

        setComandoIke(157);
       if(user == 1) this->setUserss1();
       else if(user == 2) this->setUserss2();
     else if(user == 3) this->setUserss3();
      else if(user == 4) this->setUserss4();

        qDebug()<<user;
    }
}

int SerialIke::bcc(int size)//faz o cálculo do bcc
{
    int i,aux;
    i = 1;
    aux = ikeenv[i];
   // size = 6;
    for(i = 2; i< size;i++)  // faz o cálculo do bcc
    {
        aux = aux ^ ikeenv[i];
    }
    return aux;
}
//lê os dados de calibração
void SerialIke::readFlash()
{
    QFile range;

    range.setFileName("/root/arquivosCalibracao"); // caminho de onde está salvo os dados de calibração
    if(!range.open(QIODevice::ReadOnly))
    {
        qDebug("Falaha ao abrir o arquivo");

        return;
    }

    dadoSalvo = range.readAll();

  videoLevel =  dadoSalvo[0] ;
  videoLevelLow1 = dadoSalvo[1];
  videoLevelLow2 = dadoSalvo[2];
  videoLevelLow3 = dadoSalvo[3];
  videoLevelLow4 = dadoSalvo[4];
  enhancementHigh1 = dadoSalvo[5];
  enhancementHigh2  =  dadoSalvo[6] ;
  enhancementHigh3  = dadoSalvo[7];
   enhancementHigh4 = dadoSalvo[8];
   serialNumero = dadoSalvo[9];



    range.close();

     qDebug("ler o arquivo");

     qDebug() << serialNumero;

    this->myNumberSerie();
    emit serialScreen();

}
//escreve os dados de calibração
void SerialIke::writeFlash()
{
    QFile escrita;

    dadoSalvo[0] = videoLevel;
    dadoSalvo[1] = videoLevelLow1;
    dadoSalvo[2] = videoLevelLow2;
    dadoSalvo[3] = videoLevelLow3;
    dadoSalvo[4] = videoLevelLow4;
    dadoSalvo[5] = enhancementHigh1;
    dadoSalvo[6] = enhancementHigh2;
    dadoSalvo[7] = enhancementHigh3;
    dadoSalvo[8] = enhancementHigh4;
     dadoSalvo[9] = serialNumero;

    escrita.setFileName("/root/arquivosCalibracao"); // caminho de onde está salvo os dados de calibração
    if(!escrita.open(QIODevice::WriteOnly))
    {
        qDebug("Falaha ao abrir o arquivo");

        return;
    }
     qDebug("lendo o arquivo");

  escrita.write(dadoSalvo);
   escrita.flush();
    escrita.close();

    this->myNumberSerie();
    emit serialScreen();

     qDebug() <<  dadoSalvo[9];

}

// salvará os dados da calibração
void SerialIke::salvarDadosCalibracao()
{
    int auxVideolevel = 0;
    int auxenhancement = 0;


   switch(user)
   {
       case 1:
        {
            videoLevelLow1 = videoLevel;  videoLevelLow = videoLevel;
            qDebug() << videoLevel;

            enhancementHigh1 = enhancement;  enhancementHigh = enhancement;
           // qDebug("user 1");

             qDebug() << enhancement;

        }break;

       case 2:
      {
          videoLevelLow2 = videoLevel;  videoLevelLow = videoLevel;
          qDebug() << videoLevel;

          enhancementHigh2 = enhancement;  enhancementHigh = enhancement;
         // qDebug("user 2");

         qDebug() << enhancement;

      }break;

   case 3:
  {
      videoLevelLow3 = videoLevel;  videoLevelLow = videoLevel;
      qDebug() << videoLevel;

      enhancementHigh3 = enhancement;  enhancementHigh = enhancement;
     // qDebug("user 2");

     qDebug() << enhancement;

  }break;

   case 4:
  {
      videoLevelLow4 = videoLevel;  videoLevelLow = videoLevel;
      qDebug() << videoLevel;

      enhancementHigh4 = enhancement;  enhancementHigh = enhancement;
     // qDebug("user 4");

     qDebug() << enhancement;

  }break;
   }

   //trocaUser(user);

   setComandoIke(3);// sai fora da configuraçao

   writeFlash();
}

void SerialIke::trocaUser(int user_)
{

    readFlash(); //lê os dados de calibração

   switch(user_)
   {
      case 1:
      {
        videoLevelLow = videoLevelLow1;

        enhancementHigh = enhancementHigh1;

       }break;

      case 2:
     {
        videoLevelLow = videoLevelLow2;

        enhancementHigh = enhancementHigh2;

       }break;

      case 3:
      {
        videoLevelLow = videoLevelLow3;

        enhancementHigh = enhancementHigh3;

      }break;

      case 4:
     {
       videoLevelLow = videoLevelLow4;

       enhancementHigh = enhancementHigh4;

     }break;
   }

    setUser(user_);

   videoLevelHigh = videoLevel + deltaVideoLevel;
   videoLevelHigh2 = videoLevelHigh + deltaVideoLevel2;

   enhancementMed = enhancementHigh - deltaEnhancement2;
   enhancementLow = enhancementMed - deltaEnhancement;

   videoLevel = videoLevelLow;
   enhancement = enhancementHigh;


   if(user == 3)
   {
       enhancement = 0;
   }

   if(user != 3)this->setEnhanceHigh();

   else this-> setEnhanceOff();
}


   void SerialIke::whiteNegado()
   {
       this->setWhiteNeg();
   }

   void SerialIke::whiteAceito()
   {
       this->setWhiteAcept();
   }

   void SerialIke::inicializa()
   {
       this->setInitializa();
   }

   void SerialIke::setWhiteNeg()
   {
       emit negaWhite();
   }

   void SerialIke::setWhiteAcept()
   {
       emit aceptWhite();
   }

   void SerialIke::setInitializa()
   {
       emit initEquip();
   }

   void SerialIke::setUserss3()
   {
       emit changedUsers3();
   }

   void SerialIke::setUserss1()
   {
       emit changedUsers1();
   }

   void SerialIke::setUserss2()
   {
       emit changedUsers2();
   }

   void SerialIke::setUserss4()
   {
       emit changedUsers4();
   }
   //muda as figuras do enhancement
   void SerialIke::setEnhanceHigh()
   {
       emit changeEnhanceHigh();
   }

   void SerialIke::setEnhanceMed()
   {
      emit changeEnhanceMed();
   }

   void SerialIke::setEnhanceLow()
   {
       emit changeEnhanceLow();
   }

   void SerialIke::setEnhanceOff()
   {
       emit changeEnhanceOff();
   }

   void SerialIke::setGanhoLow()
   {
       emit changeGanhoLow();
   }

   void SerialIke::setGanhoMed()
   {
       emit changeGanhoMed();
   }

   void SerialIke::setGanhoHigh()
   {
       emit changeGanhoHig();
   }

   void SerialIke::initIke(int fase)
   {
       setComandoIke(1004);
   }

   void SerialIke::setFormating(bool mode)
   {
       formatacao = mode;
   }

   void SerialIke::perguntas(void)
   {
        setComandoIke(1003);
           qDebug("perguntei");
           pergunte.stop();

   }

   void SerialIke::placaGrav(bool tem)
   {
       PlacaGravacao = tem;


       if(PlacaGravacao == true)
       {
           setComandoIke(1005);//pergunta se a gravação esta no ar
       }
   }

   void SerialIke::Gravacao()
   {

       if(PlacaGravacao == true)
       {
          if(grava == false) setComandoIke(1002);//inicia gravação

          else  setComandoIke(1001);//inicia gravação
        }
   }

   QList<int> SerialIke::readBytes()
   {
       QList<int> *l = new QList<int>();

        QList<int> *d = new QList<int>();
      int ike = 0;
     // int videoLevel;

      bool error= false;
       QByteArray buf =0;
       QByteArray resp;
       resp.resize(8);


       while(port->waitForReadyRead(100)) // aguarda um tempo para receber a resposta
         {
             if (isopen() && port->bytesAvailable())
             {
                 buf.append(port->readAll().simplified());
                 for (int i=0; i<buf.size(); i++)l->append(buf.at(i));

               }
         }


       // verifica a resposta e vê que recebemos da ikegami

        switch(comando)
        {
            case 1:
            {

            //resposta do white ballance
               resp.resize(8);
               resp[0] = 0x7a; resp[1] = 0x13; resp[2] = 0x01; resp[3] = 0x04; resp[4] = 0x19; resp[5] = 0x85; resp[6] = 0x00; resp[7] = 0x8a;
               for(int j =3;j<= 7;j++)
               {
                 if(buf[5]==resp[5])
                 {
                      whiteBalance = false;
                     qDebug("white balance negado");
                     this->whiteNegado();
                      t2->start(700);
                      t1->start(800);
                     j = 100;
                     if(buf[7] == 0x8a) contWite = 1;
               }
               else
               {
                     if(!contWite)
                     {
                        qDebug("white balance OK");
                        this->setWhiteAcept();
                        t1->stop();
                         t2->stop();
                        j = 100;
                         whiteBalance = false;
                     }

                      if(buf[7] == 0x8c) contWite = 0;
               }
            }

          }break;
        // joga zoom de 1.0 na ikegami durante a inicialização
        case 2:
        {
         //   qDebug("chegou alguma coisa");
            resp.resize(10);
              resp[0] = 0x7a; resp[1] = 0x13; resp[2] = 0x01; resp[3] = 0x07; resp[4] = 0x14; resp[5] = 0x8f; resp[6] = 0x6f; resp[7] = 0x10;
              for(int i = 0;i<= 7; ++i)
              {
                 if(buf[i] == resp[i])
                 {
                     error = false;
                 }
              }
               //if(error == false) this ->setscreen();
        }break;

           // pergunta se tem placa adicional instalada
        case 3:
        {
           // qDebug("chegou alguma coisa");
            resp.resize(10);
              resp[0] = 0x7a; resp[1] = 0x13; resp[2] = 0x01; resp[3] = 0x07; resp[4] = 0x14; resp[5] = 0x8f; resp[6] = 0xE4; resp[7] = 0x14;
              for(int i = 0;i<= 7; ++i)
              {
                 if(buf[i] != resp[i])
                 {
                     error = true;
                     i = 1000;
                 }
              }
              if(error == false){

                  qDebug("tem placa adicional");
                   mensagens(13,2);
                  //this ->setscreen();
                   emit temPlacaAdicional();
                   //this->setComandoIke(1004);
                   emit iniciaIke();
              }

              else {
                  qDebug("Nao tem placa adicional");

                  mensagens(13,2);
                 // this ->setscreen();
                  emit naoTemPlacaAdicional();

                  emit naoIniciaike(); //não tem gravação

              }
        }break;

        case 4:
        {
             qDebug("tamo no aguardo");
        }break;

            // manda o modo do white balalance
        case 5:
        {
            resp.resize(10);
             resp[0] = 0x7a; resp[1] = 0x13; resp[2] = 0x01; resp[3] = 0x07; resp[4] = 0x14; resp[5] = 0x8f; resp[6] = 0x6a; resp[7] = 0x12;
             for(int i = 0;i<= 7; ++i)
             {
                if(buf[i] == resp[i])
                {
                    error = false;
                }
             }
             if(error == false){

                 qDebug("modo awb com sucesso");
                 //this ->setscreen();
             }
        }break;
            //seta auto folder  resposta
        case 6:
        {
            resp.resize(10);
             resp[0] = 0x7a; resp[1] = 0x13; resp[2] = 0x01; resp[3] = 0x06; resp[4] = 0x14; resp[5] = 0x8f; resp[6] = 0x31; resp[7] = 0x80;
             for(int i = 0;i<= 7; ++i)
             {
                if(buf[i] == resp[i])
                {
                    error = false;
                }
             }
             if(error == false){

                 qDebug("auto folder suave");
              //   this ->setscreen();

                // t3->stop();
             }
        }break;
   //pergunta qual é o video level  ganho
           case 24:
           {
            resp.resize(10);

            resp[0] = 0x7a; resp[1] = 0x13; resp[2] = 0x01; resp[3] = 0x25; resp[4] = 0x8f; resp[5] = 0x8f; resp[6] = 0x8f; resp[7] = 0x11;

            for(int i = 0;i<= 7; ++i)
            {
               if(buf[i] == resp[i])
               {
                   error = false;
               }
            }
              if(error == false)
               {
                  ike =resp[5];

                  videoLevel = (buf[8] *256) + buf[9];

                  if(videoLevel > 2047) // faz o complemento de 1
                  {
                      videoLevel = 0xFFFF - videoLevel + 1;
                      videoLevel = videoLevel*(-1);
                  }
                   videoLevel = videoLevel/32; // para colocar no padrão que aparece la na configuração

                  qDebug() << videoLevel;
                  writeFlash();

                }
           }break;

        case 50://verifica a resposta do enhancement que se encontra no user atual
        {
            resp.resize(10);

            resp[0] = 0x7a; resp[1] = 0x13; resp[2] = 0x01; resp[3] = 0x06; resp[4] = 0x25; resp[5] = 0x7D;  resp[8] = 0x00;
            for(int i = 0;i<= 5; ++i)
            {
               if(buf[i] == resp[i])
               {
                   error = false;
               }
            }
            if(error == false)
            {
                enhancement = 256*buf[6] + buf[7];

                if(enhancement > 2047)//detail gain é negativo: tem que fazer complemento de 1
                {
                    enhancement = 0xFFFF - enhancement + 1;
                    enhancement = enhancement*(-1);
                }

                enhancement = enhancement/16;// para colocar no padrão que aparece na configuração:2048 equivale a 64 (2048/64)
                qDebug() << enhancement;
            }


        }break;

        case 1002://resposta do comando grava
        {
            int a;
            bool erro = true;
         resp.resize(8);

   // resp[0] = 0x7a; resp[1] = 0x13; resp[2] = 0x01;
         resp[3] = 0x05; resp[4] = 0x14; resp[5] = 0x71; resp[6] = 0x11; resp[7] = 0x00;

         for(int i = 3;i<= 7;i++)
         {
             if(resp[i] != buf[i])
             {
                // erro = false;
                  qDebug("não ta gravando");
             }
            // else qDebug("tudo certo");
         }

       if(erro == false)
         {
             emit gravandoNot();
             grava = false;
         }
         else {
             emit gravando();
             grava = true;
         }


        }break;

        case 1001://rsposta da parada
        {
            int a ;
            bool erro = false;
         resp.resize(8);
       // resp[3] = 0x07; resp[4] = 0x14;
       // resp[5] = 0x82;
        resp[6] = 0x7E; resp[7] = 0x12;// não pode vir igual

         for(int i = 6;i<= 7;i++)
         {
             if(resp[i] == buf[i])
             {
                  // i  = 100;
                 erro = true;

             }
     }

         if(erro == false)
         {
             emit gravandoNot();
             grava = false;

         }
         else {
             emit gravando();
             grava = true;

         }


        }break;

        case 1003://rsposta da gravação
        {
            int a ;
            bool erro = true;
         resp.resize(8);

        resp[6] = 0x7E; resp[7] = 0x12;//  pode vir igual

         for(int i = 6;i<= 7;i++)
         {
             if(resp[i] == buf[i])
             {
                  // i  = 100;
                 erro = false;

             }
           //  else qDebug("parada ok");


         }

         if(erro == true)
         {
             emit gravandoNot();
             grava = false;

              qDebug("nao ta gravando");
               emit noMediaConnected();
            // timeError.start(300);
         }
       /*  else {
             emit gravando();
             grava = true;
              qDebug("ta gravando");

              //  timeGravando->start(500);//fica perguntando sobre a mídia
         }*/



        }break;

        case 1005:
        {
            int cu = buf[6];
           if(buf[6] == 0xB0)
           {
               qDebug(" esta no ar");
           }

           else  qDebug("nao esta no ar");

           qDebug()<< cu;

        }break;

        case 1014:
        {
            int cu = buf[6];
           if(buf[6] == 0x34)
           {
               qDebug(" esta formatando");
               emit yesFormating();
               format = true;
           }

           else if (buf[6] == 0xB4)
           {
               qDebug("nao esta formatando");
               if(format == true)
               {
                   format = false;
                   emit formatOK();
               }
               else {
                   emit formatNeg();
               }
           }

            qDebug("sinal recebido");

           qDebug()<< cu;

        }break;

        case 1020://resposta se está gravando
        {
           int cu = buf[7];
           int erro = true;
           resp[3] = 0x06;resp[4] = 0x24;resp[5] = 0x8F;resp[6] = 0xE4;
          // qDebug("chegou o porque  no ar");
           for(int i = 3;i<= 6;i++)
           {
               if(resp[i] == buf[i])
               {
                   erro = false;
                }
               if(erro == false)
               {
                   estadoMidia = buf[7];
               }
            }

           if(formatacao == true)
           {
              if(estadoMidia == 0x14)  emit formatNotConnected();

               else emit formatConnected();//setComandoIke(1014);
           }
          else //(estadoMidia == 0x14)
           {
               emit noMediaConnected();

               emit gravandoNot();
               grava = false;
               qDebug() << estadoMidia;

             //  timeGravando->stop();
           }



        }break;

        }
      //  port->clear(QSerialPort::AllDirections);
        port->clearError();
        port->close();
       return *l;
   }



   void SerialIke::setMenu_telaPrincipal()
   {
       emit menu_TelaPrincipal();
   }


   void SerialIke::setscreen()
   {
       emit goTela();
   }
   void SerialIke::setIntensidadeLed(char sinal)
   {
       int tamanho;

       if(sinal == 2){
           intensidadeLed ++;
           qDebug("sinal +");
           if(intensidadeLed > 10) {intensidadeLed = 10; return;}
       }
       if(sinal == 1){
           intensidadeLed --;
             qDebug("sinal -");
           if(intensidadeLed <= 0) {intensidadeLed = 0; }
       }

       ikeenv[0] = 0xA5; ikeenv[1] = 0x07; ikeenv[2] = 0x06; ikeenv[4] = 0x00;

        switch(intensidadeLed)
        {
           case 0:{ikeenv[3] = 0x05; ikeenv[5] = 0x8A;  ikeenv[6] = 0x3C;comando = 0;tamanho = 6; }break;

            case 1:{ikeenv[3] = 0x14; ikeenv[5] = 0x86;  ikeenv[6] = 0x6C; comando = 0;tamanho = 6;}break;

            case 2: { ikeenv[3] = 0x32; ikeenv[5] = 0x9C;  ikeenv[6] = 0x0C; comando = 0; tamanho = 6;}break;

            case 3:{ikeenv[3] = 0x50; ikeenv[5] = 0xB5;  ikeenv[6] = 0x6C; comando = 0; tamanho = 6;}break;

           case 4: {ikeenv[3] = 0x78; ikeenv[5] = 0xAB;  ikeenv[6] = 0x6C; comando = 0;tamanho = 6;}break;

            case 5: {ikeenv[3] = 0xAA; ikeenv[5] = 0xF7;  ikeenv[6] = 0xcC; comando = 0;tamanho = 6;}break;//0xaa,0x00,0xf7,0xcc

             case 6: {ikeenv[3] = 0xE6; ikeenv[5] = 0xC3;  ikeenv[6] = 0x0C; comando = 0;tamanho = 6;}break;//0xe6,0x00,0xc3,0x0c

             case 7: {ikeenv[3] = 0xE6; ikeenv[5] = 0x79;  ikeenv[6] = 0x6C; comando = 0;tamanho = 6;}break;//0xe6,0x00,0x79,0x6c

             case 8: {ikeenv[3] = 0xCC; ikeenv[4] = 0x01; ikeenv[5] = 0x1D;  ikeenv[6] = 0xAC; comando = 0;tamanho = 6;}break;//0xcc,0x01,0x1d,0xac

             case 9: {ikeenv[3] = 0xBC; ikeenv[4] = 0x02; ikeenv[5] = 0x78;  ikeenv[6] = 0x6D; comando = 0;tamanho = 6;}break;//0xbc,0x02,0x78,0x6d

             case 10: {ikeenv[3] = 0xFF; ikeenv[4] = 0x03; ikeenv[5] = 0x88;  ikeenv[6] = 0x9d; comando = 0;tamanho = 6;}break;//0xff,0x03,0x88,0x9d

        }

         this->openSerial("ttymxc0");
        for(int i = 0;i<=tamanho;i++)
        {
           this->writeBytes({ikeenv[i]},comando);
        }

         //    readResp();
   }

   void SerialIke::stopInit()
   {
        t3->stop();

        zoom = 16;
   }

   void SerialIke::Inicializa()
   {
       bool init = false;
       while(init == false)
       {
           t4->setInterval(2000);

        }
   }

/***************************************************************************************************************************/
   void SerialIke::setSerialNumber(const int number)
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
                serialNumero = serialDig;
                this->writeFlash();
                contSerial = 0;
                serialDig = 0;
                emit backMenu();
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

   void SerialIke::readNumberSerie(const int value)
   {
       this->myNumberSerie();
       emit serialScreen();
   }

   void SerialIke::readResp()
   {
       QByteArray resp;
       char cu;
      port->waitForBytesWritten(100);
      port->waitForReadyRead(100);
      if(port->bytesAvailable())
      {
          resp = port->read(5);
          cu = resp[1];
          qDebug("chegou bytes");
            qDebug() <<cu;
      }
   }

   int SerialIke::myNumberSerie()
   {

       return serialNumero;
   }

   void SerialIke::setNumberSerie(const int serial)
   {

       if(m_serial != serial)
       {
           m_serial = serial;

           emit serialChanged();
           qDebug() << serial;

       }
   }

   int SerialIke::serialNumber()
   {
       return serialDig;
   }



