/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-31 10:34:59
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-31 13:30:27
*/
//可达矩阵做法不对
// class Solution
// {
//     vector<vector<bool>> d;
// public:
//     int minReorder(int n, vector<vector<int>>& connections)
//     {
//         d = vector<vector<bool>>(n, vector<bool>(n, false));
//         for(int i = 0; i < n; ++i)
//         {
//             d[i][i] = true;
//         }
//         // int Count = connections.size();
//         for(auto& c : connections)
//         {
//             d[c[0]][c[1]] = true;
//         }
//         for(int k = 0; k < n; ++k)
//         {
//             for(int i = 0; i < n; ++i)
//             {
//                 for(int j = 0; j < n; ++j)
//                 {
//                     d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
//                 }
//             }
//         }
//         int res = 0;
//         for(int i = 0; i < n; ++i)
//         {
//             if(!d[i][0])
//                 ++res;
//         }
//         return res;
//     }
// };
#include <bits/stdc++.h>
using namespace std;

//from Heltion
class Solution2
{
public:
    int minReorder(int n, vector<vector<int>>& connections)
    {
        vector<vector<int>> G(n);
        for(auto v : connections)
        {
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        vector<int> d(n, -1);
        d[0] = 0;
        queue<int> q;
        q.push(0);
        while(not q.empty())
        {
            int u = q.front();
            q.pop();
            for(int v : G[u])
                if(d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
        }
        int ans = 0;
        for(auto v : connections) ans += d[v[0]] < d[v[1]];
        return ans;
    }
};

class Solution
{
    vector<set<int>> G_inv;
    vector<set<int>> G;
    vector<bool> vis;
    int count;
public:
    void dfs(int cur)
    {
        vis[cur] = true;
        for(auto& v : G[cur])
        {
            if(vis[v]) continue;
            if(G_inv[cur].count(v) == 0)
            {
                ++count;
                // G_inv[cur].insert(v);
                // G[cur].erase(v);
                dfs(v);
            }
        }
        for(auto& v : G_inv[cur])
        {
            if(vis[v]) continue;
            dfs(v);
        }
        vis[cur] = false;
    }
    void bfs(int head)
    {
        queue<int> Q;
        Q.push(head);
        vis[head] = true;
        while(!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
            for(auto& v : G[cur])
            {
                if(vis[v]) continue;
                if(G_inv[cur].count(v) == 0)
                {
                    ++count;
                    Q.push(v);
                    vis[v] = true;
                }
            }
            for(auto& v : G_inv[cur])
            {
                if(vis[v]) continue;
                Q.push(v);
                vis[v] = true;
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections)
    {
        count = 0;
        G_inv = vector<set<int>>(n, set<int> {});
        G = vector<set<int>>(n, set<int> {});
        vis = vector<bool>(n, false);
        for(auto& c : connections)
        {
            G[c[0]].insert(c[1]);
            G_inv[c[1]].insert(c[0]);
        }
        // dfs(0);
        bfs(0);
        return count;
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    cout << soluter.minReorder(6, connections) << endl;
    return 0;
}