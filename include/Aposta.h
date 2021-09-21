#ifndef APOSTA_H
#define APOSTA_H

#include <string>

class Aposta
{
    public:
        Aposta();

        void deletarAposta(); //zera todos os atributos

        void setNomeApostador(std::string nome);
        void setAposta(int aposta);
        void setNumeroCartela(int numCart);
        void setQuantiaApostada(float quantia);

        std::string getNomeApostador();
        int getAposta();
        int getNumeroCartela();
        float getQuantiaApostada();

    private:
        std::string nomeApostador;
        int aposta;
        int numeroCartela;
        float quantiaApostada;
};

#endif // APOSTA_H
