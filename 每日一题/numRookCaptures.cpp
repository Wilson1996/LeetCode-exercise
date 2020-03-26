/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-26 09:47:10
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-26 10:25:08
*/
/*********************************************************
* 题目[简单]： https://leetcode-cn.com/problems/available-captures-for-rook
在一个 8 x 8 的棋盘上，有一个白色车（rook）。也可能有空方块，白色的象（bishop）和黑色的卒（pawn）。
它们分别以字符 “R”，“.”，“B” 和 “p” 给出。大写字符表示白棋，小写字符表示黑棋。
车按国际象棋中的规则移动：它选择四个基本方向中的一个（北，东，西和南），然后朝那个方向移动，
直到它选择停止、到达棋盘的边缘或移动到同一方格来捕获该方格上颜色相反的卒。另外，车不能与其他
友方（白色）象进入同一个方格。
返回车能够在一次移动中捕获到的卒的数量。
 

示例 1：
输入：
[[".",".",".",".",".",".",".","."],
 [".",".",".","p",".",".",".","."],
 [".",".",".","R",".",".",".","p"],
 [".",".",".",".",".",".",".","."],
 [".",".",".",".",".",".",".","."],
 [".",".",".","p",".",".",".","."],
 [".",".",".",".",".",".",".","."],
 [".",".",".",".",".",".",".","."]]
输出：3
解释：
在本例中，车能够捕获所有的卒。

提示：
board.length == board[i].length == 8
board[i][j] 可以是 'R'，'.'，'B' 或 'p'
只有一个格子上存在 board[i][j] == 'R'
*********************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	static int _numOfCaptures(vector<vector<char>>& board, int _i, int _j)
	{
		int captures = 0;
		vector<vector<int>> steps = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		for(int k = 0; k < steps.size(); ++k)
		{
			int x = _i;
			int y = _j;
			while(x >= 0 && x < board.size() && y >= 0 && y < board[x].size())
			{
				if(board[x][y] == 'B') break;
				else if(board[x][y] == 'p')
				{
					++captures;
					break;
				}
				x += steps[k][0];
				y += steps[k][1];
			}
		}
		return captures;
	}
	static int numRookCaptures(vector<vector<char>>& board)
	{
		for(int i = 0; i < board.size(); ++i)
		{
			for(int j = 0; j < board[i].size(); ++j)
			{
				if(board[i][j] == 'R')
				{
					return _numOfCaptures(board, i, j);
				}
			}
		}
		return 0;
	}
};
