/*
* @Author: wilson_t
* @Date:   2020-08-14 09:42:06
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-14 09:42:49
*/
/*
* 题目[简单]：
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true
*/
class Solution {
public:
    bool isValid(string s) {
        if(s == "") return true;
        stack<char> sk;
        int n = s.size();
        unordered_map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                sk.push(c);
            } else {
                if(sk.empty() || mp[c] != sk.top()) return false;
                sk.pop();
            }
        }
        return sk.empty();
    }
};