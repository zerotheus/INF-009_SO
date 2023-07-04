#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
using namespace std;

int buffer[100]; // RC
int cheio = 0, vazio = 99;
condition_variable daConsumidora, daProdutora;
atomic<bool> mutualValue(false);
bool estaCheio = false, estaVazio = true;
typedef struct semafaros
{
    mutex mutual;
    mutex mutexProdutoras;
    mutex mutexConsumidoras;
} semafaro;
semafaro semapharo;

void retornaaZero(int *num);
void produtor();
void produzir(int pos);
void consumidor();
void consumir(int pos);
void espera();
void ativaMutex();
void desativaMutex();

thread produtora(produtor);
thread consumidora(consumidor);

int main()
{
    // 0 nao tem nada
    for (int i = 0; i < 100; i++)
    {
        buffer[i] = 0;
    }
    printf("De volta");
    produtora.join();
    consumidora.join();
}

void produtor()
{
    int i = 0;
    static int produzEm = 0;
    while (i < 257)
    {
        i++;
        if (cheio == 99)
        {
            semapharo.mutexConsumidoras.unlock();
            printf("cheio\n");
            estaCheio = true;
            estaVazio = false;
            semapharo.mutexProdutoras.lock();
            unique_lock<std::mutex> lk(semapharo.mutexProdutoras);
            daConsumidora.notify_one();
            daProdutora.wait(lk);
            printf("\nprodutor sleep\n");
        }
        else
        {
            estaCheio = false;
        }
        espera();
        ativaMutex();
        produzir(produzEm); // RC
        if (produzEm == 100)
            retornaaZero(&produzEm);
        desativaMutex();
    }
    printf("\nend\n");
}

void produzir(int pos)
{
    vazio--;
    buffer[pos] = 1;
    cheio++;
}

void consumidor()
{
    int i = 0;
    static int consomeEm = 0;
    while (i < 257)
    {
        i++;
        if (vazio == 0)
        {
            semapharo.mutexProdutoras.unlock();
            daProdutora.notify_all();
            printf("\nconsumidor sleep\n");
            semapharo.mutexConsumidoras.lock();
            unique_lock<std::mutex> lk(semapharo.mutexConsumidoras);
            daConsumidora.wait(lk);
            estaVazio = true;
        }
        else
        {
            estaVazio = false;
        }
        espera();
        ativaMutex();
        consumir(consomeEm); // RC
        if (consomeEm == 100)
            retornaaZero(&consomeEm);
        desativaMutex();
    }
}

void consumir(int pos)
{
    vazio++;
    buffer[pos] = 3;
    cheio--;
}

void ativaMutex()
{
    semapharo.mutual.lock();
    mutualValue.store(true);
}

void desativaMutex()
{
    semapharo.mutual.unlock();
    mutualValue.store(false);
}

void espera()
{
    while (mutualValue.load())
    {
        printf("wait");
    }
}

void retornaaZero(int *num)
{
    *num = 0;
}