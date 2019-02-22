import QtQuick 2.0
import AstusFonte 1.0

Item {
    Image {
        id: user
        x: 50
        y: 50
        source: "Telas/telaUser.png"
        fillMode: Image.PreserveAspectFit
        MouseArea{
            anchors.fill: parent
            onClicked: {}
       }

        //agurada um tempo e volta para atela principal
        Timer{
            id:backPri
            interval: 2000
            repeat:false
            running: false

            onTriggered: {

                   root.state  = "Principal"
            }
        }

        //agurada 10ms para dar tempo para a serial se atualizar
        Timer{
            id:setmens
            interval: 100
            repeat:false
            running: false

            onTriggered: {
                serial.mensagens(1,0);
            }
        }

        //agurada 1500 ms para apagar a mensagem
        Timer{
            id:clearMens
            interval: 3000
            repeat:false
            running: false

            onTriggered: {
                serial.mensagens(101,1);
            }
        }

        Image {
            id: users
            x: 0
            y: 0
            source: "Icones/Userlaparo1.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
              onClicked:{
                    root.state = "Principal"

                }
            }

            state: "laparo_1"

             states: [
                 State {
                     name: "laparo_1"

                     },
                 State {
                     name: "laparo_2"

                     },
                 State {
                     name: "endoflexivel"

                     },
                 State {
                     name:"histero/uro"

                     }
              ]

             Image {
                 id: lap1
                 source: "Icones/Userlaparo1.png"
                  visible:users.state ==  "laparo_1"
             }

             Image {
                 id: lap2
                 source: "Icones/Userlaparo2.png"
                  visible:users.state ==  "laparo_2"
             }

             Image {
                 id: endo
                 source: "Icones/UserEndiflexivel.png"
                  visible:users.state ==  "endoflexivel"
             }

             Image {
                 id:hist
                 source: "Icones/UserHisteroUro.png"
                  visible:users.state ==  "histero/uro"
             }

        }

        Image {
            id: lap01
            x: 206
            y: 79
            source: "Icones/Laparo01.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {

                    serial.trocaUser(1);
                     backPri.start();
                    clearMens.start();
                    setmens.start();//agurada 10ms para dar tempo para a serial se atualizar
                     users.state = "laparo_1"
                     parent.scale = 1.0;
                }
            }
        }

        Image {
            id: endoflex
            x: 206
            y: 233
            source: "Icones/Endiflexivel.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    serial.trocaUser(3);

                     backPri.start();

                      setmens.start();//agurada 10ms para dar tempo para a serial se atualizar
                        clearMens.start();
                      users.state = "endoflexivel"
                }
            }
        }

        Image {
            id: histero
            x: 206
            y: 316
            source: "Icones/HistreoUro.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    serial.trocaUser(4);
                      clearMens.start();
                     backPri.start();

                    setmens.start();//agurada 10ms para dar tempo para a serial se atualizar
                     users.state =  "histero/uro"
                }
            }
        }

        Image {
            id: lap02
            x: 206
            y: 157
            source: "Icones/Laparo02.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    serial.trocaUser(2);

                    backPri.start();
                     setmens.start();
                    clearMens.start();
                     users.state = "laparo_2"
                }
            }
        }
    }

}
