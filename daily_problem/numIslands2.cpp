/*
* @Author: wilson_t
* @Date:   2020-10-11 20:27:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-11 20:29:03
*/
/*********************************************************
* 题目[困难]：
假设你设计一个游戏，用一个 m 行 n 列的 2D 网格来存储你的游戏地图。
起始的时候，每个格子的地形都被默认标记为「水」。我们可以通过使用 addLand 进行操作，将位置 (row, col) 的「水」变成「陆地」。
你将会被给定一个列表，来记录所有需要被操作的位置，然后你需要返回计算出来 每次 addLand 操作后岛屿的数量。
注意：一个岛的定义是被「水」包围的「陆地」，通过水平方向或者垂直方向上相邻的陆地连接而成。你可以假设地图网格的四边均被无边无际的「水」所包围。
请仔细阅读下方示例与解析，更加深入了解岛屿的判定。

示例:
输入: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
输出: [1,1,2,3]

解析:
起初，二维网格 grid 被全部注入「水」。（0 代表「水」，1 代表「陆地」）
0 0 0
0 0 0
0 0 0
操作 #1：addLand(0, 0) 将 grid[0][0] 的水变为陆地。
1 0 0
0 0 0   Number of islands = 1
0 0 0
操作 #2：addLand(0, 1) 将 grid[0][1] 的水变为陆地。
1 1 0
0 0 0   岛屿的数量为 1
0 0 0
操作 #3：addLand(1, 2) 将 grid[1][2] 的水变为陆地。
1 1 0
0 0 1   岛屿的数量为 2
0 0 0
操作 #4：addLand(2, 1) 将 grid[2][1] 的水变为陆地。
1 1 0
0 0 1   岛屿的数量为 3
0 1 0

拓展：
你是否能在 O(k log mn) 的时间复杂度程度内完成每次的计算？（k 表示 positions 的长度）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands-ii
*********************************************************/
class Solution {
    vector<int> fa;
    int comp_cnt, m, n, mn;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    int find(int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    bool join(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if(fx != fy) {
            if(fx > fy) swap(fx, fy);
            fa[fy] = fx;
            --comp_cnt;
            return true;
        }
        return false;
    }

    void add(int x) {
        comp_cnt++;
        fa[x] = x;
    }

    vector<int> numIslands2(int _m, int _n, vector<vector<int>>& positions) {
        m = _m;
        n = _n;
        mn = m * n;
        fa = vector<int>(mn, -1);
        vector<int> res;
        comp_cnt = 0;
        for(auto& pos : positions) {
            int pp = pos[0] * n + pos[1];
            if(fa[pp] == -1) {
                add(pp);
                for(int k = 0; k < 4; ++k) {
                    int nx = dx[k] + pos[0];
                    int ny = dy[k] + pos[1];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && fa[nx * n + ny] != -1) {
                        join(pp, nx * n + ny);
                    }
                }
            }
            res.emplace_back(comp_cnt);
        }
        return res;
    }
};