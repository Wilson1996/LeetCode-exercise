/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-29 09:13:40
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-29 10:59:04
*/
/*********************************************************
* 题目[中等]：
你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）
都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，你知道距离陆地区域最远的海洋区
域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。我们这里说的距离是
『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的
距离是 |x0 - x1| + |y0 - y1| 。
如果我们的地图上只有陆地或者海洋，请返回 -1。
 
示例 1：
输入：[[1,0,1],[0,0,0],[1,0,1]]
输出：2
解释：
海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。

示例 2：
输入：[[1,0,0],[0,0,0],[0,0,0]]
输出：4
解释：
海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。

提示：
1 <= grid.length == grid[0].length <= 100
grid[i][j] 不是 0 就是 1
*********************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
	struct Cordinate
	{
		int x, y;
		Cordinate(int _x, int _y): x(_x), y(_y) {}
	};
public:
	static bool isAvailable(vector<vector<int>>& grid, int _x, int _y)
	{
		if(_x >= 0 && _x < grid.size() && _y >= 0 &&
				_y < grid[_x].size() && grid[_x][_y] == 0)
		{
			return true;
		}
		return false;
	}
	//方法一：多源BFS
	static int maxDistance(vector<vector<int>>& grid)
	{
		queue<Cordinate> Q;
		vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		for(int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[i].size(); ++j)
			{
				if(grid[i][j])
					Q.push(Cordinate(i, j));
			}
		}
		if(Q.size() == 0 || Q.size() == grid.size() * grid[0].size())
			return -1;
		while(!Q.empty())
		{
			Cordinate temp = Q.front();
			Q.pop();
			for(int k = 0; k < dirs.size(); ++k)
			{
				int nextX = temp.x + dirs[k][0];
				int nextY = temp.y + dirs[k][1];
				if(isAvailable(grid, nextX, nextY))
				{
					Q.push(Cordinate(nextX, nextY));
					grid[nextX][nextY] = grid[temp.x][temp.y] + 1;	//已经访问过的标记
				}
			}
			if(Q.size() == 1)
			{
				cout << "ocean cordinate: " << Q.front().x << ", " << Q.front().y << endl;
				return grid[Q.front().x][Q.front().y] - 1;
			}
		}
		return -1;
	}
};

int main(int argc, char* argv[])
{
	vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
	// vector<vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	cout << Solution::maxDistance(grid) << endl;
	return 0;
}