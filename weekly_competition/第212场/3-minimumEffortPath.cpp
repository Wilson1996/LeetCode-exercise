/*
* @Author: wilson_t
* @Date:   2020-10-27 12:28:57
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-27 12:34:29
*/
/*
你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。
一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。
你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。
一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。
请你返回从左上角走到右下角的最小 体力消耗值 。

提示：
rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-with-minimum-effort
*/
/** from zerotrac
作者：zerotrac2
链接：https://leetcode-cn.com/problems/path-with-minimum-effort/solution/zui-xiao-ti-li-xiao-hao-lu-jing-by-zerotrac2/

本题实际上即为：
将每个格子抽象成图中的一个点；
将每两个相邻的格子之间连接一条边，长度为这两个格子本身权值的差的绝对值；
需要找到一条从左上角到右下角的「最短路径」，其中路径的长度定义为路径上所有边的权值的最大值。
这也是一道比较经典的题目了，常用的方法有如下几种：

* 「二分答案」：我们可以对最短路径的长度进行二分。当我们二分枚举到的长度为 xx 时，
我们只保留所有长度 \leq x≤x 的边。随后从左上角开始进行搜索（深度优先搜索、广度优先搜索）均可，只需要判断是否能够到达右下角即可。
如果能够到达右下角，我们就可以减小 xx 的值，反之增大 xx 的值。
* 「并查集」：我们可以将所有边按照长度进行排序并依次添加进并查集，直到左上角和右下角连通为止。
* 「最短路」：我们可以使用任一单源最短路径的算法（例如 Dijkstra 算法），只需要在维护当前路径长度时，将其修改为题目中的定义即可。

来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

using ll = long long;
int d4x[4] = {1, 0, -1, 0};
int d4y[4] = {0, 1, 0, -1};

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

    void reset() {
        comp_cnt = n;
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

//二分答案 + (dfs\bfs\并查集)
class Solution {
    vector<vector<bool>> vis;
    int m, n;
public:
    bool dfs(vector<vector<int>>& heights, int x, int y, int thresh) {
        if(x == m - 1 && y == n - 1) {
            return true;
        }
        vis[x][y] = true;
        bool ret = false;
        for(int k = 0; k < 4; ++k) {
            int nx = x + d4x[k], ny = y + d4y[k];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
                if(abs(heights[nx][ny] - heights[x][y]) > thresh) continue;
                ret = ret || dfs(heights, nx, ny, thresh);
            }
        }
        return ret;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vis = vector<vector<bool>> (m, vector<bool>(n, false));
        // UF uf(m * n);
        int l = 0, r = 1e6;
        while(l < r) {
            // uf.reset();
            for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) vis[i][j] = false;
            int mid = (l + r) / 2;
            // for(int i = 0; i < m; ++i){
            //     for(int j = 0; j < n; ++j){
            //         if(i > 0 && abs(heights[i][j] - heights[i-1][j]) <= mid) uf.findAndUnite(i*n+j, (i-1)*n+j);
            //         if(j > 0 && abs(heights[i][j] - heights[i][j-1]) <= mid) uf.findAndUnite(i*n+j, i*n+j-1);
            //     }
            // }
            // if(uf.findset(0) == uf.findset(m*n - 1)){
            if(dfs(heights, 0, 0, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};