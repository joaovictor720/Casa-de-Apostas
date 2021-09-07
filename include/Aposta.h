#ifndef APOSTA_H
#define APOSTA_H

#include <string>

class Aposta
{
    public:
        std::string nomeApostador;
        int aposta;
        int numeroCartela;
        float quantiaApostada;

        Aposta(); // n�o faz nada
        void deletarAposta(); //zera todos os atributos
};

#endif // APOSTA_H
