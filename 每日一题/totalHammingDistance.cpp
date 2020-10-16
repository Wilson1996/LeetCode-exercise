/*
* @Author: wilson_t
* @Date:   2020-10-15 15:25:43
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-15 15:26:31
*/
/**
* 题目[中等]：
两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
计算一个数组中，任意两个数之间汉明距离的总和。

示例:
输入: 4, 14, 2
输出: 6
解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

注意:
数组中元素的范围为从 0到 10^9。
数组的长度不超过 10^4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/total-hamming-distance
*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), res = 0;
        int cnt[32] = {0};
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 32; ++j) {
                if(nums[i] & (1 << j)) cnt[j]++;
            }
        }
        for(int i = 0; i < 32; ++i) {
            res += cnt[i] * (n - cnt[i]);
        }
        return res;
    }
};