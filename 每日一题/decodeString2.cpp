/*
* @Author: wilson_t
* @Date:   2020-09-25 22:08:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-25 22:11:29
*/
/********************************************************
* 题目[中等]：
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例 1：
输入：s = "3[a]2[bc]"
输出："aaabcbc"

示例 2：
输入：s = "3[a2[c]]"
输出："accaccacc"

示例 3：
输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"

示例 4：
输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-string
*********************************************************/
//递归
class Solution {
public:
    string decodeString(string s) {
        if(s == "") return "";
        string front = "";
        int n = s.size(), i, mid = n, k = 0;
        for(i = 0; i < n; ++i) {
            if(s[i] >= '0' && s[i] <= '9') {
                k = s[i] - '0';
                ++i;
                while(i < n && s[i] >= '0' && s[i] <= '9') {
                    k = k * 10 + s[i] - '0';
                    ++i;
                }
                mid = i;
                break;
            }
            front += s[i];
        }
        if(mid + 1 < n - 1) {
            int left = 1;
            for(i += 2; i < n; ++i) {
                if(s[i] == '[') left++;
                else if(s[i] == ']') left--;
                if(left == 0) {
                    break;
                }
            }
            string copy = decodeString(s.substr(mid + 1, i - mid - 1));
            for(int j = 0; j < k; ++j)
                front += copy;
        }
        if(i < n - 1) {
            front += decodeString(s.substr(i + 1, n - i - 1));
        }
        return front;
    }
};

//栈
class Solution {
public:
    string getDigits(string& s, size_t& ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string getString(vector <string>& v) {
        string ret;
        for (const auto& s : v) {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s) {
        vector <string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {
                // 获取一个字母并进栈
                stk.push_back(string(1, s[ptr++]));
            } else {
                ++ptr;
                vector <string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前 sub 对应的字符串应该出现的次数
                int repTime = stoi(stk.back());
                stk.pop_back();
                string t, o = getString(sub);
                // 构造字符串
                while (repTime--) t += o;
                // 将构造好的字符串入栈
                stk.push_back(t);
            }
        }

        return getString(stk);
    }
};
