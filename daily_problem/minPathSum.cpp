/*
* @Author: wilson_t
* @Date:   2020-07-23 11:17:28
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-07-23 11:18:12
*/
/*********************************************************
* 题目[中等]：
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

示例:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*********************************************************/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        vector<vector<int>> f(m, vector<int>(n));
        f[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i){
            f[i][0] = f[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < n; ++j){
            f[0][j] = f[0][j-1] + grid[0][j];
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
            }
        }
        return f[m-1][n-1];
    }
};