#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
using namespace std;

int buffer[100]; // RC
atomic<short> cheio(0), vazio(99);
atomic<bool> mutualValue(false), mutexdasProdutoras(false), mutexdasConsumidoras(true);
bool estaCheio = false, estaVazio = true;

void retornaaZero(int *num);
void produtor();
void produzir(int pos);
void consumidor();
void consumir(int pos);
void espera();
void ativaMutex();
void desativaMutex();
bool esperaCons();
void esperaProd();
void show();
thread produtora(produtor);
thread consumidora(consumidor);

int main()
{
    // 0 nao tem nada
    for (int i = 0; i < 100; i++)
    {
        buffer[i] = 0;
    }
    produtora.join();
    consumidora.join();
}

void produtor()
{
    int i = 0;
    static int produzEm = 0;
    while (i < 100)
    {
        i++;
        if (cheio == 99)
        {
            mutexdasProdutoras.store(true);
            printf("cheio\n");
            estaCheio = true;
            printf("\nprodutor sleep\n");
            esperaProd();
        }
        else
        {
            estaCheio = false;
        }
        if (cheio == 0)
        {
            mutexdasConsumidoras.store(true);
        }
        espera();
        ativaMutex();
        produzir(produzEm); // RC
        produzEm++;
        if (produzEm == 100)
            retornaaZero(&produzEm);
        desativaMutex();
        if (cheio != 0)
        {
            mutexdasConsumidoras.store(false);
        }
    }
}

void produzir(int pos)
{
    vazio--;
    buffer[pos] = 1;
    show();
    cheio++;
}

void consumidor()
{
    int i = 0;
    static int consomeEm = 0;
    while (i < 100)
    {
        i++;
        if (vazio == 99)
        {
            mutexdasConsumidoras.store(true);
            printf("\nconsumidor sleep\n");
            esperaCons();
            if (!produtora.joinable() && vazio == 99)
            {
                return;
            }
        }
        else
        {
            estaVazio = false;
        }
        espera();
        ativaMutex();
        consumir(consomeEm); // RC
        consomeEm++;
        if (consomeEm == 100)
            retornaaZero(&consomeEm);
        desativaMutex();
    }
}

void consumir(int pos)
{
    vazio++;
    buffer[pos] = 3;
    show();
    cheio--;
    mutexdasProdutoras.store(false);
}

void ativaMutex()
{
    mutualValue.store(true);
}

void desativaMutex()
{
    mutualValue.store(false);
}

void espera()
{
    while (mutualValue.load())
    {
        //   printf("espera\n");
    }
}

void esperaProd()
{
    while (mutexdasProdutoras.load())
    {
        //     printf("prod\n");
    }
}

bool esperaCons()
{
    while (mutexdasConsumidoras.load())
    {
        //  printf("consu\n");
        if (!produtora.joinable())
        {
            return true;
        }
    }
    return false;
}

void retornaaZero(int *num)
{
    *num = 0;
}

void show()
{
    for (int i = 0; i < 100; i++)
    {
        printf(" %d ", buffer[i]);
        if ((i + 1) % 10 == 0 && i != 0)
        {
            printf("\n");
        }
    }
    printf("\ncheio: %d\tvazio %d\n", cheio.load(), vazio.load());
}