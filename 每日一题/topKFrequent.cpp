/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-01 17:55:48
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-01 18:31:28
*/
/*********************************************************
* 题目[中等]：
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:
输入: nums = [1], k = 1
输出: [1]
 
提示：
你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for(auto& x : nums)
        {
            ++mp[x];
        }
        for(auto& x : mp)
        {
            if(pq.size() < k)
                pq.push({x.second, x.first});
            else
            {
                if(x.second > pq.top().first)
                {
                    pq.pop();
                    pq.push({x.second, x.first});
                }
            }
        }
        vector<int> res(k);
        int idx = k - 1;
        while(!pq.empty())
        {
            res[idx--] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};