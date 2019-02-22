import QtQuick 2.0

Item {
    Image {
        id: formatmidia
        x: 50
        y: 50
        source: "Telas/MidiaFormat.bmp"
        fillMode: Image.PreserveAspectFit

        Image {
            id: iniciar
            x: 181
            y: 175
            source: "IconesConfig/inicio.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea
            {
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
                    parent.scale = 1.0;
                    serial.setComandoIke(1020);
                     eventFormat.state =  "formatWait"
                }
          }
        }

        Image {
            id: cancelar
            x: 447
            y: 175
            source: "IconesConfig/cancel.bmp"
            fillMode: Image.PreserveAspectFit
            MouseArea
            {
                anchors.fill: parent
                onPressed: {parent.scale = 0.95;}
                onReleased: {
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
            MouseArea
            {
                anchors.fill: parent
                onPressed: {parent.scale = 0.97;}
                onReleased: {
                    parent.scale = 1.0;
                    root.state =  "Menu"
                    serial.setFormating(false);
                }
          }
        }



         Image {
             id: mediaconect
             x: 267
             y: 355
             source: "IconesConfig/formatmidiayes.png"
             fillMode: Image.PreserveAspectFit
             states: [
                 State {
                     name: "Nomedia"
                   },

                 State {
                     name: "YesMedia"
                   }
             ]

             Image {
                id: no
                 source: "IconesConfig/formatmidianNot.png"
                   visible: mediaconect.state =="Nomedia"
             }

             Image {
                 id: yes
                 source: "IconesConfig/formatmidiayes.png"
                 visible: mediaconect.state =="YesMedia"
             }
         }



         Connections{
             target: serial
            onFormatNotConnected:
            {
              mediaconect.state =  "Nomedia"
                eventFormat.state = "formatNegado"
                mediatime.start();
            }
         }


         Connections{
             target: serial
            onFormatConnected://espera 300 milissegundos para enviar o comando de formatação
            {
               format.start();
            }
         }

         Timer
         {
             id:format
              interval: 300
            running: false
            repeat: false
            onTriggered:
            {
            // mediaconect.state =  "YesMedia"
                 serial.setComandoIke(1014);//manda formatar
            }
         }

         Connections{
             target: serial
            onYesFormating://espera 300 milissegundos para enviar o comando de formatação
            {
              formatando.start();
                eventFormat.state =  "formatWait"
            }
         }

         Timer
         {
             id:formatando//tempo para perguntar se está formatando
              interval: 5000
            running: false
            repeat: false
            onTriggered:
            {
               serial.setComandoIke(1015);//pergunta se está formatando
            }
         }

         Timer
         {
             id:mediatime
              interval: 1000
              running: false
              repeat: false
              onTriggered:
              {
                  mediaconect.state =  "YesMedia"
              }
         }

         Image {
             id: eventFormat
             x: 376
             y: 275
             fillMode: Image.PreserveAspectFit
             source: "IconesConfig/nada.bmp"

             states: [
                 State {
                     name:  "formatZero"
                   },

                 State {
                     name: "formatWait"
                   },

                 State {
                     name: "formatOk"
                 },
                 State {
                     name: "formatNegado"
                 }
             ]

             Image {
                 id: zeero
                 source: "IconesConfig/nada.bmp"
                 visible: eventFormat.state =="formatZero"
             }

             Image {
                 id: wait
                 source: "IconesConfig/waitt.bmp"
                 visible: eventFormat.state =="formatWait"
             }

             Image {
                 id: ok
                 source: "IconesConfig/Ok.bmp"
                 visible: eventFormat.state =="formatOk"
             }

             Image {
                 id: neg
                 source: "IconesConfig/negado.bmp"
                 visible: eventFormat.state =="formatNegado"
             }

         }



         Connections{
             target: serial
            onFormatOK://espera 300 milissegundos para enviar o comando de formatação
            {
                 eventFormat.state =  "formatOk"
            }
         }

         Connections{
             target: serial
            onFormatNeg://espera 300 milissegundos para enviar o comando de formatação
            {
                 eventFormat.state = "formatNegado"
            }
         }
    }

}
