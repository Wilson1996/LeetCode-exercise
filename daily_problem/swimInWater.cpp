/*
* @Author: wilson_t
* @Date:   2021-01-30 10:13:39
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-30 10:15:05
*/
/*
在一个 N x N 的坐标方格 grid 中，每一个方格的值 grid[i][j] 表示在位置 (i,j) 的平台高度。
现在开始下雨了。当时间为 t 时，此时雨水导致水池中任意位置的水位为 t 。你可以从一个平台游向四周相邻的任意一个平台，
但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。
当然，在你游泳的时候你必须待在坐标方格里面。
你从坐标方格的左上平台 (0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台 (N-1, N-1)？

提示:
2 <= N <= 50.
grid[i][j] 是 [0, ..., N*N - 1] 的排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swim-in-rising-water
 */
int fa[2505];
class Solution {
    int n;
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

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = 0, r = n * n;
        auto reachable = [&](int t) {
            iota(fa, fa + n * n, 0);
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(grid[i][j] <= t) {
                        if(i > 0 && grid[i - 1][j] <= t) merge(grid[i][j], grid[i - 1][j]);
                        if(j > 0 && grid[i][j - 1] <= t) merge(grid[i][j], grid[i][j - 1]);
                    }
                }
            }
            return find(grid[0][0]) == find(grid[n - 1][n - 1]);
        };

        while(l < r) {
            int mid = (l + r) / 2;
            if(reachable(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};