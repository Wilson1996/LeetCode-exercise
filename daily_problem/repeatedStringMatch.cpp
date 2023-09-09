/*
* @Author: wilson_t
* @Date:   2020-11-12 14:27:47
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-12 14:28:48
*/
/*********************************************************
 * 题目[中等]：
给定两个字符串 a 和 b，寻找重复叠加字符串 a 的最小次数，使得字符串 b 成为叠加后的字符串 a 的子串，如果不存在则返回 -1。
注意：字符串 "abc" 重复叠加 0 次是 ""，重复叠加 1 次是 "abc"，重复叠加 2 次是 "abcabc"。
 
示例 1：
输入：a = "abcd", b = "cdabcdab"
输出：3
解释：a 重复叠加三遍后为 "abcdabcdabcd", 此时 b 是其子串。

示例 2：
输入：a = "a", b = "aa"
输出：2

示例 3：
输入：a = "a", b = "a"
输出：1

示例 4：
输入：a = "abc", b = "wxyz"
输出：-1
 
提示：
1 <= a.length <= 104
1 <= b.length <= 104
a 和 b 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/repeated-string-match
*********************************************************/
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m = a.size(), n = b.size();
        int l = 1, mx = n / m + 3, r = mx;
        while(l < r) {
            int mid = l + (r - l) / 2;
            string aa = "";
            for(int t = 0; t < mid; ++t) aa += a;
            if(aa.find(b) != string::npos) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l == mx ? -1 : l;
    }
};