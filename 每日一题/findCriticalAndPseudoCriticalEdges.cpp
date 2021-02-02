/*
* @Author: wilson_t
* @Date:   2021-01-21 20:42:47
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-21 20:44:18
*/
/*
给你一个 n 个点的带权无向连通图，节点编号为 0 到 n-1 ，同时还有一个数组 edges ，其中 edges[i] = [fromi, toi, weighti] 
表示在 fromi 和 toi 节点之间有一条带权无向边。最小生成树 (MST) 是给定图中边的一个子集，
它连接了所有节点且没有环，而且这些边的权值和最小。请你找到给定图中最小生成树的所有关键边和伪关键边。如果从图中删去某条边，
会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。
请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标。

提示：
2 <= n <= 100
1 <= edges.length <= min(200, n * (n - 1) / 2)
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti <= 1000
所有 (fromi, toi) 数对都是互不相同的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree
 */
class Solution {
    int n;
    int m;
    int fa[105];
    int cand;
    vector<int> idx;
public:
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if(fx != fy) {
            if(fx > fy) swap(fx, fy);
            fa[fy] = fx;
            return true;
        }
        return false;
    }

    int kruskal(vector<vector<int>>& edges, int mask, bool isContained) {
        iota(fa, fa + n, 0);
        int cnt = n, res = 0, i;
        if(isContained && mask >= 0) {
            merge(edges[idx[mask]][0], edges[idx[mask]][1]);
            --cnt;
            res += edges[idx[mask]][2];
        }
        for(i = 0; i < m; ++i) {
            if(i == mask) {
                continue;
            }
            if(merge(edges[idx[i]][0], edges[idx[i]][1])) {
                --cnt;
                res += edges[idx[i]][2];
            }
            if(cnt == 1) break;
        }
        if(cnt == 1) {
            return res;
        } else return INT_MAX;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int _n, vector<vector<int>>& edges) {
        n = _n;
        m = edges.size();
        cand = m;
        idx = vector<int>(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return edges[i][2] < edges[j][2];
        });
        vector<vector<int>> res(2);
        int mst_w = kruskal(edges, -1, false);
        //寻找关键边
        unordered_set<int> critical;
        for(int i = 0; i < m; ++i) {
            int now_w = kruskal(edges, i, false);
            if(now_w > mst_w) {
                res[0].emplace_back(idx[i]);
                critical.insert(i);
            }
        }
        //非关键边
        for(int i = 0; i < m; ++i) {
            if(critical.find(i) != critical.end()) continue;
            int now_w = kruskal(edges, i, true);
            if(now_w == mst_w) {
                res[1].emplace_back(idx[i]);
            }
        }
        return res;
    }
};