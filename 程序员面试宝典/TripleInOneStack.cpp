/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-19 09:13:41
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-19 09:43:57
*/
/**********************************************************
* 题目[简单]：
三合一。描述如何只用一个数组来实现三个栈。你应该实现push(stackNum, value)、
pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。stackNum表示栈下标，value表示压入的值。
构造函数会传入一个stackSize参数，代表每个栈的大小。

示例1:
 输入：
["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
[[1], [0, 1], [0, 2], [0], [0], [0], [0]]
 输出：
[null, null, null, 1, -1, -1, true]
说明：当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素。
**********************************************************/
#include <iostream>

using namespace std;

class TripleInOne
{
private:
    int* data;
    int bottom[3];  //栈底
    int top[3];     //栈顶
    int size;
public:
    TripleInOne(int stackSize): size(stackSize)
    {
        data = new int[stackSize * 3];
        for(int i = 0; i < 3; ++i)
        {
            bottom[i] = top[i] = stackSize * i;
        }
    }
    ~TripleInOne()
    {
        if(data != nullptr)
            delete[] data;
    }
    void push(int stackNum, int value)
    {
        if(!isFull(stackNum))
        {
            data[top[stackNum]] = value;
            ++top[stackNum];
        }
    }

    int pop(int stackNum)
    {
        if(!isEmpty(stackNum))
        {
            --top[stackNum];
            return data[top[stackNum]];
        }
        return -1;
    }

    int peek(int stackNum)
    {
        if(!isEmpty(stackNum))
        {
            return data[top[stackNum] - 1];
        }
        return -1;
    }

    bool isEmpty(int stackNum)
    {
        return top[stackNum] == bottom[stackNum];
    }

    bool isFull(int stackNum)
    {
        return top[stackNum] == (bottom[stackNum] + size);
    }
};

int main(int argc, char* argv[])
{
    TripleInOne triStack(10);
    triStack.push(0, 0);
    triStack.push(1, 2);
    triStack.pop(2);
    triStack.peek(2);
    triStack.push(2, 0);
    cout << triStack.peek(0) << endl;
    cout << triStack.pop(0) << endl;
    cout << triStack.pop(1) << endl;
    return 0;
}