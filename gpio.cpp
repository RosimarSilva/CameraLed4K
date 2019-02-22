#include "gpio.h"
#include  <QEvent>
#include "gpio.h"


GPIO::GPIO(QObject *parent): QObject(parent),
   m_path_b1("/sys/class/gpio/keypad_pin6/value"),m_path_b2("/sys/class/gpio/keypad_pin8/value"),
   m_path_b3("/sys/class/gpio/keypad_pin7/value"),m_value_b1(0),m_value_b2(0),m_value_b3(0)
{
    qDebug("construido");

  qDebug() << Q_FUNC_INFO;
  gpioExport();
  setDirectionGpioIke();
  setDirectionGpioLedBotao();
  setDirectionGpioBotao1();
  setDirectionGpioBotao2();
   setDirectionGpioBotao3();
  setTela(1);

   timerBotao.start(150);
   //Lê os botoẽs da cabeça a cada 250 mlissegundos
  connect(&timerBotao, &QTimer::timeout, [&](){

      QByteArray gpioValue1;
     QFile gpio1(m_path_b1);
     QByteArray gpioValue2;
     QFile gpio2(m_path_b2);
     QByteArray gpioValue3;
     QFile gpio3(m_path_b3);
     int botao1,botao2,botao3;

  if (gpio1.open(QIODevice::ReadOnly)) {         // Abre arquivo
      gpioValue1 = gpio1.readAll();//  // Le o arquivo
       gpio1.close();

       tecla = gpioValue1[0]; // lê se há tecla pressionada
        if(tecla == 49)  // se for 49 não há
       {
         botao1 = 0;

         setLed = false;
        if(tela == 1) // se a tela for (principal)
        {
           if(auxBotao != botao1) // // se o botao antes estava apertado e agora está solto
           {
               if(tela == 1)this->setWiteBalnce();//this->setEnhance(); // muda o enhancement
            }

        }
         auxBotao = botao1;// iguala os botoes

      }else {
          botao1 = 1;
          if((tela == 2)&&(setLed == false))this-> changeLuminousMais();//this-> setLuminousMenos(); // se estiver na tela de ajuste do Led este botao diminui a intensidade do led
          auxBotao = botao1;// iguala botoes
     }
  }

  if (gpio2.open(QIODevice::ReadOnly)) {         // Abre arquivo
      gpioValue2 = gpio2.readAll();// // Le o arquivo e remove
      gpio2.close();                             // Fecha arquivo

      tecla2 = gpioValue2[0]; // lê se há tecla pressionada

      if(tecla2 == 49)
      {
         botao2 = 0;

        // setWhite = false;// não deixar dar white balance ao voltar para atela principal
        //  setLed = false;


         if(tela == 1) changeTelas = true;
         else changeTelas = false;

         if(tela == 1) //se atela for a do ajuste deo led
         {
            if(auxBotao2 != botao2)  // se o botao antes estava apertado e agora está solto
            {
               if((tela == 1) &&(setGain == true)) this->setGanho();// this->setEnhance();
            }
         }
            setGain = true;// não deixar dar white balance ao voltar para atela principal
          auxBotao2 = botao2;  // iguala os botoes



      }else {
            botao2 = 1;
            cont2 ++;
            contBotao2 ++;


          if((tela == 2)&&(changeTelas == false))
          {
            if((auxBotao2 == botao2)&&(contBotao2 > 5))//se o botao estiver pressionado por alguns segundos volta a tela principal
            {
                  setGain = false;// não deixar dar white balance ao voltar para atela principal
                 this->setTelaPrincipal();  // volta para a tela principal
                return;
              }
            }

        else if((tela == 1)&&(changeTelas == true))
          {
            if((auxBotao2 == botao2)&&(contBotao2 > 5))//se o botao estiver pressionado por alguns segundos volta a tela principal
            {
                //  setGain = false;// não deixar dar white balance ao voltar para atela principal
                this->setTelaLed(); // vai para a tela de controle de luminosidade
                return;
              }
            }

             auxBotao2 = botao2;
     }
  }
  if (gpio3.open(QIODevice::ReadOnly)) {         // Abre arquivo
      gpioValue3 = gpio3.readAll();// // Le o arquivo e remove
      gpio3.close();                             // Fecha arquivo

      tecla3 = gpioValue3[0]; // lê se há tecla pressionada

      if(tecla3 == 49)
      {
         botao3 = 0;
         cont3 =0;
         contBotao3 =0;

         if(tela == 1) // se a tela for (principal)
         {
            if(auxBotao3 != botao3) // // se o botao antes estava apertado e agora está solto
            {
                 if((tela == 1) &&(setGain == true))  this->setEnhance();//this->setGanho(); // se estiver na tela principal o primeiro botão da cabeça tem a função de white balance
             }

         }
        // setGain = true;// não deixar dar white balance ao voltar para atela principal
         auxBotao3 = botao3;  // iguala os botoes
        }else {

         botao3 = 1;
         cont3 ++;
         contBotao3 ++;

          if(tela == 2)this-> setLuminousMenos();//this-> changeLuminousMais();  // aumenta a luminosidade do led

            auxBotao3 = botao3;
      }
  }
  });

}

