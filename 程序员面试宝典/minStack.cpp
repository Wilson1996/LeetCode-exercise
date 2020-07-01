/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-18 13:25:21
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-18 14:22:43
*/
/**********************************************************
* 题目[简单]：
请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，
该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。

示例：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
***********************************************************/
#include <iostream>
#include <stack>

using namespace std;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack
{
    //双栈法
    stack<int> SK_data;
    stack<int> SK_min;
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }
    void push(int x)
    {
        SK_data.push(x);
        if(SK_min.empty() || x < SK_min.top()) SK_min.push(x);
        else SK_min.push(SK_min.top());
    }
    void pop()
    {
        SK_data.pop();
        SK_min.pop();
    }
    int top()
    {
        return SK_data.top();
    }
    int getMin()
    {
        return SK_min.top();
    }
};

int main(int argc, char* argv[])
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;  // --> 返回 -3.
    minStack.pop();
    cout << minStack.top() << endl;     // --> 返回 0.
    cout << minStack.getMin() << endl;  // --> 返回 -2.
    return 0;
}

/*
访问越界：
Line 157: Char 17: runtime error: reference binding to misaligned address 0xbebebebebebec0ba for type 'int',
which requires 4 byte alignment (stl_deque.h) 0xbebebebebebec0ba: note: pointer points here
<memory cannot be printed>
*/