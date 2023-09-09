/*
* @Author: wilson_t
* @Date:   2020-12-04 10:41:36
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-04 10:52:50
*/
/*
给你一个整数数组 nums 和一个正整数 k ，返回长度为 k 且最具 竞争力 的 nums 子序列。
数组的子序列是从数组中删除一些元素（可能不删除元素）得到的序列。
在子序列 a 和子序列 b 第一个不相同的位置上，如果 a 中的数字小于 b 中对应的数字，那么我们称子序列 a 比子序列 b（相同长度下）更具 竞争力 。
例如，[1,3,4] 比 [1,3,5] 更具竞争力，在第一个不相同的位置，也就是最后一个位置上， 4 小于 5 。

示例 1：
输入：nums = [3,5,2,6], k = 2
输出：[2,6]
解释：在所有可能的子序列集合 {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]} 中，[2,6] 最具竞争力。

示例 2：
输入：nums = [2,4,3,3,5,4,9,6], k = 4
输出：[2,3,3,4]
 
提示：
1 <= nums.length <= 105
0 <= nums[i] <= 109
1 <= k <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-most-competitive-subsequence
*/
//最小队列
class Solution {
private:
    queue<int> A;
    deque<int> B;
public:
    void push(vector<int>& nums, int idx) {
        A.push(idx);
        while(!B.empty() && nums[idx] < nums[B.back()]) {
            B.pop_back();
        }
        B.push_back(idx);
    }
    int min() {
        return B.front();
    }
    int pop() {
        int idx = A.front();
        A.pop();
        if(idx == B.front()) B.pop_front();
        return idx;
    }
    int size() {
        return A.size();
    }

    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        A = queue<int>();
        B.clear();
        vector<int> res;
        int i = 0;
        while(k > 0 && i < n) {
            int j = i;
            for( ; j <= n - k; ++j) {
                push(nums, j);
            }
            int idx = min();
            while(pop() != idx) {}
            res.emplace_back(nums[idx]);
            i = j;
            --k;
        }
        return res;
    }
};


//单调栈
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> sk;
        int n = nums.size(), remain = n - k;
        for(int x : nums) {
            while(!sk.empty() && remain > 0 && sk.back() > x) {
                sk.pop_back();
                --remain;
            }
            sk.push_back(x);
        }
        while(sk.size() > k) {
            sk.pop_back();
        }
        return sk;
    }
};