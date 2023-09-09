/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-18 09:08:04
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-18 09:47:57
*/
/***********************************************************
* 题目[简单]：
矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。
如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。
给出两个矩形，判断它们是否重叠并返回结果。

示例 1：
输入：rec1 = [0,0,2,2], rec2 = [1,1,3,3]
输出：true

示例 2：
输入：rec1 = [0,0,1,1], rec2 = [1,0,2,1]
输出：false

说明：
两个矩形 rec1 和 rec2 都以含有四个整数的列表的形式给出。
矩形中的所有坐标都处于 -10^9 和 10^9 之间。
***********************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	static bool isLineOverlap(int x1, int x2, int y1, int y2)
	{
		if(x1 >= y2 || x2 <= y1)
			return false;
		return true;
	}
	static bool isRectangleOverlap_1(vector<int>& rec1, vector<int>& rec2)
	{
		return isLineOverlap(rec1[0], rec1[2], rec2[0], rec2[2])
			   && isLineOverlap(rec1[1], rec1[3], rec2[1], rec2[3]);
	}
	static bool isRectangleOverlap_2(vector<int> &rec1, vector<int>& rec2)
	{
		return !(rec1[0] >= rec2[2] || rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1]);
	}
};

int main(int argc, char* argv[])
{
	vector<int> rec1 = {0,0,2,2};
	vector<int> rec2 = {1,1,3,3};
	Solution::isRectangleOverlap_2(rec1, rec2) ? cout << "true" << endl : cout << "false" << endl;
	return 0;
}