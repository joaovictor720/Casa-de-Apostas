#include "Aposta.h"

Aposta::Aposta()
{
    //ctor
}

void Aposta::deletarAposta(){
    nomeApostador = "";
    aposta = 0;
    numeroCartela = 0;
    quantiaApostada = 0;
}

void Aposta::setNomeApostador(std::string nome){
    nomeApostador = nome;
}
void Aposta::setAposta(int aposta){
    this->aposta = aposta;
}
void Aposta::setNumeroCartela(int numCart){
    numeroCartela = numCart;
}
void Aposta::setQuantiaApostada(float quantia){
    quantiaApostada = quantia;
}

std::string Aposta::getNomeApostador(){
    return nomeApostador;
}
int Aposta::getAposta(){
    return aposta;
}
int Aposta::getNumeroCartela(){
    return numeroCartela;
}
float Aposta::getQuantiaApostada(){
    return quantiaApostada;
}
