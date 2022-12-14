#include "mainwindow.h"
#include "ui_mainwindow.h"

#define T1 0
#define T2 1
#define T3 2
#define T4 3
#define T5 4

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1, 330, 110);
    trem2 = new Trem(2, 610, 160);
    trem3 = new Trem(3, 170, 300);
    trem4 = new Trem(4, 440, 350);
    trem5 = new Trem(5, 710, 290);

    //Inicializa o semaforo das regiões
    for(int i=0; i<7; i++){
        regiao[i].release(1);
    }


    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */

    connect(trem1,SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));


    //Sincornização de entrar_em_regiao em cada thread
    connect(trem1,SIGNAL(entrar_em_regiao(int,int)), SLOT(entrar_em_regiao(int,int)));
    connect(trem2,SIGNAL(entrar_em_regiao(int,int)), SLOT(entrar_em_regiao(int,int)));
    connect(trem3,SIGNAL(entrar_em_regiao(int,int)), SLOT(entrar_em_regiao(int,int)));
    connect(trem4,SIGNAL(entrar_em_regiao(int,int)), SLOT(entrar_em_regiao(int,int)));
    connect(trem5,SIGNAL(entrar_em_regiao(int,int)), SLOT(entrar_em_regiao(int,int)));


    //Sincornização de sair_de_regiao em cada thread
    connect(trem1,SIGNAL(sair_de_regiao(int)), SLOT(sair_de_regiao(int)));
    connect(trem2,SIGNAL(sair_de_regiao(int)), SLOT(sair_de_regiao(int)));
    connect(trem3,SIGNAL(sair_de_regiao(int)), SLOT(sair_de_regiao(int)));
    connect(trem4,SIGNAL(sair_de_regiao(int)), SLOT(sair_de_regiao(int)));
    connect(trem5,SIGNAL(sair_de_regiao(int)), SLOT(sair_de_regiao(int)));

    //Sincornização de  em cada thread
    connect(trem1,SIGNAL(ir_para_zona_livre(int, int)), SLOT(ir_para_zona_livre(int, int)));
    connect(trem2,SIGNAL(ir_para_zona_livre(int, int)), SLOT(ir_para_zona_livre(int, int)));
    connect(trem3,SIGNAL(ir_para_zona_livre(int, int)), SLOT(ir_para_zona_livre(int, int)));
    connect(trem4,SIGNAL(ir_para_zona_livre(int, int)), SLOT(ir_para_zona_livre(int, int)));
    connect(trem5,SIGNAL(ir_para_zona_livre(int, int)), SLOT(ir_para_zona_livre(int, int)));

    //Inicialização das threads
    trem1->start();
    //printf("INICIANDO \n");
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int ID, int x, int y){
    switch(ID){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x, y, 21, 17);
        break;

    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x, y, 21, 17);
        break;

    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x, y, 21, 17);
        break;

    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x, y, 21, 17);
        break;

    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x, y, 21, 17);
        break;

    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Entrar em região crítica

