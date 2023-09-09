/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-06 01:12:00
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-06 16:17:14
*/
/*********************************************************
* 题目[困难]：
给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。

示例:
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //方法一：哈希表
    int longestConsecutive(vector<int>& nums)
    {
        unordered_map<int, bool> mp;
        for(auto& x : nums) mp[x] = true;
        int res = 0;
        auto next = mp.begin();
        auto pre = next;
        for(auto& it : mp)
        {
            if(it.second == false) continue;
            int tmp = 1;
            int value = it.first;
            while((next = mp.find(++value)) != mp.end())
            {
                ++tmp;
                next->second = false;
            }
            value = it.first;
            while((pre = mp.find(--value)) != mp.end())
            {
                ++tmp;
                pre->second = false;
            }
            res = max(res, tmp);
        }
        return res;
    }
};

//方法二：并查集 from leck
class Solution2
{
public:
    unordered_map<int, int> a, b;
    int find(int x)
    {
        return a.count(x) ? a[x] = find(a[x]) : x;
    }
    int longestConsecutive(vector<int>& nums)
    {
        for(auto i : nums)
            a[i] = i + 1;
        int ans = 0;
        for(auto i : nums)
        {
            int y = find(i + 1);
            ans = max(ans, y - i);
        }
        return ans;
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << soluter.longestConsecutive(nums) << endl;
    return 0;
}