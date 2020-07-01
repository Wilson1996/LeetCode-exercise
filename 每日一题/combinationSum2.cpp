/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-27 14:37:16
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-27 14:37:58
*/
/*********************************************************
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。

说明：
所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
*********************************************************/
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> candidates;
    int n;
    int target;
public:
    void dfs(int start, int sum)
    {
        if(sum == target)
        {
            res.push_back(path);
            return;
        }
        if(sum < target)
        {
            // unordered_set<int> ms;
            for(int i = start; i < n; ++i)
            {
                auto& x = candidates[i];
                if(x + sum > target) continue;
                if(i > start && candidates[i] == candidates[i - 1]) continue;
                path.push_back(x);
                dfs(i + 1, sum + x);
                path.pop_back();
                // ms.insert(x);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int tar)
    {
        candidates = cand;
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        target = tar;
        dfs(0, 0);
        // sort(res.begin(), res.end());
        // res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};