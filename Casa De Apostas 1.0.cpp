#include <iostream>
#include <string>
#include <iomanip>

#define MAX_EVENTS 100
#define MAX_APOSTAS 100

using namespace std;

typedef struct {
    string nomeApostador;
    string aposta;
    int numeroCartela;
    float quantiaApostada;
    float premioRecebido;

}tAposta;

typedef struct {
    tAposta apostas[MAX_APOSTAS];
    string nomeEvento;
    float premioAcumulado = 0;
    int nApostadores = 0;
    string resultadoFinal;

}tEvento;

// array de eventos
tEvento eventos[MAX_EVENTS];

//contador de eventos cadastrados
int nEventos = 0;

void ExibeMenu(){
    cout << "\n----------- Menu -----------\n"
           "1 - Criar novo evento\n"
           "2 - Cadastrar aposta\n"
           "3 - Atualizar aposta\n"
           "4 - Deletar aposta\n"
           "5 - Cadastrar Ganhador\n"
           "6 - Relatorio da Casa\n"
           "7 - Sair\n\n";
}

int IndiceEvento(string eventoEscolhido){
    int i;
    bool eventoExiste = true; // flag de segurança, saber se o evento digitado existe

    // procurando o índice com o nome do evento que será manipulado
    // e checando se o evento digitado existe
    for (i = 0; i < nEventos; i++){
        if (eventos[i].nomeEvento == eventoEscolhido){
            eventoExiste = true;
            break;
        }
        eventoExiste = false; // dizendo que o evento não existe
    }
    if (eventoExiste == false){
        cout << "\nEVENTO \"" << eventoEscolhido << "\" NAO EXISTE" << endl;
        return -1;
    }
    return i;
}

int IndiceAposta(string eventoEscolhido, string apostaEscolhida){
    int i, iEvento;
    bool apostaExiste = true; // flag de segurança, saber se a aposta digitada existe

    iEvento = IndiceEvento(eventoEscolhido);

    // procurando o índice da aposta escolhida e checando se a aposta digitado existe
    for (i = 0; i < eventos[iEvento].nApostadores; i++){
        if (eventos[iEvento].apostas[i].nomeApostador == apostaEscolhida){
            apostaExiste = true;
            break;
        }
        apostaExiste = false; // dizendo que a aposta não existe
    }
    if (apostaExiste == false){
        cout << "\nAPOSTA de \"" << apostaEscolhida << "\" NAO EXISTE" << endl;
        return -1;
    }
    return i;
}

void CriarEvento(){
    cout << "[NOVO EVENTO]\n" << endl;
    cout << "Digite o nome do evento: ";
    getline(cin, eventos[nEventos].nomeEvento); // lendo o nome do evento, a única coisa que o identifica

    nEventos++; // contando o novo evento
}

void CadastrarGanhador(){
    int iEvento; // guarda índice importante
    string eventoEscolhido;

    cout << "[CADASTRAR GANHADOR]\n" << endl;
    cout << "Informe o evento: ";
    getline(cin, eventoEscolhido); // lendo o evento escolhido

    iEvento = IndiceEvento(eventoEscolhido);
    if (iEvento == -1){
        return;
    }

    cout << "Aposta vencedora: ";
    getline(cin, eventos[iEvento].resultadoFinal); // lendo o resultado final daquele evento
}

void CadastraApostas(){
    int iEvento, iAposta; // guardam índices importantes
    string eventoEscolhido; // string temporária com o nome do evento escolhido

    cout << "[CADASTRAR APOSTA]\n" << endl;
    cout << "Evento apostado: ";
    getline(cin, eventoEscolhido); // lendo o evento escolhido

    iEvento = IndiceEvento(eventoEscolhido); // índice do evento no array de eventos
    if (iEvento == -1){
        return;
    }
    iAposta = eventos[iEvento].nApostadores; // índice da aposta naquele evento

    // lendo o nome do apostador
    cout << "Nome do apostador: ";
    getline(cin, eventos[iEvento].apostas[iAposta].nomeApostador);

    // lendo o número que o apostador aplicou a aposta
    cout << "Aposta: ";
    getline(cin, eventos[iEvento].apostas[iAposta].aposta);

    // lendo quanto dinheiro o apostador apostou
    cout << "Quantia apostada: ";
    cin >> eventos[iEvento].apostas[iAposta].quantiaApostada;
    cin.ignore();

    // registrando numeração da nova cartela
    eventos[iEvento].apostas[iAposta].numeroCartela = eventos[iEvento].nApostadores+1;
    cout << "\n[Nova Cartela] >> CARTELA " << eventos[iEvento].apostas[iAposta].numeroCartela << endl;

    // zerando o premio recebido por aquele apostador, até o momento
    eventos[iEvento].apostas[iAposta].premioRecebido = 0;
    // somando a quantia apostada ao premio acumulado
    eventos[iEvento].premioAcumulado += eventos[iEvento].apostas[iAposta].quantiaApostada;
    // contando mais um apostador naquele evento
    eventos[iEvento].nApostadores++;
}

