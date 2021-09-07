#include <iostream>
#include <iomanip>
#include "Evento.h"
// incluindo Evento.h, que j� cont�m a classe Aposta

#define MAX_EVENTS 100

using namespace std;

// array de eventos
Evento eventos[MAX_EVENTS];

//contador de eventos cadastrados
int nEventos = 0;

void ExibeMenu(){
    cout << "\n----------- Menu -----------\n"
           "1 - Criar novo evento\n"
           "2 - Cadastrar aposta\n"
           "3 - Deletar aposta\n"
           "4 - Relatorio da Casa\n"
           "5 - Sair\n\n";
}

void CriarEvento(){
    cout << "Digite o nome do evento: ";
    getline(cin, eventos[nEventos].nomeEvento); // lendo o nome do evento, a �nica coisa que o identifica
    cout << "Informe a aposta vencedora: ";
    cin >> eventos[nEventos].resultadoFinal; // lendo o resultado final daquele evento
    cin.ignore();

    nEventos++; // contando o novo evento
}

void CadastraApostas(){
    int i;
    int iEvento, iAposta; // guardam �ndices importantes
    bool eventoExiste = true; // flag de seguran�a, saber se o evento digitado existe
    string eventoEscolhido; // string tempor�ria com o nome do evento escolhido

    cout << "Informe o evento apostado: ";
    getline(cin, eventoEscolhido); // lendo o evento escolhido

    // procurando o �ndice com o nome do evento que ser� manipulado
    // e checando se o evento digitado existe
    for (i = 0; i < nEventos; i++){
        if (eventos[i].nomeEvento == eventoEscolhido){
            eventoExiste = true;
            break;
        }
        eventoExiste = false; // dizendo que evento n�o existe
    }
    if (eventoExiste == false){
        cout << "\nEVENTO \"" << eventoEscolhido << "\" NAO EXISTE" << endl;
        return;
    }

    iEvento = i; // �ndice do evento no array de eventos
    iAposta = eventos[iEvento].nApostadores; // �ndice da aposta naquele evento

    // lendo o nome do apostador
    cout << "Informe o nome do apostador: ";
    getline(cin, eventos[iEvento].apostas[iAposta].nomeApostador);

    // lendo o n�mero que o apostador aplicou a aposta
    cout << "Informe a aposta: ";
    cin >> eventos[iEvento].apostas[iAposta].aposta;

    // lendo a numera��o da cartela do apostador
    cout << "Informe a numeracao da aposta: ";
    cin >> eventos[iEvento].apostas[iAposta].numeroCartela;

    // lendo quanto dinheiro o apostador apostou
    cout << "Informe a quantia apostada: ";
    cin >> eventos[iEvento].apostas[iAposta].quantiaApostada;
    cin.ignore();

    // somando a quantia apostada ao premio acumulado
    eventos[i].premioAcumulado += eventos[iEvento].apostas[iAposta].quantiaApostada;
    eventos[iEvento].nApostadores++; // contando mais um apostador naquele evento
}

void DeletarAposta(){
    int apostaDeletar; // inteiro tempor�rio com o n�mero da cartela que ser� deletada
    int i, iEvento; // iEvento guarda o �ndice no array de eventos
    string eventoDeletar; // string tempor�ria com o evento que ter� a aposta deletada
    bool eventoExiste;

    cout << "Informe o evento da aposta a ser deletada: ";
    getline(cin, eventoDeletar);

    cout << "Informe a cartela a ser deletada: ";
    cin >> apostaDeletar;

    // procurando o �ndice com o nome do evento que ser� manipulado
    // e checando se o evento digitado existe
    for (i = 0; i < nEventos; i++){
        if (eventos[i].nomeEvento == eventoDeletar){
            eventoExiste = true;
            break;
        }
        eventoExiste = false; // dizendo que evento n�o existe
    }
    if (eventoExiste == false){
        cout << "\nEVENTO \"" << eventoDeletar << "\" NAO EXISTE" << endl;
        return;
    }

    iEvento = i; // guardando o i do for como �ndice do evento no array de eventos

    // procurando a cartela igual a aposta escolhida para ser deletada
    for (i = 0; i < eventos[iEvento].nApostadores; i++){
        if (eventos[iEvento].apostas[i].numeroCartela == apostaDeletar){

            // chamando o m�todo que zera todos os atributos daquela aposta
            eventos[iEvento].apostas[i].deletarAposta();
            eventos[iEvento].nApostadores--; // descontando o n�mero de apostadores naquele evento
        }
    }
}

void RelatorioCasa(){
    int i, j;

    cout << endl;

    for (i = 0; i < nEventos; i ++){
        cout << "--------------------------------------------------------------------\n";
        cout << "-->> EVENTO: " << eventos[i].nomeEvento << endl;
        cout << "-->> APOSTA VENCEDORA: " << eventos[i].resultadoFinal << endl;
        cout << "-->> PREMIO: R$ " << fixed << setprecision(2) << eventos[i].premioAcumulado << endl;
        cout << "\nAPOSTA\tAPOSTADOR\tCARTELA\t\tRESULTADO\n";
        cout << "--------------------------------------------------------------------\n";
        for (j = 0; j < eventos[i].nApostadores; j ++){
            cout << eventos[i].apostas[j].aposta << "\t"
                 << eventos[i].apostas[j].nomeApostador << "\t"
                 << eventos[i].apostas[j].numeroCartela << "\t\t";

            if (eventos[i].apostas[j].aposta == eventos[i].resultadoFinal){
                cout << "Ganhou" << endl;
            }else {
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

        if (opcao == 5)
            break;

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

            default:
                puts("Opcao invalida >> Digite um dos valores informados");
        }
    }

    return 0;
}
