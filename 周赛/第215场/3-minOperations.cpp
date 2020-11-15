/*
* @Author: wilson_t
* @Date:   2020-11-15 21:24:12
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-15 21:24:50
*/
/**
* 题目[中等]：
给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，
然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。
如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。

示例 1：
输入：nums = [1,1,4,2,3], x = 5
输出：2
解释：最佳解决方案是移除后两个元素，将 x 减到 0 。

示例 2：
输入：nums = [5,6,7,8,9], x = 4
输出：-1

示例 3：
输入：nums = [3,2,20,1,1,3], x = 10
输出：5
解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
 
提示：
1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero
 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l = 0, r = 0, n = nums.size(), mxLen = -1, target = accumulate(nums.begin(), nums.end(), 0) - x;
        if(target < 0) return -1;
        int sum = 0;
        while(r < n) {
            if(sum < target) {
                sum += nums[r];
                ++r;
            } else if(sum > target) {
                sum -= nums[l];
                ++l;
            } else {
                mxLen = max(mxLen, r - l);
                sum -= nums[l];
                ++l;
            }
        }
        if(sum == target) {
            mxLen = max(mxLen, r - l);
        }
        return mxLen == -1 ? -1 : n - mxLen;
    }
};