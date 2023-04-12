#include <string.h>
#include <thread>
#include <iostream>
#include <Windows.h>

/*Simulação de uma condição de corrida e como controlar o acesso a variavel*/

using namespace std;

int x = 2;
int mutex = 0;

void mutexDown()
{
    mutex = 1;
}

void mutexUp()
{
    mutex = 0;
}

void task1()
{
    while (mutex != 0)
    {
        printf("espera task1\n");
        Sleep(100);
    }
    mutexDown();
    x = x + 1;
    printf("thread soma: %d\n", x);
    mutexUp();
}

void task2()
{
    while (mutex != 0)
    {
        printf("espera task2\n");
        Sleep(100);
    }
    mutexDown();
    x = x * 2;
    printf("thread multi: %d\n", x);
    mutexUp();
}

int main()
{
    thread t1(task1);
    thread t2(task2);
    thread t3(task2);
    thread t4(task1);

    t3.join();
    t2.join();
    printf("mensagem main\n");
    t1.join();
    t4.join();
}