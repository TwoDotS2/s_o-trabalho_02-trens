#ifndef TREM_H
#define TREM_H

#include <QThread>

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread{
 Q_OBJECT
public:
    /**
     * @brief Construtor
     */
    Trem(int,int,int);

    /**
     * Função a ser executada pela thread, ela é executada após executar trem->START
     * @brief run
     */
    void run();

    /**
     * seta a velocidade atual para o tem
     * A função da velocidade varia de 0 até 200
     * @brief set_velocidade
     * @param vel
     */
    void set_velocidade(int vel);

    /**
     * seta a posição x do trem
     * @brief Trem::set_x
     * @param x
     */
    void set_x(int x);

    /**
     * seta a posição y do trem
     * @brief Trem::set_y
     * @param y
     */
    void set_y(int y);

//Cria um sinal
signals:
    void updateGUI(int,int,int);

    void entrar_em_regiao(int ID, int regiao);

    void sair_de_regiao(int regiao, int regiao_trem);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int ID;          //ID do trem
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
};

#endif // TREM_H
