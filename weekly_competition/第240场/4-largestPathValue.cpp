/*
给你一个 有向图 ，它含有 n 个节点和 m 条边。节点编号从 0 到 n - 1 。
给你一个字符串 colors ，其中 colors[i] 是小写英文字母，表示图中第 i 个节点的 颜色 （下标从 0 开始）。
同时给你一个二维数组 edges ，其中 edges[j] = [aj, bj] 表示从节点 aj 到节点 bj 有一条 有向边 。
图中一条有效 路径 是一个点序列 x1 -> x2 -> x3 -> ... -> xk ，对于所有 1 <= i < k ，从 xi 到 xi+1 在图中有一条有向边。
路径的 颜色值 是路径中 出现次数最多 颜色的节点数目。
请你返回给定图中有效路径里面的 最大颜色值 。如果图中含有环，请返回 -1 。

示例 1：
输入：colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
输出：3
解释：路径 0 -> 2 -> 3 -> 4 含有 3 个颜色为 "a" 的节点（上图中的红色节点）。

示例 2：
输入：colors = "a", edges = [[0,0]]
输出：-1
解释：从 0 到 0 有一个环。
 
提示：
n == colors.length
m == edges.length
1 <= n <= 105
0 <= m <= 105
colors 只含有小写英文字母。
0 <= aj, bj < n
 */
//拓扑排序+记忆化dfs
const int maxn = 1e5 + 5;
int f[maxn][26];
vector<int> g[maxn];
int vis[maxn];
int n;
vector<int> topoOrder;
class Solution {
    string colors;
public:
    void dfs(int cur) {
        vis[cur] = 1;
        int curColor = colors[cur] - 'a';
        for(int v : g[cur]) {
            if(!vis[v]) dfs(v);
            for(int j = 0; j < 26; ++j) {
                f[cur][j] = max(f[cur][j], f[v][j]);
            }
        }
        f[cur][curColor] += 1;
    }
    void topoSort() {
        topoOrder.resize(0);
        vector<int> inDeg(n, 0);
        for(int i = 0; i < n; ++i) {
            for(int v : g[i]) {
                inDeg[v]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(inDeg[i] == 0) {
                q.push(i);
                topoOrder.emplace_back(i);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : g[u]) {
                --inDeg[v];
                if(inDeg[v] == 0) {
                    q.push(v);
                    topoOrder.emplace_back(v);
                }
            }
        }
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        this->colors = colors;
        n = colors.size();
        for(int i = 0; i < n; ++i) {
            g[i].resize(0);
            vis[i] = 0;
            for(int j = 0; j < 26; ++j) f[i][j] = 0;
        }
        for(auto& e : edges) {
            g[e[0]].emplace_back(e[1]);
        }
        int res = 0;
        topoSort();
        if(topoOrder.size() < n) return -1;
        for(int i : topoOrder) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 26; ++j) {
                res = max(res, f[i][j]);
            }
        }
        return res;
    }
};
