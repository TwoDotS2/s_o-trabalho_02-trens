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
<<<<<<< HEAD
            //Trem 1
           //Quinas: Sentido do movimento do trem
               //min_x: 260
               //max_x: 440

               //min_y: 110
               //max_y: 230

           //Quina 1
               //x == 260 && y == 110
           //Quina 2
               //x == 440 && y == 110
           //Quina 3
               //x == 260 && y == 230
           //Quina 4
               //x == 440 && y == 230

           if (x < 440 && y == 110){
               if(x == 420){
                   emit entrar_em_regiao(ID, 0);
               }
               else { x += 10; }
           }
=======
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

                } else if (x == 380 && y == 230){
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
>>>>>>> 3fe2fdef259e4fcdaa04fa2a7adfbd83bacb606c

           else if (x == 440 && y <= 230){
               if(y == 210){
                   emit entrar_em_regiao(ID, 2);
               }
               if(y == 230){
                   emit sair_de_regiao(0);
                   x-=10;
               }
               else y += 10;
           }

           else if (x >= 260 && y == 230){
                   if(x == 370){
                       emit entrar_em_regiao(ID, 1);
                   }
                   else if(x == 350){
                       emit sair_de_regiao(2);
                       x-=10;
                   }
                   else if(x == 260){
                       emit ir_para_zona_livre(0, 1);
                       y -= 10;
                   }
                   else x-=10;
           }
               else y-=10;

           emit updateGUI(ID, x,y);    //Emite um sinal


//                //Trem 1
//                // O Trem 1 usa as regiões: 0, 2, 1.
//            printf("ANALISANDO TREM 1 EM SUAS POSIÇÕES: %d , %d \n", x , y);
//                 /* ---- REGIÃO 0 ------*/
//                if (x == 420 && y == 110){
//                    emit entrar_em_regiao(ID, 0);
//                } else if (x == 440 && y == 120){
//                    emit sair_de_regiao(0, 1);
//                     y += deslocamento;
//                     printf("SAINDO DA REGIÃO 0");
//                }

//                /* ---- REGIÃO 2 ------*/
//                else if (x == 440 && y == 210){
//                    emit entrar_em_regiao(ID, 2);

<<<<<<< HEAD
//                } else if (x == 380 && y == 230){
//                    emit sair_de_regiao(2, 1);
//                    x -= deslocamento;
//                    printf("SAINDO DA REGIÃO 2");
//                } else if(x == 440 && y == 220){
//                    y += deslocamento;
//                } else if(x == 440 && y == 230){
//                    x -= deslocamento;
//                }


//                /* ---- REGIÃO 1 ------*/
//                else if (x == 370 && y == 230){
//                    emit entrar_em_regiao(ID, 1);
=======
            case 2:
            printf("ANALISANDO TREM 2 EM SUAS POSIÇÕES: %d , %d \n", x , y);
                //Trem 2
                // O Trem 2 usa as regiões: 4, 3, 0.

                /* ---- REGIÃO 4 ------*/
                if (x == 610 && y == 210){
                    printf("TREM 2 ENTRANDO DA REGIAO 4 \n");
                    emit entrar_em_regiao(ID, 4);
                } else if (x == 610 && y == 230){
                    printf("TREM 2  VIRAA \n");
                     x -= deslocamento;
                }

              /* ---- REGIÃO 3 ------*/
                else if (x == 550 && y == 230){
                    printf("TREM 2 ENTRANDO DA REGIAO 3 \n");
                    emit entrar_em_regiao(ID, 3);
                } else if (x == 470 && y == 230){
                    printf("TREM 2 SAINDO DA REGIAO 3 \n");
                    emit sair_de_regiao(3, 2);
                    x -= deslocamento;
                }

                /* ---- REGIÃO 0 ------*/
                else if (x == 460 && y == 230){
                    printf("TREM 2 ENTRANDO NA REGIÃO 0 \n");
                    emit entrar_em_regiao(ID, 0);
                } else if (x == 440 && y == 110){
                    emit sair_de_regiao(0, 2);
                    x += deslocamento;
                }

                /* ---- REGIÃO 6 ------*/
                else if(x == 550 && y == 230){
                    printf("TREM 2 ENTRANDO DA REGIAO 6 \n");
                    emit entrar_em_regiao(ID, 6);
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
                    printf("TREM %d ENTRANDO DA REGIAO 5 \n", ID);
                    emit entrar_em_regiao(ID, 5);
                } else if (x == 350 && y == 250){
                   printf("TREM %d SAINDO DA REGIAO 5 \n", ID);
                    emit sair_de_regiao(5, 3);
                    y += deslocamento;
                } else if(x == 350 && y == 230){
                    y += deslocamento;
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
>>>>>>> 3fe2fdef259e4fcdaa04fa2a7adfbd83bacb606c

//                } else if (x == 260 && y == 230){
//                    emit sair_de_regiao(1, 1);
//                    printf("SAINDO DA REGIÃO 1");
//                    y -= deslocamento;
//                }


//                /* ---- ZONA LIVRE ------*/
//                else if (x == 260 && y > 110){
//                    y -= deslocamento;
//                } else if(x < 420 && y == 110){
//                    x += deslocamento;
//                } else if(x < 440 && y == 230){
//                    x -= deslocamento;
//                } else if(x < 440 && y == 110){
//                       x += deslocamento;
//                } else if(x == 440 && y < 210){
//                    y += deslocamento;
//                }

//                emit updateGUI(ID, x, y);    //Emite um sinal

               break;
            case 2:
//            printf("ANALISANDO TREM 2 EM SUAS POSIÇÕES: %d , %d \n", x , y);
//                //Trem 2
//                // O Trem 2 usa as regiões: 4, 3, 0.

//                /* ---- REGIÃO 4 ------*/
//                if (x == 610 && y == 210){
//                    printf("TREM 2 ENTRANDO DA REGIAO 4 \n");
//                    emit entrar_em_regiao(ID, 4);
//                } else if (x == 610 && y == 230){
//                    printf("TREM 2  VIRAA \n");
//                     x -= deslocamento;
//                }

//              /* ---- REGIÃO 3 ------*/
//                else if (x == 550 && y == 230){
//                    printf("TREM 2 ENTRANDO DA REGIAO 3 \n");
//                    emit entrar_em_regiao(ID, 3);
//                } else if (x == 470 && y == 230){
//                    printf("TREM 2 SAINDO DA REGIAO 3 \n");
//                    emit sair_de_regiao(3, 2);
//                    x -= deslocamento;
//                }

//                /* ---- REGIÃO 0 ------*/
//                else if (x == 460 && y == 230){
//                    printf("TREM 2 ENTRANDO NA REGIÃO 0 \n");
//                    emit entrar_em_regiao(ID, 0);
//                } else if (x == 440 && y == 110){
//                    emit sair_de_regiao(0, 2);
//                    x += deslocamento;
//                }

//                /* ---- REGIÃO 6 ------*/
//                else if(x == 550 && y == 230){
//                    printf("TREM 2 ENTRANDO DA REGIAO 6 \n");
//                    emit entrar_em_regiao(ID, 6);
//                }

//                /* ---- ZONA LIVRE ------*/
//                else if (x < 610 && y == 110){ // caminha no superior horizontal
//                    x += deslocamento;
//                } else if(x == 440 && y > 110){ // caminha na lateral esquerda pra cima
//                    y -= deslocamento;
//                } else if(x < 610 && y == 230){ //caminha no inferior horizontal
//                    x -= deslocamento;
//                } else if(x == 610 && y == 220){
//                    printf("DESLOQUE SO MAIS UM");
//                    y += deslocamento;
//                } else if(x == 610 && y >= 110){ //caminha na lateral direita pra baixo
//                    y += deslocamento;}
////                } else if(x == 610 && y == 230){}


//                emit updateGUI(ID, x,y);    //Emite um sinal


            case 3:

//            printf("ANALISANDO TREM %d EM SUAS POSIÇÕES: %d , %d \n", ID, x , y);
//                //Trem 3
//                // O Trem 3 usa as regiões: 1, 5.

//                /* ---- REGIÃO 1 ------*/
//                if (x == 240 && y == 230){
//                    printf("TREM %d ENTRANDO DA REGIAO 1 \n", ID);
//                    emit entrar_em_regiao(ID, 1);
//                } else if(x > 240 && x < 280 && y == 230){
//                    x += deslocamento;
//                }
//                else if (x == 280 && y == 230){
//                    emit sair_de_regiao(1, 3);
//                     x += deslocamento;
//                }

//                /* ---- REGIÃO 5 ------*/
//                else if (x == 330 && y == 230){
//                    printf("TREM %d ENTRANDO DA REGIAO 5 \n", ID);
//                    emit entrar_em_regiao(ID, 5);
//                } else if (x == 350 && y == 250){
//                   printf("TREM %d SAINDO DA REGIAO 5 \n", ID);
//                    emit sair_de_regiao(5, 3);
//                    y += deslocamento;
//                } else if(x == 350 && y == 230){
//                    y += deslocamento;
//                }

//                /* ---- ZONA LIVRE ------*/
//                else if (x > 170 && y == 350){
//                    x -= deslocamento;
//                } else if (x == 170 && y > 230)
//                    y -= deslocamento;
//                else if (x < 240 && y == 230){
//                    x += deslocamento;
//               } else if(x > 280 && y == 230){
//                    x += deslocamento;
//               } else if(x == 350 && y < 350){
//                    y += deslocamento;
//               }


//                emit updateGUI(ID, x, y);    //Emite um sinal

            break;

            case 4:
                    //Trem 4
                    //Quinas: Sentido do movimento do trem
                        //min_x: 350
                        //max_x: 530

                        //min_y: 230
                        //max_y: 350

                    //Quina 1
                        //x == 350 && y == 230
                    //Quina 2
                        //x == 530 && y == 230
                    //Quina 3
                        //x == 350 && y == 350
                    //Quina 4
                        //x == 530 && y == 350

                     if ( x > 350 && y == 350){
                            if(x == 530){
                                emit ir_para_zona_livre(6, 4);
                                x -= 10; //retrocede
                            }

                            else if(x == 370){
                                emit entrar_em_regiao(ID, 5);
                            }
                            else x -= 10;
                        }

                        else if (x == 350 && y >= 230){
                            if(y == 250){
                                 emit entrar_em_regiao(ID, 2);
                            }
                            else if(y == 230){
                                emit sair_de_regiao(5);
                                x+=10;
                            }
                            else y-=10;
                        }

                        else if (x <= 530 && y == 230){
                            if(x == 440){
                                emit sair_de_regiao(2);
                                x += 10;
                            }
                            else if(x == 420){
                                   emit entrar_em_regiao(ID, 3);
                           }

                            else if(x == 510){
                                    emit entrar_em_regiao(ID, 6);
                            }

                            else if(x == 530){
                                 emit sair_de_regiao(3);
                                y += 10;

                            }

                            else x+=10;

                        }
                        else
                            if(y == 350){
                                emit sair_de_regiao(6);
                                y+=10;
                            }
                           else y+=10;

            emit updateGUI(ID, x, y);


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
        if (velocidade == 200) msleep(1);
        else msleep(velocidade);
    }
}




