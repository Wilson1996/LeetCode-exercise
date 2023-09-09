/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-10 14:41:10
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-10 19:49:02
*/

/****************************************************************
* 题目[中等]：
* 给定一幅由N × N矩阵表示的图像，其中每个像素的大小为4字节，
* 编写一种方法，将图像旋转90度。不占用额外内存空间能否做到？
*
* 示例 1:
* 给定 matrix =
* [
*   [1,2,3],
*   [4,5,6],
*   [7,8,9]
* ],
* 原地旋转输入矩阵，使其变为:
* [
*   [7,4,1],
*   [8,5,2],
*   [9,6,3]
* ]
* 解答：原址交换
****************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	static void rotate(vector<vector<int>>& matrix)
	{
		int row = matrix.size();
		int col = matrix[0].size();
		//上下交换
		for(int j = 0; j < col; ++j)
		{
			for (int i = 0; i < row / 2; ++i)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[row - 1 - i][j];
				matrix[row - 1 - i][j] = temp;
			}
		}
		//对角交换
		for(int i = 0; i < row; ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
	}
};

int main(int argc, char* argv[])
{
	vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Solution::rotate(matrix);
	for(int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			cout << matrix[i][j] << ", ";
		}
		cout << endl;
	}
}