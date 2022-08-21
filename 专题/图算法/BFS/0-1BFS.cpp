/*
* @Author: wilson_t
* @Date:   2022-05-29 21:24:08
* @Last Modified by:   wilson_t
* @Last Modified time: 2022-05-29 21:26:13
*/

// 0-1BFS用来解决：边权值为0或1，或者能够转化为这种边权值的最短路问题，时间复杂度为O(E+V).
// 0-1BFS,从队列front中去除点u，遍历u的所有边，如果当前边可以进行relax操作，则relax，然后判断level，若level相同，放到队列的front，否则，放到back，队列采用双端队列deque。
//
class Solution {
    static constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dis[m][n];
        memset(dis, 0x3f, sizeof(dis));
        dis[0][0] = 0;
        deque<pair<int, int>> q;
        q.emplace_front(0, 0);
        while (!q.empty()) {
            auto[x, y] = q.front();
            q.pop_front();
            for (auto &[dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                    int g = grid[nx][ny];
                    if (dis[x][y] + g < dis[nx][ny]) {
                        dis[nx][ny] = dis[x][y] + g;
                        g == 0 ? q.emplace_front(nx, ny) : q.emplace_back(nx, ny);
                    }
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};
