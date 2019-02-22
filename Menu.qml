import QtQuick 2.0

Item {
    property int versaoSoftawre: 210219
    property int  numSerie: 0

    Image {
        id: menu
        x: 50
        y: 50
        source: "Telas/Menu.bmp"
        fillMode: Image.PreserveAspectFit

        MouseArea{
            anchors.fill: parent
            onClicked: {}


            Connections{  //enquanto não há white balance feito fica piscando
                    target: serial
                onSerialScreen:{numSerie = serial.myNumberSerie;

                }
            }

            Image {
                id: brilho
                x: 649
                y: 13
                fillMode: Image.PreserveAspectFit
                source: "IconesBrilho/IconeBrilho.jpg"
                MouseArea{
                    anchors.fill: parent
                    onPressed: {parent.scale = 0.97;}
                    onReleased: {
                        root.state = "Brilhos"
                        parent.scale = 1.0;
                    }
                }
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
                    root.state = "Principal"
                    parent.scale = 1.0;
                }
            }
        }

        Image {
            id: calender
            x: 142
            y: 77
            source: "IconesConfig/Calendario.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    root.state = "Calendario"
                    parent.scale = 1.0;
                }
            }
        }

        Image {
            id: conf
            x: 412
            y: 77
            source: "IconesConfig/configuration.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                   // root.state =  "Configuration"
                    root.state = "Senha"
                    parent.scale = 1.0;
                }
            }
        }

        Image {
            id: serialNumber
            x: 412
            y: 200
            source: "IconesConfig/serialNumber.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.rightMargin: 2
                anchors.bottomMargin: 0
                anchors.leftMargin: -2
                anchors.topMargin: 0
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    gpio.setTela(20);
                    root.state = "Senha";
                }
            }
        }

        Image {
            id: sI
            x: 142
            y: 191
            source: "IconesConfig/si.png"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                }
            }
        }

            Image {
                id: midiaFormat
                x: 281
                y: 290
                source: "IconesConfig/midiaFormat.png"
                fillMode: Image.PreserveAspectFit
                MouseArea{
                    anchors.fill: parent
                    onPressed: {parent.scale = 0.95;}
                    onReleased: {
                        parent.scale = 1.0;
                        root.state =  "MidiaFormat"
                        serial.setFormating(true);
                    }
                }
            }

            Text {
                 x:520
                  y: 390
                 width: parent.width/2
                height: 25
                horizontalAlignment:  Text.AlignVCenter
               font.pointSize: 15
               color: "white"
               text: +versaoSoftawre
           }

            Text {
                x: 390
                y: 390
                 width: parent.width/2
                horizontalAlignment:  Text.AlignVCenter
                font.pointSize: 15
                color: "white"
                text: +serial.myNumberSerie;
            }

          /*  Text {
                 x:410
                  y: 390
                 width: parent.width/2
                height: 25
                horizontalAlignment:  Text.AlignVCenter
               font.pointSize: 15
               color: "white"
               text: +1
           }

            Text {
                 x:430
                  y: 390
                 width: parent.width/2
                height: 25
                horizontalAlignment:  Text.AlignVCenter
               font.pointSize: 15
               color: "white"
               text: +0
           }

            Text {
                 x:450
                  y: 390
                 width: parent.width/2
                height: 25
                horizontalAlignment:  Text.AlignVCenter
               font.pointSize: 15
               color: "white"
               text: +2
           }

            Text {
                 x:470
                  y: 390
                 width: parent.width/2
                height: 25
                horizontalAlignment:  Text.AlignVCenter
               font.pointSize: 15
               color: "white"
               text: +5
           }*/
     }




}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
