/*
* @Author: wilson_t
* @Date:   2020-09-14 21:07:02
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-15 12:08:03
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> fa;
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n = edges.size();
        fa.resize(n + 1);
        vector<int> degree(n + 1);
        for (auto& v : edges) {
            ++degree[v[1]];
        }
        for (int i = n - 1; i >= 0; --i) {
            if (degree[edges[i][1]] == 2) {
                if (helper(edges, i)) return edges[i];
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (degree[edges[i][1]] == 1) {
                if (helper(edges, i)) return edges[i];
            }
        }
        return {};
    }

    bool helper(vector<vector<int>>& e, int except) {
        for (int i = 1; i <= n; ++i) fa[i] = i;
        int cnt = n;
        for (int i = 0; i < n; ++i) {
            if (i == except) continue;
            int fx = find(e[i][0]), fy = find(e[i][1]);
            if (fx != fy) {
                --cnt;
                fa[fy] = fx;
            }
        }
        return cnt == 1;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> edges = {{2, 1}, {3, 1}, {4, 2}, {1, 4}};
    auto res = solution.findRedundantDirectedConnection(edges);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    return 0;
}