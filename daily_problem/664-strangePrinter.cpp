/*
* 题目[困难]：
有台奇怪的打印机有以下两个特殊要求：
打印机每次只能打印由 同一个字符 组成的序列。
每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。
给你一个字符串 s ，你的任务是计算这个打印机打印它需要的最少打印次数。
 
示例 1：
输入：s = "aaabbb"
输出：2
解释：首先打印 "aaa" 然后打印 "bbb"。

示例 2：
输入：s = "aba"
输出：2
解释：首先打印 "aaa" 然后在第二个位置打印 "b" 覆盖掉原来的字符 'a'。
 
提示：
1 <= s.length <= 100
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/strange-printer
 */
//区间dp
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        //f[i][j]: 打印完成区间[i, j]时的最小操作次数
        vector<vector<int> > f(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n; ++i) f[i][i] = 1;
        for(int len = 2; len <= n; ++len) {
            for(int l = 0; l < n - len + 1; ++l) {
                int r = l + len - 1;
                if(s[l] == s[r]) f[l][r] = f[l][r - 1];
                else {
                    for(int k = l; k < r; ++k) {
                        f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
                    }
                }
            }
        }

        return f[0][n - 1];
    }
};