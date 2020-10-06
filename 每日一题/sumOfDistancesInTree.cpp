/*
* @Author: wilson_t
* @Date:   2020-10-06 12:02:37
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-06 12:41:38
*/
/*********************************************************
* 题目[困难]：
给定一个无向、连通的树。树中有 N 个标记为 0...N-1 的节点以及 N-1 条边 。
第 i 条边连接节点 edges[i][0] 和 edges[i][1] 。
返回一个表示节点 i 与其他所有节点距离之和的列表 ans。

示例 1:
输入: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
输出: [8,12,6,10,10,10]
解释:
如下为给定的树的示意图：
  0
 / \
1   2
   /|\
  3 4 5

我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
说明: 1 <= N <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-distances-in-tree
*********************************************************/
using PII = pair<int, int>;

const int maxn = 10005;
vector<int> tree[maxn];
int cnt[maxn];
int dist[maxn];
bool vis[maxn];
class Solution {
    vector<int> res;
    int N;
public:
    //返回值{first: 子树节点个数; second: 距离之和}
    PII dfs1(int cur) {
        vis[cur] = true;
        PII ret(1, 0);
        for(int v : tree[cur]) {
            if(!vis[v]) {
                PII tmp = dfs1(v);
                ret.first += tmp.first;
                ret.second += (tmp.first + tmp.second);
            }
        }
        cnt[cur] = ret.first;
        dist[cur] = ret.second;
        return ret;
    }

    void dfs2(int cur) {
        vis[cur] = true;
        for(int v : tree[cur]) {
            if(!vis[v]) {
                res[v] = res[cur] + N - 2 * cnt[v];
                dfs2(v);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int _N, vector<vector<int>>& edges) {
        N = _N;
        res.resize(N);
        for(int i = 0; i < N; ++i) {
            tree[i].clear();
            vis[i] = false;
        }
        for(auto& e : edges) {
            tree[e[0]].emplace_back(e[1]);
            tree[e[1]].emplace_back(e[0]);
        }
        dfs1(0);
        for(int i = 0; i < N; ++i) {
            vis[i] = false;
        }
        res[0] = dist[0];
        dfs2(0);
        return res;
    }
};