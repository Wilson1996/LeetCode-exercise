/*
* @Author: wilson_t
* @Date:   2020-10-26 09:22:38
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-26 09:36:59
*/
/*********************************************************
* 题目[简单]：
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。
以数组形式返回答案。

示例 1：
输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释： 
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。 
对于 nums[3]=2 存在一个比它小的数字：（1）。 
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。

示例 2：
输入：nums = [6,5,4,8]
输出：[2,1,0,3]

示例 3：
输入：nums = [7,7,7,7]
输出：[0,0,0,0]
 
提示：
2 <= nums.length <= 500
0 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number
*********************************************************/
//计数排序
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        int cnt[105] = {0};
        for(int x : nums) cnt[x + 1]++;
        for(int i = 1; i <= 101; ++i) cnt[i] += cnt[i - 1];
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i) {
            res[i] = cnt[nums[i]];
        }
        return res;
    }
};

//快速排序
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        vector<int> res(n);
        res[idx[0]] = 0;
        for(int i = 1; i < n; ++i) {
            if(nums[idx[i]] == nums[idx[i - 1]]) {
                res[idx[i]] = res[idx[i - 1]];
            } else {
                res[idx[i]] = i;
            }
        }
        return res;
    }
};