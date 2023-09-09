/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-23 15:23:21
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-14 15:58:19
*/
/*********************************************************
* 题目[困难]：
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：
如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
*********************************************************/
//滑动窗口
const int INF = 1e9;
class Solution {
public:
    string minWindow(string s, string t) {
        int mp[52] = {0}, cnt[52] = {0};
        for(char c : t) {
            if(c >= 'a') mp[c - 'a' + 26]++;
            else mp[c - 'A']++;
        }
        int l = 0, r = 0;
        auto valid = [&]() {
            for(int i = 0; i < 52; ++i) {
                if(cnt[i] < mp[i]) return false;
            }
            return true;
        };
        int miLen = INF, n = s.size(), start = 0;
        while(r < n) {
            if(!valid()) {
                if(s[r] >= 'a') cnt[s[r] - 'a' + 26]++;
                else cnt[s[r] - 'A']++;
                ++r;
            } else {
                if(r - l < miLen) {
                    miLen = r - l;
                    start = l;
                }
                if(s[l] >= 'a') cnt[s[l] - 'a' + 26]--;
                else cnt[s[l] - 'A']--;
                ++l;
            }
        }
        while(valid()) {
            if(r - l < miLen) {
                miLen = r - l;
                start = l;
            }
            if(s[l] >= 'a') cnt[s[l] - 'a' + 26]--;
            else cnt[s[l] - 'A']--;
            ++l;
        }
        return miLen == INF ? "" : s.substr(start, miLen);
    }
};