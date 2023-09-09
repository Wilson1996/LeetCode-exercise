/*
* @Author: wilson_t
* @Date:   2021-08-02 10:17:33
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-08-02 10:18:39
*/
/*
* 题目[中等]：
有 n 个网络节点，标记为1到 n。
给你一个列表times，表示信号经过 有向 边的传递时间。times[i] = (ui, vi, wi)，
其中ui是源节点，vi是目标节点， wi是一个信号从源节点传递到目标节点的时间。
现在，从某个节点K发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回-1 。

示例 1：
输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
输出：2

示例 2：
输入：times = [[1,2,1]], n = 2, k = 1
输出：1

示例 3：
输入：times = [[1,2,1]], n = 2, k = 2
输出：-1

提示：
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
所有 (ui, vi) 对都 互不相同（即，不含重复边）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/network-delay-time
 */
typedef pair<int, int> pii;
typedef long long int64;
const int inf = INT_MAX / 2;
class Solution {
    int n;
    int dist[105];
    vector<vector<pii>> g;
public:
    void dijkstra(int start) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[start] = 0;
        pq.emplace(0, start);
        while(!pq.empty()) {
            auto [dis, u] = pq.top();
            pq.pop();
            for(auto [v, w] : g[u]) {
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        this->n = n;
        g.resize(n + 1);
        for(vector<int>& e : times) {
            g[e[0]].emplace_back(e[1], e[2]);
        }
        for(int i = 1; i <= n; ++i) dist[i] = inf;
        dijkstra(k);
        int res = 0;
        for(int i = 1; i <= n; ++i) {
            if(dist[i] == inf) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};