/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-21 18:26:39
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-21 23:17:14
*/
/*********************************************************
* 题目[中等]：
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
*********************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	//方法一和方法二在面试中会问到
    //方法一：动态规划 O(n^2)
    string longestPalindrome(string s)
    {
        int maxLen = 1;
        int start = 0;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i)
            dp[i][i] = true;
        //dp[i][j] = dp[i+1][j-1]    if s[i]==s[j] and j-1-(i+1) >=1
        for(int j = 1; j < n; ++j)
        {
            for(int i = 0; i < j; ++i)
            {
                if(s[i] != s[j])
                    dp[i][j] = false;
                else
                {
                    if(j - i < 3) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                    if(j - i + 1 > maxLen)
                    {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
    //方法二：中心扩散 O(n^2) 性能比动态规划好
    vector<int> expand(const string& s, int l, int r)
    {
        int n = s.length();
        while(l >= 0 && r < n && s[l] == s[r])
        {
            --l;
            ++r;
        }
        // return vector<int> {l + 1, r - 1};
        return {l + 1, r - 1};
    }
    string longestPalindrome_2(string s)
    {
        int maxLen = 1;
        int start = 0;
        int n = s.length();
        for(int i = 0; i < n; ++i)
        {
            vector<int> p1 = expand(s, i, i);
            vector<int> p2 = expand(s, i, i + 1);
            if(p1[1] - p1[0] + 1 > maxLen)
            {
                maxLen = p1[1] - p1[0] + 1;
                start = p1[0];
            }
            if(p2[1] - p2[0] + 1 > maxLen)
            {
                maxLen = p2[1] - p2[0] + 1;
                start = p2[0];
            }
        }
        return s.substr(start, maxLen);
    }
    //方法三：Manacher算法 O(n)
};

int main(int argc, char* argv[])
{
    Solution soluter;
    cout << soluter.longestPalindrome_2("babad") << endl;
    return 0;
}