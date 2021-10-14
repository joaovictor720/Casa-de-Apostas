#ifndef APOSTA_H
#define APOSTA_H

#include <string>

class Aposta
{
    public:
        Aposta();
        virtual ~Aposta();

        // setters
        void setNomeApostador(std::string nome);
        void setAposta(std::string aposta);
        void setNumeroCartela(int numCart);
        void setQuantiaApostada(float quantia);
        void setPremioRecebido(float premio);

        // getters
        std::string getNomeApostador();
        std::string getAposta();
        int getNumeroCartela();
        float getQuantiaApostada();
        float getPremioRecebido();

    protected:
        std::string nomeApostador;
        std::string aposta;
        int numeroCartela;
        float quantiaApostada;
        float premioRecebido;
};

#endif // APOSTA_H
