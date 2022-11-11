#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Mudar valor da velocidade
void Trem::set_velocidade(int vel){
    //A função da velocidade varia de 0 até 200
    this->velocidade =  (vel - 200)*(-1);
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){

        case 1:     //Trem 1
            if (y == 110 && x < 440)
                x+=10;
            else if (x == 440 && y < 230)
                y+=10;
            else if (x > 260 && y == 230)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;

        case 2: //Trem 2
            if (y == 110 && x <610)
                x+=10;
            else if (x == 610 && y < 230)
                y+=10;
            else if (x > 440 && y == 230)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        case 3:     //Trem 3
            if (y == 230 && x < 350)
                x+=10;
            else if (x == 350 && y < 350)
                y+=10;
            else if (x > 170 && y == 350)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;

        case 4: //Trem 4
            if (y == 230 && x < 530)
                x+=10;
            else if (x == 530 && y < 350)
                y+=10;
            else if (x > 350 && y == 350)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;


        case 5:     //Trem 5
            if (y == 230 && x < 710)
                x+=10;
            else if (x == 710 && y < 350)
                y+=10;
            else if (x > 530 && y == 350)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;


        default:
            break;
        }

        while(velocidade == 0);

        msleep(velocidade);
    }
}




