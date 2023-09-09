/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-01 19:32:04
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-01 20:27:06
*/
/*********************************************************
* 题目[中等]：
给一非空的单词列表，返回前 k 个出现次数最多的单词。
返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

示例 1：
输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。
 
示例 2：
输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
输出: ["the", "is", "sunny", "day"]
解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。

注意：
假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
输入的单词均由小写字母组成。
 
扩展练习：
尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

// using PIS = pair<int, string>;
using PSI = pair<string, int>;
struct PSICmp
{
    bool operator()(const PSI& a, const PSI& b)
    {
        if(a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        PSICmp psicmp;
        unordered_map<string, int> mp;
        priority_queue<PSI, vector<PSI>, PSICmp> pq;
        for(auto& w : words) ++mp[w];
        for(auto& x : mp)
        {
            if(pq.size() < k)
                pq.push(x);
            else
            {
                if(psicmp(x, pq.top()))
                {
                    pq.pop();
                    pq.push(x);
                }
            }
        }
        vector<string> res(k);
        int idx = k - 1;
        while(!pq.empty())
        {
            res[idx--] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> res = soluter.topKFrequent(words, 2);
    for(auto& x : res)
    {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}