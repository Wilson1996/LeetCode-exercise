/*
* @Author: wilson_t
* @Date:   2020-10-03 20:24:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-05 11:10:46
*/
/*
给你一个整数 n，你需要重复执行多次下述操作将其转换为 0 ：
翻转 n 的二进制表示中最右侧位（第 0 位）。
如果第 (i-1) 位为 1 且从第 (i-2) 位到第 0 位都为 0，则翻转 n 的二进制表示中的第 i 位。
返回将 n 转换为 0 的最小操作次数。

示例 1：
输入：n = 0
输出：0

示例 2：
输入：n = 3
输出：2
解释：3 的二进制表示为 "11"
"11" -> "01" ，执行的是第 2 种操作，因为第 0 位为 1 。
"01" -> "00" ，执行的是第 1 种操作。

示例 3：
输入：n = 6
输出：4
解释：6 的二进制表示为 "110".
"110" -> "010" ，执行的是第 2 种操作，因为第 1 位为 1 ，第 0 到 0 位为 0 。
"010" -> "011" ，执行的是第 1 种操作。
"011" -> "001" ，执行的是第 2 种操作，因为第 0 位为 1 。
"001" -> "000" ，执行的是第 1 种操作。

示例 4：
输入：n = 9
输出：14

示例 5：
输入：n = 333
输出：393

提示：
0 <= n <= 109
*/

//from wifiii
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res  = 0;
        while(n) {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};

//from lucifer1004
class Solution {
    int f(int n) {
        if (n <= 1)
            return n;
        int t = 32 - __builtin_clz(n) - 1;
        int ans = (1 << t) + g(n ^ (1 << t), t - 1);
        return ans;
    }

    int g(int n, int t) {
        if (t == 0)
            return 1 - n;
        if (n & (1 << t))
            return f(n ^ (1 << t));
        int ans = (1 << t) + g(n, t - 1);
        return ans;
    }
public:
    int minimumOneBitOperations(int n) {
        return f(n);
    }
};