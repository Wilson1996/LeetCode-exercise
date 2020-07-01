/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-20 10:20:43
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-20 11:01:59
*/
/*********************************************************
* 题目[中等]：
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

示例 1:
输入:
11110
11010
11000
00000
输出: 1

示例 2:
输入:
11000
11000
00100
00011
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
*********************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

class Solution
{
public:
    //dfs
    void infect(vector<vector<char>>& grid, int i, int j)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
        {
            return;
        }
        grid[i][j] = '2';
        infect(grid, i - 1, j);
        infect(grid, i + 1, j);
        infect(grid, i, j - 1);
        infect(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int islandNum = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    infect(grid, i, j);
                    ++islandNum;
                }
            }
        }
        return islandNum;
    }
    int numIslands2(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(0 == m || 0 == n)
            return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> Q;
        int nums = 0;
        for(int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if('1' == grid[i][j] && !visited[i][j])
                {
                    Q.emplace(i, j);
                    visited[i][j] = true;
                    ++nums;
                    while(!Q.empty())
                    {
                        auto& pos = Q.front();
                        Q.pop();
                        for(int k = 0; k < 4; ++k)
                        {
                            int x = pos.first + dirs[k][0];
                            int y = pos.second + dirs[k][1];
                            if(x >= 0 && x < m && y >= 0 && y < n && '1' == grid[x][y] && !visited[x][y])
                            {
                                visited[x][y] = true;
                                Q.emplace(x, y);
                            }
                        }
                    }
                }
            }
        }
        return nums;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<char>> theMap =
    {
        {'0', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0'},
        {'0', '1', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '1', '0', '0', '1', '1', '0', '0', '1', '0', '1', '0', '0'},
        {'0', '1', '0', '0', '1', '1', '0', '0', '1', '1', '1', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0'},
    };
    Solution soluter;
    cout << soluter.numIslands2(theMap) << endl;
    return 0;
}