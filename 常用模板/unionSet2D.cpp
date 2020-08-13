/*
* @Author: wilson_t
* @Date:   2020-08-13 14:29:31
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-13 14:29:38
*/
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