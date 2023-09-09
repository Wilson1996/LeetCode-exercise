/*
* @Author: wilson_t
* @Date:   2021-01-25 11:05:58
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-25 11:08:08
*/
/*
* 题目[中等]：
在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。
（请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。
返回区域的数目。

提示：
1 <= grid.length == grid[0].length <= 30
grid[i][j] 是 '/'、'\'、或 ' '。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regions-cut-by-slashes
 */
const int maxn = 4000;
int fa[maxn];
class Solution {
public:
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if(fx != fy) {
            if(fx > fy)swap(fx, fy);
            fa[fy] = fx;
            return true;
        }
        return false;
    }

    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        iota(fa, fa + 2 * m * n, 0);
        int count = 2 * m * n;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int fi = i * 2 * n + 2 * j, se = fi + 1;
                if(grid[i][j] == ' ') {
                    if(merge(fi, se)) --count;
                }
                if(j > 0) {
                    if(merge(fi - 1, fi)) --count;
                }
                if(grid[i][j] == '/' || grid[i][j] == ' ') {
                    if(i > 0) {
                        if(grid[i - 1][j] == '/') {
                            if(merge(se - 2 * n, fi)) --count;
                        } else {
                            if(merge(fi - 2 * n, fi)) --count;
                        }
                    }
                } else if(grid[i][j] == '\\') {
                    if(i > 0) {
                        if(grid[i - 1][j] == '/') {
                            if(merge(se - 2 * n, se)) --count;
                        } else {
                            if(merge(fi - 2 * n, se)) --count;
                        }
                    }
                }
            }
        }
        return count;
    }
};