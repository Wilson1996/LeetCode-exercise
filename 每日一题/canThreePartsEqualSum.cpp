/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-11 08:58:18
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-11 10:56:54
*/

/****************************************************************
* 题目[简单]：
* 给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。
* 形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i]
* == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。
*
* 示例 1：
* 输入：[0,2,1,-6,6,-7,9,1,2,0,1]
* 输出：true
* 解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
*
* 示例 2：
* 输入：[0,2,1,-6,6,7,9,-1,2,0,1]
* 输出：false
*
* 提示：
* 3 <= A.length <= 50000
* -10^4 <= A[i] <= 10^4
****************************************************************/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
	//方法一：暴力求解
	static bool canThreePartsEqualSum(vector<int> &A)
	{
		if (A.size() <= 2)
			return false;
		vector<int> B(A.size(), 0);
		B[0] = A[0];
		for (int i = 1; i < A.size(); ++i)
		{
			B[i] = B[i - 1] + A[i];
		}
		for (int i = 0; i < B.size(); ++i)
		{
			cout << B[i] << ", ";
		}
		cout << endl;
		int rightNum = B.back();
		for (int i = 0; i < B.size(); ++i)
		{
			int middleNum = (rightNum + B[i]) / 2;
			if (middleNum - B[i] == B[i])
			{
				for (int j = i + 1; j < B.size() - 1; ++j)
				{
					if (B[j] == middleNum)
					{
						cout << i << ", " << j << endl;
						return true;
					}
				}
			}
		}
		return false;
	}
	//方法二：贪心算法
	static bool canThreePartsEqualSum2(vector<int> &A)
	{
		if (A.size() <= 2)
			return false;
		int sum = accumulate(A.begin(), A.end(), 0);
		if (sum % 3 != 0)
			return false;
		int tempSum = 0;
		bool findFirst = false;
		// cout << sum << endl;
		for (int i = 0; i < A.size() - 1; ++i)
		{
			tempSum += A[i];
			if (!findFirst && tempSum == sum / 3)
			{
				cout << "i = " << i << "  tempSum: " << tempSum << endl;
				findFirst = true;
			}
			else if (findFirst && tempSum == sum * 2 / 3)
			{
				cout << "i = " << i << "  tempSum: " << tempSum << endl;
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char* argv[])
{
	vector<int> A = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
	// vector<int> A = {0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
	// vector<int> A = {1, -1, 1, -1};
	Solution::canThreePartsEqualSum2(A) ? cout << "yes" << endl : cout << "no" << endl;
	return 0;
}