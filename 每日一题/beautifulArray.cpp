/*
* @Author: wilson_t
* @Date:   2020-10-19 15:02:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-19 15:03:55
*/
/*
* 题目[中等]:
对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：
对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。
那么数组 A 是漂亮数组。
给定 N，返回任意漂亮数组 A（保证存在一个）

示例 1：
输入：4
输出：[2,1,4,3]

示例 2：
输入：5
输出：[3,1,2,5,4]
 
提示：
1 <= N <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/beautiful-array
*/
class Solution {
public:
    vector<int> beautifulArray(int N) {
        if(N == 1) return {1};
        int l = N / 2, r = (N + 1) / 2;
        vector<int> left = beautifulArray(l);
        vector<int> right = beautifulArray(r);
        vector<int> res;
        for(const int& x : left) res.emplace_back(x * 2);
        for(const int& x : right) res.emplace_back(x * 2 - 1);
        return res;
    }
};