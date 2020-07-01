/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-02 00:43:12
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-02 18:20:54
*/
/*********************************************************
* 题目[中等]：
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*********************************************************/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution
{
public:
    static int lengthOfLongestSubstring(string s)
    {
        int hash_ch[256] = {0};
        int res = 0;
        int pl = 0, pr = 0;
        while(pr < s.length())
        {
            while(pr < s.length() && 0 == hash_ch[s[pr]])
            {
                ++hash_ch[s[pr]];
                ++pr;
            }
            char mark = s[pr];
            cout << mark << endl;
            if(pr - pl > res)	res = pr - pl;
            while(pl < pr && s[pl] != mark)
            {
            	--hash_ch[s[pl]];
                ++pl;
            }
            --hash_ch[s[pl]];
            ++pl;
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    string s = "abcabcbb";
    cout << Solution::lengthOfLongestSubstring(s) << endl;
    cout << "---------" << endl;
    return 0;
}