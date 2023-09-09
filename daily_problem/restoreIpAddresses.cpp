/*
* @Author: wilson_t
* @Date:   2020-08-09 21:44:07
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-09 21:45:31
*/
/****************************************************************
* 题目[中等]：
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

示例:
输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
****************************************************************/
class Solution {
    vector<string> res;
    string ip;
    int n;
public:
    void dfs(string& s, int depth, int idx) {
        if(idx >= n) {
            if(depth == 4) {
                res.emplace_back(ip);
            }
            return;
        }
        if(depth == 3) {
            string tmp = s.substr(idx, n - idx);
            if(tmp[0] == '0' && tmp.size() > 1) return;
            if(stoi(tmp) <= 255) {
                string backup = ip + "." + tmp;
                res.emplace_back(backup);
            }
            return;
        }
        int minLen = max(1, (n - idx) - (3 - depth) * 3);
        // int maxLen = max(1, min(n - idx - 3, 3));
        for(int i = minLen; i <= 3; ++i) {
            string tmp = s.substr(idx, i);
            if(tmp[0] == '0' && tmp.size() > 1) break;
            if(i == 3 && stoi(tmp) > 255) break;
            string backup = ip;
            if(depth > 0) {
                ip += ".";
            }
            ip += tmp;
            dfs(s, depth + 1, idx + i);
            ip = backup;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        if(n > 12) return {};
        res.clear();
        ip = "";
        dfs(s, 0, 0);
        return res;
    }
};