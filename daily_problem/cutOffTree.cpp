/*
* @Author: wilson_t
* @Date:   2021-02-05 01:09:18
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-02-05 01:11:19
*/
/*
* 题目[困难]：
你被请来给一个要举办高尔夫比赛的树林砍树。树林由一个 m x n 的矩阵表示， 在这个矩阵中：
0 表示障碍，无法触碰
1 表示地面，可以行走
比 1 大的数 表示有树的单元格，可以行走，数值表示树的高度
每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。
你需要按照树的高度从低向高砍掉所有的树，每砍过一颗树，该单元格的值变为 1（即变为地面）。
你将从 (0, 0) 点开始工作，返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 -1 。
可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。

提示：
m == forest.length
n == forest[i].length
1 <= m, n <= 50
0 <= forest[i][j] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cut-off-trees-for-golf-event
 */
using PII = pair<int, int>;
const int INF = 1e9 + 5;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

struct Node {
    int h;
    int x, y;
    Node(int _h, int _x, int _y) : h(_h), x(_x), y(_y) {}
    bool operator<(const Node& rhs) {
        return h < rhs.h;
    }
};

class Solution {
    int m, n;
public:
    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        vector< vector<int> > dist(m, vector<int>(n, INF));
        queue<PII> q;
        q.emplace(sx, sy);
        dist[sx][sy] = 0;
        while(!q.empty()) {
            auto [x, y] = q.front();
            if(x == tx && y == ty) return dist[tx][ty];
            q.pop();
            for(int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && forest[nx][ny] != 0) {
                    if(dist[x][y] + 1 < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
        return INF;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size();
        n = forest[0].size();
        vector<Node> vn;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(forest[i][j] > 1) {
                    vn.emplace_back(forest[i][j], i, j);
                }
            }
        }
        sort(vn.begin(), vn.end());
        int res = 0;
        int prex = 0, prey = 0;
        for(int i = 0; i < vn.size(); ++i) {
            int now = bfs(forest, prex, prey, vn[i].x, vn[i].y);
            if(now >= INF) return -1;
            res += now;
            prex = vn[i].x;
            prey = vn[i].y;
        }
        return res;
    }
};