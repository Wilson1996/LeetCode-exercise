/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-15 00:04:15
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-15 08:32:49
*/
/********************************************************
* 题目[简单]：
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:
所有输入只包含小写字母 a-z 。
********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string res;
        int n = strs.size();
        if(n == 0) return "";
        int minLen = 1e9;
        for(auto& s : strs) minLen = min(minLen, s.size());
        for(int i = 0; i < minLen; ++i)
        {
            char c = strs[0][i];
            for(int j = 1; j < n; ++j)
            {
                if(c != strs[j][i]) return res;
            }
            res.push_back(c);
        }
        return res;
    }
};