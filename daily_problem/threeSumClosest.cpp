/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-24 09:04:37
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-24 11:12:11
*/
/*********************************************************
* 题目[中等]：
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

示例：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。

提示：
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l, r;
        int dist = 1e9;
        int res;
        for(int i = 0; i < n - 2; ++i)
        {
            l = i + 1, r = n - 1;
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target)
                {
                    return target;
                }
                else if(sum < target)
                {
                    if(abs(sum - target) < dist)
                    {
                        dist = abs(sum - target);
                        res = sum;
                    }
                    ++l;
                }
                else
                {
                    if(abs(sum - target) < dist)
                    {
                        dist = abs(sum - target);
                        res = sum;
                    }
                    --r;
                }
            }
        }
        return res;
    }
};