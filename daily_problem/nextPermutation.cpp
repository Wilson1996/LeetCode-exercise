/*
* @Author: wilson_t
* @Date:   2020-08-27 22:31:17
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-27 22:32:06
*/
/*********************************************************
* 题目[中等]：
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。
以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
*********************************************************/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        for(; i > 0; --i) {
            if(nums[i] > nums[i - 1]) {
                break;
            }
        }
        if(i == 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        int cand = i;
        for(int j = i + 1; j < n; ++j) {
            if(nums[j] > nums[i - 1] && nums[j] <= nums[cand]) {
                cand = j;
            }
        }
        swap(nums[i - 1], nums[cand]);
        reverse(nums.begin() + i, nums.end());
    }
};