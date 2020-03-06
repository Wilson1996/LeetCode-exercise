/*
 * @Descripttion: 
 * @version: 
 * @Author: WillissTaan(Wilson.T@sjtu.edu.cn)
 * @Date: 2020-03-04 21:04:34
 * @Last Modified by: WillissTaan
 * @Last Modified Time: Do not edit
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution
{
public:
    static bool infect(vector<vector<int>> &grid, int i, int j)
    {
        bool hasInfected = false;
        if (i > 0 && grid[i - 1][j] == 1)
        {
            grid[i - 1][j] = 2;
            hasInfected = true;
        }
        if (i < grid.size() - 1 && grid[i + 1][j] == 1)
        {
            grid[i + 1][j] = 2;
            hasInfected = true;
        }
        if (j > 0 && grid[i][j - 1] == 1)
        {
            grid[i][j - 1] = 2;
            hasInfected = true;
        }
        if (j < grid[0].size() - 1 && grid[i][j + 1] == 1)
        {
            grid[i][j + 1] = 2;
            hasInfected = true;
        }
        return hasInfected;
    }
    static int orangesRotting(vector<vector<int>> &grid)
    {
        int timer = 0;
        while (true)
        {
            bool hasInfected = false;
            for (int i = 0; i < grid.size(); ++i)
            {
                for (int j = 0; j < grid[0].size(); ++j)
                {
                    if (grid[i][j] == 2)
                    {
                        hasInfected = (infect(grid, i, j) || hasInfected);
                    }
                }
            }
            if (!hasInfected)
                break;
            ++timer;
        }
        return timer;
    }

    static int orangesRotting2(vector<vector<int>> &grid)
    {
        int timer = -1;
        int notInfected = 0;
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> rots;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 2)
                {
                    rots.push(make_pair(i, j));
                }
                else if(grid[i][j] == 1)
                {
                    ++notInfected;
                }
            }
        }
        if(0 == notInfected)
            return 0;
        while (!rots.empty())
        {
            ++timer;
            int len = rots.size();
            for (int k = 0; k < len; ++k)
            {
                pair<int, int> p = rots.front();
                rots.pop();
                int row = p.first;
                int col = p.second;
                if (row > 0 && grid[row - 1][col] == 1)
                {
                    grid[row - 1][col] = 2;
                    rots.push(make_pair(row - 1, col));
                }
                if (row < grid.size() - 1 && grid[row + 1][col] == 1)
                {
                    grid[row + 1][col] = 2;
                    rots.push(make_pair(row + 1, col));
                }
                if (col > 0 && grid[row][col - 1] == 1)
                {
                    grid[row][col - 1] = 2;
                    rots.push(make_pair(row, col - 1));
                }
                if (col < grid[0].size() - 1 && grid[row][col + 1] == 1)
                {
                    grid[row][col + 1] = 2;
                    rots.push(make_pair(row, col + 1));
                }
            }
        }
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return timer;
    }
};

int main(int argc, const char** argv) 
{
    // vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    // vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};
    vector<vector<int>> grid = {{0,2}};
    
    cout << grid.size() << endl;
    cout << grid[0].size() << endl;
    cout << Solution::orangesRotting2(grid) << endl;
    return 0;
}