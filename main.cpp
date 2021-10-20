#include <iostream>
#include <iomanip>
#include "Evento.h"
// incluindo Evento.h, que já contém a classe Aposta

#define MAX_EVENTS 10

using namespace std;

// array de eventos
static Evento eventos[MAX_EVENTS];

// contador de eventos cadastrados
static int nEventos = 0;

// variáveis temporárias para os métodos set
static string nomeEv, nomeApost, result, aposta;
static float quantia;

void ExibeMenu(){
    cout << "\n----------- Menu -----------\n"
           "1 - Criar novo evento\n\n"
           "2 - Cadastrar aposta\n\n"
           "3 - Atualizar aposta\n\n"
           "4 - Deletar aposta\n\n"
           "5 - Cadastrar Ganhador\n\n"
           "6 - Relatorio da Casa\n\n"
           "7 - Sair\n\n";
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
    cout << "[NOVO EVENTO] <> Insira 0 para cancelar\n" << endl;
    cout << "Digite o nome do evento: ";
    getline(cin, nomeEv); // lendo o nome do evento, a única coisa que o identifica
    if (nomeEv == "0"){
        cout << "\nSaindo..." << endl;
        return;
    }
    eventos[nEventos].setNomeEvento(nomeEv); // settando o nome do evento

    cout << "\n[EVENTO CRIADO] >> " << eventos[nEventos].getNomeEvento() << endl;
    nEventos++; // contando o novo evento
}

void CadastrarAposta(){
    int iEvento, iAposta;
    string eventoEscolhido;

    cout << "[CADASTRAR APOSTA] <> Insira 0 para cancelar\n" << endl;
    cout << "Evento apostado: ";
    getline(cin, eventoEscolhido); // pesquisando evento
    if (eventoEscolhido == "0"){
        cout << "\nSaindo..." << endl;
        return;
    }

    iEvento = IndiceEvento(eventoEscolhido); // índice do evento no array de eventos
    if (iEvento == -1)
        return;
    iAposta = eventos[iEvento].getNumApostadores(); // índice da aposta naquele evento
    eventos[iEvento].apostas[iAposta] = new Aposta(); // criando nova aposta a ser preenchida

    cout << "Nome do apostador: ";
    getline(cin, nomeApost); // lendo o nome do apostador
    if (nomeApost == "0"){
        cout << "\nSaindo..." << endl;
        return;
    }

    cout << "Aposta: ";
    getline(cin, aposta); // lendo o número que o apostador aplicou a aposta
    if (aposta == "0"){
        cout << "\nSaindo..." << endl;
        return;
    }

    cout << "Quantia apostada: ";
    cin >> quantia; // lendo quanto dinheiro o apostador apostou
    cin.ignore();
    if (quantia == 0){
        cout << "\nSaindo..." << endl;
        return;
    }

    // settando o que foi inserido
    eventos[iEvento].apostas[iAposta]->setNomeApostador(nomeApost);
    eventos[iEvento].apostas[iAposta]->setAposta(aposta);
    eventos[iEvento].apostas[iAposta]->setQuantiaApostada(quantia);
    eventos[iEvento].addPremio(quantia); // somando a quantia apostada ao premio total
    eventos[iEvento].addNumApostadores(); // incrementando +1 no número de apostadores

    // registrando nova cartela
    eventos[iEvento].apostas[iAposta]->setNumeroCartela( eventos[iEvento].getNumApostadores() );
    cout << "\n[NOVA CARTELA] >> Cartela " << eventos[iEvento].apostas[iAposta]->getNumeroCartela() << endl;
}

void AtualizarAposta(){
    int iEvento, iAposta;
    string eventoEscolhido, apostaEscolhida;

    cout << "[ATUALIZAR APOSTA] <> Insira 0 para cancelar\n" << endl;
    cout << "Informe o evento: ";
    getline(cin, eventoEscolhido); // pesquisando evento
    if (eventoEscolhido == "0"){
        cout << "\nSaindo..." << endl;
        return;
    }

    iEvento = IndiceEvento(eventoEscolhido);
    if (iEvento == -1)
        return;

    cout << "Nome do apostador: ";
    getline(cin, apostaEscolhida); // pesquisando aposta
    if (apostaEscolhida == "0"){
        cout << "\nSaindo..." << endl;
        return;
    }

    iAposta = eventos[iEvento].getIndiceAposta(apostaEscolhida);
    if (iAposta == -1){
        cout << "APOSTADOR \"" << apostaEscolhida << "\" NAO EXISTE" << endl;
        return;
    }

    // subtraindo, do premio total, a quantia aplicada pelo apostador
    // isso é para que seja possível atribuir, no premio total, a nova quantia aplicada
    eventos[iEvento].subPremio( eventos[iEvento].apostas[iAposta]->getQuantiaApostada() );

    cout << "Nova aposta: ";
    getline(cin, aposta);
    if (aposta == "0"){
        cout << "\nSaindo..." << endl;
        return;
    }

    cout << "Nova quantia apostada: ";
    cin >> quantia;
    if (quantia == 0){
        cout << "\nSaindo..." << endl;
        return;
    }
    cin.ignore();

    eventos[iEvento].apostas[iAposta]->setAposta(aposta); // settando a nova aposta lida
    eventos[iEvento].apostas[iAposta]->setQuantiaApostada(quantia); // settando a nova quantia aplicada
    eventos[iEvento].addPremio( eventos[iEvento].apostas[iAposta]->getQuantiaApostada() ); // atribuindo a nova quantia aplicada

    cout << "\n[APOSTA ATUALIZADA] >> Cartela " << eventos[iEvento].apostas[iAposta]->getNumeroCartela() << endl;
}

