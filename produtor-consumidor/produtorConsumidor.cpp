#include <stdlib.h>
#include <stdio.h>

int buffer[100]; // RC
int cheio = 0;
int vazio = 99;

int main()
{
    // 0 nao tem nada
    for (int i = 0; i < 100; i++)
    {
        buffer[i] = 0;
    }
    printf("De volta");
}

void produtor()
{
    static int produzEm = 0;
    if (cheio == 99)
    {
        printf("produtor sleep");
        // sleep
    }
    produzir(); // RC
}

void produzir()
{
    vazio--;
    cheio++;
}

void consumidor()
{
    static int consomeEm = 0;
    if (vazio == 0)
    {
        printf("consumidor sleep");
        // sleep
    }
    consumir(); // RC
}

void consumir()
{
    vazio++;
    cheio--;
}