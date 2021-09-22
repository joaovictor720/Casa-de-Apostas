#include "Evento.h"

Evento::Evento()
{
    nomeEvento = "";
    premioAcumulado = 0;
    nApostadores = 0;
    resultadoFinal = "";
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
