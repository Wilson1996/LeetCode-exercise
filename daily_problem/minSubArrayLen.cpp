/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-28 00:03:44
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-28 00:31:20
*/
/*********************************************************
* 题目[中等]：
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的
长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

示例: 
输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。

进阶:
如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(nlogn) 时间复杂度的解法。
*********************************************************/
class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int n = nums.size();
        if(n == 0) return 0;
        int l = 0, r = -1;
        int sum = 0;
        int len = 1e9;
        while(r < n)
        {
            if(sum >= s)
            {
                len = min(r - l + 1, len);
                sum -= nums[l];
                ++l;
            }
            else
            {
                ++r;
                if(r >= n) break;
                sum += nums[r];
            }
        }
        if(sum >= s) len = min(r - l + 1, len);
        return len == 1e9 ? 0 : len;
    }
};