/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-30 16:04:54
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-30 16:19:27
*/
/*********************************************************
* 题目[中等]：
根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再
等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，
你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int sk[30000];
    int top = 0;
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        int n = T.size();
        vector<int> right(n, 0);
        for(int i = n - 1; i >= 0; --i)
        {
            while(!(top == 0) && T[sk[top - 1]] <= T[i])
                --top;
            if(!(top == 0)) right[i] = sk[top - 1] - i;
            sk[top++] = i;
        }
        return right;
    }
    vector<int> dailyTemperatures2(vector<int>& T)
    {
        int n = T.size();
        vector<int> right(n, 0);
        stack<int> sk;
        for(int i = n - 1; i >= 0; --i)
        {
            while(!sk.empty() && T[sk.top()] <= T[i])
                sk.pop();
            if(!sk.empty()) right[i] = sk.top() - i;
            // right[i] = sk.empty() ? 0 : sk.top() - i;
            sk.push(i);
        }
        return right;
    }
};