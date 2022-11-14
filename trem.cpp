#include "trem.h"
#include <QtCore>

Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
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
                // O Trem 1 usa as regiões: 0, 2, 5, 1.

                //Região 0
                if (x == 440 && y == 110){
                    //Entrar na região 0
                    emit entrar_em_regiao(ID, 0);
                } else if (x == 440 && y == 230){
                    //Sair da região 0
                    emit sair_de_regiao(0);
                     x -= deslocamento;
                }

                //Região 2
                else if (x == 440 && y == 230){
                    //Entrar na região 2
                    emit entrar_em_regiao(ID, 2);
                } else if (x == 350 && y == 230){
                    //Sair da região 2
                    emit sair_de_regiao(2);
                    x -= deslocamento;
                }

                //Região 5
                else if (x == 370 && y == 230){
                    //Entrar na região 5
                    emit entrar_em_regiao(ID, 5);
                } else if (x == 350 && y == 230){
                    //Sair da região 5
                    emit sair_de_regiao(5);
                    x -= deslocamento;
                }

                //Região 1
                else if (x == 370 && y == 230){
                    //Entrar na região 1
                    emit entrar_em_regiao(ID, 1);
                } else if (x == 260 && y == 230){
                    //Sair da região 1
                    emit sair_de_regiao(1);
                    y -= deslocamento;
                }

                //Zona livre do trem 1
                else if (x == 260 && y > 110){ //Primeira lateral
                    y -= deslocamento;
                } else if((x >= 260 && y == 110) && (x < 440 && y == 110)){
                    x += deslocamento;
                } else if(x == 440 && y > 110){
                    y += deslocamento;
                } else if(x > 260 && y == 230){
                    x -= deslocamento;
                }


                emit updateGUI(ID, x, y);    //Emite um sinal
                break;


            case 2:
                //Trem 2
                // O Trem 2 usa as regiões: 4, 6, 3, 0.

                //Região 4
                if (x == 610 && y == 210){
                    //Entrar na região 4
                    emit entrar_em_regiao(ID, 4);
                } else if (x == 530 && y == 230){
                    //Sair da região 4
                    emit sair_de_regiao(4);
                     x -= deslocamento;
                }

                //Região 6
                else if (x == 550 && y == 230){
                    //Entrar na região 6
                    emit entrar_em_regiao(ID, 6);
                } else if (x == 530 && y == 230){
                    //Sair da região 6
                    emit sair_de_regiao(6);
                     x -= deslocamento;
                }

                //Região 3
                else if (x == 550 && y == 230){
                    //Entrar na região 3
                    emit entrar_em_regiao(ID, 3);
                } else if (x == 440 && y == 230){
                    //Sair da região 3
                    emit sair_de_regiao(3);
                    y -= deslocamento;
                }

                //Região 0
                else if (x == 460 && y == 230){
                    //Entrar na região 0
                    emit entrar_em_regiao(ID, 0);
                } else if (x == 440 && y == 110){
                    //Sair da região 0
                    emit sair_de_regiao(0);
                    x += deslocamento;
                }

                else if ((x > 440 && y == 110) && (x < 610 && y == 110)){
                    //Zona livre do trem 2
                    x += deslocamento;
                } else if(x == 610 && y > 110){
                    y += deslocamento;
                } else if(x == 440 && y > 110){
                    y -= deslocamento;
                }


                emit updateGUI(ID, x,y);    //Emite um sinal
                break;


            case 3:
                //Trem 3
                // O Trem 3 usa as regiões: 1, 5.

                if (x == 240 && y == 230){
                    //Entrar na região 1
                    emit entrar_em_regiao(ID, 1);
                }

                else if (x == 350 && y == 230){
                    //Sair da região 1
                    emit sair_de_regiao(1);
                     y += deslocamento;
                }

                else if (x == 330 && y == 230){
                    //Entrar na região 5
                    emit entrar_em_regiao(ID, 5);
                } else if (x == 350 && y == 350){
                    //Sair da região 5
                    emit sair_de_regiao(5);
                    x -= deslocamento;
                }

                else if (x > 170 && y == 110){
                    //Zona livre do trem 3
                    x -= deslocamento;
                } else
                    y -= deslocamento;


                emit updateGUI(ID, x, y);    //Emite um sinal
                break;

            case 4:
                //Trem 4
                // O Trem 4 usa as regiões: 5, 2, 0, 3, 6.

                if (x == 370 && y == 350){
                    //Entrar na região 5
                    emit entrar_em_regiao(ID, 5);
                } else if (x == 350 && y == 230){
                    //Sair da região 5
                    emit sair_de_regiao(5);
                    x += deslocamento;
                }


                else if (x == 350 && y == 250){
                    //Entrar na região 2
                    emit entrar_em_regiao(ID, 2);
                } else if (x == 440 && y == 230){
                    //Sair da região 2
                    emit sair_de_regiao(2);
                    x += deslocamento;
                }


                else if (x == 420 && y == 230){
                    //Entrar na região 0 e 3
                    emit entrar_em_regiao(ID, 0);
                    emit entrar_em_regiao(ID, 3);

                } else if (x == 440 && y == 230){
                    //Sair da região 0
                    emit sair_de_regiao(0);
                    x += deslocamento;

                } else if (x == 530 && y == 230){
                    //Sair da região 3
                    emit sair_de_regiao(3);
                    y -= deslocamento;
                }


                else if (x == 510 && y == 230){
                    //Entrar na região 6
                    emit entrar_em_regiao(ID, 6);
                } else if (x == 530 && y == 250){
                    //Sair da região 6
                    emit sair_de_regiao(6);
                     x -= deslocamento;
                }
                else
                    x -= deslocamento;

                emit updateGUI(ID, x, y);    //Emite um sinal
                break;


            case 5:
                //Trem 5
                // O Trem 5 usa as regiões: 6, 4.

                if (x == 550 && y == 350){
                    //Entrar na região 6
                    emit entrar_em_regiao(ID, 6);
                }

                else if (x == 530 && y == 230){
                    //Sair da região 6
                    emit sair_de_regiao(6);
                     x += deslocamento;
                }

                else if (x == 530 && y == 250){
                    //Entrar na região 4
                    emit entrar_em_regiao(ID, 4);
                }

                else if (x == 610 && y == 230){
                    //Sair da região 4
                    emit sair_de_regiao(4);
                    x += deslocamento;
                }

                else if (x < 710 && y == 230){
                    //Zona livre do trem 4
                    x += deslocamento;
                } else
                    y += deslocamento;



                emit updateGUI(ID, x, y);    //Emite um sinal
                break;


            default:
                break;
        }

        msleep(velocidade);
    }
}




