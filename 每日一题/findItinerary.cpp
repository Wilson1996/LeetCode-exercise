/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-30 16:47:23
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-27 22:37:41
*/
/*********************************************************
* 题目[中等]：
给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别
表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些
机票都属于一个从JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 出发。

说明:
如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。
例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前
所有的机场都用三个大写字母表示（机场代码）。
假定所有机票至少存在一种合理的行程。

示例 1:
输入: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
输出: ["JFK", "MUC", "LHR", "SFO", "SJC"]

示例 2:
输入: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出: ["JFK","ATL","JFK","SFO","ATL","SFO"]
解释: 另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

namespace ANSWER{
class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;
    vector<string> stk;

    void dfs(const string& curr) {
        while (vec.count(curr) && vec[curr].size() > 0) {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& it : tickets) {
            vec[it[0]].emplace(it[1]);
        }
        dfs("JFK");

        reverse(stk.begin(), stk.end());
        return stk;
    }
};
}

namespace SOLVE{
class Solution {
    unordered_map<string, int> idhash;
    vector<string> airports;
    vector<vector<int>> G;
    unordered_map<long long, int> eCnt;
    vector<int> path;
    int nodecnt;
    int edgecnt;
public:
    bool dfs(int cur) {
        if(path.size() == edgecnt + 1)
            return true;
        for(auto& v : G[cur]) {
            if(eCnt[((long long)cur << 32) | v] == 0) continue;
            path.push_back(v);
            eCnt[((long long)cur << 32) | v]--;
            if(dfs(v)) {
                return true;
            }
            path.pop_back();
            eCnt[((long long)cur << 32) | v]++;
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        edgecnt = 0;
        for(auto& t : tickets) {
            airports.emplace_back(t[0]);
            airports.emplace_back(t[1]);
            ++edgecnt;
        }
        sort(airports.begin(), airports.end());
        airports.erase(unique(airports.begin(), airports.end()), airports.end());
        nodecnt = 0;
        for(auto& a : airports) {
            idhash[a] = nodecnt++;
        }
        G = vector<vector<int>>(nodecnt);
        for(auto& t : tickets) {
            G[idhash[t[0]]].emplace_back(idhash[t[1]]);
            eCnt[((long long)idhash[t[0]] << 32) | idhash[t[1]]]++;
        }
        for(auto& g : G) {
            sort(g.begin(), g.end());
        }
        int cur = idhash["JFK"];
        path.clear();
        path.push_back(cur);
        if(dfs(cur)) {
            vector<string> res(path.size());
            for(int i = 0; i < path.size(); ++i) res[i] = airports[path[i]];
            return res;
        } else {
            return vector<string> {};
        }
    }
};
}

int main(int argc, char* argv[]) {
    SOLVE::Solution soluter;
    // vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<vector<string>> tickets = {{"EZE", "AXA"}, {"TIA", "ANU"}, {"ANU", "JFK"}, {"JFK", "ANU"}, {"ANU", "EZE"}, {"TIA", "ANU"}, {"AXA", "TIA"}, {"TIA", "JFK"}, {"ANU", "TIA"}, {"JFK", "TIA"}};
    vector<string> res = soluter.findItinerary(tickets);
    for(auto& x : res) {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}