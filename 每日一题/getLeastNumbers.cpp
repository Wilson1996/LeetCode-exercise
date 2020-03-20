/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-20 09:49:43
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-20 17:36:20
*/
/********************************************************
* 题目[简单]：
输入整数数组 arr ，找出其中最小的 k 个数。
例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]

限制：
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
* 方法：
1、使用快速排序中的partition操作
2、使用优先队列
********************************************************/
#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
	static vector<int> getLeastNumbers(vector<int>& arr, int k)
	{
		vector<int> result;
		if(k <= 0)
			return result;
		//大顶堆
		priority_queue<int, vector<int>, less<int>> Q;
		for(int x : arr)
		{
			if(Q.size() < k)
				Q.push(x);
			else if(x < Q.top())
			{
				Q.pop();
				Q.push(x);
			}
		}
		while(!Q.empty())
		{
			result.push_back(Q.top());
			Q.pop();
		}
		return result;
	}
};

int main(int argc, char* argv[])
{
	vector<int> arr = {4, 5, 1, 6, 2, 7, 3, 8};
	vector<int> result = Solution::getLeastNumbers(arr, 4);
	for(int x : result)
	{
		cout << x << ", ";
	}
	cout << endl;
	return 0;
}
