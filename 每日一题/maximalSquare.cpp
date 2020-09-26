/*
* @Author: wilson_t
* @Date:   2020-09-26 11:54:50
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-26 11:59:42
*/
/*********************************************************
* 题目[中等]：
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
示例:
输入:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-square
*********************************************************/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size();
        if(m == 0) return 0;
        int n = mat[0].size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(mat[i - 1][j - 1] == '1') {
                    //状态转移方程！！
                    f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
                }
                res = max(res, f[i][j]);
            }
        }
        return res * res;
    }
};


//利用前缀和，比较麻烦
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size();
        if(m == 0) return 0;
        int n = mat[0].size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> prefixR(m, vector<int>(n + 1, 0));
        vector<vector<int>> prefixC(m + 1, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
            for(int j = 1; j <= n; ++j)
                prefixR[i][j] = prefixR[i][j - 1] + (mat[i][j - 1] - '0');
        for(int j = 0; j < n; ++j)
            for(int i = 1; i <= m; ++i)
                prefixC[i][j] = prefixC[i - 1][j] + (mat[i - 1][j] - '0');
        int res = 0;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(mat[i - 1][j - 1] == '0') f[i][j] = 0;
                else {
                    int pre = f[i - 1][j - 1];
                    if(pre == prefixR[i - 1][j - 1] - prefixR[i - 1][j - pre - 1]
                            && pre == prefixC[i - 1][j - 1] - prefixC[i - pre - 1][j - 1]) {
                        f[i][j] = pre + 1;
                    } else {
                        int rowCnt = 0, colCnt = 0;
                        for(int k = j - 2; k >= 0; --k) {
                            if(mat[i - 1][k] == '1') ++rowCnt;
                            else break;
                        }
                        for(int k = i - 2; k >= 0; --k) {
                            if(mat[k][j - 1] == '1') ++colCnt;
                            else break;
                        }
                        f[i][j] = min(rowCnt, colCnt) + 1;
                    }
                }
                res = max(res, f[i][j]);
            }
        }
        return res * res;
    }
};