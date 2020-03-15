/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-13 19:34:18
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-15 20:01:34
*/
/**************************************************************
* 题目[简单]：
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

* 示例 1:
输入: [3,2,3]
输出: 3

* 示例 2:
输入: [2,2,1,1,1,2,2]
输出: 2
***************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	//方法一：哈希表
	static int majorityElement_1(vector<int>& nums)
	{
		unordered_map<int, int> mySet;
		for(int i = 0; i < nums.size(); ++i)
		{
			mySet[nums[i]] += 1;
			if(mySet[nums[i]] > nums.size() / 2)
				return nums[i];
		}
		return 0;
	}
	/*
	//方法二：Boyer-Moore 投票算法
	* Boyer-Moore 算法的本质和方法四中的分治十分类似。我们首先给出 Boyer-Moore 算法的详细步骤：
		我们维护一个候选众数 candidate 和它出现的次数 count。初始时 candidate 可以为任意值，count 为 0；
		我们遍历数组 nums 中的所有元素，对于每个元素 x，在判断 x 之前，如果 count 的值为 0，我们先将 x 
		的值赋予 candidate，随后我们判断 x：
			如果 x 与 candidate 相等，那么计数器 count 的值增加 1；
			如果 x 与 candidate 不等，那么计数器 count 的值减少 1。
		在遍历完成后，candidate 即为整个数组的众数。
	*/
	static int majorityElement_2(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};

int main(int argc, char* argv[])
{
	vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
	// vector<int> nums = {3,2,3};
	cout << Solution::majorityElement_2(nums) << endl;
}