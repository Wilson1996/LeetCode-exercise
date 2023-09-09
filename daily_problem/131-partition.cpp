/*
* @Author: wilson_t
* @Date:   2021-03-07 11:54:13
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-03-07 11:54:46
*/
/*
* 题目[中等]：
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
返回 s 所有可能的分割方案。

示例:
输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
 */
class Solution {
    vector<vector<string>> res;
    vector<vector<int>> next;
    int n;
public:
    void dfs(const string& s, vector<string>& path, int cur) {
        if(cur == n) {
            res.emplace_back(path);
            return;
        }
        for(int nx : next[cur]) {
            path.emplace_back(s.substr(cur, nx - cur + 1));
            dfs(s, path, nx + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        res.clear();
        n = s.size();
        next.resize(n);
        for(int i = 0; i < n; ++i) {
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                next[l].emplace_back(r);
                --l;
                ++r;
            }
            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                next[l].emplace_back(r);
                --l;
                ++r;
            }
        }
        vector<string> path;
        dfs(s, path, 0);
        return res;
    }
};