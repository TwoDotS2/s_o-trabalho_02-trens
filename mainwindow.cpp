#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string.h"
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define ACESSIVEL 1
#define INACESSIVEL 0

int   estado_malhas_criticas[7]; // Vetor para controlar o estado de cada malha crítica
sem_t semaforo;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Inicialização do semaforo
    sem_init(&semaforo, 0, 1);

    //Todas as malhas estão livres a priori;
    for(i= 0; i < 7 ;i++ ){
        estado_malhas_criticas[i] = ACESSIVEL;
    }

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1, 350, 110);
    trem2 = new Trem(2, 610, 160);
    trem3 = new Trem(3, 170, 290);
    trem4 = new Trem(4, 440, 350);
    trem5 = new Trem(5, 710, 290);

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
        ui->label_trem1->setGeometry(x,y,21,17);
        break;

    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;

    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;

    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;

    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
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

void MainWindow::entrar_em_regiao(int ID, int regiao){
    sem_wait(&semaforo);

    switch (ID) {

    case 1:

        if(regiao == 0){
            if( railState[0] == FREE &&
                !(railState[5] == BUSY && railState[1] == BUSY && railState[2] == BUSY && railState[6] == BUSY) &&
                !(railState[2] == BUSY && railState[4] == BUSY && railState[6] == BUSY) &&
                (railState[2] == FREE || railState[3] == FREE)

             ){


                railState[0] = BUSY;
                trem1->setX(ui->label_trem1->x()+10);
            }
        }
        else if(regiao == 2){
            if(railState[2] == FREE){
                railState[2] = BUSY;
                trem1->setY(ui->label_trem1->y()+10);
            }
        }


        break;

    case 2:

        break;

    case 3:

        break;

    case 4:

        break;

    case 5:

        break;

    default:
        break;
    }

}

//Sair da região crítica

void MainWindow::sair_de_regiao(int regiao){
    sem_wait(&semaforo);
    estado_malhas_criticas[regiao] == ACESSIVEL;
    sem_post(&semaforo);
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
