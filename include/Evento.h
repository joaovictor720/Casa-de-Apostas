#ifndef EVENTO_H
#define EVENTO_H
#define MAX_APOSTAS 100

#include "Aposta.h"

class Evento
{
    public:
        Aposta apostas[MAX_APOSTAS]; // array de objetos da classe Aposta

        Evento(); // construtor

        void setNomeEvento(std::string nome);
        void setPremio(float premio);
        void setNumApostadores(int nApostadores);
        void setResultado(int result);

        std::string getNomeEvento();
        float getPremio();
        int getNumApostadores();
        int getResultado();

    private:
        std::string nomeEvento;
        float premioAcumulado;
        int nApostadores;
        int resultadoFinal;
};

#endif // EVENTO_H
