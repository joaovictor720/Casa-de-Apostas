#include <iostream>
#include <iomanip>
#include "Evento.h"
// incluindo Evento.h, que já contém a classe Aposta

#define MAX_EVENTS 100

using namespace std;

// array de eventos
Evento eventos[MAX_EVENTS];

// contador de eventos cadastrados
int nEventos = 0;

// variáveis temporárias para os métodos set
string nomeEv, nomeApost;
int aposta, numCart, numApost, result;
float quantia, premio;

void ExibeMenu(){
    cout << "\n----------- Menu -----------\n"
           "1 - Criar novo evento\n"
           "2 - Cadastrar aposta\n"
           "3 - Deletar aposta\n"
           "4 - Relatorio da Casa\n"
           "5 - Cadastrar Ganhador\n"
           "6 - Sair\n\n";
}

int IndiceEvento(string eventoEscolhido){
    int i;
    bool eventoExiste = true; // flag de segurança, saber se o evento digitado existe

    // procurando o índice com o nome do evento que será manipulado
    // e checando se o evento digitado existe
    for (i = 0; i < nEventos; i++){
        if (eventos[i].getNomeEvento() == eventoEscolhido){
            eventoExiste = true;
            break;
        }
        eventoExiste = false; // dizendo que evento não existe
    }
    if (eventoExiste == false){
        cout << "\nEVENTO \"" << eventoEscolhido << "\" NAO EXISTE" << endl;
        return -1;
    }
    return i;
}

void CriarEvento(){
    cout << "Digite o nome do evento: ";
    getline(cin, nomeEv); // lendo o nome do evento, a única coisa que o identifica
    eventos[nEventos].setNomeEvento(nomeEv);

    nEventos++; // contando o novo evento
}

void CadastrarGanhador(){
    int iEvento; // guarda índice importante
    string eventoEscolhido;

    cout << "Informe o evento: ";
    getline(cin, eventoEscolhido); // lendo o evento escolhido

    iEvento = IndiceEvento(eventoEscolhido);
    if (iEvento == -1){
        return;
    }

    cout << "Informe a aposta vencedora: ";
    cin >> result; // lendo o resultado final daquele evento
    eventos[iEvento].setResultado(result);
    cin.ignore();
}

void CadastraApostas(){
    int iEvento, iAposta; // guardam índices importantes
    string eventoEscolhido; // string temporária com o nome do evento escolhido

    cout << "Informe o evento apostado: ";
    getline(cin, eventoEscolhido); // lendo o evento escolhido

    iEvento = IndiceEvento(eventoEscolhido); // índice do evento no array de eventos
    if (iEvento == -1){
        return;
    }
    iAposta = eventos[iEvento].getNumApostadores(); // índice da aposta naquele evento

    // lendo o nome do apostador
    cout << "Informe o nome do apostador: ";
    getline(cin, nomeApost);
    eventos[iEvento].apostas[iAposta].setNomeApostador(nomeApost);

    // lendo o número que o apostador aplicou a aposta
    cout << "Informe a aposta: ";
    cin >> aposta;
    eventos[iEvento].apostas[iAposta].setAposta(aposta);

    // lendo a numeração da cartela do apostador
    cout << "Informe a numeracao da aposta: ";
    cin >> numCart;
    eventos[iEvento].apostas[iAposta].setNumeroCartela(numCart);

    // lendo quanto dinheiro o apostador apostou
    cout << "Informe a quantia apostada: ";
    cin >> quantia;
    eventos[iEvento].apostas[iAposta].setQuantiaApostada(quantia);
    cin.ignore();

    // somando a quantia apostada ao premio acumulado
    eventos[iEvento].setPremio( eventos[iEvento].getPremio() + eventos[iEvento].apostas[iAposta].getQuantiaApostada());
    eventos[iEvento].setNumApostadores( eventos[iEvento].getNumApostadores()+1 ); // contando mais um apostador naquele evento
}

void DeletarAposta(){
    int apostaDeletar; // inteiro temporário com o número da cartela que será deletada
    int i, iEvento; // iEvento guarda o índice no array de eventos
    string eventoDeletar; // string temporária com o evento que terá a aposta deletada

    cout << "Informe o evento da aposta a ser deletada: ";
    getline(cin, eventoDeletar);

    cout << "Informe a cartela a ser deletada: ";
    cin >> apostaDeletar;

    iEvento = IndiceEvento(eventoDeletar); // guardando o i do for como índice do evento no array de eventos
    if (iEvento == -1){
        return;
    }

    // procurando a cartela igual a aposta escolhida para ser deletada
    for (i = 0; i < eventos[iEvento].getNumApostadores(); i++){
        if (eventos[iEvento].apostas[i].getNumeroCartela() == apostaDeletar){

            // chamando o método que zera todos os atributos daquela aposta
            eventos[iEvento].apostas[i].deletarAposta();
            eventos[iEvento].setNumApostadores( eventos[iEvento].getNumApostadores()-1 ); // descontando o número de apostadores naquele evento
        }
    }
}

void RelatorioCasa(){
    int i, j;

    cout << endl;

    for (i = 0; i < nEventos; i++){
        cout << "--------------------------------------------------------------------\n";
        cout << "-->> EVENTO: " << eventos[i].getNomeEvento() << endl;
        cout << "-->> APOSTA VENCEDORA: " << eventos[i].getResultado() << endl;
        cout << "-->> PREMIO: R$ " << fixed << setprecision(2) << eventos[i].getPremio() << endl;
        cout << "\nAPOSTA\tAPOSTADOR\tCARTELA\t\tRESULTADO\n";
        cout << "--------------------------------------------------------------------\n";
        for (j = 0; j < eventos[i].getNumApostadores(); j ++){
            cout << eventos[i].apostas[j].getAposta() << "\t"
                 << eventos[i].apostas[j].getNomeApostador() << "\t"
                 << eventos[i].apostas[j].getNumeroCartela() << "\t\t";

            if (eventos[i].apostas[j].getAposta() == eventos[i].getResultado()){
                cout << "Ganhou" << endl;
            }else if(eventos[i].getResultado() == 0){
                cout << "Indefinido" << endl;
            }else{
                cout << "Perdeu" << endl;
            }
        }
    }

    cout << "--------------------------------------------------------------------\n";
}

int main()
{
    int opcao;

    while (1){
        ExibeMenu();
        cout << "Digite a opcao: ";
        cin >> opcao;
        cin.ignore();

        switch(opcao){
            case 1:
                CriarEvento();
                break;
            case 2:
                CadastraApostas();
                break;
            case 3:
                DeletarAposta();
                break;
            case 4:
                RelatorioCasa();
                break;
            case 5:
                CadastrarGanhador();
                break;
            case 6:
                cout << "Encerrando...";
                return 0;

            default:
                puts("Opcao invalida >> Digite um dos valores informados");
        }
    }

    return 0;
}
