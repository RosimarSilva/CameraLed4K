import QtQuick 2.0

Item {
    property int  senha__: 0;


    Image {
        id: senha
        x: 50
        y: 50
        source: "Telas/senha.bmp"
        fillMode: Image.PreserveAspectFit

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
                    senha_.setSenha(1);
                    setImage();
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
                      senha_.setSenha(2);
                    setImage();
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
                      senha_.setSenha(3);
                    setImage();
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
                      senha_.setSenha(4);
                    setImage();
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
                      senha_.setSenha(5);
                    setImage();
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
                      senha_.setSenha(6);
                    setImage();
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
                      senha_.setSenha(7);
                    setImage();
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
                      senha_.setSenha(8);
                    setImage();
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
                      senha_.setSenha(9);
                    setImage();
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
                      senha_.setSenha(0);
                    setImage();
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
                    senha_.setSenha(99);

                    senha__ -= 2;
                    if(senha__ <= -1) senha__ = -1;
                  setImage();

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
                      senha_.setSenha(100);
                  // serial.writeFlash();
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
                    senha__ = 0;
                    asterisco.state = "Zero"
                }
            }
        }

        Connections{  //enquanto não há white balance feito fica piscando
                target: senha_
            onScreenConfig:{
                asterisco.state = "Zero"
                root.state =  "Configuration"
                senha__ = 0;

                 serial.setComandoIke(2);
             }
        }

        Connections{  //enquanto não há white balance feito fica piscando
            target: senha_
            onScreenMenu:{
                asterisco.state = "Zero"
                 senha__ = 0;

                root.state =  "Menu"
            }
        }

        Connections{  //enquanto não há white balance feito fica piscando
            target: senha_
            onScreenNumberSerie:{
                 senha__ = 0;
                asterisco.state = "Zero"
               root.state =  "SerialNumber"
            }
        }



        Image {
            id: asterisco
            x: 163
            y: 82
            source: "IconesSenha/asterisco0.bmp"
            fillMode: Image.PreserveAspectFit

            states: [
                State {
                    name: "Zero"
                },
                State {
                    name: "Hum"
                },
                State {
                    name: "Dois"
                },
                State {
                    name: "Tres"
                },
                State {
                    name: "Quatro"
                }
            ]

            Image {
               id:zero0
               source: "IconesSenha/asterisco0.bmp"
               visible:asterisco.state == "Zero"
            }
            Image {
               id:hum1
               source: "IconesSenha/asterisco1.bmp"
               visible:asterisco.state == "Hum"
            }
            Image {
               id:dois2
               source: "IconesSenha/asterisco2.bmp"
               visible:asterisco.state == "Dois"
            }
            Image {
               id:tres3
               source: "IconesSenha/asterisco3.bmp"
               visible:asterisco.state == "Tres"
            }
            Image {
               id:quatro4
               source:  "IconesSenha/asterisco4.bmp"
               visible:asterisco.state == "Quatro"
            }
        }
    }

    function setImage()
    {
        senha__ ++
        switch(senha__)
        {
            case 0:asterisco.state = "Zero"
                break
            case 1:asterisco.state = "Hum"
                break
            case 2:asterisco.state = "Dois"
                break
            case 3:asterisco.state = "Tres"
                break
            case 4:asterisco.state = "Quatro"
                break
        }
    }

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
