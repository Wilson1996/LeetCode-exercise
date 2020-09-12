/*
* @Author: wilson_t
* @Date:   2020-09-12 11:11:23
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-12 11:16:03
*/
/*********************************************************
* 题目[困难]：
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。

示例 1:
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

示例 2:
输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。

示例 3:
输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。

示例 4:
输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".

示例 5:
输入:
s = "acdcb"
p = "a*c?b"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wildcard-matching
*********************************************************/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        //f[i][j]: s长度为i, p长度为j时是否能匹配
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        f[0][0] = true;
        for(int j = 1; j <= n; ++j) {
            f[0][j] = f[0][j - 1] && (p[j - 1] == '*');
        }
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                // f[i][j] = (f[i-1][j] && p[j-1]=='*') || (f[i][j-1] && p[j-1]=='*')
                // ||(f[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?' || p[j-1] == '*'));
                if (p[j - 1] == '*') {
                    f[i][j] = f[i][j - 1] || f[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                }
            }
        }
        return f[m][n];
    }
};