GPIO::~GPIO()
{
   timerBotao.stop();
  qDebug() << Q_FUNC_INFO;
   qDebug("destruido");

}

void GPIO::gpioExport()
{
    QFile gpioExportFile("/sys/class/gpio/export");// exporta todos os pinos i/o
    if(!gpioExportFile.open(QIODevice::Append))
    {
        qDebug("Falha ao tentar exportar o gpio");
    }

    else   qDebug("Sucesso ao exportar");
}

void GPIO::setDirectionGpioLedBotao()
{
    QFile gpiosetDirectionFile("/sys/class/gpio/keypad_pin4/direction");
    if(!gpiosetDirectionFile.open(QIODevice::Append))
    {
        qDebug("Falha ao tentar abrir o gpio");
        return;
    }
     else   qDebug("Sucesso ao abrir");

    gpiosetDirectionFile.write("out");
    gpiosetDirectionFile.close();
}

void GPIO::setDirectionGpioBotao1()
{
    QFile gpiosetDirectionFile("/sys/class/gpio/keypad_pin6/direction");
    if(!gpiosetDirectionFile.open(QIODevice::Append))
    {
        qDebug("Falha ao tentar abrir a entrada do gpio");
        return;
    }
     else   qDebug("Sucesso ao abrir a entrada");
    gpiosetDirectionFile.write("in");
    gpiosetDirectionFile.close();

}

void GPIO::setDirectionGpioBotao2()
{
    QFile gpiosetDirectionFile("/sys/class/gpio/keypad_pin8/direction");
    if(!gpiosetDirectionFile.open(QIODevice::Append))
    {
        qDebug("Falha ao tentar abrir a entrada do gpio 8");
        return;
    }
     else   qDebug("Sucesso ao abrir a entrada");
    gpiosetDirectionFile.write("in");
    gpiosetDirectionFile.close();
}

void GPIO::setDirectionGpioBotao3()
{
    QFile gpiosetDirectionFile("/sys/class/gpio/keypad_pin7/direction");
    if(!gpiosetDirectionFile.open(QIODevice::Append))
    {
        qDebug("Falha ao tentar abrir a entrada do gpio 7");
        return;
    }
     else   qDebug("Sucesso ao abrir a entrada 7");
    gpiosetDirectionFile.write("in");
    gpiosetDirectionFile.close();
}

void GPIO::setDirectionGpioIke()//define a direção do pino da ikegami
{
    QFile gpiosetDirectionFile("/sys/class/gpio/keypad_pin3/direction");
    if(!gpiosetDirectionFile.open(QIODevice::Append))
    {
        qDebug("Falha ao tentar abrir o gpio");
        return;
    }
     else   qDebug("Sucesso ao abrir");

    gpiosetDirectionFile.write("out");
    gpiosetDirectionFile.close();
}

