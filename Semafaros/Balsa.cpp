#include <string.h>
#include <thread>
#include <iostream>
using namespace std;

// 1 ocupado// 2 fechado servos//3 fechado hackers 4 ocupado por hacker
/*Es*/
int mute = 0;

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

void temAcentoDisponivel(int isHacker)
{
    if (isHacker == 1)
    {
        if (balsa.hackers == 3)
        {
            for (int i = 0; i < 4; i++)
            {
                balsa.slot[i] = 2;
                break;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (balsa.slot[i] == 0 || balsa.slot[i] == 2)
            {
                balsa.slot[i] = 4;
            }
        }
    }
    else
    {
        if (balsa.servos == 3)
        {
            for (int i = 0; i < 4; i++)
            {
                balsa.slot[i] = 3;
                break;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (balsa.slot[i] == 0 || balsa.slot[i] == 3)
            {
                balsa.slot[i] = 1;
            }
        }
    }
    // printf("saiu\n");
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
    while (mute == 1)
    {
        // printf("sleep\n");
    }
    muteUp();
    balsa.qtd++;
    temAcentoDisponivel(isHacker);
    if (isHacker == 1)
    {
        balsa.hackers++;
        int i = 0;
        while (i < 125)
        {
            i++;
        }
    }
    else
    {
        balsa.servos++;
    }
    if (balsa.qtd == 4)
    {
        printf("qtd: %d: \n", balsa.qtd);
        printf("qtd hackers %d, qtd servos: %d\n", balsa.hackers, balsa.servos);
        rowBoat();
        unboard();
    }
    // printf("\t qtd: %d", balsa.qtd);
    muteDown();
    if (balsa.qtd < 4)
    {
        printf("qtd hackers %d, qtd servos: %d\n", balsa.hackers, balsa.servos);
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
