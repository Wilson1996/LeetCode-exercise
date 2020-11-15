/*
* @Author: wilson_t
* @Date:   2020-11-15 13:31:10
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-15 13:33:47
*/
/****************************************************************
* 题目[中等]：
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。
注意:
num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。

示例 1 :
输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。

示例 2 :
输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。

示例 3 :
输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-k-digits
****************************************************************/
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()) return "0";
        vector<char> sk;
        for(char c : num) {
            if(!sk.empty()) {
                while(k > 0 && !sk.empty() && c < sk.back()) {
                    sk.pop_back();
                    --k;
                }
                if(!sk.empty() || c != '0' ) {
                    sk.push_back(c);
                }
            } else {
                if(c != '0') sk.push_back(c);
            }
        }
        while(k > 0 && !sk.empty()) {
            sk.pop_back();
            --k;
        }
        string res;
        for(char c : sk) res.push_back(c);
        return res == "" ?  "0" : res;
    }
};