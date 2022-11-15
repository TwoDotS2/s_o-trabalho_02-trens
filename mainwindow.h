#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSemaphore>
#include <array>

#define ZONA_LIVRE -1

static QSemaphore regiao[7]; //semaforos das regioes criticas
static std::array<int, 5> trem_por_regiao{ZONA_LIVRE, ZONA_LIVRE, ZONA_LIVRE, ZONA_LIVRE, ZONA_LIVRE}; //array que guarda as regiões que cada trem está acessando no momento
static QSemaphore mutex; //mutex para controlar a mudanca de estado

#include <QMainWindow>
#include "trem.h"
#include <QAbstractSlider>


namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);

    void entrar_em_regiao(int ID, int regiao);

    void sair_de_regiao(int regiao);

private slots:
  void on_slider_vel_trem1_valueChanged(int value);

  void on_slider_vel_trem2_valueChanged(int value);

  void on_slider_vel_trem3_valueChanged(int value);

  void on_slider_vel_trem4_valueChanged(int value);

  void on_slider_vel_trem5_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    //Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;

};

#endif // MAINWINDOW_H
