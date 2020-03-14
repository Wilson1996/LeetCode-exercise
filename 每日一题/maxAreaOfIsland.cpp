/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-15 00:30:37
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-15 00:54:44
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
public:
    static int maxAreaOfIsland(vector<vector<int>>& grid)
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
};

int main(int argc, char* argv[])
{
    vector<vector<int>> theMap = {  
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
    cout << Solution::maxAreaOfIsland(theMap) << endl;
    return 0;
}