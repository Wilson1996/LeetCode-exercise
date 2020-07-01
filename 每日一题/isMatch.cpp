/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-20 13:08:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-20 13:53:17
*/
/*********************************************************
* 题目[困难]：
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

示例 1:
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

示例 2:
输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素,
在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

示例 3:
输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

示例 4:
输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

示例 5:
输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
*********************************************************/
class Solution
{
public:
    bool isAlpha(char ch)
    {
        return ch >= 'a' && ch <= 'z';
    }
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        int ps = 0, pp = 0;
        int state = 0;
        for (int i = 0; i < m; ++i)
        {
            switch(state)
            {
                case 0: //a-z
                {
                    if(isAlpha(p[i]))
                    {
                        if(p[i] != s[ps]) return false;
                        ++ps;
                    }
                    else if(p[i] == '.')
                    {
                        state = 1;
                        ++ps;
                    }
                    else
                    {
                        state = 2;
                        if(ps > 0 && s[ps - 1] != s[ps]) return false;
                        ++ps;
                    }
                }
                break;
                case 1:	//.
                {
                    if(isAlpha(p[i]))
                    {
                        if(p[i] != s[ps]) return false;
                        state = 1;
                    }
                    else if(p[i] == '.')
                    {
                        ++ps;
                    }
                    else
                    {
                        return true;
                    }
                }
                break;
                case 2:	//*
                {
                    if(isAlpha(p[i]))
                    {
                        if(p[i] != s[ps])
                        {
                            if(ps > 0 && s[ps - 1] != s[ps]) return false;
                            else ++ps;
                        }
                        else
                        {
                            state = 0;
                            ++ps;
                        }
                    }
                    else if(p[i] == '.')
                    {
                        state = 1;
                        ++ps;
                    }
                    else
                    {
                        ++ps;
                    }
                }
                break;
            }
            if(ps >= n) return true;
        }
        return true;
    }
};