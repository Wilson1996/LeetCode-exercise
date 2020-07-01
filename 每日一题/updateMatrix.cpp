/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-15 10:48:16
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-16 09:40:36
*/
/*********************************************************
* 题目[中等]：
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
两个相邻元素间的距离为 1 。

示例 1:
输入:
0 0 0
0 1 0
0 0 0

输出:
0 0 0
0 1 0
0 0 0

示例 2:
输入:
0 0 0
0 1 0
1 1 1

输出:
0 0 0
0 1 0
1 2 1

注意:
给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。
*********************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

class Solution
{
public:
	//动态规划
	static vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> result(m, vector<int>(n));
		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(0 == matrix[i][j])
					result[i][j] = 0;
				else
					result[i][j] =  INT_MAX / 2;
			}
		}
		//左上
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(0 == result[i][j])
					continue;
				if(i > 0) result[i][j] = min(result[i - 1][j] + 1, result[i][j]);
				if(j > 0) result[i][j] = min(result[i][j - 1] + 1, result[i][j]);
			}
		}
		//右下
		for (int i = m - 1; i >= 0; --i)
		{
			for (int j = n - 1; j >= 0; --j)
			{
				if(0 == result[i][j])
					continue;
				if(i < m - 1) result[i][j] = min(result[i + 1][j] + 1, result[i][j]);
				if(j < n - 1) result[i][j] = min(result[i][j + 1] + 1, result[i][j]);
			}
		}
		return result;
	}
	//BFS
	static vector<vector<int>> updateMatrix2(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		queue<pair<int, int>> Q;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		// vector<vector<int>> result(m, vector<int>(n, 0));
		int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(0 == matrix[i][j])
				{
					// Q.push(make_pair(i, j));
					Q.emplace(i, j);
					visited[i][j] = true;
				}
			}
		}
		int dist = 0;
		while(!Q.empty())
		{
			auto Pos = Q.front();
			Q.pop();
			for(int k = 0; k < 4; ++k)
			{
				int x = Pos.first + dirs[k][0];
				int y = Pos.second + dirs[k][1];
				if(x >= 0 && x < m && y >= 0 && y < n && !visited[x][y])
				{
					visited[x][y] = true;
					matrix[x][y] = matrix[Pos.first][Pos.second] + 1;
					Q.emplace(x, y);
				}
			}
		}
		return matrix;
	}
};

int main(int argc, char* argv[])
{
	// vector<vector<int>> matrix = {
	// 								{0, 0, 0},
	// 								{0, 1, 0},
	// 								{1, 1, 1}
	// 							};
	vector<vector<int>> matrix = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
	vector<vector<int>> result = Solution::updateMatrix2(matrix);
	for(auto& line : result)
	{
		for(auto& x : line)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}