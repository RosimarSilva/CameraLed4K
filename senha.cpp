#include "senha.h"
#include <QDebug>

senha::senha(QObject *parent): QObject(parent)
{
     //connect(this,&senha::setscreenConfig,this,&senha::screenConfig);

    // connect(this,&senha::setscreenMenu,this,&senha::screenMenu);
    qDebug() << Q_FUNC_INFO;
}

senha::~senha()
{
qDebug() << Q_FUNC_INFO;
}

void senha::setSenha(int number)
{

    switch (number)
    {
       case 1:
       {
            if(contSenha <= 3)
            {
                auxSenha = number;
                senhaDig = senhaDig*10;
                senhaDig = senhaDig += auxSenha;
                contSenha ++;
             }

       } break;

       case 2:
      {
        if(contSenha <= 3)
        {
            auxSenha = number;
            senhaDig = senhaDig*10;
            senhaDig = senhaDig += auxSenha;
             contSenha ++;
        }
      } break;

       case 3:
     {
        if(contSenha <= 3)
        {
            auxSenha = number;
            senhaDig = senhaDig*10;
            senhaDig = senhaDig += auxSenha;
            contSenha ++;
        }
      } break;

      case 4:
      {
        if(contSenha <= 3)
        {
            auxSenha = number;
            senhaDig = senhaDig*10;
            senhaDig = senhaDig += auxSenha;
            contSenha ++;
        }
      } break;

      case 5:
     {
        if(contSenha <= 3)
        {
            auxSenha = number;
            senhaDig = senhaDig*10;
            senhaDig = senhaDig += auxSenha;
            contSenha ++;
          }
     } break;

     case 6:
     {
        if(contSenha <= 3)
        {
            auxSenha = number;
            senhaDig = senhaDig*10;
            senhaDig = senhaDig += auxSenha;
            contSenha ++;
       }
      } break;

      case 7:
      {
        if(contSenha <= 3)
        {
            auxSenha = number;
            senhaDig = senhaDig*10;
            senhaDig = senhaDig += auxSenha;
            contSenha ++;
        }
      } break;

      case 8:
      {
        if(contSenha <= 3)
        {
           auxSenha = number;
           senhaDig = senhaDig*10;
           senhaDig = senhaDig += auxSenha;
           contSenha ++;
        }
      } break;

      case 9:
      {
        if(contSenha <= 3)
        {
            auxSenha = number;
            senhaDig = senhaDig*10;
            senhaDig = senhaDig += auxSenha;
             contSenha ++;
        }
      } break;

      case 0:
      {
        if(contSenha <= 3)
        {
            auxSenha = number;
            senhaDig = senhaDig += auxSenha;
           if(contSenha<=2)  senhaDig = senhaDig*10;
          contSenha ++;
        }
      } break;
      case 100:
      {
       if(senhaDig == senhaConfig)
        {
            this->setscreenConfig();
        }

       else if(senhaDig == senhaNumberSerie)
       {
            emit screenNumberSerie();
       }
        else {
          this->setscreenMenu();
        }
             contSenha = 0;
             senhaDig = 0;
      } break;

      case 99:
      {
         if(contSenha == 4) {senhaDig = senhaDig - auxSenha; senhaDig = senhaDig/10;}

         else if(contSenha == 3)senhaDig = senhaDig/10;

           else if(contSenha == 2) senhaDig = senhaDig/10;

         else if(contSenha == 1)senhaDig = senhaDig/10;

         else if(contSenha == 0) senhaDig = 0;


          if(senhaDig <= 0)senhaDig = 0;
           contSenha --;
          if(contSenha < 0) contSenha = 0;
      } break;
    }

}

void senha::setscreenConfig()
{
    emit screenConfig();
}

void senha::setscreenMenu()
{
   emit screenMenu();
}
