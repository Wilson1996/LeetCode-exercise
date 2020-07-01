/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-02 00:29:55
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-02 00:44:41
*/
/*********************************************************
* 题目[中等]：
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

示例 1：
输入: n = 3
输出: 6

示例 2：
输入: n = 9
输出: 45

限制：
1 <= n <= 10000
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Dummy
{
public:
    static int sum;
    static int N;
    Dummy()
    {
        sum += N;
        ++N;
    }
    static int getSum() {return sum;}
};
int Dummy::sum = 0;
int Dummy::N = 1;
class Solution
{
public:
    int sumNums(int n)
    {
        Dummy::sum = 0;
        Dummy::N = 1;
        Dummy* d = new Dummy[n];
        int res = Dummy::getSum();
        delete[] d;
        return res;
    }
    //方法二
    int sumNums2(int n)
    {
        int res = 0;
        n && (res = n + sumNums2(n-1));
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    cout << soluter.sumNums2(100) << endl;
    return 0;
}