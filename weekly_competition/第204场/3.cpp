/*
* @Author: wilson_t
* @Date:   2020-08-31 19:55:57
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-31 21:32:03
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m, n;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    int vis[35][35];
public:
    void dfs(vector<vector<int>>& g, int x, int y) {
        vis[x][y] = 1;
        for(int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] == 1 && !vis[nx][ny]) {
                dfs(g, nx, ny);
            }
        }
    }
    bool check(vector<vector<int>>& g) {
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                vis[i][j] = 0;
            }
        }
        bool first = true;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(g[i][j] == 1 && vis[i][j] == 0) {
                    if(first) {
                        dfs(g, i, j);
                        first = false;
                    } else {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if(check(grid)) return 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) continue;
                grid[i][j] = 0;
                if(check(grid)) return 1;
                grid[i][j] = 1;
            }
        }
        return 2;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> grid = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    // vector<vector<int>> grid = {{1,1}};
    Solution solution;
    cout << solution.minDays(grid) << endl;
    return 0;
}