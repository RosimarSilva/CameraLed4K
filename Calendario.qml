import QtQuick 2.0

Item {
    id :calendaro

    property int calendarioDia: 0
    property int calendarioMes: 0
    property int calendarioAno: 0
    property int calendarioHora: 0
    property int calendariominuto: 0

    property int  rMes: 0
    property int  qMes: 0

    property int  qDia: 0
    property int  rDia: 0

    property int  qAno: 0
    property int  rAno: 0

    property int  qhora: 0
    property int  rHora: 0

    property int  qMinuto: 0
    property int  rMinuto: 0

   property color colorCaixa: "#88000000"
    property color colorText: "white"

    property string horaAgora:    "00"
    property string minutoAgora:  "00"
    property string segundoAgora: "00"
    property string diaHoje:    "00"
    property string mesHoje:  "00"
    property string anoHoje: "00"

        property int tamanhoBorda: 4
    property color corFundo: "#242424"
    property color corLaranja: "#f37906"



    Image {
        id: calendario
        x: 50
        y: 50
        source: "Telas/calendario.bmp"
        fillMode: Image.PreserveAspectFit
        MouseArea{
            anchors.fill: parent
            onClicked: {}
        }

        Connections{  //enquanto não há white balance feito fica piscando
                target: calendario_
            onChangedDia:{calendarioDia = calendario_.dia;
                qDia = calendarioDia/10;
                rDia = calendarioDia%10;
            }
        }

        Connections{  //enquanto não há white balance feito fica piscando
                target: calendario_
            onChangedMes:{calendarioMes  = calendario_.mes;
               qMes = calendarioMes/10;
                rMes = calendarioMes%10;
            }
        }
        Connections{  //enquanto não há white balance feito fica piscando
                target: calendario_
             onChangedAno:{calendarioAno = calendario_.ano;
                 qAno = calendarioAno/10;
                  rAno = calendarioAno%10;
             }
        }

        Connections{  //enquanto não há white balance feito fica piscando
                target: calendario_
             onChangedHora:{calendarioHora = calendario_.hora;
                 qhora = calendarioHora/10;
                  rHora = calendarioHora%10;
             }
        }

        Connections{  //enquanto não há white balance feito fica piscando
                target: calendario_
             onChangeMinuto:{calendariominuto = calendario_.minuto;
                 qMinuto = calendariominuto/10;
                  rMinuto = calendariominuto%10;
             }
        }

        Image {
            id: back
            x: 0
            y: 0
            source: "Icones/Back.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    root.state = "Menu"
                    parent.scale = 1.0;
                }
            }
        }

        Image {
            id: maisDia
            x: 235
            y: 158
            source: "IconesConfig/BotaoPlus.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    calendario_.setDay(1);
                 }
            }
        }

        Image {
            id: menosDia
            x: 140
            y: 158
            source: "IconesConfig/BotaoMinus.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    calendario_.setDay(2);
                }
            }
        }

        Image {
            id: menosMes
            x: 345
            y: 158
            source: "IconesConfig/BotaoMinus.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                     calendario_.setMonth(4);
                }
            }
        }

        Image {
            id: maisMes
            x: 441
            y: 159
            source: "IconesConfig/BotaoPlus.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    calendario_.setMonth(3);
                }
            }
        }

        Image {
            id: maisAno
            x: 639
            y: 158
            source: "IconesConfig/BotaoPlus.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                     calendario_.setYear(5);
                }
            }
        }

        Image {
            id: menosAno
            x: 542
            y: 158
            source: "IconesConfig/BotaoMinus.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    calendario_.setYear(6);
                }
            }
        }

        Image {
            id: maisMinuto
            x: 441
            y: 292
            source: "IconesConfig/BotaoPlus.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                      calendario_.setminute(5);
                }
            }
        }

        Image {
            id: menosMinuto
            x: 351
            y: 292
            source: "IconesConfig/BotaoMinus.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    calendario_.setminute(6);
                }
            }
        }

        Image {
            id: maisHora
            x: 235
            y: 292
            source: "IconesConfig/BotaoPlus.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    calendario_.setHour(5);
                }
            }
        }

        Image {
            id: menosHora
            x: 140
            y: 292
            source: "IconesConfig/BotaoMinus.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    calendario_.setHour(6);
                }
            }
        }
//variaveis do dia
        Text {
            x: 210
            y: 158
            width: parent.width/2
            height: 50
            horizontalAlignment:  Text.verticalCenter
            font.pointSize: 30
            color: calendaro.colorText
            text: +calendaro.rDia
        }

        Text {
            x: 190
            y: 158
            width: parent.width/2
            height: 50
            horizontalAlignment:  Text.verticalCenter
            font.pointSize: 30
            color: calendaro.colorText
            text: +calendaro.qDia
        }
