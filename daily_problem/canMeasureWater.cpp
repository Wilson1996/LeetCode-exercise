/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-21 10:18:24
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-21 11:03:17
*/
/**********************************************************
* 题目[中等]：
有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

你允许：
装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空

示例 1: (From the famous "Die Hard" example)
输入: x = 3, y = 5, z = 4
输出: True

示例 2:
输入: x = 2, y = 6, z = 5
输出: False
* 方法一：深度优先搜索
* 方法二：数学(裴蜀定律)
**********************************************************/
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
class Solution
{
public:
	//ax+by=z => z是x,y的最大公约数的倍数
	static bool canMeasureWater(int x, int y, int z)
	{
		if(x + y < z)
			return false;
		if(x == 0 || y == 0)
			return z == 0 || x + y == z;
		return z % gcd(x, y) == 0;
	}
};

int main(int argc, char* argv[])
{
	Solution::canMeasureWater(6, 8, 4) ? cout << "True" << endl : cout << "False" << endl;
	return 0;
}