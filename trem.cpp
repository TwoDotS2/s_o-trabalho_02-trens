#include "trem.h"
#include "mainwindow.h"
#include <QtCore>
#include <iostream>

Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
    printf(" ---> POSIÇÃO TREM %d é %d , %d \n", this->ID, this->x, this->y);
}

void Trem::set_velocidade(int vel){
    this->velocidade =  (vel - 200)*(-1);
}

void Trem::set_x(int x){
    this->x = x;
}

void Trem::set_y(int y){
    this->y = y;
}

void Trem::run(){

    int deslocamento;

    while(true){
        //Se a velocidade chegar em zero, o trem não deve se mover
        if (velocidade == 200) deslocamento = 0;
        else deslocamento = 10;

        switch(ID){
            case 1:
                //Trem 1
                // O Trem 1 usa as regiões: 0, 2, 1.
            printf("ANALISANDO TREM 1 EM SUAS POSIÇÕES: %d , %d \n", x , y);
                 /* ---- REGIÃO 0 ------*/
                if (x == 420 && y == 110){
                    emit entrar_em_regiao(ID, 0);
                } else if (x == 440 && y == 120){
                    emit sair_de_regiao(0, 1);
                     y += deslocamento;
                     printf("SAINDO DA REGIÃO 0");
                }

                /* ---- REGIÃO 2 ------*/
                else if (x == 440 && y == 210){
                    emit entrar_em_regiao(ID, 2);

                } else if (x == 350 && y == 230){
                    emit sair_de_regiao(2, 1);
                    x -= deslocamento;
                    printf("SAINDO DA REGIÃO 2");
                } else if(x == 440 && y == 220){
                    y += deslocamento;
                } else if(x == 440 && y == 230){
                    x -= deslocamento;
                }


                /* ---- REGIÃO 1 ------*/
                else if (x == 370 && y == 230){
                    emit entrar_em_regiao(ID, 1);

                } else if (x == 260 && y == 230){
                    emit sair_de_regiao(1, 1);
                    printf("SAINDO DA REGIÃO 1");
                    y -= deslocamento;
                }

                /* ---- ZONA LIVRE ------*/
                else if (x == 260 && y > 110){
                    y -= deslocamento;
                } else if(x < 420 && y == 110){
                    x += deslocamento;
                } else if(x < 440 && y == 230){
                    x -= deslocamento;
                } else if(x < 440 && y == 110){
                       x += deslocamento;
                } else if(x == 440 && y < 210){
                    y += deslocamento;
                }

                emit updateGUI(ID, x, y);    //Emite um sinal
                break;


            case 2:
            printf("ANALISANDO TREM 2 EM SUAS POSIÇÕES: %d , %d \n", x , y);
                //Trem 2
                // O Trem 2 usa as regiões: 4, 3, 0.

                /* ---- REGIÃO 4 ------*/
                if (x == 610 && y == 210){
                    printf("TREM 2 ENTRANDO DA REGIAO 4 \n");
                    emit entrar_em_regiao(ID, 4);
                } else if (x == 610 && y == 230){
                    emit sair_de_regiao(4, 2);
                    printf("TREM 2 SAINDO DA REGIAO 4 VIRAA \n");
                     x -= deslocamento;
                }

              /* ---- REGIÃO 3 ------*/
                else if (x == 550 && y == 230){
                    emit entrar_em_regiao(ID, 3);
                } else if (x == 440 && y == 230){
                    emit sair_de_regiao(3, 2);
                    y -= deslocamento;
                }

                /* ---- REGIÃO 0 ------*/
                else if (x == 460 && y == 230){
                    //Entrar na região 0
                    emit entrar_em_regiao(ID, 0);
                } else if (x == 440 && y == 110){
                    //Sair da região 0
                    emit sair_de_regiao(0, 2);
                    x += deslocamento;
                }

                /* ---- ZONA LIVRE ------*/
                else if (x < 610 && y == 110){ // caminha no superior horizontal
                    x += deslocamento;
                } else if(x == 440 && y > 110){ // caminha na lateral esquerda pra cima
                    y -= deslocamento;
                } else if(x < 610 && y == 230){ //caminha no inferior horizontal
                    x -= deslocamento;
                } else if(x == 610 && y == 220){
                    printf("DESLOQUE SO MAIS UM");
                    y += deslocamento;
                } else if(x == 610 && y >= 110){ //caminha na lateral direita pra baixo
                    y += deslocamento;}
//                } else if(x == 610 && y == 230){}


                emit updateGUI(ID, x,y);    //Emite um sinal
                break;


            case 3:
            printf("ANALISANDO TREM %d EM SUAS POSIÇÕES: %d , %d \n", ID, x , y);
                //Trem 3
                // O Trem 3 usa as regiões: 1, 5.

                /* ---- REGIÃO 1 ------*/
                if (x == 240 && y == 230){
                    printf("TREM %d ENTRANDO DA REGIAO 1 \n", ID);
                    emit entrar_em_regiao(ID, 1);
                } else if(x > 240 && x < 280 && y == 230){
                    x += deslocamento;
                }
                else if (x == 280 && y == 230){
                    emit sair_de_regiao(1, 3);
                     x += deslocamento;
                }

                /* ---- REGIÃO 5 ------*/
                else if (x == 330 && y == 230){
                    //Entrar na região 5
                    emit entrar_em_regiao(ID, 5);
                } else if (x == 350 && y == 350){
                    //Sair da região 5
                    emit sair_de_regiao(5, 3);
                    x -= deslocamento;
                }

                /* ---- ZONA LIVRE ------*/
                else if (x > 170 && y == 350){
                    x -= deslocamento;
                } else if (x == 170 && y > 230)
                    y -= deslocamento;
                else if (x < 240 && y == 230){
                    x += deslocamento;
               } else if(x > 280 && y == 230){
                    x += deslocamento;
               } else if(x == 350 && y < 350){
                    y += deslocamento;
               }


                emit updateGUI(ID, x, y);    //Emite um sinal
                break;

            case 4:
//                //Trem 4
//                // O Trem 4 usa as regiões: 5, 2, 3, 6.

//                //Região 5
//                if (x == 370 && y == 350){
//                    //Entrar na região 5
//                    emit entrar_em_regiao(ID, 5);

//                } else if (x > 350 && y == 350){
//                    x -= deslocamento;

//                } else if (x == 350 && y > 350){
//                    y -= deslocamento;

//                } else if (x == 350 && y == 230){
//                    //Sair da região 5
//                    emit sair_de_regiao(5);
//                    x += deslocamento;
//                }

//                //Região 2
//                else if (x == 350 && y == 250){
//                    //Entrar na região 2
//                    emit entrar_em_regiao(ID, 2);
//                } else if (x == 440 && y == 230){
//                    //Sair da região 2
//                    emit sair_de_regiao(2);
//                    x += deslocamento;
//                }


//                //Região 3
//                else if (x == 420 && y == 230){
//                    //Entrar na região 3
//                    emit entrar_em_regiao(ID, 3);

//                } else if (x == 440 && y == 230){
//                    //Sair da região 0
//                    emit sair_de_regiao(0);
//                    x += deslocamento;

//                } else if (x == 530 && y == 230){
//                    //Sair da região 3
//                    emit sair_de_regiao(3);
//                    y -= deslocamento;
//                }


//                //Região 6
//                else if (x == 510 && y == 230){
//                    //Entrar na região 6
//                    emit entrar_em_regiao(ID, 6);
//                } else if (x == 530 && y == 250){
//                    //Sair da região 6
//                    emit sair_de_regiao(6);
//                     x -= deslocamento;
//                }
//                else
//                    x -= deslocamento;

                emit updateGUI(ID, x, y);    //Emite um sinal
                break;


            case 5:
                //Trem 5
                // O Trem 5 usa as regiões: 6, 4.

                //Região 6
//                if (x == 550 && y == 350){
//                    //Entrar na região 6
//                    emit entrar_em_regiao(ID, 6);
//                }

//                else if (x == 530 && y == 230){
//                    //Sair da região 6
//                    emit sair_de_regiao(6);
//                     x += deslocamento;
//                }

//                //Região 4
//                else if (x == 530 && y == 250){
//                    //Entrar na região 4
//                    emit entrar_em_regiao(ID, 4);
//                }
//                else if (x == 610 && y == 230){
//                    //Sair da região 4
//                    emit sair_de_regiao(4);
//                    x += deslocamento;
//                }

//                //Zona Livre
//                else if (x < 710 && y == 230){
//                    //Zona livre do trem 4
//                    x += deslocamento;
//                } else if (x == 710 && y < 350){
//                    y += deslocamento;
//                } else if (x > 550 && y == 350){
//                    x-= deslocamento;
//                }

                emit updateGUI(ID, x, y);    //Emite um sinal
                break;


            default:
                break;
        }

        msleep(velocidade);
    }
}




