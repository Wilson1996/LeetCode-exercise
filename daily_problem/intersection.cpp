/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-12 11:37:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-12 18:47:55
*/
/*********************************************************
* 题目[困难]：
给定两条线段（表示为起点start = {X1, Y1}和终点end = {X2, Y2}），
如果它们有交点，请计算其交点，没有交点则返回空值。要求浮点型误差
不超过10^-6。若有多个交点（线段重叠）则返回 X 值最小的点，X 坐标相同则返回 Y 值最小的点。

示例 1：
输入：
line1 = {0, 0}, {1, 0}
line2 = {1, 1}, {0, -1}
输出： {0.5, 0}

示例 2：
输入：
line1 = {0, 0}, {3, 3}
line2 = {1, 1}, {2, 2}
输出： {1, 1}

示例 3：
输入：
line1 = {0, 0}, {1, 1}
line2 = {1, 0}, {2, 1}
输出： {}，两条线段没有交点

提示：
坐标绝对值不会超过 2^7
输入的坐标均是有效的二维坐标
*********************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	static vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2)
	{
		vector<double> result;
		int x1 = start1[0], y1 = start1[1], x2 = end1[0], y2 = end1[1],
		x3 = start2[0], y3 = start2[1], x4 = end2[0], y4 = end2[1];
		int _y = y2 - y1 + y3 - y4;
		int tmp = y3*x4 - y4*x3 + y2*x1 - y1*x2;
		double commonX = 0, commonY = 0;
		if(_y != 0)
		{
			commonX = (double)(tmp) / _y;
		}
		else if(tmp != 0)
		{
			return result;
		}
		else
		{
			commonX = min(min(x1, x2), min(x3, x4));
		}
		if(x2 - x1 != 0)
		{
			commonY = (double)(y2-y1)/(x2-x1)*(commonX-x1)+y1;
		}
		else
		{
			commonY = (double)(y4-y3)/(x4-x3)*(commonX-x3)+y3;
		}

	
		result.push_back(commonX);
		result.push_back(commonY);

		return result;
	}
};

int main(int argc, char* argv[])
{
	vector<int> start1 = {0, 0};
	vector<int> end1 = {3, 3};
	vector<int> start2 = {1, 1};
	vector<int> end2 = {2, 2};
	vector<double> result = Solution::intersection(start1, end1, start2, end2);
	if(!result.empty())
		cout << "{" << result[0] << ", " << result[1] << "}" << endl;
	return 0;
}