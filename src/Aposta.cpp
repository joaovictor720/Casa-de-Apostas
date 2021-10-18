#include "Aposta.h"

Aposta::Aposta()
{
    quantiaApostada = 0;
    premioRecebido = 0;
}

Aposta::~Aposta(){
    // destrutor
}

void Aposta::setNomeApostador(std::string nome){
    nomeApostador = nome;
}
void Aposta::setAposta(std::string aposta){
    this->aposta = aposta;
}
void Aposta::setNumeroCartela(int numCart){
    numeroCartela = numCart;
}
void Aposta::setQuantiaApostada(float quantia){
    quantiaApostada = quantia;
}
void Aposta::setPremioRecebido(float premio){
    premioRecebido = premio;
}

std::string Aposta::getNomeApostador(){
    return nomeApostador;
}
std::string Aposta::getAposta(){
    return aposta;
}
int Aposta::getNumeroCartela(){
    return numeroCartela;
}
float Aposta::getQuantiaApostada(){
    return quantiaApostada;
}
float Aposta::getPremioRecebido(){
    return premioRecebido;
}
