/*
* @Author: wilson_t
* @Date:   2021-01-16 15:29:06
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-16 15:30:37
*/
/*
* 题目[困难]:
有一个 m x n 的二元网格，其中 1 表示砖块，0 表示空白。砖块 稳定（不会掉落）的前提是：
一块砖直接连接到网格的顶部，或者
至少有一块相邻（4 个方向之一）砖块 稳定 不会掉落时
给你一个数组 hits ，这是需要依次消除砖块的位置。每当消除 hits[i] = (rowi, coli) 位置上的砖块时，对应位置的砖块（若存在）会消失，
然后其他的砖块可能因为这一消除操作而掉落。一旦砖块掉落，它会立即从网格中消失（即，它不会落在其他稳定的砖块上）。
返回一个数组 result ，其中 result[i] 表示第 i 次消除操作对应掉落的砖块数目。
注意，消除可能指向是没有砖块的空白位置，如果发生这种情况，则没有砖块掉落。

示例 1：
输入：grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
输出：[2]
解释：
网格开始为：
[[1,0,0,0]，
 [1,1,1,0]]
消除 (1,0) 处加粗的砖块，得到网格：
[[1,0,0,0]
 [0,1,1,0]]
两个加粗的砖不再稳定，因为它们不再与顶部相连，也不再与另一个稳定的砖相邻，因此它们将掉落。得到网格：
[[1,0,0,0],
 [0,0,0,0]]
因此，结果为 [2] 。

示例 2：
输入：grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
输出：[0,0]
解释：
网格开始为：
[[1,0,0,0],
 [1,1,0,0]]
消除 (1,1) 处加粗的砖块，得到网格：
[[1,0,0,0],
 [1,0,0,0]]
剩下的砖都很稳定，所以不会掉落。网格保持不变：
[[1,0,0,0], 
 [1,0,0,0]]
接下来消除 (1,0) 处加粗的砖块，得到网格：
[[1,0,0,0],
 [0,0,0,0]]
剩下的砖块仍然是稳定的，所以不会有砖块掉落。
因此，结果为 [0,0] 。

提示：
m == grid.length
n == grid[i].length
1 <= m, n <= 200
grid[i][j] 为 0 或 1
1 <= hits.length <= 4 * 104
hits[i].length == 2
0 <= xi <= m - 1
0 <= yi <= n - 1
所有 (xi, yi) 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bricks-falling-when-hit
 */
int fa[40005];
int sz[40005];
bool stable[40005];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int tot_stable = 0;
class Solution {
public:
    inline int find(int x) {
        if(x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }

    inline bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if(fx != fy) {
            if(fx > fy) swap(fx, fy);
            fa[fy] = fx;
            sz[fx] += sz[fy];
            int tmp = 0;
            if(!stable[fx]) tmp += sz[fx];
            if(!stable[fy]) tmp += sz[fy];
            stable[fx] = stable[fy] = (stable[fx] || stable[fy]);
            if(stable[fx]) {
                tot_stable += tmp;
            }
            return true;
        }
        return false;
    }

    inline bool isStable(int x) {
        return stable[find(x)];
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size(), mn = m * n;
        tot_stable = 0;
        for(auto& h : hits) {
            if(grid[h[0]][h[1]] == 1) grid[h[0]][h[1]] = -1;
        }
        iota(fa, fa + mn, 0);
        for(int i = 0; i < mn; ++i) {
            sz[i] = 1;
            stable[i] = false;
        }
        for(int j = 0; j < n; ++j) if(grid[0][j] == 1) {
                stable[j] = true;
                tot_stable++;
            }
        for(int i = 1; i < m; ++i) {
            if(grid[i][0] == 1 && grid[i - 1][0] == 1) merge(i * n, (i - 1)*n);
            for(int j = 1; j < n; ++j) {
                if(grid[i][j] == 1) {
                    if(grid[i - 1][j] == 1) merge(i * n + j, (i - 1)*n + j);
                    if(grid[i][j - 1] == 1) merge(i * n + j, i * n + j - 1);
                }
            }
        }
        vector<int> res(hits.size(), 0);
        for(int i = hits.size() - 1; i >= 0; --i) {
            int x = hits[i][0], y = hits[i][1];
            if(grid[x][y] == 0) continue;
            int now_stable = tot_stable;
            if(grid[x][y] == -1) {
                grid[x][y] = 1;
                if(x == 0) {
                    stable[y] = true;
                    tot_stable++;
                }
            }
            for(int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    merge(x * n + y, nx * n + ny);
                }
            }
            res[i] = tot_stable - now_stable;
            if(isStable(x * n + y)) res[i]--;
            if(res[i] < 0) res[i] = 0;
        }

        return res;
    }
};