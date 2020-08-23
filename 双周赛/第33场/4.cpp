/*
* @Author: wilson_t
* @Date:   2020-08-23 12:56:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-23 13:16:11
*/
/*
给你一个二维字符网格数组 grid ，大小为 m x n ，你需要检查 grid 中是否存在 相同值 形成的环。
一个环是一条开始和结束于同一个格子的长度 大于等于 4 的路径。对于一个给定的格子，
你可以移动到它上、下、左、右四个方向相邻的格子之一，可以移动的前提是这两个格子有 相同的值 。
同时，你也不能回到上一次移动时所在的格子。比方说，环  (1, 1) -> (1, 2) -> (1, 1) 是不合法的，
因为从 (1, 2) 移动到 (1, 1) 回到了上一次移动时的格子。
如果 grid 中有相同值形成的环，请你返回 true ，否则返回 false 。

提示：
m == grid.length
n == grid[i].length
1 <= m <= 500
1 <= n <= 500
grid 只包含小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/detect-cycles-in-2d-grid
*/
class Solution {
    int depth[501][501];
    bool vis[501][501];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m, n;
public:
    bool dfs(vector<vector<char>>& g, int x, int y, int dep) {
        char cur = g[x][y];
        depth[x][y] = dep;
        vis[x][y] = true;
        for(int k = 0; k < 4; ++k) {
            int nx = dx[k] + x;
            int ny = dy[k] + y;
            if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if(g[nx][ny] == cur && vis[nx][ny]) {
                    if((dep - depth[nx][ny]) >= 3) {
                        return true;
                    } else {
                        continue;
                    }
                } else if(g[nx][ny] != cur || vis[nx][ny])
                    continue;
                if(dfs(g, nx, ny, dep + 1))
                    return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(depth, 0, sizeof(depth));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!vis[i][j]) {
                    if(dfs(grid, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};

//from zerotrac
class UF {
public:
    vector<int> fa;
    vector<int> sz;
    int n;
    int comp_cnt;

public:
    UF(int _n): n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int findset(int x) {
        return fa[x] == x ? x : fa[x] = findset(fa[x]);
    }

    void unite(int x, int y) {
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
    }

    bool findAndUnite(int x, int y) {
        int x0 = findset(x);
        int y0 = findset(y);
        if (x0 != y0) {
            unite(x0, y0);
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UF uf(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0 && grid[i][j] == grid[i - 1][j]) {
                    if (!uf.findAndUnite(i * n + j, (i - 1) * n + j)) {
                        return true;
                    }
                }
                if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                    if (!uf.findAndUnite(i * n + j, i * n + j - 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};