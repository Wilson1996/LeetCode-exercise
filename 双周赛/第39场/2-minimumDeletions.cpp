/*
* @Author: wilson_t
* @Date:   2020-11-15 20:58:04
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-15 20:59:58
*/
/**
* 题目[中等]：
给你一个字符串 s ，它仅包含字符 'a' 和 'b'​​​​ 。
你可以删除 s 中任意数目的字符，使得 s 平衡 。我们称 s 平衡的 当不存在下标对 (i,j) 满足 i < j 且 s[i] = 'b' 同时 s[j]= 'a' 。
请你返回使 s 平衡 的 最少 删除次数。
 
示例 1：
输入：s = "aababbab"
输出：2
解释：你可以选择以下任意一种方案：
下标从 0 开始，删除第 2 和第 6 个字符（"aababbab" -> "aaabbb"），
下标从 0 开始，删除第 3 和第 6 个字符（"aababbab" -> "aabbbb"）。

示例 2：
输入：s = "bbaaaaabb"
输出：2
解释：唯一的最优解是删除最前面两个字符。

提示：
1 <= s.length <= 105
s[i] 要么是 'a' 要么是 'b'​ 。​

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-deletions-to-make-string-balanced
 */
int f[100005][2];
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        f[0][0] = s[0] == 'a' ? 1 : 0;
        f[0][1] = s[0] == 'b' ? 1 : 0;
        for(int i = 1; i < n; ++i) {
            if(s[i] == 'a') {
                f[i][0] = f[i - 1][0] + 1;
                f[i][1] = f[i - 1][1];
            } else {
                f[i][0] = f[i - 1][0];
                f[i][1] = max(f[i - 1][1], f[i - 1][0]) + 1;
            }
        }
        return n - max(f[n - 1][0], f[n - 1][1]);
    }
};
