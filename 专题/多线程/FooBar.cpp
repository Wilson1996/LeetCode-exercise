/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-30 14:13:12
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-30 14:16:56
*/
/*********************************************************
* 题目[中等]：
我们提供一个类：
class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }
  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
两个不同的线程将会共用一个 FooBar 实例。其中一个线程将会调用 foo() 方法，另一个线程将会调用 bar() 方法。
请设计修改程序，以确保 "foobar" 被输出 n 次。

示例 1:
输入: n = 1
输出: "foobar"
解释: 这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。

示例 2:
输入: n = 2
输出: "foobarfoobar"
解释: "foobar" 将被输出两次。
*********************************************************/
#include <bits/stdc++.h>
#include <semaphore.h>
using namespace std;

class FooBar
{
private:
    int n;
    sem_t fooJobDone;
    sem_t barJobDone;
public:
    FooBar(int n)
    {
        this->n = n;
        sem_init(&fooJobDone, 0, 0);
        sem_init(&barJobDone, 0, 0);
        sem_post(&barJobDone);
    }

    void foo(function<void()> printFoo)
    {
        for (int i = 0; i < n; i++)
        {
            // printFoo() outputs "foo". Do not change or remove this line.
            sem_wait(&barJobDone);
            printFoo();
            sem_post(&fooJobDone);
        }
    }

    void bar(function<void()> printBar)
    {
        for (int i = 0; i < n; i++)
        {
            // printBar() outputs "bar". Do not change or remove this line.
            sem_wait(&fooJobDone);
            printBar();
            sem_post(&barJobDone);
        }
    }
};