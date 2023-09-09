/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-25 09:36:27
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-25 13:15:39
*/
/*********************************************************
* 题目[中等]：
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*********************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<int>& nums, vector<int>& seq, vector<bool>& visit, vector<vector<int>>& result)
    {
        if(seq.size() == nums.size())
        {
            result.push_back(seq);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(!visit[i])
            {
                seq.push_back(nums[i]);
                visit[i] = true;
                dfs(nums, seq, visit, result);
                seq.pop_back();
                visit[i] = false;
            }
        }
    }
    void backtrack(vector<vector<int>>& result, vector<int>& nums, int first)
    {
        if(first == nums.size())
        {
            result.emplace_back(nums);
            return;
        }
        for(int i = first; i < nums.size(); ++i)
        {
            swap(nums[i], nums[first]);
            backtrack(result, nums, first + 1);
            swap(nums[i], nums[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        // backtrack(result, nums, 0);
        vector<int> seq;
        vector<bool> visit(nums.size(), false);
        dfs(nums, seq, visit, result);
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1, 2, 3};
    Solution soluter;
    vector<vector<int>> result = soluter.permute(nums);
    cout << "nums: " << result.size() << endl;
    for(auto& seq : result)
    {
        for(auto& num : seq)
        {
            cout << num << ", ";
        }
        cout << endl;
    }
}