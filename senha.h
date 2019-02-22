#ifndef SENHA_H
#define SENHA_H

#include <QObject>
#include <QDebug>

class senha :public QObject
{
    Q_OBJECT
public:
    explicit senha(QObject* parent = nullptr);
    ~senha();
    Q_INVOKABLE void setSenha(int number);
    void setscreenConfig(void);
     void setscreenMenu(void);

signals:
   void screenConfig(void);
   void screenMenu(void);
   void screenNumberSerie(void);

private:
    int senhaDig = 0;
    int senhaConfig = 5519;
    int  senhaNumberSerie = 1369;
    int contSenha = 0,auxSenha = 0;
};

#endif // SENHA_H