void MainWindow::entrar_em_regiao(int ID, int _regiao){
    printf("\n ENTRAR_EM_REGIAO : SWITCH -> %d \n", ID);
    printf("STATUS DAS REGIÕES: \n");
    printf("Trem 1: %d | Trem 2: %d | Trem 3: %d | Trem 4: %d | Trem 5: %d\n",
            trem_por_regiao[T1], trem_por_regiao[T2], trem_por_regiao[T3], trem_por_regiao[T4], trem_por_regiao[T5]);

    switch (ID) {

    case 1:
        //Trem 1
        // O Trem 1 usa as regiões: 0, 2, 1.

       //Acessar região 0
       if(_regiao == 0){
            printf("ACESSANDO REGIÃO 0 \n");
            if(trem_por_regiao[T1] == ZONA_LIVRE){

               //Trava o "mutex"
               mutex.lock();

               if( trem_por_regiao[T2] != 3 && trem_por_regiao[T4] != 2 && trem_por_regiao[T4] != 5 ){
                    printf("PERMITIDO ENTRAR: T1 ESTA EM ZONA 0 \n");
                    trem_por_regiao[T1] = 0;
                } else {
                   printf("TREM 1 ESTÁ DORMINDO");
               }

               //Libera o "mutex"
               mutex.unlock();
           }

           //Se tem acesso a região, se desloca
           if(trem_por_regiao[T1] == 0){
               regiao[0].acquire(1);
               trem1->set_x(ui->label_trem1->x()+10);
           } else {
               trem1->set_x(ui->label_trem1->x()+0);
           }
       }

       //Acessar região 2
        if(_regiao == 2){
        printf("TREM 1 ENTRANDO NA REGIAO 2 \n");

            if(trem_por_regiao[T1] == 0){
                //Trava o "mutex"
                mutex.lock();

                if(trem_por_regiao[T3] != 1 && trem_por_regiao[T4] != 5){
                    printf("TREM 1 REGISTRADO NA REGIAO 2 \n");
                    trem_por_regiao[T1] = 2;
                }
                //Libera o "mutex"
                mutex.unlock();

            }

            if(trem_por_regiao[T1] == 2){
                regiao[2].acquire(1);
                trem1->set_y(ui->label_trem1->y()+10);
            }
        }

        //Acessar região 1
        if(_regiao == 1){
            printf("ENTRANDO NA REGIAO 1, state: %d\n", trem_por_regiao[T1]);

            if( trem_por_regiao[T1] == 2 ){
                //Trava o "mutex"
                mutex.lock();

                 trem_por_regiao[T1] = 1;

                //Libera o "mutex"
                mutex.unlock();

            }

            printf("TREM 1: %d\n", trem_por_regiao[T1]);

            if(trem_por_regiao[T1] == 1){
                regiao[1].acquire(1);
                trem1->set_x(ui->label_trem1->x()-10);
            }
        }

        break;

    case 2:
        //Trem 2
                // O Trem 2 usa as regiões: 4, 3, 0.

               //Acessar região 4
               if(_regiao == 4){
                    printf("TREM 2: ENTRANDO NA REGIAO 4, state: %d\n", trem_por_regiao[T2]);
                   if(trem_por_regiao[T2] == ZONA_LIVRE){

                       //Trava o "mutex"
                       mutex.lock();

                       if( trem_por_regiao[T4] != 3 &&
                           trem_por_regiao[T4] != 2 &&
                           trem_por_regiao[T5] != 6 ){
                             printf("TREM 2 REGISTRADO NA REGIAO 4 \n");
                           trem_por_regiao[T2] = 4;
                        }
                       //Libera o "mutex"
                       mutex.unlock();
                   }

                  //Se tem acesso a região, se desloca
                   if(trem_por_regiao[T2] == 4){
                       printf("\n TREM 2 TEM ACESSO A REGIÃO 4 \n");
                       regiao[4].acquire(1);
                       trem2->set_y(ui->label_trem2->y()+10);
                   }
               }

               //Acessar região 3
                if(_regiao == 3){
                     printf("TREM 2: ENTRANDO NA REGIAO 3, state: %d\n", trem_por_regiao[T2]);
                    if(trem_por_regiao[T2] == 4){
                        //Trava o "mutex"
                        mutex.lock();

                        if( trem_por_regiao[T1] != 0 &&
                            trem_por_regiao[T4] != 2 ){
                            printf("TREM 2 REGISTRADO NA REGIAO 3 \n");
                            trem_por_regiao[T2] = 3;
                        }

                        //Libera o "mutex"
                        mutex.unlock();

                    }

                    if(trem_por_regiao[T2] == 3){
                        regiao[3].acquire(1);
                         trem2->set_x(ui->label_trem2->x()-10);
                    }
                }

                //Acessar região 0
                if(_regiao == 0){
                    if(trem_por_regiao[T1] != 0 && trem_por_regiao[T2] == 3 ){
                        //Trava o "mutex"
                        mutex.lock();

//                          if(!(trem_por_regiao[T1] == 0 && trem_por_regiao[T4] == 0))
                            trem_por_regiao[T2] = 0;

                        //Libera o "mutex"
                        mutex.unlock();

                    }

                    if(trem_por_regiao[T2] == 0){
                        regiao[0].acquire(1);
                        trem2->set_x(ui->label_trem2->x()-10);
                    }
                }

        break;

    case 3:
        //Trem 3
                // O Trem 3 usa as regiões: 1, 5.

                //Acessar região 1
                if(_regiao == 1){
                    printf("DENTRO DA REGIÃO 1 DE TREM 3\n");

                    if(trem_por_regiao[T3] == ZONA_LIVRE){
                        //Trava o "mutex"
                        mutex.lock();

                        if(trem_por_regiao[T1] != 2 && trem_por_regiao[T4] != 5){
                            printf("AGORA TREM 3 TA REGISTRADO NA REGIAO 1\n");
                            trem_por_regiao[T3] = 1;
                        }
                        //Libera o "mutex"
                        mutex.unlock();

                    }

                    if(trem_por_regiao[T3] == 1){
                        regiao[1].acquire(1);
                        trem3->set_x(ui->label_trem3->x()+10);
                    }
                }

                //Acessar região 5
               if(_regiao == 5){
                   //printf("ENTRANDO NA REGIAO 5, state: ", trem_por_regiao[T3]);

                       //Trava o "mutex"
                       mutex.lock();

                       trem_por_regiao[T3] = 5;

                       //Libera o "mutex"
                       mutex.unlock();


                   //Se tem acesso a região, se desloca
                   if(trem_por_regiao[T3] == 5){
                       regiao[5].acquire(1);
                       trem3->set_x(ui->label_trem3->x()+10);
                   }
               }

        break;
    case 4:

        //Trem 4
        // O Trem 4 usa as regiões: 5, 2, 3, 6.
       printf("\nTREM 4: \n");
         //Acessar região 5
        if(_regiao == 5){
           printf("ENTRANDO NA REGIAO 5, state: %d\n", trem_por_regiao[T4]);

            if(trem_por_regiao[T4] == ZONA_LIVRE){

                //Trava o "mutex"
                mutex.lock();

                if( trem_por_regiao[T1] != 2 && trem_por_regiao[T3] != 1 && trem_por_regiao[T1] != 0){
                    printf("AGORA TREM 4 TA REGISTRADO NA REGIAO 5\n");
                    trem_por_regiao[T4] = 5;
                }
                //Libera o "mutex"
                mutex.unlock();
            }

            //Se tem acesso a região, se desloca
            if(trem_por_regiao[T4] == 5){
                regiao[5].acquire(1);
                trem4->set_x(ui->label_trem4->x()-10);
            }
        }

        //Acessar região 2
        if(_regiao == 2){
            printf("ENTRANDO NA REGIAO 2, state: %d\n", trem_por_regiao[T4]);

            if(trem_por_regiao[T4] == 5){

                //Trava o "mutex"
                mutex.lock();

                if( trem_por_regiao[T2] != 3 &&
                    trem_por_regiao[T2] != 4 &&
                    trem_por_regiao[T1] != 0){

                    printf("AGORA TREM 4 TA REGISTRADO NA REGIAO 2\n");
                    trem_por_regiao[T4] = 2;
                }

                //Libera o "mutex"
                mutex.unlock();
            }

            if(trem_por_regiao[T4] == 2){
                regiao[2].acquire(1);
                trem4->set_y(ui->label_trem4->y()-10);
            }

        }

        //Acessar região 3
        if(_regiao == 3){
            printf("ENTRANDO NA REGIAO 3, state: %d\n", trem_por_regiao[T4]);

//            if(trem_por_regiao[T4] == 2){

                //Trava o "mutex"
                mutex.lock();

                if( trem_por_regiao[T5] != 6 && trem_por_regiao[T2] != 4 )
                trem_por_regiao[T4] = 3;

                //Libera o "mutex"
                mutex.unlock();
//            }

            if(trem_por_regiao[T4] == 3){
                regiao[3].acquire(1);
                trem4->set_x(ui->label_trem4->x()+10);
            }
        }

        //Acessar região 6
        if(_regiao == 6){
            printf("ENTRANDO NA REGIAO 6, state: %d", trem_por_regiao[T4]);

//            if(trem_por_regiao[T4] == 3){

                //Trava o "mutex"
                mutex.lock();

                trem_por_regiao[T4] = 6;

                //Libera o "mutex"
                mutex.unlock();
//            }

            if(trem_por_regiao[T4] == 6){
                regiao[6].acquire(1);
                trem4->set_x(ui->label_trem4->x()+10);
            }

        }

        break;

    case 5:
                //Trem 5
                // O Trem 5 usa as regiões: 6, 4.

                if(_regiao == 6){
                    //printf("ENTRANDO NA REGIAO 6, state: ", trem_por_regiao[T5]);

                    if(trem_por_regiao[T5] == ZONA_LIVRE){

                        //Trava o "mutex"
                        mutex.lock();

                        if ( trem_por_regiao[T4] != 3 && trem_por_regiao[T2] != 4)
                            trem_por_regiao[T5] = 6;

                        //Libera o "mutex"
                        mutex.unlock();
                    }

                    if(trem_por_regiao[T5] == 6){
                        regiao[6].acquire(1);
                        trem5->set_x(ui->label_trem5->x()-10);
                    }

                }

                if(_regiao == 4){
                  //printf("ENTRANDO NA REGIAO 4, state: ", trem_por_regiao[T5]);

                    //if(trem_por_regiao[T5] == 6){

                        //Trava o "mutex"
                        mutex.lock();

                         trem_por_regiao[T5] = 4;

                        //Libera o "mutex"
                        mutex.unlock();
                    //}

                    //Se tem acesso a região, se desloca
                    if(trem_por_regiao[T5] == 4){
                        regiao[4].acquire(1);
                        trem5->set_y(ui->label_trem5->y()-10);
                    }
                }

        break;

    default:
        break;

   }
}

