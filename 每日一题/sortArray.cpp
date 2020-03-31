/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-31 08:53:10
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-31 09:04:25
*/
/*********************************************************
给定一个整数数组 nums，将该数组升序排列。

示例 1：
输入：[5,2,3,1]
输出：[1,2,3,5]

示例 2：
输入：[5,1,1,2,0,0]
输出：[0,0,1,1,2,5]

提示：
1 <= A.length <= 10000
-50000 <= A[i] <= 50000
*********************************************************/
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int RandomInRange(int start, int end)
{
	srand((unsigned)time(NULL));
	return rand() % (end - start + 1) + start;
}

void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
class Solution
{
public:
	static int Partition(vector<int>& data, int start, int end)
	{
		if(data.size() <= 0 || start < 0 || end >= data.size())
		{
			// throw new std::exception("Invalid Parameters.");
			throw exception();
			abort();
		}
		int index = RandomInRange(start, end);
		Swap(&data[index], &data[end]);
		int small = start - 1;
		for (index = start; index < end; ++index)
		{
			if(data[index] < data[end])
			{
				++small;
				if(small != index)
					Swap(&data[index], &data[small]);
			}
		}
		++small;
		Swap(&data[small], &data[end]);
		return small;
	}
	static void QuickSort(vector<int>& data, int start, int end)
	{
		if(start == end)
			return;
		int index = Partition(data, start, end);
		if(index > start)
			QuickSort(data, start, index - 1);
		if(index < end)
			QuickSort(data, index + 1, end);
	}
	static vector<int> sortArray(vector<int>& nums)
	{
		vector<int> result = nums;
		QuickSort(result, 0, result.size()-1);
		return result;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> data = {5, 3, 7, 6, 4, 1, 0, 2, 9, 8 };
	vector<int> result = Solution::sortArray(data);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << ",";
	}
	cout << endl;
	return 0;
}