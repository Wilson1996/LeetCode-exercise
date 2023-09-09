/*
* @Author: wilson_t
* @Date:   2020-09-15 10:31:50
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-15 10:33:32
*/
/*********************************************************
* 题目[困难]：
编写一个程序，通过已填充的空格来解决数独问题。
一个数独的解法需遵循如下规则：
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。

Note:
给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sudoku-solver
*********************************************************/
class Solution {
    int vis_block[3][3], vis_row[9], vis_col[9];
    bool occupy[9][9];
public:
    bool dfs(vector<vector<char>>& board, int m, int n) {
        if(m == 9) {
            return true;
        }
        for(int j = n; j < 9; ++j) {
            //if(board[m][j] != '.') continue;
            if(occupy[m][j]) {
                if (j == 8) {
                    if (dfs(board, m + 1, 0)) return true;
                }
                continue;
            }
            int vis = vis_block[m / 3][j / 3] | vis_row[m] | vis_col[j];
            if(vis == 0x1ff) return false;
            for(int p = 0; p < 9; ++p) {
                if((vis & (1 << p)) == 0) {
                    board[m][j] = p + '1';
                    vis_block[m / 3][j / 3] |= (1 << p);
                    vis_row[m] |= (1 << p);
                    vis_col[j] |= (1 << p);

                    if(j == 8) {
                        if(dfs(board, m + 1, 0)) return true;
                    } else {
                        if(dfs(board, m, j + 1)) return true;
                    }

                    board[m][j] = '.';
                    vis_block[m / 3][j / 3] &= (~(1 << p));
                    vis_row[m] &= (~(1 << p));
                    vis_col[j] &= (~(1 << p));
                }
            }
            break;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(vis_block, 0, sizeof(vis_block));
        memset(vis_row, 0, sizeof(vis_row));
        memset(vis_col, 0, sizeof(vis_col));
        memset(occupy, 0, sizeof(occupy));
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    int x = board[i][j] - '1';
                    vis_row[i] |= (1 << x);
                    vis_col[j] |= (1 << x);
                    vis_block[i / 3][j / 3] |= (1 << x);
                    occupy[i][j] = true;
                }
            }
        }
        dfs(board, 0, 0);
    }
};