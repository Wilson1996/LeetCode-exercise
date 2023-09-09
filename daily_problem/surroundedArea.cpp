/*
* @Author: wilson_t
* @Date:   2020-08-11 12:53:40
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-11 13:02:14
*/
/*
* 题目[中等]：
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:
X X X X
X O O X
X X O X
X O X X

运行你的函数后，矩阵变为：
X X X X
X X X X
X X X X
X O X X

解释:
被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。
任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
*/
//并查集
class Solution {
public:
    using PII = pair<int, int>;
    vector<vector<PII>> parent;
    PII& find(int x, int y) {
        auto& pos = parent[x][y];
        if((pos.first == x && pos.second == y) || (pos.first == -1 && pos.second == -1))
            return pos;
        parent[x][y] = find(pos.first, pos.second);
        return parent[x][y];
    }
    void join(int x1, int y1, int x2, int y2) {
        PII& root1 = find(x1, y1);
        PII& root2 = find(x2, y2);
        if(root1 != root2) {
            if(root2.first == -1 && root2.second == -1) {
                parent[root1.first][root1.second] = root2;
                // root2 = root1;
            } else {
                parent[root2.first][root2.second] = root1;
                // root1 = root2;
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int m = board.size();
        int n = board[0].size();
        parent = vector<vector<PII>>(m, vector<PII>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    parent[i][j] = make_pair(-1, -1);
                } else {
                    parent[i][j] = make_pair(i, j);
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 'O') {
                    for(int k = 0; k < 4; ++k) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
                            join(i, j, x, y);
                        }
                    }
                }
            }
        }
        // for(int i = 0; i < m; ++i){
        //     for(int j = 0; j < n; ++j){
        //         cout << "(" << parent[i][j].first << "," << parent[i][j].second << ")" << "; ";
        //     }
        //     cout << endl;
        // }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 'O') {
                    auto& p = find(i, j);
                    if(p.first != -1 && p.second != -1) {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};

//dfs
class Solution {
public:
    int n, m;

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) {
            return;
        }
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};