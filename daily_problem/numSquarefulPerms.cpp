/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-08 20:21:00
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-08 20:54:39
*/
/*********************************************************
* 题目[困难]：
给定一个非负整数数组 A，如果该数组每对相邻元素之和是一个完全平方数，则称这一数组为正方形数组。
返回 A 的正方形排列的数目。两个排列 A1 和 A2 不同的充要条件是存在某个索引 i，使得 A1[i] != A2[i]。
 
示例 1：
输入：[1,17,8]
输出：2
解释：
[1,8,17] 和 [17,8,1] 都是有效的排列。

示例 2：
输入：[2,2,2]
输出：1
 
提示：
1 <= A.length <= 12
0 <= A[i] <= 1e9
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int res;
    unordered_map<int, int> G;
    int n;
public:
    bool isSquare(int x)
    {
        int tmp = (sqrt(x) + 0.5);
        return tmp * tmp == x;
    }
    void dfs(int cur, int depth)
    {
        if(depth == n)
        {
            ++res;
            return;
        }
        --G[cur];
        for(auto& x : G)
        {
            if(x.second > 0 && isSquare(cur + x.first))
                dfs(x.first, depth + 1);
        }
        ++G[cur];
    }
    int numSquarefulPerms(vector<int>& A)
    {
        res = 0;
        n = A.size();
        for(auto& x : A)
        {
            ++G[x];
        }
        for(auto& x : G)
        {
            if(x.second > 0)
                dfs(x.first, 1);
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    // vector<int> A = {1,17,8};
    vector<int> A = {2, 2, 2};
    cout << soluter.numSquarefulPerms(A) << endl;
    return 0;
}