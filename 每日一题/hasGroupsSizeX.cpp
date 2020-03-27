/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-27 14:00:49
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-27 14:41:51
*/
/*********************************************************
* 题目[简单]：
给定一副牌，每张牌上都写着一个整数。此时，你需要选定一个数字 X，
使我们可以将整副牌按下述规则分成 1 组或更多组：每组都有 X 张牌。
组内所有的牌上都写着相同的整数。仅当你可选的 X >= 2 时返回 true。

示例 1：
输入：[1,2,3,4,4,3,2,1]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]

示例 2：
输入：[1,1,1,2,2,2,3,3]
输出：false
解释：没有满足要求的分组。

示例 3：
输入：[1]
输出：false
解释：没有满足要求的分组。

示例 4：
输入：[1,1]
输出：true
解释：可行的分组是 [1,1]

示例 5：
输入：[1,1,2,2,2,2]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[2,2]

提示：
1 <= deck.length <= 10000
0 <= deck[i] < 10000
*********************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	static bool hasGroupsSizeX(vector<int>& deck)
	{
		unordered_map<int, int> groups;
		for(int x : deck)
		{
			groups[x] += 1;
		}
		int X = groups.begin()->second;
		for(auto iter = groups.begin(); iter != groups.end(); ++iter)
		{
			// int minVal = min(X, iter->second);
			// int maxVal = max(X, iter->second);
			// if(maxVal / minVal * minVal != maxVal)
			// {
			// 	int Gcd = __gcd(maxVal, minVal);
			// 	if(Gcd == 1)
			// 		return false;
			// 	else
			// 		X = Gcd;
			// }
			// else
			// 	X = minVal;
			X = __gcd(X, iter->second);
			if(X == 1)
				return false;
		}
		return X >= 2;
	}
};

int main(int argc, char* argv[])
{
	// vector<int> deck = {1,2,3,4,4,3,2,1};
	vector<int> deck = {2,2,2,2,3,3,3,3,3,3};
	// vector<int> deck = {1,1,1,2,2,2,3,3};

	Solution::hasGroupsSizeX(deck) ? cout << "true" << endl : cout << "false" << endl;
	return 0;
}