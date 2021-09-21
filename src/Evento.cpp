#include "Evento.h"

Evento::Evento()
{
    nomeEvento = "";
    premioAcumulado = 0;
    nApostadores = 0;
    resultadoFinal = 0;
}

void Evento::setNomeEvento(std::string nome){
    nomeEvento = nome;
}
void Evento::setPremio(float premio){
    premioAcumulado = premio;
}
void Evento::setNumApostadores(int nApostadores){
    this->nApostadores = nApostadores;
}
void Evento::setResultado(int result){
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
int Evento::getResultado(){
    return resultadoFinal;
}