void GPIO::PutValPin3(int out)// aciona o rele que ligará a ikegami
{
    QFile gpioSetValue("/sys/class/gpio/keypad_pin3/value");
    if(!gpioSetValue.open(QIODevice::Append))
    {
        qDebug("Falha ao tentar setar o gpio");
        return;
    }
     else   qDebug("Sucesso ao setar");

    if(out == 0)gpioSetValue.write("0");
    else gpioSetValue.write("1");
    gpioSetValue.close();
}

void GPIO::PutvalPin4(int out)// aciona o pino do botão liga desl
{
    QFile gpioSetValue("/sys/class/gpio/keypad_pin4/value");
    if(!gpioSetValue.open(QIODevice::Append))
    {
        qDebug("Falha ao tentar setar o gpio");
        return;
    }
     else   qDebug("Sucesso ao setar");

    if(out == 0)gpioSetValue.write("0");
    else gpioSetValue.write("1");
    gpioSetValue.close();
}
//notifica o software que mudou de tela
void GPIO::setTela(int screen)
{
    tela = screen;
}

void GPIO::setLuminousMais()
{
    emit changeLuminousMais();
}

void GPIO::setWiteBalnce()
{
    emit changeWhiteBalance();
}

void GPIO::setEnhance()
{
    emit changeEnhance();
}

void GPIO::setGanho()
{
    emit changeGanho();
}

void GPIO::setTelaLed()
{
    emit changeTelaLed();
}

void GPIO::setTelaPrincipal()
{
    emit changeTelaPrincipal();
}

void GPIO::setLuminousMenos()
{
    emit changeLuminousMenos();
}

/*void GPIO::readBotao1()
{
 QByteArray gpioValue;
int botao1;
   char data;
    QFile gpio(QString("/sys/class/gpio/keypad_pin6/value"));
    if(!gpio.open(QIODevice::ReadOnly))
    {
        qCritical() << "falha ao abrir"<< gpio.fileName();
        return;
    }

    gpioValue = gpio.readAll().simplified();;

    tecla = gpioValue[0];

    gpio.close();

    if(tecla == 49)
    {
       botao1 = 0;
    }else {
        botao1 = 1;

        if(tela == 2)
        {
           this-> setLuminousMenos();
        }
    }
}

void GPIO::readBotao2()
{
    QByteArray gpioValue2;
   int botao2;
      char data;
       QFile gpio2(QString("/sys/class/gpio/keypad_pin8/value"));
       if(!gpio2.open(QIODevice::ReadOnly))
       {
           qCritical() << "falha ao abrir"<< gpio2.fileName();
           return;
       }

       gpioValue2 = gpio2.readAll().simplified();

       tecla2 = gpioValue2[0];

       gpio2.close();

       if(tecla2 == 49)
       {
          botao2 = 0;
       }else {
           botao2 = 1;
           if(tela == 1)
           {
              this->setWiteBalnce();
           }
           else if(tela == 2){
           this-> changeLuminousMais();
           }
       }

}

/*void GPIO::readBotao3()
{
    QByteArray gpioValue3;
   int botao3;
      char data;
       QFile gpio3(QString("/sys/class/gpio/keypad_pin7/value"));
       if(!gpio3.open(QIODevice::ReadOnly))
       {
           qCritical() << "falha ao abrir"<< gpio3.fileName();
           return;
       }

       gpioValue3 = gpio3.readAll().simplified();

       tecla3 = gpioValue3[0];

       gpio3.close();

       if(tecla3 == 49)
       {
          botao3 = 0;
       }else {
           botao3 = 1;
           if(tela == 1)
           {
              this->setWiteBalnce();
           }
           else if(tela == 2){
           this-> changeLuminousMais();
           }
       }
}*/
