#ifndef SERIALNUMBER_H
#define SERIALNUMBER_H

#include <QObject>
#include "serialike.h"

#include <QFile>
#include <QProcess>
#include <QFileSystemWatcher>
#include <QTextStream>
#include <QIODevice>

class SerialNumber:public  QObject
{
    Q_OBJECT
     Q_PROPERTY(int serialNumber READ serialNumber WRITE setNumberSerie NOTIFY serialChanged);

public:
    explicit SerialNumber(QObject* parent = nullptr);
    ~SerialNumber();

    Q_INVOKABLE void setSerialNumber(const int number);

    void setNumberSerie(const int serial);
    int serialNumber(void);

   Q_INVOKABLE void writeNumberFlash(void);
   Q_INVOKABLE void readNumberFlash();


signals:

   void serialChanged(void);

private:

   int auxSerial,serialDig,contSerial = 0;
   int m_serial, numberSerie;
  // SerialIke *flash;
   QByteArray NumberSerial;

};

#endif // SERIALNUMBER_H