//variaveis do mes
      Text {
                x:395
                y: 158
                width:parent.width/2
                height: 50
                horizontalAlignment:  Text.AlignVCenter
                font.pointSize: 30
                color: calendaro.colorText
                text: +calendaro.qMes
            }

      Text {
                x:415
                y: 158
                width: parent.width/2
                height: 50
               horizontalAlignment:  Text.AlignVCenter
                font.pointSize: 30
                color: calendaro.colorText
                text: +calendaro.rMes
            }

      //variaveis do ano
            Text {
                x: 590
                y: 158
                horizontalAlignment:  Text.AlignVCenter
                font.pointSize: 30
                color: calendaro.colorText
                text: +calendaro.qAno
            }

            Text {
                x: 610
                y: 158
                horizontalAlignment:  Text.AlignVCenter
                font.pointSize: 30
                color: calendaro.colorText
                text: +calendaro.rAno
            }



    //variaveis da hora
          Text {
              x: 210
              y: 292
              horizontalAlignment:  Text.AlignVCenter
              font.pointSize: 30
              color: calendaro.colorText
              text:  +calendaro.rHora
          }

          Text {
              x: 190
              y: 292
              horizontalAlignment:  Text.AlignVCenter
              font.pointSize: 30
              color: calendaro.colorText
              text:+calendaro.qhora
          }

          //variaveis da minuto
                Text {
                    x: 395
                    y: 292
                    horizontalAlignment:  Text.AlignVCenter
                    font.pointSize: 30
                    color: calendaro.colorText
                    text: +calendaro.qMinuto
                }

                Text {
                    x: 415
                    y: 292
                    horizontalAlignment:  Text.AlignVCenter
                    font.pointSize: 30
                    color: calendaro.colorText
                    text:+calendaro.rMinuto
                }


/*
                Rectangle {
                    id: rectFoo
                    width: parent.width
                    height: parent.height*0.275
                   // anchors.top: viewMeteorologia.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                  //  color: calendaro.corLaranja
                    border.width: calendaro.tamanhoBorda
                    border.color: calendaro.corFundo

                    Text {
                        id: txtHora
                       /* anchors.centerIn: parent
                        font {
                            family: openSansFont.name;
                            pixelSize: parent.height*0.65
                            weight: Font.ExtraBold
                        }*/
                     /*   horizontalAlignment:  Text.AlignVCenter
                        font.pointSize: 30
                        style: Text.Sunken
                        color: "#CCFFFFFF"
                        text: calendaro.horaAgora + ":" + calendaro.minutoAgora + ":" + calendaro.segundoAgora

                    }*/

                    Text {
                        x: 623
                        y: 26
                        horizontalAlignment:  Text.AlignVCenter
                        font.pointSize: 15
                        color: calendaro.colorText
                        text:+ calendaro.horaAgora
                    }
                    Text {
                        x: 655
                        y: 26
                        horizontalAlignment:  Text.AlignVCenter
                        font.pointSize: 15
                        color: calendaro.colorText
                        text:+ calendaro.minutoAgora
                    }

                    Text {
                        x: 410
                        y: 26
                        horizontalAlignment:  Text.AlignVCenter
                        font.pointSize: 15
                        color: calendaro.colorText
                        text:+ calendaro.diaHoje
                    }
                    Text {
                        x: 455
                        y: 26
                        horizontalAlignment:  Text.AlignVCenter
                        font.pointSize: 15
                        color: calendaro.colorText
                        text:+ calendaro.mesHoje
                    }
                    Text {
                        x: 495
                        y: 26
                        horizontalAlignment:  Text.AlignVCenter
                        font.pointSize: 15
                        color: calendaro.colorText
                        text:+ calendaro.anoHoje
                    }

                }
                Timer {
                    id:timeHora
                    interval: 1000; running: true; repeat: true;
                    onTriggered: {
                         var date = new Date;
                        calendaro.horaAgora = date.getHours();
                        calendaro.minutoAgora = date.getMinutes();
                        calendaro.segundoAgora = date.getUTCSeconds();
                         calendaro.diaHoje = date.getUTCDay();
                          calendaro.mesHoje = date.getMonth();
                          calendaro.anoHoje = date.getFullYear();

                        calendarioDia = date.getUTCDay();
                        qDia = calendarioDia/10;
                        rDia = calendarioDia%10;

                       calendarioAno = date.getFullYear();
                        qAno = calendarioAno/10;
                         rAno = calendarioAno%10;

                        calendarioMes = date.getMonth();
                        qMes = calendarioMes/10;
                         rMes = calendarioMes%10;

                        calendarioHora =date.getHours();
                        qhora = calendarioHora/10;
                         rHora = calendarioHora%10;

                        calendariominuto = date.getMinutes();;
                        qMinuto = calendariominuto/10;
                         rMinuto = calendariominuto%10;


                        if (calendaro.horaAgora < 10)    { calendaro.horaAgora    = "0" + calendaro.horaAgora;    }
                        if (calendaro.minutoAgora < 10)  { calendaro.minutoAgora  = "0" + calendaro.minutoAgora;  }
                        if (calendaro.segundoAgora < 10) { calendaro.segundoAgora = "0" + calendaro.segundoAgora;}
                         if (calendaro.diaHoje < 10) { calendaro.diaHoje= "0" + calendaro.diaHoje;}
                          if (calendaro.mesHoje < 10) { calendaro.mesHoje = "0" + calendaro.mesHoje;}
                           if (calendaro.anoHoje < 10) { calendaro.anoHoje = "0" + calendaro.anoHoje;}
                }
                }

              /*  function acertarHora() {
                    var date = new Date;
                    calendaro.horaAgora = date.getHours();
                    calendaro.minutoAgora = date.getMinutes();
                    calendaro.segundoAgora = date.getUTCSeconds();

                    if (calendaro.horaAgora < 10)    { calendaro.horaAgora    = "0" + calendaro.horaAgora;    }
                    if (calendaro.minutoAgora < 10)  { calendaro.minutoAgora  = "0" + calendaro.minutoAgora;  }
                    if (calendaro.segundoAgora < 10) { calendaro.segundoAgora = "0" + calendaro.segundoAgora; }
                }*/


}

