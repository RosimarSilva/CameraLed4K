#ifndef SERIALIKE_H
#define SERIALIKE_H

#include <QObject>
#include <QObject>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QSerialPort>
#include <QIODevice>
#include <QTimer>
#include <QFile>
#include <QProcess>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QTextStream>
#include <QTimer>


class SerialIke:public QObject
{
    Q_OBJECT
     Q_PROPERTY(int myNumberSerie READ myNumberSerie WRITE readNumberSerie NOTIFY serialScreen);
      Q_PROPERTY(int serialNumber READ serialNumber WRITE setNumberSerie NOTIFY serialChanged);

public:
    explicit SerialIke(QObject* parent = nullptr);
    ~SerialIke();

    Q_INVOKABLE bool openSerial(const QString &name);

     Q_INVOKABLE bool isopen(void);

    Q_INVOKABLE bool paramSet(const QString &name, const QString &value) ;

    Q_INVOKABLE int writeBytes(const QList<int> &l, const int resp);

     Q_INVOKABLE void cahngeTela(void);
     Q_INVOKABLE void changedMenu(void);
     Q_INVOKABLE void requestmenu_TelaPrincipal(void);

    Q_INVOKABLE void displayOff(void);
     Q_INVOKABLE void displayOn(void);
      Q_INVOKABLE void displayBrightness(const int luz);
   //  Q_INVOKABLE void powerOff(void);

     Q_INVOKABLE void init(int comander);

   //Q_INVOKABLE void setComandoIke(int comando);
     Q_INVOKABLE void setUser(int scene);

     void whiteNegado(void);
     void whiteAceito(void);
     void inicializa(void);
     int bcc(int size);

    Q_INVOKABLE void readFlash(void);
    Q_INVOKABLE void writeFlash(void);

     Q_INVOKABLE void salvarDadosCalibracao(void);

     Q_INVOKABLE void trocaUser(int user_);

     Q_INVOKABLE void mensagens(int message, int cor);

     Q_INVOKABLE void setIntensidadeLed(char sinal);

      Q_INVOKABLE void stopInit(void);

     Q_INVOKABLE void Inicializa(void);

      Q_INVOKABLE void placaGrav(bool tem);

     Q_INVOKABLE void Gravacao();

    Q_INVOKABLE void setFormating(bool mode);

      Q_INVOKABLE void setSerialNumber(const int number);

      Q_INVOKABLE void readNumberSerie(const int value);




     int myNumberSerie(void);

     void setscreen(void);
     void setScreenMenu(void);
     void setMenu_telaPrincipal(void);
     void setWhiteNeg(void);
     void setWhiteAcept(void);
     void setInitializa(void);
     void setUserss3(void);
     void setUserss1(void);
     void setUserss2(void);
     void setUserss4(void);

     void setEnhanceHigh(void);
     void setEnhanceMed(void);
     void setEnhanceLow(void);
     void setEnhanceOff(void);
     void setGanhoLow(void);
     void setGanhoMed(void);
     void setGanhoHigh(void);
     void initIke(int fase);



     void setNumberSerie(const int serial);
     int serialNumber(void);




 signals:
     void goTela(void);
     void menuChanged(void);
     void menu_TelaPrincipal(void);

     void piscWhiteBlance(void);
     void piscWbNegval(void);

     void negaWhite(void);// coloca no display white balance negado
     void aceptWhite(void); // aceita o white balance
     void initEquip(void);
     void changedUsers3();
     void changedUsers1();
     void changedUsers2();
     void changedUsers4();

     void changeEnhanceHigh(void);
     void changeEnhanceMed(void);
     void changeEnhanceLow(void);
     void changeEnhanceOff(void);

     void changeGanhoLow(void);
     void changeGanhoHig(void);
     void changeGanhoMed(void);

      void setinit2(void);
      void temPlacaAdicional(void);
      void naoTemPlacaAdicional(void);
      void iniciaIke(void);
      void naoIniciaike(void);

       void gravando();//pergunta se está grvando
       void gravandoNot(void);

       void noMediaConnected(void);

       void formatNotConnected(void);
         void formatConnected(void);
         void yesFormating(void); //está formatando dispara um timer para perguntar se anida esta formatando
         void formatOK(void);
           void formatNeg(void);

            void serialChanged(void);
           void backMenu();
           void serialScreen(void);



 public slots:
    Q_INVOKABLE  QList<int>readBytes(void);
    Q_INVOKABLE void setComandoIke(int comando);

       void perguntas(void);
       void perguntaMidia(void);
        void readResp(void);




 private:
     QSerialPort *port;
     QByteArray  *out_;
     QTimer *t1;
     QTimer *t2;
     QTimer *t3;
      QTimer *t4;
        QTimer pergunte;
        QTimer clearRec;
       QTimer timeError;
      QTimer  *timeGravando;

     bool open_ ;
     bool whiteBalance = false;
     bool timeWhite;
     int pont;
     int comando;
     int contWite;
     QByteArray ikeenv;
     QByteArray dadoSalvo;
     int videoLevel;
     int videoLevel_low1;
     int enhancement;
     int zoom = 31;
     int user = 3;
     int videoLevelLow1,videoLevelLow2,videoLevelLow3,videoLevelLow4,videoLevelLow;
     int  enhancementHigh1,enhancementHigh2,enhancementHigh3,enhancementHigh4, enhancementHigh;
     int enhancementMed,videoLevelHigh2,enhancementLow,videoLevelHigh;
     int deltaVideoLevel = 16;
     int deltaVideoLevel2 = 10;
     int deltaEnhancement = 27;
     int deltaEnhancement2 = 27;
     int userConf = 0;
     int intensidadeLed,estadoMidia;
     bool PlacaGravacao;
     bool grava = false;
     bool formatacao = false;
     bool format = false;

     int auxSerial,serialDig,contSerial = 0;
     int serialNumero;
     int m_serial, numberSerie;
    // int rec =0;

};

#endif // SERIALIKE_H
