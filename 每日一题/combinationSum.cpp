/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-27 10:26:33
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-27 10:32:46
*/
/*********************************************************
* 题目[中等]：
给定一个无重复元素的数组 candidates 和一个目标数 target ，
找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 

示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]

示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*********************************************************/
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    int n;
    int target;
public:
    void dfs(int start, vector<int>& candidates, int sum)
    {
        if(sum == target)
        {
            res.push_back(path);
            return;
        }
        if(sum < target)
        {
            for(int i = start; i < n; ++i)
            {
                auto& x = candidates[i];
                if(x + sum > target) continue;
                path.push_back(x);
                dfs(i, candidates, sum + x);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int tar)
    {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        target = tar;
        dfs(0, candidates, 0);
        // for(auto& p : res){
        //     sort(p.begin(), p.end());
        // }
        // sort(res.begin(), res.end());
        // res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};