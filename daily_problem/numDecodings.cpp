/*
* @Author: wilson_t
* @Date:   2020-10-06 19:35:06
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-06 19:36:32
*/
/*********************************************************
* 题目[中等]：
一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。
题目数据保证答案肯定是一个 32 位的整数。

示例 1：
输入："12"
输出：2
解释：它可以解码为 "AB"（1 2）或者 "L"（12）。

示例 2：
输入："226"
输出：3
解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

示例 3：
输入：s = "0"
输出：0

示例 4：
输入：s = "1"
输出：1

示例 5：
输入：s = "2"
输出：1
 
提示：
1 <= s.length <= 100
s 只包含数字，并且可以包含前导零。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-ways
*********************************************************/
class Solution {
public:
    bool isValidAlpha(char a, char b) {
        if((a > '0' && a < '2' && b >= '0' && b <= '9') || (a == '2' && b >= '0' && b <= '6')) {
            return true;
        }
        return false;
    }
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0 || s[0] == '0')
            return 0;
        if(len == 1)
            return 1;
        vector<int> dp(len);
        dp[0] = 1;
        dp[1] = (s[1] == '0' ? 0 : 1) + (isValidAlpha(s[0], s[1]) ? 1 : 0);
        for (int i = 2; i < len; ++i) {
            dp[i] = (s[i] == '0' ? 0 : dp[i - 1]) + (isValidAlpha(s[i - 1], s[i]) ? dp[i - 2] : 0);
        }
        return dp[len - 1];
    }
};