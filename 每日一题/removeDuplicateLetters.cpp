/*
* @Author: wilson_t
* @Date:   2020-12-20 18:11:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-20 18:11:59
*/
/*
* 题目[中等]：
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 
示例 1：
输入：s = "bcabc"
输出："abc"

示例 2：
输入：s = "cbacdcbc"
输出："acdb"
 
提示：
1 <= s.length <= 104
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-letters
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26] = {0};
        bool used[26] = {0};
        for(char c : s) ++cnt[c - 'a'];
        vector<char> sk;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(used[c - 'a']) {
                --cnt[c - 'a'];
                continue;
            }
            while(!sk.empty() && c < sk.back() && cnt[sk.back() - 'a'] > 0) {
                used[sk.back() - 'a'] = false;
                sk.pop_back();
            }
            sk.push_back(c);
            --cnt[c - 'a'];
            used[c - 'a'] = true;
        }
        return string(sk.begin(), sk.end());
    }
};