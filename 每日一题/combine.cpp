/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-29 14:07:07
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-29 18:45:15
*/
/*********************************************************
* 题目[中等]：
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
示例:
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*********************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> result;
public:
    void dfs(vector<int>& paths, int depth, int n, int k)
    {
        if(depth == k)
        {
            result.push_back(paths);
            return;
        }
        int start = paths.empty() ? 1 : paths.back() + 1;
        for(int i = start; i <= n; ++i)
        {
            paths.push_back(i);
            dfs(paths, depth + 1, n,  k);
            paths.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> paths;
        dfs(paths, 0, n, k);
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    vector<vector<int>> result = soluter.combine(4, 2);
    for(auto& line : result)
    {
        for(auto& x : line)
        {
            cout << x << ", ";
        }
        cout << endl;
    }
    return 0;
}