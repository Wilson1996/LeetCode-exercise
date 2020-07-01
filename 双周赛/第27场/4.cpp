/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-31 00:11:39
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-31 00:12:10
*/
class Solution
{
    int f[75][75][75];
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size(), i, j, k, l, o, ans = 0;
        memset(f, 128, sizeof(f));
        f[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
        for(i = 0; i + 1 < n; i++)
            for(j = 0; j < m; j++)
                for(k = 0; k < m; k++)
                    for(l = -1; l < 2; l++)
                        if(j + l >= 0 && j + l < m)
                            for(o = -1; o < 2; o++)
                                if(k + o >= 0 && k + o < m)
                                    f[i + 1][j + l][k + o] = max(f[i + 1][j + l][k + o], f[i][j][k] + grid[i + 1][j + l] + (j + l == k + o ? 0 : grid[i + 1][k + o]));
        for(i = 0; i < m; i++)for(j = 0; j < m; j++)ans = max(ans, f[n - 1][i][j]);
        return ans;
    }
};