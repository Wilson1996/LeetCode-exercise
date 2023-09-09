/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-10 11:31:08
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-10 13:51:21
*/
// class Solution
// {
// public:
//     int ways(vector<string>& pizza, int k)
//     {
//     }
// };

//zerotrac
class Solution
{
private:
    vector<vector<int>> sufsum;
    int f[50][50][11];
    static constexpr int mod = 1000000007;
    int m, n;

public:
    int dfs(int x, int y, int rest)
    {
        if (f[x][y][rest] != -1)
        {
            return f[x][y][rest];
        }
        if (sufsum[x][y] < rest)
        {
            return f[x][y][rest] = 0;
        }
        if (rest == 1)
        {
            return 1;
        }
        f[x][y][rest] = 0;
        int base = sufsum[x][y];
        for (int i = x + 1; i < m; ++i)
        {
            if (sufsum[i][y] < base)
            {
                f[x][y][rest] += dfs(i, y, rest - 1);
                f[x][y][rest] %= mod;
            }
        }
        for (int j = y + 1; j < n; ++j)
        {
            if (sufsum[x][j] < base)
            {
                f[x][y][rest] += dfs(x, j, rest - 1);
                f[x][y][rest] %= mod;
            }
        }
        return f[x][y][rest];
    }

    int ways(vector<string>& pizza, int k)
    {
        m = pizza.size();
        n = pizza[0].size();
        sufsum = vector<vector<int>>(m, vector<int>(n));
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                int ap = (pizza[i][j] == 'A');
                if (i == m - 1 && j == n - 1)
                {
                    sufsum[i][j] = ap;
                }
                else if (i == m - 1)
                {
                    sufsum[i][j] = sufsum[i][j + 1] + ap;
                }
                else if (j == n - 1)
                {
                    sufsum[i][j] = sufsum[i + 1][j] + ap;
                }
                else
                {
                    sufsum[i][j] = sufsum[i + 1][j] + sufsum[i][j + 1] - sufsum[i + 1][j + 1] + ap;
                }
            }
        }
        memset(f, -1, sizeof(f));
        return dfs(0, 0, k);
    }
};
