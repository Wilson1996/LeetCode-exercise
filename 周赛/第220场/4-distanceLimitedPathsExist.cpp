/*
* @Author: wilson_t
* @Date:   2020-12-20 18:17:57
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-20 18:18:57
*/
/**
给你一个 n 个点组成的无向图边集 edgeList ，其中 edgeList[i] = [ui, vi, disi] 表示点 ui 和点 vi 之间有一条长度为 disi 的边。请注意，两个点之间可能有 超过一条边 。
给你一个查询数组queries ，其中 queries[j] = [pj, qj, limitj] ，你的任务是对于每个查询 queries[j] ，判断是否存在从 pj 到 qj 的路径，且这条路径上的每一条边都 严格小于 limitj 。
请你返回一个 布尔数组 answer ，其中 answer.length == queries.length ，当 queries[j] 的查询结果为 true 时， answer 第 j 个值为 true ，否则为 false 。

提示：
2 <= n <= 105
1 <= edgeList.length, queries.length <= 105
edgeList[i].length == 3
queries[j].length == 3
0 <= ui, vi, pj, qj <= n - 1
ui != vi
pj != qj
1 <= disi, limitj <= 109
两个点之间可能有 多条 边。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/checking-existence-of-edge-length-limited-paths
 */

//离线算法
const int maxn = 100005;
int fa[maxn];
class Solution {
public:
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if(fx != fy) {
            if(fx > fy) swap(fx, fy);
            fa[fy] = fx;
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& qs) {
        for(int i = 0; i < n; ++i) fa[i] = i;
        sort(edges.begin(), edges.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        vector<int> idx(qs.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return qs[i][2] < qs[j][2];
        });
        vector<bool> res(qs.size());
        int j = 0;
        for(int i = 0; i < idx.size(); ++i) {
            int now = idx[i];
            while(j < edges.size() && edges[j][2] < qs[now][2]) {
                merge(edges[j][0], edges[j][1]);
                ++j;
            }
            res[now] = connected(qs[now][0], qs[now][1]);
        }
        return res;
    }
};