import QtQuick 2.0

Item {
    Image {
        id: image
        x: 50
        y: 50
        source: "Telas/TelaConfig.bmp"
        fillMode: Image.PreserveAspectFit

        MouseArea{
            anchors.fill: parent
            onClicked: {}
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
                    serial.salvarDadosCalibracao();

                    serial.writeFlash();
                    parent.scale = 1.0;
                }
            }
        }

        Image {
            id: ok
            x: 421
            y: 197
            source: "IconesConfig/SetaOk.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    serial.openSerial("ttymxc0");
                serial.writeBytes([0x7A,0x13,0x00,0x07,0x14,0x81,0x67,0x11,0x80,0x00,0x77],1);
                     requestvideolevel.start();

                      requestganho.start();
                }
            }
        }

        Image {
            id: cima
            x: 421
            y: 99
            source: "IconesConfig/SetaUp.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    serial.openSerial("ttymxc0");
                  serial.writeBytes([0x7A,0x13,0x00,0x07,0x14,0x81,0x67,0x12,0x80,0x00,0x74],1);

                     requestvideolevel.start();
                     requestganho.start();
                }
            }
        }

        Image {
            id: baixo
            x: 421
            y: 287
            source: "IconesConfig/SetaDown.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    serial.openSerial("ttymxc0");
                     serial.writeBytes([0x7A,0x13,0x00,0x07,0x14,0x81,0x67,0x13,0x80,0x00,0x75],1);

                     requestvideolevel.start();
                     requestganho.start();
                    parent.scale = 1.0;
                }
            }
        }

        Image {
            id: ladoDir
            x: 509
            y: 197
            source: "IconesConfig/SetaDir.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    serial.openSerial("ttymxc0");
                    serial.writeBytes([0x7A,0x13,0x00,0x07,0x14,0x81,0x67,0x14,0x80,0x00,0x72],1);
                    requestvideolevel.start();

                      requestganho.start();
                    parent.scale = 1.0;
                }
            }
        }

        Image {
            id: ladoEsc
            x: 332
            y: 197
            source: "IconesConfig/setaEsc.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    serial.openSerial("ttymxc0");
                 serial.writeBytes([0x7A,0x13,0x00,0x07,0x14,0x81,0x67,0x15,0x80,0x00,0x73],1);

                     requestvideolevel.start();

                      requestganho.start();
                }
            }
        }
        Timer{
            id:requestvideolevel
            interval: 300
            repeat:false
            running: false

            onTriggered: {
                serial.setComandoIke(24);// pergunta o video level
           }
    }

        Timer{
            id:requestganho
            interval: 400
            repeat:false
            running: false

            onTriggered: {
                serial.setComandoIke(50);// pergunta o video level
           }
    }
    }

}
