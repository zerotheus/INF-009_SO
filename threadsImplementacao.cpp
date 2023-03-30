#include <string.h>
#include <thread>
#include <iostream>

using namespace std;

int x = 2;

void task1(std::string msg)
{
    x = x + 1;
    printf("thread soma: %d\n", x);
}

void task2(std::string msg)
{
    x = x * 2;
    printf("thread multi: %d\n", x);
}

int main()
{
    thread t1(task1, "hello thread\n");
    thread t2(task2, "hello thread\n");
    thread t3(task2, "hello thread\n");
    thread t4(task1, "hello thread\n");

    t3.join();
    t2.join();
    printf("mensagem main\n");
    t1.join();
    t4.join();
}