void AtualizaAposta(){
    int iEvento, iAposta; // guardam índices importantes
    string eventoEscolhido, apostaEscolhida; // string temporária com o nome do evento escolhido

    cout << "[ATUALIZAR APOSTA]\n" << endl;
    cout << "Informe o evento: ";
    getline(cin, eventoEscolhido); // lendo o evento escolhido

    iEvento = IndiceEvento(eventoEscolhido); // índice do evento no array de eventos
    if (iEvento == -1){
        return;
    }
    // lendo o nome do apostador
    cout << "Nome do apostador: ";
    getline(cin, apostaEscolhida);
    iAposta = IndiceAposta(eventoEscolhido, apostaEscolhida);

    //descontando a quantia apostada inicialmente
    eventos[iEvento].premioAcumulado -= eventos[iEvento].apostas[iAposta].quantiaApostada;

    // lendo o número que o apostador aplicou a aposta
    cout << "Nova aposta: ";
    getline(cin, eventos[iEvento].apostas[iAposta].aposta);

    // lendo quanto dinheiro o apostador apostou
    cout << "Nova quantia apostada: ";
    cin >> eventos[iEvento].apostas[iAposta].quantiaApostada;
    cin.ignore();

    // somando a quantia apostada ao premio acumulado
    eventos[iEvento].premioAcumulado += eventos[iEvento].apostas[iAposta].quantiaApostada;
}

void DeletarAposta(){
    int apostaDeletar; // inteiro temporário com o número da cartela que será deletada
    int i, iEvento; // iEvento guarda o índice no array de eventos
    string eventoDeletar; // string temporária com o evento que terá a aposta deletada
    bool eventoExiste;

    cout << "[DELETAR APOSTA]\n" << endl;
    cout << "Informe o evento: ";
    getline(cin, eventoDeletar);

    cout << "Cartela a deletar: ";
    cin >> apostaDeletar;

    // procurando o índice com o nome do evento que será manipulado
    // e checando se o evento digitado existe
    for (i = 0; i < nEventos; i++){
        if (eventos[i].nomeEvento == eventoDeletar){
            eventoExiste = true;
            break;
        }
        eventoExiste = false; // dizendo que evento não existe
    }
    if (eventoExiste == false){
        cout << "\nEVENTO \"" << eventoDeletar << "\" NAO EXISTE" << endl;
        return;
    }

    // guardando o i do for como índice do evento no array de eventos
    iEvento = IndiceEvento(eventoDeletar);
    if (iEvento == -1){
        return;
    }

    // procurando a cartela igual a aposta escolhida para ser deletada
    for (i = 0; i < eventos[iEvento].nApostadores; i++){
        if (eventos[iEvento].apostas[i].numeroCartela == apostaDeletar){

            // descontando do premio e num. de apostadores a aposta deletada
            eventos[iEvento].premioAcumulado -= eventos[iEvento].apostas[i].quantiaApostada;
            eventos[iEvento].nApostadores--;

            // zerando todos os atributos da aposta escolhida
            eventos[iEvento].apostas[i].nomeApostador = "";
            eventos[iEvento].apostas[i].aposta = "";
            eventos[iEvento].apostas[i].numeroCartela = 0;
            eventos[iEvento].apostas[i].quantiaApostada = 0;
        }
    }
}

float TotalPulesVenc(int iEvento){
    float totalPules = 0;
    for (int j = 0; j < eventos[iEvento].nApostadores; j++){
        if (eventos[iEvento].apostas[j].aposta == eventos[iEvento].resultadoFinal){
            totalPules += eventos[iEvento].apostas[j].quantiaApostada;
        }
    }
    return totalPules;
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
                float rateio;
                rateio = eventos[i].premioAcumulado / (TotalPulesVenc(i));
                eventos[i].apostas[j].premioRecebido = (eventos[i].apostas[j].quantiaApostada * rateio);
                cout << "Ganhou R$" << eventos[i].apostas[j].premioRecebido;
            }else if(eventos[i].resultadoFinal == ""){
                cout << "Indefinido";
            }else{
                cout << "Perdeu";
            }
            cout << endl;
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
                system("CLS");
                CriarEvento();
                break;
            case 2:
                system("CLS");
                CadastraApostas();
                break;
            case 3:
                system("CLS");
                AtualizaAposta();
                break;
            case 4:
                system("CLS");
                DeletarAposta();
                break;
            case 5:
                system("CLS");
                CadastrarGanhador();
                break;
            case 6:
                system("CLS");
                RelatorioCasa();
                break;
            case 7:
                cout << "Encerrando...";
                return 0;

            default:
                puts("Opcao invalida >> Digite um dos valores informados");
        }
    }

    return 0;
}
