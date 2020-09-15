/*
* @Author: wilson_t
* @Date:   2020-09-15 23:12:36
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-15 23:22:12
*/
/*********************************************************
* 题目[中等]：
在计算机界中，我们总是追求用有限的资源获取最大的收益。
现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。

注意:
给定 0 和 1 的数量都不会超过 100。
给定字符串数组的长度不会超过 600。

示例 1:
输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
输出: 4
解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。

示例 2:
输入: Array = {"10", "0", "1"}, m = 1, n = 1
输出: 2
解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ones-and-zeroes
*********************************************************/
//多重背包问题
int f[605][105][105];
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size(), zeros, ones;
        for(int i = 0; i <= size; ++i)
            for(int j = 0; j <= m; ++j)
                for(int k = 0; k <= n; ++k)
                    f[i][j][k] = 0;
        for(int i = 1; i <= size; ++i) {
            zeros = ones = 0;
            for (char c : strs[i - 1]) {
                if(c == '0') zeros++;
            }
            ones = strs[i - 1].size() - zeros;
            for(int j = 0; j <= m; ++j) {
                for(int k = 0; k <= n; ++k) {
                    if(zeros <= j && ones <= k)
                        f[i][j][k] = max(f[i - 1][j][k], 1 + f[i - 1][j - zeros][k - ones]);
                    else f[i][j][k] = f[i - 1][j][k];
                }
            }
        }
        return f[size][m][n];
    }
};

//滚动数组优化空间复杂度
int f[105][105];
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size(), zeros, ones;
        for(int j = 0; j <= m; ++j) for(int k = 0; k <= n; ++k) f[j][k] = 0;
        for(int i = 1; i <= size; ++i) {
            zeros = ones = 0;
            for (char c : strs[i - 1]) {
                if(c == '0') zeros++;
            }
            ones = strs[i - 1].size() - zeros;
            //从后往前滚动
            for(int j = m; j >= 0; --j) {
                for(int k = n; k >= 0; --k) {
                    if(zeros <= j && ones <= k)
                        f[j][k] = max(f[j][k], 1 + f[j - zeros][k - ones]);
                }
            }
        }
        return f[m][n];
    }
};