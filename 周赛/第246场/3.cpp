/*
* @Author: wilson_t
* @Date:   2021-06-20 10:24:39
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-20 12:24:55
*/
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

class Solution {
    int fa[250005];
public:
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if(fx != fy) {
            if(fx > fy) swap(fx, fy);
            fa[fy] = fx;
            return true;
        }
        return false;
    }

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& g, vector<vector<bool>>& vis, int x, int y, int parent) {
        vis[x][y] = true;
        int m = g.size(), n = g[0].size();
        bool res = true;
        if(find(x * n + y) != parent || grid1[x][y] == 0) res = false;
        for(int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && g[nx][ny] == 1) {
                res = dfs(grid1, g, vis, nx, ny, parent) && res;
            }
        }
        return res;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        for(int i = 0; i <= m * n; ++i) fa[i] = i;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid1[i][j] == 1) {
                    for(int k = 0; k < 4; ++k) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid1[nx][ny] == 1) {
                            merge(i * n + j, nx * n + ny);
                        }
                    }
                }
            }
        }

        int res = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!vis[i][j] && grid2[i][j] == 1) {
                    ++cnt;
                    int pa = find(i * n + j);
                    if(dfs(grid1, grid2, vis, i, j, pa)) {
                        ++res;
                        // cout << i << "," << j << endl;
                    }
                }
            }
        }
        // cout << "cnt: " << cnt << endl;

        return res;
    }
};