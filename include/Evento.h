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
        void setResultado(std::string result);

        std::string getNomeEvento();
        float getPremio();
        int getNumApostadores();
        std::string getResultado();

    private:
        std::string nomeEvento;
        float premioAcumulado;
        int nApostadores;
        std::string resultadoFinal;
};

#endif // EVENTO_H
