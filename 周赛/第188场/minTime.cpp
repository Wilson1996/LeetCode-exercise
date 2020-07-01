/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-10 10:58:46
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-10 12:22:08
*/
/*********************************************************
给你一棵有 n 个节点的无向树，节点编号为 0 到 n-1 ，它们中有一些节点有苹果。
通过树上的一条边，需要花费 1 秒钟。你从 节点 0 出发，请你返回最少需要多少秒，
可以收集到所有苹果，并回到节点 0 。

无向树的边由 edges 给出，其中 edges[i] = [fromi, toi] ，表示有一条边连接 from 和 toi 。
除此以外，还有一个布尔数组 hasApple ，其中 hasApple[i] = true 代表节点 i 有一个苹果，否则，节点 i 没有苹果。
*********************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    int steps = 0;
public:
    bool dfs(vector<vector<int>>& G, int cur, vector<bool>& hasApple, vector<bool>& vis)
    {
        vis[cur] = true;
        bool flag = false;
        if(hasApple[cur]) flag = true;
        for(int i = 0; i < G[cur].size(); ++i)
        {
            if(!vis[G[cur][i]])
            {
                bool tmp = dfs(G, G[cur][i], hasApple, vis);
                if(tmp) steps += 2;
                flag = flag || tmp;
            }
        }
        vis[cur] = false;
        return flag;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
    {
        vector<vector<int>> G(n);
        for(auto& e : edges)
        {
            G[e[0]].emplace_back(e[1]);
            G[e[1]].emplace_back(e[0]);
        }
        vector<bool> vis(n, false);
        dfs(G, 0, hasApple, vis);
        return steps;
    }
};