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
}

void consumidor()
{
}

void consumir()
{
}

void produzir()
{
}