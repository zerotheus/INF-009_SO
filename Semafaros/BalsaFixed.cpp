// BalsadaDoredoSofrimento.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <string.h>
#include <thread>
#include <iostream>
using namespace std;

// 1 ocupado// 4 ocupado por hacker
int mute = 0;
// int mutexSaida = 0;

struct Balsa
{
    int slot[4] = {0, 0, 0, 0};
    int hackers = 0;
    int servos = 0;
    int qtd = 0;
};

Balsa balsa;

void unboard()
{
    balsa.slot[0] = 0;
    balsa.slot[1] = 0;
    balsa.slot[2] = 0;
    balsa.slot[3] = 0;
    balsa.hackers = 0;
    balsa.servos = 0;
    balsa.qtd = 0;
}

void rowBoat()
{

    printf("\n%d", balsa.slot[0]);
    printf("\n%d", balsa.slot[1]);
    printf("\n%d", balsa.slot[2]);
    printf("\n%d\n", balsa.slot[3]);
}

int temAcentoDisponivel(int isHacker)
{
    if (balsa.qtd < 4)
    {
        if (isHacker == 1)
        {
            if (balsa.servos == 3)
            {
                return 0;
            }
            if (balsa.hackers == 2 && balsa.servos == 1)
            {
                return 0;
            }
            printf("balsa qtd %d\n", balsa.qtd);
            balsa.slot[balsa.qtd] = 4;
            balsa.hackers++;
            balsa.qtd++;
            return 1;
        }
        else
        {
            if (balsa.hackers == 3)
            {
                return 0;
            }
            if (balsa.servos == 2 && balsa.hackers == 1)
            {
                return 0;
            }
            printf("balsa qtd %d", balsa.qtd);
            balsa.slot[balsa.qtd] = 1;
            balsa.servos++;
            balsa.qtd++;
            return 1;
        }
    }
    return 0;
}

void muteUp()
{
    mute = 1;
}

void muteDown()
{
    mute = 0;
}

void board(int isHacker)
{
    int entrou = 0;
    while (mute == 1)
    {
        // mutex
    }
    while (entrou == 0)
    {
        muteUp();
        if (balsa.qtd < 4)
        {
            entrou = temAcentoDisponivel(isHacker);
            if (balsa.qtd == 4)
            {
                printf("qtd: %d: \n", balsa.qtd);
                printf("qtd hackers %d, qtd servos: %d\n", balsa.hackers, balsa.servos);
                rowBoat();
                unboard();
            }
            muteDown();
        }
    }

    if (balsa.qtd < 4)
    {
        return;
    }
}

void hacker()
{

    board(1);
}

void servo()
{
    board(0);
}

int main()
{
    thread t1(hacker);
    thread t2(hacker);
    thread t3(hacker);
    thread t4(hacker);
    thread t5(servo);
    thread t6(servo);
    thread t7(servo);
    thread t8(servo);

    t1.join();
    t6.join();
    t5.join();
    t2.join();
    t3.join();
    t4.join();
    t7.join();
    t8.join();

    printf("mensagem main\n");
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar:
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