//Sair da região crítica

void MainWindow::sair_de_regiao(int num_regiao){
    //flag
    // ou o número do trem ou um indicativo de entrada em zona livre
    printf("SAINDO DE REGIAO %d\n", num_regiao);
    printf("Trem 1: %d | Trem 2: %d | Trem 3: %d | Trem 4: %d | Trem 5: %d\n", trem_por_regiao[T1], trem_por_regiao[T2], trem_por_regiao[T3], trem_por_regiao[T4], trem_por_regiao[T5]);
    regiao[num_regiao].release(1);

    for (int i = 0; i < 7; ++i) {
        printf("%d: %d\n", i,  regiao[i].available());
    }

    return;
}

void MainWindow::ir_para_zona_livre(int num_regiao, int trem){
    printf("TREM %d, INDO PARA  [ ZONA_LIVRE ]\n", trem+1);
    trem_por_regiao[trem] = ZONA_LIVRE;
    sair_de_regiao(num_regiao);

    return;
}

//Sliders

void MainWindow::on_slider_vel_trem1_valueChanged(int value)
{
    if(value == 200)  trem1->set_velocidade(199);
    else trem1->set_velocidade(value);
    ui->label_vel_trem1->setText(QString::number(value) + " U.M.");
}

void MainWindow::on_slider_vel_trem2_valueChanged(int value)
{
    if(value == 200)  trem2->set_velocidade(199);
    else trem2->set_velocidade(value);
    ui->label_vel_trem2->setText(QString::number(value) + " U.M.");
}

void MainWindow::on_slider_vel_trem3_valueChanged(int value)
{
    if(value == 200)  trem3->set_velocidade(199);
    else trem3->set_velocidade(value);
    ui->label_vel_trem3->setText(QString::number(value) + " U.M.");
}

void MainWindow::on_slider_vel_trem4_valueChanged(int value)
{
    if (value == 200)  trem4->set_velocidade(199);
    else trem4->set_velocidade(value);
    ui->label_vel_trem4->setText(QString::number(value)+ " U.M.");
}

void MainWindow::on_slider_vel_trem5_valueChanged(int value)
{
    if (value == 200)  trem5->set_velocidade(199);
    else trem5->set_velocidade(value);
    ui->label_vel_trem5->setText(QString::number(value)+ " U.M.");
}
