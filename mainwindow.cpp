#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1, 350, 110);
    trem2 = new Trem(2, 610, 160);
    trem3 = new Trem(3, 170, 290);
    trem4 = new Trem(4, 440, 350);
    trem5 = new Trem(5, 710, 290);

    //Inicializa o semaforo das regiões
    for(int i=0; i<7; i++){
        regiao[i].release(1);
    }
    //inicializa o mutex
    mutex.release(1);

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


    //Inicialização das threads
    trem1->start();
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

void MainWindow::entrar_em_regiao(int ID, int num_regiao){

    switch (ID) {

    case 1:
        if(num_regiao == 0){
            while(trem_por_regiao[ID-1] == ZONA_LIVRE){
                //Trava o "mutex"
                mutex.acquire(1);

                //Caso os trens 3, 4 não ocuparem as regiões 2 e 5, respecivamente
                // o trem 1 pode acesser a região 0
                if(trem_por_regiao[3] != 2 && trem_por_regiao[4] != 5)
                    trem_por_regiao[0] = 0;

                //Libera o "mutex"
                mutex.release(1);
            }

            if(trem_por_regiao[0] == 0){
                (regiao[0]).acquire(1); //trava a regiao 0
                trem1->set_y(ui->label_trem1->y()+10);
            }

      }

//    else if(regiao == 2){
//            if(estado_malhas_criticas[2] == ACESSIVEL){
//                estado_malhas_criticas[2] = INACESSIVEL;
//                trem1->set_x(ui->label_trem1->x()-10);
//            }
//        } else if(regiao == 5){
//            if(estado_malhas_criticas[5] == ACESSIVEL){
//                estado_malhas_criticas[5] = INACESSIVEL;
//                trem1->set_x(ui->label_trem1->x()-10);
//            }
//        } else if(regiao == 1){
//            if(estado_malhas_criticas[1] == ACESSIVEL){
//                estado_malhas_criticas[1] = INACESSIVEL;
//                trem1->set_y(ui->label_trem1->y()-10);
//            }
//        }
        break;

    case 2:
//        if(regiao == 0){
//            if(estado_malhas_criticas[0] == ACESSIVEL){
//                estado_malhas_criticas[0] = INACESSIVEL;
//                trem1->set_y(ui->label_trem1->y()-10);
//            }
//        } else if(regiao == 3){
//            if(estado_malhas_criticas[3] == ACESSIVEL){
//                estado_malhas_criticas[3] = INACESSIVEL;
//                trem1->set_x(ui->label_trem1->x()+10);
//            }
//        } else if(regiao == 4){
//            if(estado_malhas_criticas[4] == ACESSIVEL){
//                estado_malhas_criticas[4] = INACESSIVEL;
//                trem1->set_x(ui->label_trem1->x()-10);
//            }
//        } else if(regiao == 6){
//            if(estado_malhas_criticas[6] == ACESSIVEL){
//                estado_malhas_criticas[6] = INACESSIVEL;
//                trem1->set_x(ui->label_trem1->x()-10);
//            }
//        }
        break;

    case 3:
//        if(regiao == 1){

//        } else if(regiao == 5){

//        }

        break;

    case 4:
//        if(regiao == 0){

//        } else if(regiao == 2){

//        } else if(regiao == 3){

//        } else if(regiao == 5){

//        } else if(regiao == 6){

//        }
        break;
    case 5:
//        if(regiao == 4){

//        } else if(regiao == 6){

//        }
        break;

    default:
        break;
   }
}

//Sair da região crítica

void MainWindow::sair_de_regiao(int num_regiao){
    regiao[num_regiao].release(1);
    return;
}

//Sliders

void MainWindow::on_slider_vel_trem1_valueChanged(int value)
{
    trem1->set_velocidade(value);
    ui->label_vel_trem1->setText(QString::number(value) + " U.M.");
}

void MainWindow::on_slider_vel_trem2_valueChanged(int value)
{
    trem2->set_velocidade(value);
    ui->label_vel_trem2->setText(QString::number(value) + " U.M.");
}

void MainWindow::on_slider_vel_trem3_valueChanged(int value)
{
    trem3->set_velocidade(value);
    ui->label_vel_trem3->setText(QString::number(value) + " U.M.");
}

void MainWindow::on_slider_vel_trem4_valueChanged(int value)
{
    trem4->set_velocidade(value);
    ui->label_vel_trem4->setText(QString::number(value)+ " U.M.");
}

void MainWindow::on_slider_vel_trem5_valueChanged(int value)
{
    trem5->set_velocidade(value);
    ui->label_vel_trem5->setText(QString::number(value)+ " U.M.");
}
