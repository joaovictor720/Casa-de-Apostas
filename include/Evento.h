#ifndef EVENTO_H
#define EVENTO_H
#define MAX_APOSTAS 50

#include "Aposta.h"

class Evento
{
    public:
        Aposta *apostas[MAX_APOSTAS]; // array de ponteiros para classe Aposta

        Evento();

        float getRateio();
        float getTotalPulesVenc();
        int getIndiceAposta(std::string apEscolhida);

        // adders
        void addPremio(float add);
        void addNumApostadores();

        // subtractors
        void subPremio(float sub);
        void subNumApostadores();

        // std setters
        void setNomeEvento(std::string nome);
        void setPremio(float premio);
        void setNumApostadores(int nApostadores);
        void setResultado(std::string result);

        // std getters
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
