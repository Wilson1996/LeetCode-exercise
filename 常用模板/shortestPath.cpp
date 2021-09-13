/*
* @Author: wilson_t
* @Date:   2020-12-20 11:12:12
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-09-13 13:47:34
*/

// Dijkstra algorithm
void dijkstra(int source) {
    vector<int> dist(n, inf), vis(n, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, source);
    dist[source] = 0;
    vis[source] = 1;
    while(pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        for(auto[v, w] : g[u]) {
            if(!vis[v] && d + w < dist[v]) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
                vis[v] = 1;
            }
        }
    }
}

// Bellman-ford algorithm
struct edge {
    int v, w;
};
vector<edge> e[maxn];
int dis[maxn];
bool bellmanford(int n, int s) {
    memset(dis, 63, sizeof(dis));
    dis[s] = 0;
    bool flag;
    for (int i = 1; i <= n; i++) {
        flag = false;
        for (int u = 1; u <= n; u++) {
            for (auto ed : e[u]) {
                int v = ed.v, w = ed.w;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    flag = true;
                }
            }
        }
        // 没有可以松弛的边时就停止算法
        if (!flag) break;
    }
    // 第 n 轮循环仍然可以松弛时说明 s 点可以抵达一个负环
    return flag;
}
/*
[负环判断中存在的常见误区]
需要注意的是，以S点为源点跑 Bellman-Ford 算法时，如果没有给出存在负环的结果，
只能说明从S点出发不能抵达一个负环，而不能说明图上不存在负环。
因此如果需要判断整个图上是否存在负环，最严谨的做法是建立一个超级源点，
向图上每个节点连一条权值为 0 的边，然后以超级源点为起点执行 Bellman-Ford 算法。
*/

// SPFA
struct edge {
    int v, w;
};
vector<edge> e[maxn];
int dis[maxn], cnt[maxn], vis[maxn];
queue<int> q;
bool spfa(int n, int s) {
    memset(dis, 63, sizeof(dis));
    dis[s] = 0, vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto ed : e[u]) {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;  // 记录最短路经过的边数
                if (cnt[v] >= n) return false;
                // 在不经过负环的情况下，最短路至多经过 n - 1 条边
                // 因此如果经过了多于 n 条边，一定说明经过了负环
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return true;
}


// Floyd algorithm
void floyd() {
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
}


// Johnson algorithm
