/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-19 09:08:51
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-19 21:56:10
*/
/****************************************************************
* 题目[简单]：
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:
输入: "aba"
输出: True

示例 2:
输入: "abca"
输出: True
解释: 你可以删除c字符。

注意:
字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
****************************************************************/
class Solution
{
public:
    bool check(const string& s, int l, int r)
    {
        while(l < r && s[l] == s[r])
        {
            ++l;
            --r;
        }
        return l >= r;
    }
    bool validPalindrome(string s)
    {
        int n = s.size();
        int tmp = 0;
        int i = 0, j = n - 1;
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return check(s, i, j - 1) || check(s, i + 1, j);
            }
            ++i;
            --j;
        }
        return true;
    }
};