/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-02 09:29:42
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-02 11:06:14
*/
/*********************************************************
根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：
1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
 *如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
 *如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
 *如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
 *如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。
下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，
其中细胞的出生和死亡是同时发生的。

示例：
输入：
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
输出：
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]

进阶：
你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：
你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
本题中，我们使用二维数组来表示面板。原则上，面板是无限的，
但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
*********************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static bool isValid(vector<vector<int>>& board, int i, int j)
	{
		if(i >= 0 && i < board.size() && j >= 0 && j < board[i].size())
			return true;
		return false;
	}
	static int getAlive(vector<vector<int>>& board, int i, int j)
	{
		int sArea[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
		int alive = 0;
		for(int k = 0; k < sizeof(sArea) / sizeof(sArea[0]); ++k)
		{
			int _x = i + sArea[k][0];
			int _y = j + sArea[k][1];
			if(isValid(board, _x, _y) && board[_x][_y] == 1)
			{
				++alive;
			}
		}
		return alive;
	}
	//方法一、copy一个数组进行操作，空间复杂度大
	static void gameOfLife(vector<vector<int>>& board)
	{
		vector<vector<int>> copy_board = board;
		for(int i = 0; i < copy_board.size(); ++i)
		{
			for(int j = 0; j < copy_board[i].size(); ++j)
			{
				int alive = getAlive(copy_board, i, j);
				if(copy_board[i][j] == 1 && (alive < 2 || alive > 3))
				{
					board[i][j] = 0;
				}
				else if(copy_board[i][j] == 0 && alive == 3)
					board[i][j] = 1;
			}
		}
	}
	//方法二、使用位运算进行原位操作
	static void gameOfLife_2(vector<vector<int>>& board)
	{
		int dx[] = {-1,  0,  1, -1, 1, -1, 0, 1};
		int dy[] = {-1, -1, -1,  0, 0,  1, 1, 1};
		for(int i = 0; i < board.size(); i++)
		{
			for(int j = 0 ; j < board[0].size(); j++)
			{
				int sum = 0;
				for(int k = 0; k < 8; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size())
					{
						sum += (board[nx][ny] & 1); // 只累加最低位
					}
				}
				if(board[i][j] == 1)
				{
					if(sum == 2 || sum == 3)
					{
						board[i][j] |= 2;  // 使用第二个bit标记是否存活
					}
				}
				else
				{
					if(sum == 3)
					{
						board[i][j] |= 2; // 使用第二个bit标记是否存活
					}
				}
			}
		}
		for(int i = 0; i < board.size(); i++)
		{
			for(int j = 0; j < board[i].size(); j++)
			{
				board[i][j] >>= 1; //右移以为，用第二bit覆盖第一个bit。
			}
		}
	}
};

int main(int argc, char* argv[])
{
	vector<vector<int>> board =
	{
		{0, 1, 0},
		{0, 0, 1},
		{1, 1, 1},
		{0, 0, 0}
	};
	Solution::gameOfLife_2(board);
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			cout << board[i][j] << ", ";
		}
		cout << endl;
	}
	return 0;
}