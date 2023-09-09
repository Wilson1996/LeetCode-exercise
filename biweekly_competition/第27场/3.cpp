/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-30 22:28:43
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-31 10:12:50
*/
#include <bits/stdc++.h>
using namespace std;

//from JOHNKRAM
//邻接矩阵转可达矩阵 floyd算法
class Solution
{
    bool d[105][105];
    vector<bool> ans;
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        int i, j, k;
        memset(d, 0, sizeof(d));
        for(i = 0; i < n; i++)
            d[i][i] = 1;
        for(auto e : prerequisites)
            d[e[0]][e[1]] = 1;
        for(k = 0; k < n; k++)
            for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                    d[i][j] = d[i][j] || d[i][k] && d[k][j];
        ans.clear();
        for(auto q : queries)
            ans.push_back(d[q[0]][q[1]]);
        return ans;
    }
};

//dfs超出时间限制
class Solution
{
	vector<vector<int>> G_inv;
	bool isPre[101][101];
public:
    void dfs(int head, int cur)
    {
        isPre[cur][head] = true;
        for(auto& v : G_inv[cur])
        {
            dfs(head, v);
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        memset(isPre, 0, sizeof(G_inv));
        G_inv = vector<vector<int>>(n);
        // for(auto& pre : prerequisites)
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            auto& pre = prerequisites[i];
            G_inv[pre[1]].emplace_back(pre[0]);
            isPre[pre[1]][pre[0]] = true;
        }
        for(int i = 0; i < n; ++i)
        {
            dfs(i, i);
        }
        int m = queries.size();
        vector<bool> res(m);
        for(int i = 0; i < m; ++i)
        {
            res[i] = isPre[queries[i][0]][queries[i][1]];
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    string B[2] = {"false", "true"};
    vector<vector<int>> prerequisites;
    vector<vector<int>> queries = {{1, 0}, {0, 1}};
    vector<bool> res = soluter.checkIfPrerequisite(2, prerequisites, queries);
    for(auto x : res)
    {
        cout << B[x] << ", ";
    }
    cout << endl;
    return 0;
}
// 2
// [[1,0]]
// [[0,1],[1,0]]
// 2
// []
// [[1,0],[0,1]]
// 3
// [[1,2],[1,0],[2,0]]
// [[1,0],[1,2]]
// 3
// [[1,0],[2,0]]
// [[0,1],[2,0]]
// 5
// [[0,1],[1,2],[2,3],[3,4]]
// [[0,4],[4,0],[1,3],[3,0]]