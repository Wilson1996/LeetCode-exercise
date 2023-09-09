/*
* @Author: wilson_t
* @Date:   2020-11-30 09:34:15
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-30 09:34:51
*/
/**
* 题目[中等]：
给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。
若可行，输出任意可行的结果。若不可行，返回空字符串。

示例 1:
输入: S = "aab"
输出: "aba"

示例 2:
输入: S = "aaab"
输出: ""

注意:
S 只包含小写字母并且长度在[1, 500]区间内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorganize-string
 */
using PIC = pair<int, char>;
class Solution {
public:
    string reorganizeString(string S) {
        int cnt[26] = {0}, n = S.size();
        for(char c : S) cnt[c - 'a']++;
        priority_queue<PIC, vector<PIC>, less<PIC>> pq;
        for(int i = 0; i < 26; ++i) {
            if(cnt[i] > 0) pq.emplace(cnt[i], i + 'a');
        }
        string res = "";
        while(res.size() < n) {
            vector<PIC> cache;
            while(!pq.empty()) {
                PIC pa = pq.top();
                pq.pop();
                if(res.size() == 0 || pa.second != res.back()) {
                    res.push_back(pa.second);
                    if(pa.first - 1 > 0) {
                        pq.emplace(pa.first - 1, pa.second);
                    }
                    while(cache.size()) {
                        pq.push(cache.back());
                        cache.pop_back();
                    }
                    break;
                } else {
                    cache.emplace_back(pa);
                }
            }
            if(cache.size()) return "";
        }
        return res;
    }
};