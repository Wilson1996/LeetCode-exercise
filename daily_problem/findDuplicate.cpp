/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-26 08:15:47
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-26 09:10:54
*/
/*********************************************************
* 题目[中等]：
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），
可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:
输入: [1,3,4,2,2]
输出: 2

示例 2:
输入: [3,1,3,4,2]
输出: 3

说明：
不能更改原数组（假设数组是只读的）。	(不能排序)
只能使用额外的 O(1) 的空间。			(不能使用哈希表)
时间复杂度小于 O(n^2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。
*********************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    //计数，空间复杂度不符合要求
    int findDuplicate(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> Count(n + 1, 0);
        for(int i = 0; i < n; ++i)
        {
            ++Count[nums[i]];
            if(Count[nums[i]] > 1)
                return nums[i];
        }
        return -1;
    }
    //快慢指针寻环问题，T=O(n) V=O(1)
    int findDuplicate(vector<int>& nums)
    {
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);
        slow = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    //链接：https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode-solution/
    //二分查找 T=O(nlgn)
    int findDuplicate3(vector<int>& nums)
    {
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i)
            {
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
    //二进制位运算 T=O(nlgn)
    int findDuplicate4(vector<int>& nums)
    {
        int n = nums.size(), ans = 0;
        // 确定二进制下最高位是多少
        int bit_max = 31;
        while (!((n - 1) >> bit_max))
        {
            bit_max -= 1;
        }
        for (int bit = 0; bit <= bit_max; ++bit)
        {
            int x = 0, y = 0;
            for (int i = 0; i < n; ++i)
            {
                if (nums[i] & (1 << bit))
                {
                    x += 1;
                }
                if (i >= 1 && (i & (1 << bit)))
                {
                    y += 1;
                }
            }
            if (x > y)
            {
                ans |= 1 << bit;
            }
        }
        return ans;
    }

};