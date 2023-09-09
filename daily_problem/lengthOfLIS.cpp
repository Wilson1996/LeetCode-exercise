/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-14 09:51:16
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-14 11:26:19
*/

/**************************************************************
*题目[中等]：
给定一个无序的整数数组，找到其中最长上升子序列的长度。

*示例:
输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

*说明:
可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。

*进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
***************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	//方法一：动态规划
	//dp[i]: 以nums[i]结尾的最长子序列的长度
	static int lengthOfLIS_1(vector<int>& nums)
	{
		if(nums.size() <= 0)
			return 0;
		int* dp = new int[nums.size()];
		dp[0] = 1;
		int theMax = 1;
		for(int i = 1; i < nums.size(); ++i)
		{
			int j;
			dp[i] = 1;
			for(j = i - 1; j >= 0; --j)
			{
				if(nums[i] > nums[j] && dp[j] + 1 > dp[i])
				{
					dp[i] = dp[j] + 1;
				}
			}
			if(dp[i] > theMax)
				theMax = dp[i];
		}
		for(int i = 0; i < nums.size(); ++i)
		{
			cout << dp[i] << ", ";
		}
		cout << endl;
		delete[] dp;
		return theMax;
	}

	/*
	方法二：贪心+二分查找
	   考虑一个简单的贪心，如果我们要使上升子序列尽可能的长，则我们需要让序列上
	   升得尽可能慢，因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
	   维护一个数组 d[i]，表示长度为 i 的最长上升子序列的末尾元素的最小值.

	最后整个算法流程为：
	*设当前已求出的最长上升子序列的长度为len（初始时为 1），从前往后遍历数组nums，在遍历到nums[i] 时：
		>如果nums[i]>d[len] ，则直接加入到d数组末尾，并更新len = len + 1;
		>否则，在d数组中二分查找，找到第一个比nums[i] 小的数d[k] ，并更新d[k+1]=nums[i].
	*/
	static int lengthOfLIS_2(vector<int>& nums)
	{
		int len = 1, n = (int)nums.size();
		if (n == 0) return 0;
		vector<int> d(n + 1, 0);
		d[len] = nums[0];
		for (int i = 1; i < n; ++i)
		{
			if (nums[i] > d[len]) d[++len] = nums[i];
			else
			{
				int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
				while (l <= r)
				{
					int mid = (l + r) >> 1;
					if (d[mid] < nums[i])
					{
						pos = mid;
						l = mid + 1;
					}
					else r = mid - 1;
				}
				d[pos + 1] = nums[i];
			}
		}
		return len;
	}
};

int main(int argc, char* argv[])
{
	vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
	// vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
	cout << Solution::lengthOfLIS_2(nums) << endl;
	return 0;
}