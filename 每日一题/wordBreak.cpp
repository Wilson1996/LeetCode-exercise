/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-25 09:55:54
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-25 11:02:46
*/
/*********************************************************
* 题目[中等]：
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，
判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：
拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。

示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。

示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<bool> vis;
    vector<bool> dp;
    string s;
    vector<string> wordDict;
public:
    bool getdp(int i)
    {
        if(i <= 0) return true;
        if(vis[i]) return dp[i];
        bool res = false;
        for(auto& w : wordDict)
        {
            if(w.size() > i) continue;
            if(s.substr(i - w.size(), w.size()) != w) continue;
            res = res || getdp(i - w.size());
        }
        dp[i] = res;
        vis[i] = true;
        return res;
    }
    bool wordBreak(string _s, vector<string>& _wordDict)
    {
        s = _s;
        int n = s.size();
        wordDict = _wordDict;
        vis = vector<bool>(n + 1, false);
        dp = vector<bool>(n + 1, false);
        return getdp(n);
    }
};

class Solution2
{
    vector<bool> vis;
    vector<bool> dp;
public:
	//用引用传参要更快
    bool getdp(int i, string& s, vector<string>& wordDict)
    {
        if(i <= 0) return true;
        if(vis[i]) return dp[i];
        bool res = false;
        for(auto& w : wordDict)
        {
            if(w.size() > i) continue;
            if(s.substr(i - w.size(), w.size()) != w) continue;
            res = res || getdp(i - w.size(), s, wordDict);
        }
        dp[i] = res;
        vis[i] = true;
        return res;
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n = s.size();
        vis = vector<bool>(n + 1, false);
        dp = vector<bool>(n + 1, false);
        return getdp(n, s, wordDict);
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    string s = "catsandog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    soluter.wordBreak(s, wordDict) ? cout << "true" << endl : cout << "false" << endl;
    return 0;
}