/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-24 09:26:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-24 10:15:00
*/
/****************************************************************
* 题目[简单]：
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。
在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，
替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

注意：本题相对原题稍作改动

示例 1：
输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。

示例 2：
输入： [2,7,9,3,1]
输出： 12
解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。

示例 3：
输入： [2,1,4,5,3,1,1,3]
输出： 12
解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。
****************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	//方法一：动态规划 dp[i]:以nums[i]结尾的最大结果
	static int massage1(vector<int>& nums)
	{
		if(nums.size() <= 0)
			return 0;
		int pre_max = 0;
		int result = nums[0];
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		for(int i = 1; i < nums.size(); ++i)
		{
			dp[i] = nums[i] + pre_max;
			result = dp[i] > result ? dp[i] : result;
			pre_max = dp[i - 1] > pre_max ? dp[i - 1] : pre_max;
		}
		for(int x:dp)
		{
			cout << x << ", ";
		}
		cout << endl;
		return result;
	}
	//方法二：动态规划 dp[i]: 索引i前面组成的最大结果
	static int massage2(vector<int>& nums)
	{
		if(nums.size() <= 0)
			return 0;
		if(nums.size() == 1)
			return nums[0];
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for(int i = 2; i < nums.size(); ++i)
		{
			dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
		}
		for(int x:dp)
		{
			cout << x << ", ";
		}
		cout << endl;
		return dp[nums.size() - 1];
	}
	//优化空间复杂度
	static int massage2_1(vector<int>& nums)
	{
		if(nums.size() <= 0)
			return 0;
		if(nums.size() == 1)
			return nums[0];
		int pre_pre_dp = nums[0];
		int pre_dp = max(nums[0],nums[1]);
		int dp = max(pre_pre_dp, pre_dp);
		cout << dp << ", ";
		for(int i = 2; i < nums.size(); ++i)
		{
			dp = max(pre_dp, pre_pre_dp + nums[i]);
			cout << dp << ", ";
			pre_pre_dp = pre_dp;
			pre_dp = dp;
		}
		cout << endl;
		return dp;
	}
};

int main(int argc, char* argv[])
{
	// vector<int> nums = {2, 1, 4, 5, 3, 1, 1, 3};
	// vector<int> nums = {2,7,9,3,1};
	vector<int> nums = {2,1,1,2};

	cout << Solution::massage2_1(nums) << endl;
	return 0;
}