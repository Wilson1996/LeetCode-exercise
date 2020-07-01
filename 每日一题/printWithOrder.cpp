/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-14 21:24:12
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-14 21:41:58
*/
#include <iostream>
#include <functional>
#include <semaphore.h>
#include <thread>

using namespace std;

class Foo
{
protected:
    sem_t firstJobDone;
    sem_t secondJobDone;
public:

    Foo()
    {
        // sem_init(&firstJobDone, 0, 0);
        // sem_init(&secondJobDone, 0, 0);
    }

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first".
        printFirst();
        // sem_post(&firstJobDone);
    }

    void second(function<void()> printSecond)
    {
        // sem_wait(&firstJobDone);
        // printSecond() outputs "second".
        printSecond();
        // sem_post(&secondJobDone);
    }

    void third(function<void()> printThird)
    {
        // sem_wait(&secondJobDone);
        // printThird() outputs "third".
        printThird();
    }
};

void one() { cout << "one" << endl; }
void two() { cout << "two" << endl; }
void three() { cout << "three" << endl; }

int main(int argc, char* argv[])
{
    Foo foo;
    // thread A(foo.first(one));
    foo.first(one);
    foo.second(two);
    foo.third(three);
    return 0;
}