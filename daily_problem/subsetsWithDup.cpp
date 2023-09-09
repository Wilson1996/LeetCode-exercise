/*
* @Author: wilson_t
* @Date:   2020-10-10 14:51:17
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-10 15:11:31
*/
/*********************************************************
* 题目[中等]：
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。

示例:
输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
*********************************************************/
#include<bits/stdc++.h>
#include "debug.h"
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    int n;
public:
    void dfs(vector<int>& nums, int cur) {
        res.emplace_back(path);
        for(int i = cur; i < n; ++i) {
            if(i > cur && nums[i] == nums[i - 1]) continue;
            path.emplace_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        n = nums.size();
        dfs(nums, 0);
        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 2, 2};
    Debug() << Solution().subsetsWithDup(nums) << "\n";

    return 0;
}