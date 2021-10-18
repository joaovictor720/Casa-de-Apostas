#include "Evento.h"

Evento::Evento()
{
    nomeEvento = "<NOME>";
    premioAcumulado = 0;
    nApostadores = 0;
    resultadoFinal = "INDEFINIDO";
}

// método retorna o total de pules vencedores
// "pules vencedor" é o dinheiro apostado no vencedor do evento
float Evento::getTotalPulesVenc(){
    float totalPules = 0;
    for(int i = 0; i < nApostadores; i++){
        if (apostas[i] != NULL){
            if (apostas[i]->getAposta() == resultadoFinal){
                totalPules += apostas[i]->getQuantiaApostada();
            }
        }
    }
    return totalPules;
}

// método retorna o rateio do evento
// rateio é uma razão de proporção para distribuir o prêmio entre os vencedores
float Evento::getRateio(){
    return premioAcumulado / getTotalPulesVenc();
}

// retorna o índice da aposta pesquisada ou -1 caso não exista
int Evento::getIndiceAposta(std::string apEscolhida){
    int i;
    bool apostaExiste = true;

    for (i = 0; i < nApostadores; i++){
        if (apostas[i] != NULL){
            if (apostas[i]->getNomeApostador() == apEscolhida){
                apostaExiste = true;
                break;
            }
            apostaExiste = false;
        }
    }
    if (apostaExiste == false){
        return -1;
    }
    return i;
}

// adicionadores e subtratores do premio
void Evento::addPremio(float add){
    premioAcumulado += add;
}
void Evento::subPremio(float sub){
    premioAcumulado -= sub;
}

// adicionadores e subtratores do número de apostadores
void Evento::addNumApostadores(){
    nApostadores++;
}
void Evento::subNumApostadores(){
    nApostadores--;
}

// standard setters
void Evento::setNomeEvento(std::string nome){
    nomeEvento = nome;
}
void Evento::setPremio(float premio){
    premioAcumulado += premio;
}
void Evento::setNumApostadores(int nApostadores){
    this->nApostadores = nApostadores;
}
void Evento::setResultado(std::string result){
    resultadoFinal = result;
}

// standard getters
std::string Evento::getNomeEvento(){
    return nomeEvento;
}
float Evento::getPremio(){
    return premioAcumulado;
}
int Evento::getNumApostadores(){
    return nApostadores;
}
std::string Evento::getResultado(){
    return resultadoFinal;
}
