/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-25 00:27:27
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-25 13:08:35
*/
/**********************************************************
* 题目[简单]：
在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
请你返回最终形体的表面积。

示例 1：
输入：[[2]]
输出：10

示例 2：
输入：[[1,2],[3,4]]
输出：34

示例 3：
输入：[[1,0],[0,2]]
输出：16

示例 4：
输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：32

示例 5：
输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：46
 
提示：
1 <= N <= 50
0 <= grid[i][j] <= 50
**********************************************************/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
	static int surfaceArea(vector<vector<int>>& grid)
	{
		int result = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] != 0)
					result += grid[i][j] * 4 + 2;
				if (i > 0)
					result -= min(grid[i - 1][j], grid[i][j]) * 2;
				if (j > 0)
					result -= min(grid[i][j - 1], grid[i][j]) * 2;
			}
		}
		return result;
		////有问题
		// int upArea, leftArea, frontArea;
		// upArea = leftArea = frontArea = 0;
		// vector<int> rowMax(grid.size(), 0);
		// vector<int> colMax(50, 0);
		// for (int i = 0; i < grid.size(); ++i)
		// {
		// 	for (int j = 0; j < grid[i].size(); ++j)
		// 	{
		// 		if(grid[i][j] > 0)
		// 			++upArea;
		// 		if(grid[i][j] > rowMax[i])
		// 			rowMax[i] = grid[i][j];
		// 		if(grid[i][j] > colMax[j])
		// 			colMax[j] = grid[i][j];
		// 		if(i > 0 && i < grid.size() - 1 && grid[i][j] < grid[i - 1][j] && grid[i][j] < grid[i + 1][j])
		// 		{
		// 			frontArea += min(grid[i - 1][j], grid[i + 1][j]) - grid[i][j];
		// 		}
		// 		if(j > 0 && j < grid[i].size() - 1 && grid[i][j] < grid[i][j - 1] && grid[i][j] < grid[i][j+ 1])
		// 		{
		// 			leftArea += min(grid[i][j - 1], grid[i][j + 1]) - grid[i][j];
		// 		}
		// 	}
		// }
		// frontArea += accumulate(colMax.begin(), colMax.end(), 0);
		// leftArea += accumulate(rowMax.begin(), rowMax.end(), 0);
		// return (upArea + frontArea + leftArea) * 2;
	}
};

int main(int argc, char* argv[])
{
	// vector<vector<int>> grid = {{2}};
	// vector<vector<int>> grid = {{1,0},{0,2}};
	// vector<vector<int>> grid = {{1, 2}, {3, 4}};
	// vector<vector<int>> grid = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
	// vector<vector<int>> grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
	vector<vector<int>> grid = {{3, 3, 3}, {3, 4, 5}, {5, 0, 4}};
	cout << Solution::surfaceArea(grid) << endl;
	return 0;
}