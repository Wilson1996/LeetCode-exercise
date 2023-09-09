/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-15 00:19:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-15 20:01:41
*/
/*********************************************************
* 题目[中等]：
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。

说明 :
数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
*********************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    //超出时间限制
    int subarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < n + 1; ++i)
        {
            for(int j = i + 1; j < n + 1; ++j)
            {
                f[i][j] = nums[j - 1] + f[i][j - 1];
                if(f[i][j] == k) ++cnt;
            }
        }
        return cnt;
    }
    //前缀和、哈希表优化
    int subarraySum2(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x : nums)
        {
            pre += x;
            if (mp.find(pre - k) != mp.end()) count += mp[pre - k];
            mp[pre]++;
        }
        return count;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1,1,1,1};
    Solution soluter;
    cout << soluter.subarraySum2(nums, 2) << endl;
    return 0;
}