#ifndef APOSTA_H
#define APOSTA_H

#include <string>

class Aposta
{
    public:
        Aposta();

        void deletarAposta(); //zera todos os atributos

        void setNomeApostador(std::string nome);
        void setAposta(std::string aposta);
        void setNumeroCartela(int numCart);
        void setQuantiaApostada(float quantia);

        std::string getNomeApostador();
        std::string getAposta();
        int getNumeroCartela();
        float getQuantiaApostada();

    private:
        std::string nomeApostador;
        std::string aposta;
        int numeroCartela;
        float quantiaApostada;
};

#endif // APOSTA_H
