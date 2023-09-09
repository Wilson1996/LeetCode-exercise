/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-09 01:08:06
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-09 20:35:45
*/
/*********************************************************
* 题目[中等]：
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，
1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。
请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

提示：
0 <= num < 231
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<int, int> memo;
public:
    int dfs(long long cur)
    {
        if(cur < 10) return 1;
        if(memo.find(cur) != memo.end())
        {
        	// cout << "yes" << endl;
            return memo[cur];
        }
        int res = 0;
        int res1 = dfs(cur / 10);
        res += (memo[cur / 10] = res1);
        int tmp = cur % 100;
        if(tmp >= 10 && tmp <= 25)
        {
            int res2 = dfs(cur / 100);
            res += (memo[cur / 100] = res2);
        }
        return res;
    }
    int translateNum(long long num)
    {
        memo.clear();
        int res = dfs(num);
        return res;
    }
};

// class Solution
// {
//     int res;
// public:
//     void dfs(int cur)
//     {
//         if(cur == 0)
//         {
//             ++res;
//             return;
//         }
//         dfs(cur / 10);
//         int tmp = cur % 100;
//         if(tmp >= 10 && tmp <= 25)
//         {
//             dfs(cur / 100);
//         }
//     }
//     int translateNum(int num)
//     {
//         res = 0;
//         dfs(num);
//         return res;
//     }
// };
int main(int argc, char* argv[])
{
    Solution soluter;
    long long num = 12258ll;
    cout << soluter.translateNum(num) << endl;
    return 0;
}