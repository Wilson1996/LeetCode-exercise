/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-15 00:30:37
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-15 11:14:28
*/

/**************************************************************
* 题目[中等]：
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向
(水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。
找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:
[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。
**************************************************************/
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution
{
private:
    static bool fieldCheck(int i, int j, int max_i, int max_j)
    {
        if(i >= 0 && i < max_i && j >= 0 && j < max_j)
            return true;
        return false;
    }
public:
    static int maxAreaOfIsland_1(vector<vector<int>>& grid)
    {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    int area = 1;
                    grid[i][j] = 2;
                    queue<pair<int, int>> Q;
                    Q.push(make_pair(i, j));
                    while(!Q.empty())
                    {
                        pair<int, int> pos = Q.front();
                        Q.pop();
                        if(pos.first >= 1 && grid[pos.first - 1][pos.second] == 1)
                        {
                            grid[pos.first - 1][pos.second] = 2;
                            Q.push(make_pair(pos.first - 1, pos.second));
                            ++area;
                        }
                        if(pos.first + 1 < grid.size() && grid[pos.first + 1][pos.second] == 1)
                        {
                            grid[pos.first + 1][pos.second] = 2;
                            Q.push(make_pair(pos.first + 1, pos.second));
                            ++area;
                        }
                        if(pos.second >= 1 && grid[pos.first][pos.second - 1] == 1)
                        {
                            grid[pos.first][pos.second - 1] = 2;
                            Q.push(make_pair(pos.first, pos.second - 1));
                            ++area;
                        }
                        if(pos.second + 1 < grid[0].size() && grid[pos.first][pos.second + 1] == 1)
                        {
                            grid[pos.first][pos.second + 1] = 2;
                            Q.push(make_pair(pos.first, pos.second + 1));
                            ++area;
                        }
                    }
                    if(maxArea < area)
                        maxArea = area;
                }
            }
        }
        return maxArea;
    }

    //改进
    static int maxAreaOfIsland_2(vector<vector<int>>& grid)
    {
        pair<int, int> nextDir[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int maxArea = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(grid[i][j] == 1)
                {
                    int area = 1;
                    grid[i][j] = 2;
                    queue<pair<int, int>> Q;
                    Q.push(make_pair(i, j));
                    while(!Q.empty())
                    {
                        pair<int, int> pos = Q.front();
                        Q.pop();
                        for(int k = 0; k < sizeof(nextDir) / sizeof(nextDir[0]); ++k)
                        {
                            int next_i = pos.first + nextDir[k].first;
                            int next_j = pos.second + nextDir[k].second;
                            if(fieldCheck(next_i, next_j, row, col) && grid[next_i][next_j] == 1)
                            {
                                grid[next_i][next_j] = 2;
                                Q.push(make_pair(next_i, next_j));
                                ++area;
                            }
                        }
                    }
                    if(maxArea < area)
                        maxArea = area;
                }
            }
        }
        return maxArea;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> theMap =
    {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };
    // vector<vector<int>> theMap = {{0, 0, 0, 0, 0, 0, 0, 0}};
    cout << Solution::maxAreaOfIsland_2(theMap) << endl;
    return 0;
}