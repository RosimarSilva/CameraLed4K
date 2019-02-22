import QtQuick 2.0

Item {
    Image {

      /*  Timer{
            id:timerinit
            interval: 2000
            repeat:true
           running: true

          onTriggered: {
              serial. mensagens(80,0);
              console.log("opa")
           }
       }*/



        id: telaInit
        x: 50
        y: 50
        fillMode: Image.PreserveAspectFit
        source: "imagesInit/loading_1.bmp"



        states: [
            State {
                name: "Init1"
             },
            State {
                name: "Init2"
             },
            State {
                name: "Init3"
             },
            State {
                name: "Init4"
             },
            State {
                name: "Init5"
             },
            State {
                name: "Init6"
             },
            State {
                name: "Init7"
             },
            State {
                name: "Init8"
             },
            State {
                name: "Init9"
             },
            State {
                name: "Init10"
             }
        ]
        Image {
            id: init1
            source: "imagesInit/loading_1.bmp"
            visible: telaInit.state == "Init1"
        }
        Image {
            id: init2
            source: "imagesInit/loading_2.bmp"
            visible: telaInit.state == "Init2"
        }
        Image {
            id: init3
            source: "imagesInit/loading_3.bmp"
            visible: telaInit.state == "Init3"
        }
        Image {
            id: init4
            source: "imagesInit/loading_4.bmp"
            visible: telaInit.state == "Init4"
        }
        Image {
            id: init5
            source: "imagesInit/loading_5.bmp"
            visible: telaInit.state == "Init5"
        }
        Image {
            id: init6
            source: "imagesInit/loading_6.bmp"
            visible: telaInit.state == "Init6"
        }
        Image {
            id: init7
            source: "imagesInit/loading_7.bmp"
            visible: telaInit.state == "Init7"
        }
        Image {
            id: init8
            source: "imagesInit/loading_8.bmp"
            visible: telaInit.state == "Init8"
        }
        Image {
            id: init9
            source: "imagesInit/loading_9.bmp"
            visible: telaInit.state == "Init9"
        }
        Image {
            id: init10
            source: "imagesInit/loading_10.bmp"
            visible: telaInit.state == "Init10"
        }


        Connections{
           target: inicia
             onInit_2:
            {
              telaInit.state = "Init2"
                  serial.openSerial("ttymxc0")
                 serial.writeBytes([0xA5,0x06,0x0a,0x00,0xc4,0x49],1);// habilita o drive do led
                 inicia.setTime();
             }
        }

        Connections{
           target: inicia
             onInit_3:
            {
                 telaInit.state = "Init3"
                // serial.trocaUser(4);
                 inicia.setTime4();


            }
        }

        Connections{
           target: inicia
             onInit_4:
            {
                 telaInit.state = "Init4"
                 inicia.setTime5();
             // serial.openSerial("ttymxc0");
              // serial.writeBytes([0xA5,0x07,0x09,0x0A,0x00,0xbf,0xcf],0);
                serial.mensagens(80,1);
            }
        }
    }

    Connections{
       target: inicia
         onInit_5:
        {
             telaInit.state = "Init5"
             inicia.setTime6();

            //serial.mensagens(13,1);
        }
    }


Connections{
   target: inicia
     onInit_6:
    {
         telaInit.state = "Init6"
          serial.setComandoIke(4);//manda o zoom para 1
         inicia.setTime7();
        //serial.mensagens(13,1);
    }
}

Connections{
   target: inicia
     onInit_7:
    {
         telaInit.state = "Init7"
           serial.setComandoIke(167);//Seleciona o modo awb
        //serial.mensagens(13,1);
         inicia.setTime8();
    }
}
Connections{
   target: inicia
     onInit_8:
    {
         telaInit.state = "Init8"
          serial.setComandoIke(1019);//tem placa adicional?
        inicia.setTime9();
       // serial.mensagens(13,1);
    }
}
Connections{
   target: inicia
     onInit_9:
    {
         telaInit.state = "Init9"

         inicia.setTime10();
        //serial.mensagens(13,1);
         // serial.setComandoIke(1012);//mprioridade pendrive
         //  inicia.setTime8();

           serial.setComandoIke(6);//SETA AUTO FOLDER

    }
}



Connections{
   target: inicia
     onInit_10:
    {
        // telaInit.state = "Init10"
         root.state = "Principal"
          serial.setComandoIke(1012);//mprioridade pendrive
       // serial.mensagens(800,1);

         serial.mensagens(800,1);
    }
}

Connections{
   target: serial
     onIniciaIke:
    {
         serial.setComandoIke(1004);//mtem placa adicional?
          serial.placaGrav(true);//fala para o c++ que tem placa de gravaçaão
          inicia.setTime9();
        // serial.placaGrav(true);//fala para o c++ que tem placa de gravaçaão
     }
}


Connections{
   target: serial
     onNaoIniciaike:// não tem toca o braco
    {
         //serial.setComandoIke(1004);//mtem placa adicional?serial.mensagens(800,1)
          inicia.setTime9();

          serial.placaGrav(false);//fala para o c++ que não tem placa de gravaçaão

    }
}


}
