/*
* @Author: wilson_t
* @Date:   2021-03-28 12:21:56
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-03-28 12:22:33
*/
/*
* 题目[中等]：
给定一个长度为 n 的整数数组和一个目标值 target，寻找能够使条件 nums[i] + nums[j] + nums[k] < target 
成立的三元组  i, j, k 个数（0 <= i < j < k < n）。

示例：
输入: nums = [-2,0,1,3], target = 2
输出: 2
解释: 因为一共有两个三元组满足累加和小于 2:
     [-2,0,1]
     [-2,0,3]
进阶：是否能在 O(n2) 的时间复杂度内解决？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-smaller
*/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; ++i) {
            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum < target) {
                    res += (r - l);
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return res;
    }
};