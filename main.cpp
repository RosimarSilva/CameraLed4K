#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "serialike.h"
#include "gpio.h"
#include "senha.h"
#include "calendario.h"
#include "init.h"


int main(int argc, char *argv[])
{
  //  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    qmlRegisterType<SerialIke>("AstusFonte",1,0,"FonteLed");
     qmlRegisterType<GPIO>("Gpio",1,0,"Gpios");
       qmlRegisterType<senha>("Senha",1,0,"Password");
       qmlRegisterType<Calendario>("Calendario",1,0,"Calender");
        qmlRegisterType<Init>("Calendario",1,0,"Initial");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
