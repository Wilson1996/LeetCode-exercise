/*
* @Author: wilson_t
* @Date:   2020-08-22 16:16:32
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-14 21:55:23
*/
#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

class DIJ {
private:
    int n;
    vector<unordered_map<int, int>> g;
public:
    DIJ(vector<vector<PII>>& _g) {
        n = _g.size();
        g.resize(n);
        for(int i = 0; i < n; ++i) {
            for(auto& p : _g[i]) {
                g[i][p.first] = p.second;
            }
        }
    }

    void getShortestPath(int src, vector<int>& parent, vector<int>& dist) {
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; ++i) {
            if(i == src) dist[i] = 0;
            else dist[i] = INT_MAX;
        }
        pq.emplace(0, src);
        while(!pq.empty()) {
            auto& cur = pq.top();
            int d = cur.first, u = cur.second;
            pq.pop();
            if(!vis[u]) {
                vis[u] = true;
                for(auto& adj : g[u]) {
                    if(vis[adj.first]) continue;
                    int v = adj.first, w = adj.second;
                    if(w + d < dist[v]) {
                        dist[v] = w + d;
                        parent[v] = u;
                        pq.emplace(dist[v], v);
                    }
                }
            }
        }
    }
};

int main(int argc, char* argv[]) {
    vector<vector<PII>> graph = vector<vector<PII>>(6);
    graph[0].emplace_back(1, 5);
    graph[0].emplace_back(2, 1);
    graph[1].emplace_back(0, 5);
    graph[1].emplace_back(2, 2);
    graph[1].emplace_back(3, 1);
    graph[2].emplace_back(0, 1);
    graph[2].emplace_back(1, 2);
    graph[2].emplace_back(3, 4);
    graph[2].emplace_back(4, 8);
    graph[3].emplace_back(1, 1);
    graph[3].emplace_back(2, 4);
    graph[3].emplace_back(4, 3);
    graph[3].emplace_back(5, 6);
    graph[4].emplace_back(2, 8);
    graph[4].emplace_back(3, 3);
    graph[5].emplace_back(3, 6);

    DIJ dij(graph);
    vector<int> parent(6);
    vector<int> dist(6);
    dij.getShortestPath(0, parent, dist);
    // for(auto x : parent){
    // 	cout << x << ", ";
    // }
    // cout << endl;
    // for(auto x : dist){
    // 	cout << x << ", ";
    // }
    // cout << endl;
    stack<int> path;
    int cur = 5;
    while(cur != 0) {
        path.push(cur);
        cur = parent[cur];
    }
    path.push(cur);
    while(!path.empty()) {
        cout << path.top() << "->";
        path.pop();
    }
    cout << endl;

    return 0;
}