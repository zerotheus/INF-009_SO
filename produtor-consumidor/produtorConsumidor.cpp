#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;

int buffer[100]; // RC
int cheio = 0;
int vazio = 99;
mutex mutual;
atomic<bool> mutualValue(false);

void produtor();
void produzir(int pos);
void consumidor();
void consumir(int pos);
void espera();
void ativaMutex();
void desativaMutex();

thread produtora(produtor);

int main()
{
    // 0 nao tem nada
    for (int i = 0; i < 100; i++)
    {
        buffer[i] = 0;
    }
    printf("De volta");
    // thread consumidora(consumidor);
    produtora.join();
}

void produtor()
{
    static int produzEm = 0;
    if (cheio == 99)
    {
        printf("produtor sleep");
    }
    espera();
    ativaMutex();
    produzir(produzEm); // RC
    desativaMutex();
}

void produzir(int pos)
{
    vazio--;
    cheio++;
}

void consumidor(int pos)
{
    static int consomeEm = 0;
    if (vazio == 0)
    {
        printf("consumidor sleep");
        // sleep
    }
    consumir(consomeEm); // RC
}

void consumir(int pos)
{
    vazio++;
    cheio--;
}

void espera()
{
    while (mutualValue.load())
    {
    }
}

void ativaMutex()
{
    mutual.lock();
    mutualValue.store(true);
}

void desativaMutex()
{
    mutual.unlock();
    mutualValue.store(false);
}