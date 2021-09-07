#ifndef EVENTO_H
#define EVENTO_H
#define MAX_APOSTAS 100

#include "Aposta.h"

class Evento
{
    public:
        std::string nomeEvento;
        float premioAcumulado;
        int nApostadores;
        int resultadoFinal;
        Aposta apostas[MAX_APOSTAS]; // array de objetos da classe Aposta
        // acho que isso é a tal da herança

        Evento(); // construtor inicia algumas variáveis; olhar o .cpp
};

#endif // EVENTO_H
