/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-20 17:39:52
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-20 19:13:01
*/
/**********************************************************
* 题目[中等]：
栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。最多只能使用
一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。
该栈支持如下操作：push、pop、peek 和 isEmpty。当栈为空时，peek 返回 -1。

示例1:
 输入：
["SortedStack", "push", "push", "peek", "pop", "peek"]
[[], [1], [2], [], [], []]
 输出：
[null,null,null,1,null,2]

说明:
栈中的元素数目在[0, 5000]范围内。

* 方法：
1、一般使用两个栈来回倒数据
2、惰性更新思想：连续多次push时，需要多次把元素在两个栈中传递。想象这样一个极端情况：
连续n次push相同或相近元素，需要来回操作2n x i次，其中i为每次移动的元素数量。
实际上，我们只需要移动2 x i次：先把i个元素移到辅助栈，再把n个元素放入栈，最后将辅助栈中元素移回来即可。
此为惰性更新，惰性更新策略运用很广泛，比如著名的U&F算法、区间树等，就使用了此策略。
**********************************************************/
#include <iostream>
#include <stack>

using namespace std;

//方法一
namespace Design_1
{
class SortedStack
{
private:
    stack<int> data;
public:
    SortedStack()
    {
    }
    //normal way
    void push(int val)
    {
        stack<int> temp;
        while(!data.empty() && data.top() < val)
        {
            temp.push(data.top());
            data.pop();
        }
        data.push(val);
        while(!temp.empty())
        {
            data.push(temp.top());
            temp.pop();
        }
    }

    void pop()
    {
        if(!isEmpty())
        {
            data.pop();
        }
    }

    int peek()
    {
        if(!isEmpty())
        {
            return data.top();
        }
        return -1;
    }

    bool isEmpty()
    {
        return data.empty();
    }
};
}

//方法二：
namespace Design_2
{
class SortedStack
{
private:
    //原始栈
    stack<int> sk;
    //辅助栈
    stack<int> tmp;
public:
    SortedStack()
    {
    }

    void push(int val)
    {
        int max = sk.empty() ? INT_MAX : sk.top();
        int min = tmp.empty() ? INT_MIN : tmp.top();
        //比较原始栈与辅助栈栈顶值，使其满足 辅助栈 <= val <= 原始栈
        while(true)
        {
            if(val > max)
            {
                tmp.push(sk.top());
                sk.pop();
                max = sk.empty() ? INT_MAX : sk.top();
            }
            else if(val < min)
            {
                sk.push(tmp.top());
                tmp.pop();
                min = tmp.empty() ? INT_MIN : tmp.top();
            }
            else
            {
                sk.push(val);
                break;
            }
        }
    }

    void pop()
    {
        //将辅助栈元素push回原始栈
        while (!tmp.empty())
        {
            sk.push(tmp.top());
            tmp.pop();
        }
        if (!sk.empty())
            sk.pop();
    }

    int peek()
    {
        //将辅助栈元素push回原始栈
        while (!tmp.empty())
        {
            sk.push(tmp.top());
            tmp.pop();
        }
        return sk.empty() ? -1 : sk.top();
    }

    bool isEmpty()
    {
        return sk.empty() && tmp.empty();
    }
};
}
