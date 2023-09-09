/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-12 00:04:34
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-12 14:37:35
*/
/*********************************************************
* 题目[中等]：
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例：
给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 2; )
        {
            int p1 = i + 1, p2 = n - 1;
            int tmp = -nums[i];
            while(p1 < p2)
            {
                if(nums[p1] + nums[p2] == tmp)
                {
                    res.push_back({nums[i], nums[p1], nums[p2]});
                    int pre = nums[p1];
                    while(p1 < p2 && nums[p1] == pre)
                        ++p1;
                }
                else if(nums[p1] + nums[p2] > tmp)
                {
                    int pre = nums[p2];
                    while(p2 > p1 && nums[p2] == pre)
                        --p2;
                }
                else
                {
                    int pre = nums[p1];
                    while(p1 < p2 && nums[p1] == pre)
                        ++p1;
                }
            }
            int pre = nums[i];
            while(i < n-2 && nums[i] == pre) ++i;
        }
        return res;
    }
    //方法二
    vector<vector<int>> threeSum2(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        unordered_map<int, int> mp;
        for(auto& x : nums) ++mp[x];
        for(auto& x : mp)
        {
            if(x.second > 1 && mp.count(-x.first * 2) != 0)
            {
                res.push_back({x.first, x.first, -x.first * 2});
            }
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        n = nums.size();
        for(int i = 1; i < n - 1; ++i)
        {
            int p1 = 0, p2 = n - 1;
            int tmp = -nums[i];
            while(p1 < i && p2 > i)
            {
                if(nums[p1] + nums[p2] == tmp)
                {
                    res.push_back({nums[p1], nums[i], nums[p2]});
                    ++p1;
                }
                else if(nums[p1] + nums[p2] > tmp)
                {
                    --p2;
                }
                else
                {
                    ++p1;
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1,1,1};
    Solution soluter;
    vector<vector<int>> res = soluter.threeSum(nums);
    for(auto& x : res)
    {
        cout << x[0] << ", " << x[1] << ", " << x[2] << endl;
    }
    return 0;
}