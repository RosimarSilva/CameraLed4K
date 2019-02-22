import QtQuick 2.0

Item {
    property int pont: 0
    property bool standBy_: false
    property bool vent: false
    property int tela: 2

    Image {
        id: telaLed
        x: 50
        y: 50
        source: "Telas/19_principal.bmp"
        fillMode: Image.PreserveAspectFit
        MouseArea{
            anchors.fill: parent
            onClicked: {}
        }

        Image {
            id: imagecentral
            x: 199
            y: 69
            source: "IndicadoresCentrais/indi00.png"
            fillMode: Image.PreserveAspectFit
            //máquina de estados das figuras indicadoras de intensidade
                    states: [
                        State {
                            name: "Indicador0"
                        },
                        State {
                            name: "Indicador1"
                        },

                        State {
                            name: "Indicador2"
                        },
                        State {
                            name: "Indicador3"
                        },

                        State {
                            name: "Indicador4"
                        },
                        State {
                            name: "Indicador5"
                        },

                        State {
                            name: "Indicador6"
                        },
                        State {
                            name: "Indicador7"
                        },

                        State {
                            name: "Indicador8"
                        },
                        State {
                            name: "Indicador9"
                        },
                        State {
                            name: "Indicador10"
                        }

                    ]
            // imagens das figuras da porcentagem, do led
                    Image {
                        id: indi0

                        source: "IndicadoresCentrais/indi00.png"
                        visible: imagecentral.state == "Indicador0"
                    }

                    Image {
                        id: indi1

                        source: "IndicadoresCentrais/indi10.png"
                        visible: imagecentral.state == "Indicador1"
                    }

                    Image {
                        id: indi2

                        source: "IndicadoresCentrais/indi20.png"
                        visible: imagecentral.state == "Indicador2"
                    }
                    Image {
                        id: indi3

                        source: "IndicadoresCentrais/indi30.png"
                        visible: imagecentral.state == "Indicador3"
                    }

                    Image {
                        id: indi4

                        source: "IndicadoresCentrais/indi40.png"
                        visible: imagecentral.state == "Indicador4"
                    }

                    Image {
                        id: indi5

                        source: "IndicadoresCentrais/indi50.png"
                        visible: imagecentral.state == "Indicador5"
                    }

                    Image {
                        id: indi6

                        source: "IndicadoresCentrais/indi60.png"
                        visible: imagecentral.state == "Indicador6"
                    }

                    Image {
                        id: indi7

                        source: "IndicadoresCentrais/indi70.png"
                        visible: imagecentral.state == "Indicador7"
                    }

                    Image {
                        id: indi8

                        source: "IndicadoresCentrais/indi80.png"
                        visible: imagecentral.state == "Indicador8"
                    }

                    Image {
                        id: indi9

                        source: "IndicadoresCentrais/indi90.png"
                        visible: imagecentral.state == "Indicador9"
                    }

                    Image {
                        id: indi10
                       source: "IndicadoresCentrais/indi100.png"
                        visible: imagecentral.state == "Indicador10"
                    }

        }

        Image {
            id: menu
            x: 651
            y: 5
            source: "Icones/BotaoMenu.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.rightMargin: 0
                anchors.bottomMargin: -11
                anchors.leftMargin: 0
                anchors.topMargin: 11
                anchors.fill: parent
                onPressed: {parent.scale = 0.97;}
                onReleased: {
                  telaP.stop();
                   setMessage();
                    gpio.setTela(1);
                    root.state = "Principal"
                    parent.scale = 1.0;
                }
            }
        }

        Image {
            id: minus
            x: 40
            y: 120
            source: "IconesLed/Minus.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.90;}
                onReleased: {
                    telaP.restart();
                    pont --;
                   setLuminous() // ajusta a intensidade do led
                   // serial.setIntensidadeLed(1);
                    setMessage()
                   parent.scale = 1.0;
                }
            }
        }

        Image {
            id: plus
            x: 468
            y: 120
            source: "IconesLed/Plus.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.90;}
                onReleased: {
                    telaP.restart();
                  pont ++;
                    setLuminous() // ajusta a intensidade do led
                  //serial.setIntensidadeLed(2);
                    setMessage()
                    parent.scale = 1.0;
                }
            }
        }
        //recebe o sinal do c++
        Connections{
           target: gpio
           onChangeLuminousMais:{
               telaP.restart();
                 pont ++;
                  setLuminous() // ajusta a intensidade do led
                  setMessage()
            }
        }

        Connections{
           target: gpio
           onChangeLuminousMenos:{
                telaP.restart();
                 pont --;
                  setLuminous() // ajusta a intensidade do led
                  setMessage()
            }
        }

        Connections{
           target: gpio
           onChangeTelaPrincipal:{
                root.state  = "Principal"
               gpio.setTela(1);
               telaP.stop();
               serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x20,0x20,
                                    0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x6b],0);
            }
        }

        Image {
            id: standBy
            x: 654
            y: 130
            source: "IndicadoresCentrais/StandByBranco.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.90;}
                onReleased: {
                    if(!standBy_)
                    {
                        standBy_ = true;
                      standBy.state = "StandByOn"
                      imagecentral.state = "Indicador00"
                       serial.setIntensidadeLed(1);

                       serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,
                                           0x3e,0x11,0x27,0x4c,0x45,0x44,0x20,0x30,0x25,0x20,0x20,0x00,0x13],0);
                    }
                    else
                    {
                         standBy.state = "StandByOff"
                         standBy_ =false;

                         setLuminous() // ajusta a intensidade do ledd
                          setMessage()
                  }
                    parent.scale = 1.0;
                }

                states: [
                    State {
                        name: "StandByOn"
                    },
                    State {
                        name: "StandByOff"
                    }
                ]

                Image {
                    id: standBOn
                    source: "IndicadoresCentrais/StandByVerde.png"
                     visible:standBy.state == "StandByOn"
                }

                Image {
                    id: standBOff
                    source:  "IndicadoresCentrais/StandByBranco.png"
                     visible:standBy.state == "StandByOff"
                }
                }
            }
        }

    // desenha a porcentagem atual no display e envia o comando para o módulo do led a porcentagem correspondente

        Timer{
            id:timeezero
            interval: 100
            repeat:false
            running: false

            onTriggered: {
            serial.setIntensidadeLed(1);
        }
        }

            Timer{
                id:telaP
                interval:15000
                repeat:false
                running: false
                onTriggered: {
                gpio.setTela(1);
                root.state = "Principal"
                    serial.openSerial("ttymxc0");
                    serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x20,0x20,
                                         0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x6b],0);
            }
        }

         function setLuminous(){
                 if(standBy_)
                 {
                    standBy_= false
                    standBy.state = "StandByOff"
                 }
                if(pont >10) pont = 10;
                if(pont <= 0) pont = 0;

                 serial.openSerial("ttymxc0");
                switch(pont)
                {
                   case 0:
                        imagecentral.state = "Indicador0"

                       serial.setIntensidadeLed(1);

                       timeezero.start();

                     break
                    case 1:
                        imagecentral.state = "Indicador1"

                        serial.writeBytes([0xA5,0x07,0x06,0x14,0x00,0x86,0x6c],0);
                     break
                   case 2:
                        imagecentral.state = "Indicador2"
                        serial.writeBytes([0xA5,0x07,0x06,0x32,0x00,0x9c,0x0c],0);
                    break
                   case 3:
                        imagecentral.state = "Indicador3"
                          // serial.writeBytes([0xA5,0x07,0x06,0x50,0x00,0xb5,0x6c],0);
                    break
                   case 4:
                        imagecentral.state = "Indicador4"
                        serial.writeBytes([0xA5,0x07,0x06,0x78,0x00,0xab,0x6c],0);
                    break
                   case 5:
                        imagecentral.state = "Indicador5"
                        serial.writeBytes([0xA5,0x07,0x06,0xaa,0x00,0xf7,0xcc],0);
                    break
                   case 6:
                        imagecentral.state = "Indicador6"
                        serial.writeBytes([0xA5,0x07,0x06,0xe6,0x00,0xc3,0x0c],0);
                    break
                   case 7:
                        imagecentral.state = "Indicador7"
                        serial.writeBytes([0xA5,0x07,0x06,0xe6,0x00,0x79,0x6c],0);
                    break
                   case 8:
                        imagecentral.state = "Indicador8"
                         serial.writeBytes([0xA5,0x07,0x06,0xcc,0x01,0x1d,0xac],0);
                    break
                   case 9:
                        imagecentral.state = "Indicador9"
                        serial.writeBytes([0xA5,0x07,0x06,0xbc,0x02,0x78,0x6d],0);
                    break
                   case 10:
                        imagecentral.state = "Indicador10"
                        serial.writeBytes([0xA5,0x07,0x06,0xff,0x03,0x88,0x9d],0);
                    break


                }

                if((pont > 0)&&(vent == false))  // coloca ventilador em 100%
                {
                     //serial.openSerial("ttymxc0");
                 serial.writeBytes([0xA5,0x07,0x09,0x64,0x00,0x93,0xaf],0);
                    vent = true;
                }

                else if ((pont <= 0)&&(vent == true))  //coloca vent em 10%
                {
                     serial.openSerial("ttymxc0");
                     serial.writeBytes([0xA5,0x07,0x09,0x0A,0x00,0xbf,0xcf],0);
                    vent = false;
                }
         }
    // escreve no monitor a porcentagem do led
         function setMessage()
         {
             //
            switch(pont)
            {
            case 0:
                 serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,
                                    0x3e,0x11,0x27,0x4c,0x45,0x44,0x20,0x30,0x25,0x20,0x20,0x00,0x13],0);
                break
            case 1:
              serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x4c,0x45,
                                   0x44,0x20,0x31,0x30,0x25,0x20,0x00,0x02],0);
               break

            case 2:
              serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x4c,0x45,
                                   0x44,0x20,0x32,0x30,0x25,0x20,0x00,0x01],0);
               break
            case 3:
              serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x4c,0x45,
                                   0x44,0x20,0x33,0x30,0x25,0x20,0x00,0x00],0);
               break

            case 4:
              serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x4c,0x45,
                                   0x44,0x20,0x34,0x30,0x25,0x20,0x00,0x07],0);
               break

            case 5:
              serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x4c,0x45,
                                   0x44,0x20,0x35,0x30,0x25,0x20,0x00,0x06],0);
               break

            case 6:
              serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x4c,0x45,
                                   0x44,0x20,0x36,0x30,0x25,0x20,0x00,0x05],0);
               break

            case 7:
              serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x4c,0x45,
                                   0x44,0x20,0x37,0x30,0x25,0x20,0x00,0x04],0);
               break

            case 8:
              serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x4c,0x45,
                                   0x44,0x20,0x38,0x30,0x25,0x20,0x00,0x0b],0);
               break

            case 9:
              serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x4c,0x45,
                                   0x44,0x20,0x39,0x30,0x25,0x20,0x00,0x0a],0);
               break

            case 10:
              serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x4c,0x45,
                                   0x44,0x20,0x31,0x30,0x30,0x25,0x00,0x012],0);

                break

            case 11:
               // serial.openSerial("ttymxc0");
            serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x20,0x20,
                                 0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x6b],0);

             break


          }
         }

         function clearMessage()
         {
             serial.openSerial("ttymxc0");
             serial.writeBytes([0x7a,0x13,0x00,0x10,0x30,0x10,0x40,0x3e,0x11,0x27,0x20,0x20,
                                  0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x6b],0);

         }

}







/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
