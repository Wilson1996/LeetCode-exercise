/*
* @Author: wilson_t
* @Date:   2021-03-08 09:55:25
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-03-08 09:56:11
*/
/*
* 题目[困难]：
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
返回符合要求的 最少分割次数 。
 
示例 1：
输入：s = "aab"
输出：1
解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

示例 2：
输入：s = "a"
输出：0

示例 3：
输入：s = "ab"
输出：1

提示：
1 <= s.length <= 2000
s 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning-ii
 */
const int maxn = 2005;
const int INF = INT_MAX / 2;
vector<int> pre[maxn];
int f[maxn];

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        for(int i = 0; i <= n; ++i) {
            pre[i].resize(0);
            f[i] = INF;
        }
        for(int i = 0; i < n; ++i) {
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                pre[r].emplace_back(l);
                --l;
                ++r;
            }
            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                pre[r].emplace_back(l);
                --l;
                ++r;
            }
        }
        f[0] = -1;
        for(int i = 0; i < n; ++i) {
            for(int j : pre[i]) {
                f[i + 1] = min(f[i + 1], f[j] + 1);
            }
        }
        return f[n];
    }
};