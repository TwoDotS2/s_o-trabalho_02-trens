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

    while(true){

        if(velocidade < 200){
        switch(ID){
            case 1:
 /*
            //Trem 1
           //Quinas: Sentido do movimento do trem
               //min_x: 260
               //max_x: 440

               //min_y: 110
               //max_y: 230

           if (x < 440 && y == 110){
               if(x == 420){
                   emit entrar_em_regiao(ID, 0);
               }
               else { x += 10; }
           }

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

           else if (x > 260 && y == 230){
                   if(x == 370){
                       emit entrar_em_regiao(ID, 1);
                   }
                   else if (x == 350){
                       emit sair_de_regiao(2);
                       x -= 10;
                   }
                   else x -= 10;
           }
           else if(x == 260 && y== 230){
               emit ir_para_zona_livre(1, 0);
               y -= 10;
           }
            else if(x == 260) y-=10;

           emit updateGUI(ID, x,y);    //Emite um sinal
*/
            break;
            case 2:

            //Trem 2
               //Quinas: Sentido do movimento do trem
                   //min_x: 440
                   //max_x: 610

                   //min_y: 110
                   //max_y: 230

              //1ª parte do caminho
/*
            if (x == 610 && y < 230){
                   if (y == 210){
                     emit entrar_em_regiao(ID, 4);
                   }
                   else y += 10;
               }

                //2ª parte do caminho
               else if (x >= 530  && y == 230){
                   if(x == 550){
                       emit entrar_em_regiao(ID, 3);
                   }
                   if(x == 530){
                       emit sair_de_regiao(4);
                       x-=10;
                   }
                   else x -= 10;
               }
                //3ª parte do caminho
               else if (x >= 440 && x <= 530  && y == 230){
                       if (x == 440){
                            emit sair_de_regiao(3);
                            y -= 10;
                       }
                       else if(x == 460){
                           emit entrar_em_regiao(ID, 0);
                       }
                       else x -= 10;
               }

               //4ª parte do caminho
               else if (x == 440 && y > 110){
                   y -= 10;

                } else if (x == 440 && y == 110){
                   emit ir_para_zona_livre(0, 1);
                   x += 10;

               }

               //5ª parte do caminho
               else if(x < 610)  x += 10;

               emit updateGUI(ID, x,y);    //Emite um sinal
*/
            break;

            case 3:
//                //Trem 3
//                // O Trem 3 usa as regiões: 1, 5.
//                //min_x = 170
//                //max_x = 350

//                //min_y = 230
//                //max_y = 350
/*
                 //1ª parte do caminho
                if(x == 170 && y >= 230){
                   if(y == 230){
                       x+=10;
                   }
                   else y -= 10;
                }
                //2ª parte do caminho
                else if(x < 260 && y == 230){
                    if(x == 240){
                        emit entrar_em_regiao(ID, 1);
                    }
                    else x+=10;
                }

                else if(x <= 350 && y == 230){
                    if(x == 330){
                        emit entrar_em_regiao(ID, 5);
                    }
                    else if (x == 350){
                        emit sair_de_regiao(1);
                        y += 10;
                    }
                    else x += 10;
                }

                else if(x == 350 && y <= 350){
                    if(y == 350){
                        emit ir_para_zona_livre(5, 2);
                        x -= 10;
                    } else y += 10;
                }

                else if(x > 170 && y == 350){
                    x -= 10;
                }

            emit updateGUI(ID, x,y);    //Emite um sinal
*/
            break;

            case 4:
//                    //Trem 4
//                    //Quinas: Sentido do movimento do trem
//                        //min_x: 350
//                        //max_x: 530

//                        //min_y: 230
//                        //max_y: 350


                     if ( x > 350 && y == 350){
                           if(x == 530){
                                emit ir_para_zona_livre(6, 3);
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
                                x += 10;
                            }
                            else y -= 10;
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

                            } else x+=10;

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
                //min_x: 530
                //max_x: 710

                //min_y: 230
                //max_y: 350


                if(x == 710 && y <= 350){
                    if (y == 350) x -= 10;
                    else y += 10;
                }

                //Entrar na região 6
                else if (x > 530 && y == 350){
                    if(x == 550){
                        emit entrar_em_regiao(ID, 6);
                    } else x -= 10;
                }

                 else if (x == 530 && y >= 230){
                    if (y == 250){
                        emit entrar_em_regiao(ID, 4);
                    }
                    else if (y == 230){
                        emit sair_de_regiao(6);
                        x += 10;

                    } else y -= 10;
                }

                else if(x < 710 && y == 230){
                    if(x == 610){
                        emit ir_para_zona_livre(4, 4);
                        x += 10;
                    }
                    else x += 10;
                }

            emit updateGUI(ID, x, y);    //Emite um sinal

            break;


            default:
                break;
            }
            msleep(velocidade);
        }
    }
 }




