/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-05 00:04:57
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-05 09:42:02
*/
/*********************************************************
* 题目[简单]：
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 
限制：
0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m * n == 0) return {};
        vector<int> res(m * n);
        int _min = min(m, n);
        int layer = _min / 2;
        int idx = 0;
        int i=-1, j=-1;
        for(int l = 0; l < layer; ++l)
        {
            i = l, j = l;
            for(; j < n - l - 1; ++j) res[idx++] = matrix[i][j];
            for(; i < m - l - 1; ++i) res[idx++] = matrix[i][j];
            for(; j > l; --j) res[idx++] = matrix[i][j];
            for(; i > l; --i) res[idx++] = matrix[i][j];
        }
        if(_min & 1)
        {
            if(_min == m)
            {
                for(++i, ++j; j < n - i; ++j) res[idx++] = matrix[i][j];
            }
            else
            {
                for(++i, ++j; i < m - j; ++i) res[idx++] = matrix[i][j];
            }
        }
        return res;
    }
    // vector<int> spiralOrder2(vector<vector<int>>& matrix)
    // {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     if(m * n == 0) return {};
    //     vector<int> res(m * n);
    //     vector<vector<bool>> vis(m, vector<bool>(n, false));
    //     int x = 0, y = 0;
    //     int idx = 0;
    //     int layer = (min(m, n) + 1) / 2;
    //     for(int l = 0; l < layer; ++l)
    //     {
    //     	x = l;
    //     	y = l;
    //     	while(y < n && !vis[x][y]) {res[idx++] = matrix[x][y]; vis[x][y++] = true;}
    //     	--y;
    //         while(x < m && !vis[x][y]) {res[idx++] = matrix[x][y]; vis[x++][y] = true;}
    //         --x;
    //         while(y >= 0 && !vis[x][y]) {res[idx++] = matrix[x][y]; vis[x][y--] = true;}
    //         ++y;
    //         while(x >= 0 && !vis[x][y]) {res[idx++] = matrix[x][y]; vis[x--][y] = true;}
    //         ++x;
    //         ++y;
    //     }
    //     return res;
    // }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution soluter;
    vector<int> re = soluter.spiralOrder(matrix);
    for(auto& x : re)
    {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}