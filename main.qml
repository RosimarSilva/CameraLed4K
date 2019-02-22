import QtQuick 2.0
import QtQuick.Window 2.2

import AstusFonte 1.0
import Gpio 1.0
import Senha 1.0
import Calendario 1.0


Window {
    //visible: true
    visibility: Window.FullScreen
    width: 800
    height: 480
    color: "black"

    Rectangle{
        id:root

        FonteLed{id:serial}
        Gpios{id: gpio}
        Password{id:senha_}
        Calender{id: calendario_}
        Initial{id:inicia}



      // Telaprincipal{}
         Inicializacao{}
         // Menu{}

        states: [
            State {
                name: "Principal"
            },
            State {
                name: "Users"
            },
            State {
                name: "Configuration"
            },
            State {
                name: "Menu"
           },
            State {
                name: "Calendario"
             },
            State {
                name: "TelaLed"
            },
            State {
                name: "Senha"
            },
            State {
                name: "MidiaFormat"
            },
            State {
                name: "Brilhos"
            },
            State {
                name: "SerialNumber"
            }
        ]

        Telaprincipal
        {
            id: principal
            anchors.fill: parent
            visible: root.state == "Principal"
        }

        Users
        {
            id: user
            anchors.fill: parent
            visible: root.state == "Users"
        }
        Configuration
        {
            id: config
            anchors.fill: parent
            visible: root.state == "Configuration"
        }
        Menu
        {
            id: menu
            anchors.fill: parent
            visible: root.state == "Menu"
        }
        Calendario
        {
            id: calender
            anchors.fill: parent
            visible: root.state == "Calendario"
        }
        TelaLed
        {
            id: telaled
            anchors.fill: parent
            visible: root.state == "TelaLed"
        }
        Senha
        {
            id:telasenha
            anchors.fill: parent
            visible: root.state == "Senha"
        }
        Inicializacao
        {
            id:telaInit
            anchors.fill: parent
            visible: root.state == "TelaInit"
        }

        MidiaFormat
        {
            id:telaForm
            anchors.fill: parent
            visible: root.state == "MidiaFormat"
        }

        Brilho
        {
            id:brigtnes
            anchors.fill: parent
            visible: root.state == "Brilhos"
        }
        SerialNumber
        {
            id:numberSerie
            anchors.fill: parent
            visible: root.state == "SerialNumber"
        }

    }
 /*   Component.onCompleted:  // incia a configuração da serial da placa ikegami
    {
    /* serial.openSerial("ttymxc0")
    if(serial.isopen())
    {
        serial.paramSet('baud', '19200');
        serial.paramSet('bits', '8');
        serial.paramSet('parity', 'n');
        serial.paramSet('stops', '1');

          serial.paramSet('dtr', '1');
       serial.paramSet('rts', '1');

         console.log("configurada")
        serial.openSerial("ttymxc0");

         serial.writeBytes([0xA5,0x06,0x0a,0x00,0xc4,0x49],1);// habilita o drive do led
        serial.readFlash();

       }
         else console.log("Porta não configurada")*/


   //}
}
