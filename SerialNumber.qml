import QtQuick 2.0

Item {
    property int  numeroSerie:0
    Image {
        id: serialNumber
        x: 50
        y: 50
        fillMode: Image.PreserveAspectFit
        source: "Telas/SerialNumber.bmp"

        Connections{  //enquanto não há white balance feito fica piscando
                target: serial
            onSerialChanged:{numeroSerie = serial.serialNumber;

            }
        }

        Connections{  //enquanto não há white balance feito fica piscando
              target: serial
                onBackMenu:{
                    root.state = "Menu"
             }
        }

        Image {
            id: one
            x: 149
            y: 152
            source: "IconesSenha/1.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                   //serieNumber.setSerialNumber(1);
                    serial.setSerialNumber(1);
                 parent.scale = 1.0;
                }
            }
        }

        Image {
            id: two
            x: 215
            y: 152
            source: "IconesSenha/2.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.rightMargin: 5
                anchors.bottomMargin: 0
                anchors.leftMargin: -5
                anchors.topMargin: 0
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                     serial.setSerialNumber(2);
                 parent.scale = 1.0;
                }
            }
        }

        Image {
            id: tree
            x: 280
            y: 152
            source: "IconesSenha/3.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.rightMargin: -2
                anchors.bottomMargin: 0
                anchors.leftMargin: 2
                anchors.topMargin: 0
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                     serial.setSerialNumber(3);

                 parent.scale = 1.0;
                }
            }
        }

        Image {
            id: four
            x: 150
            y: 212
            source: "IconesSenha/4.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                     serial.setSerialNumber(4);

                 parent.scale = 1.0;
                }
            }
        }

        Image {
            id: five
            x: 219
            y: 211
            source: "IconesSenha/5.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                       serial.setSerialNumber(5);

                 parent.scale = 1.0;
                }
            }
        }

        Image {
            id: six
            x: 282
            y: 211
            source: "IconesSenha/6.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.rightMargin: -2
                anchors.bottomMargin: 0
                anchors.leftMargin: 2
                anchors.topMargin: 0
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                     serial.setSerialNumber(6);

                 parent.scale = 1.0;
                }
            }
        }

        Image {
            id: seven
            x: 150
            y: 271
            source: "IconesSenha/7.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.rightMargin: -2
                anchors.bottomMargin: 0
                anchors.leftMargin: 2
                anchors.topMargin: 0
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    serial.setSerialNumber(7);

                 parent.scale = 1.0;
                }
            }
        }

        Image {
            id: eight
            x: 218
            y: 270
            source: "IconesSenha/8.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.rightMargin: -3
                anchors.bottomMargin: 0
                anchors.leftMargin: 3
                anchors.topMargin: 0
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                      serial.setSerialNumber(8);

                 parent.scale = 1.0;
                }
            }
        }

        Image {
            id: nine
            x: 284
            y: 272
            source: "IconesSenha/9.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.rightMargin: -2
                anchors.bottomMargin: 0
                anchors.leftMargin: 2
                anchors.topMargin: 0
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                     serial.setSerialNumber(9);

                 parent.scale = 1.0;
                }
            }
        }

        Image {
            id: zero
            x: 219
            y: 331
            source: "IconesSenha/0.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                width: 61
                anchors.rightMargin: -2
                anchors.bottomMargin: 0
                anchors.leftMargin: 1
                anchors.topMargin: 0
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                     serial.setSerialNumber(0);

                 parent.scale = 1.0;
                }
            }
        }

        Image {
            id: del
            x: 152
            y: 335
            source: "IconesSenha/del.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.rightMargin: -2
                anchors.bottomMargin: 0
                anchors.leftMargin: 2
                anchors.topMargin: 0
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                  serial.setSerialNumber(99);


                 parent.scale = 1.0;
                }
            }
        }

        Image {
            id: enter
            x: 288
            y: 333
            source: "IconesSenha/enter.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.rightMargin: -2
                anchors.bottomMargin: 0
                anchors.leftMargin: 2
                anchors.topMargin: 0
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                     serial.setSerialNumber(100);

                 parent.scale = 1.0;
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
                    root.state = "Menu"
                    parent.scale = 1.0;

                }
            }
        }

        Text {
            x: 200
            y: 82
            horizontalAlignment:  Text.AlignVCenter
            font.pointSize: 30
            color: "white"
            text: + serial.serialNumber;
        }
    }

}
