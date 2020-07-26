/*
* @Author: wilson_t
* @Date:   2020-07-26 14:41:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-07-26 15:21:35
*/
/**********************************************************
* 题目[困难]:
给定一个整数矩阵，找出最长递增路径的长度。
对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:
输入: nums =
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
输出: 4
解释: 最长递增路径为 [1, 2, 6, 9]。

示例 2:
输入: nums =
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
输出: 4
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
**********************************************************/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> indegree(m, vector<int>(n, 0));
        int DIR[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto check = [&](int i, int j) {
            int cnt = 0, x, y;
            for(int k = 0; k < 4; ++k) {
                x = i + DIR[k][0];
                y = j + DIR[k][1];
                if(x >= 0 && x < m && y >= 0 && y <	n && matrix[i][j] > matrix[x][y]) {
                    ++cnt;
                }
            }
            return cnt;
        };
        queue<pair<int, int>> Q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                indegree[i][j] = check(i, j);
                if(indegree[i][j] == 0) Q.push({i, j});
            }
        }

        int res = 0;
        while(!Q.empty()) {
            ++res;
            int _size = Q.size();
            for(int _ = 0; _ < _size; ++_) {
                auto cur = Q.front();
                Q.pop();
                for(int k = 0; k < 4; ++k) {
                    int x = cur.first + DIR[k][0];
                    int y = cur.second + DIR[k][1];
                    if(x >= 0 && x < m && y >= 0 && y <	n && matrix[cur.first][cur.second] < matrix[x][y]) {
                        --indegree[x][y];
                        if(indegree[x][y] == 0) {
                            Q.push({x, y});
                        }
                    }
                }
            }
        }
        return res;
    }
};