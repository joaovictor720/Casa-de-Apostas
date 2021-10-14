#include "Evento.h"

Evento::Evento()
{
    for (int i = 0; i < MAX_APOSTAS; i++)
        apostas[i] == NULL;

    nomeEvento = "<NOME>";
    premioAcumulado = 0;
    nApostadores = 0;
    resultadoFinal = "INDEFINIDO";
}

float Evento::getTotalPulesVenc(){
    float totalPules = 0;
    for(int i = 0; i < nApostadores; i++){
        if (apostas[i]->getAposta() == resultadoFinal){
            totalPules += apostas[i]->getQuantiaApostada();
        }
    }
    return totalPules;
}

float Evento::getRateio(){
    return premioAcumulado / getTotalPulesVenc();
}

int Evento::getIndiceAposta(std::string apEscolhida){
    int i;
    bool apostaExiste = true;

    for (i = 0; i < nApostadores; i++){
        if (apostas[i]->getNomeApostador() == apEscolhida){
            apostaExiste = true;
            break;
        }
        apostaExiste = false;
    }
    if (apostaExiste == false){
        return -1;
    }
    return i;
}

void Evento::addPremio(float add){
    premioAcumulado += add;
}
void Evento::subPremio(float sub){
    premioAcumulado -= sub;
}
void Evento::addNumApostadores(){
    nApostadores++;
}
void Evento::subNumApostadores(){
    nApostadores--;
}

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