void DeletarAposta(){
    int iEvento, iAposta; // iEvento guarda o índice no array de eventos
    string eventoEscolhido, apostaDeletar; // string temporária com o evento que terá a aposta deletada

    cout << "[DELETAR APOSTA] <> Insira 0 para cancelar\n" << endl;
    cout << "Informe o evento: ";
    getline(cin, eventoEscolhido); // pesquisando evento
    if (eventoEscolhido == "0"){
        cout << "\nSaindo..." << endl;
        return;
    }

    cout << "Apostador a deletar: ";
    getline(cin, apostaDeletar); // pesquisando aposta para deletar
    if (apostaDeletar == "0"){
        cout << "\nSaindo..." << endl;
        return;
    }

    iEvento = IndiceEvento(eventoEscolhido); // guardando o i do for como índice do evento no array de eventos
    if (iEvento == -1)
        return;

    iAposta = eventos[iEvento].getIndiceAposta(apostaDeletar);
    if (iAposta == -1){
        cout << "\nAPOSTADOR \"" << apostaDeletar << "\" NAO EXISTE" << endl;
        return;
    }

    // descontando a quantia apostada do premio acumulado
    eventos[iEvento].subPremio( eventos[iEvento].apostas[iAposta]->getQuantiaApostada() );
    if (eventos[iEvento].apostas[iAposta] != NULL){
        delete eventos[iEvento].apostas[iAposta]; // liberando de fato no endereço do ponteiro para Aposta
        eventos[iEvento].apostas[iAposta] = NULL; // atribuindo NULL por segurança de acesso à memória
    }

    cout << "\n[APOSTA DELETADA]" << endl;
}

void CadastrarGanhador(){
    int iEvento; // guarda índice importante
    string eventoEscolhido;

    cout << "[CADASTRAR GANHADOR] <> Insira 0 para cancelar\n" << endl;
    cout << "Informe o evento: ";
    getline(cin, eventoEscolhido); // lendo o evento escolhido
    if (eventoEscolhido == "0"){
        cout << "\nSaindo..." << endl;
        return;
    }
    iEvento = IndiceEvento(eventoEscolhido);
    if (iEvento == -1)
        return;

    cout << "Aposta vencedora: ";
    getline(cin, result); // lendo o resultado final daquele evento
    eventos[iEvento].setResultado(result);
    cout << "\n[GANHADOR CADASTRADO] >> " << eventos[iEvento].getResultado() << endl;
}

void RelatorioCasa(){
    int i, j;

    cout << endl;

    for (i = 0; i < nEventos; i++){
        cout << "--------------------------------------------------------------------\n";
        cout << "-->> EVENTO: " << eventos[i].getNomeEvento() << endl;
        cout << "-->> APOSTA VENCEDORA: " << eventos[i].getResultado() << endl;
        cout << "-->> PREMIO: R$ " << fixed << setprecision(2) << eventos[i].getPremio() << endl;
        cout << "\nAPOSTA\tNOME\tCARTELA\tRESULTADO\n";
        cout << "--------------------------------------------------------------------\n";

        for (j = 0; j < eventos[i].getNumApostadores(); j ++){
            if (eventos[i].apostas[j] != NULL){
                cout << eventos[i].apostas[j]->getAposta() << "\t"
                     << eventos[i].apostas[j]->getNomeApostador() << "\t"
                     << setfill('0') << setw(3) << eventos[i].apostas[j]->getNumeroCartela() << "\t";

                if (eventos[i].apostas[j]->getAposta() == eventos[i].getResultado()){
                    eventos[i].apostas[j]->setPremioRecebido( eventos[i].getRateio() * eventos[i].apostas[j]->getQuantiaApostada() );
                    cout << "Ganhou R$ " << eventos[i].apostas[j]->getPremioRecebido() << endl;
                }else if(eventos[i].getResultado() == "INDEFINIDO"){
                    cout << "Indefinido" << endl;
                }else{
                    cout << "Perdeu" << endl;
                }
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
        system("CLS");

        switch(opcao){
            case 1:
                CriarEvento();
                break;
            case 2:
                CadastrarAposta();
                break;
            case 3:
                AtualizarAposta();
                break;
            case 4:
                DeletarAposta();
                break;
            case 5:
                CadastrarGanhador();
                break;
            case 6:
                RelatorioCasa();
                break;
            case 7:
                cout << "Encerrando..." << endl;
                return 0;

            default:
                puts("Opcao invalida >> Digite um dos valores informados");
        }
    }

    return 0;
}
