/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-30 09:11:58
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-30 11:39:08
*/
/*********************************************************
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

示例 1：
输入：nums = [3,4,3,3]
输出：4

示例 2：
输入：nums = [9,1,7,9,7,9,7]
输出：1
 
限制：
1 <= nums.length <= 10000
1 <= nums[i] < 2^31
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
	int base;
public:
    void dec2Ternary(int a, vector<int>& t)
    {
        int idx = 0;
        while(a != 0)
        {
            t[idx] += a % 3;
            t[idx] %= 3;
            ++idx;
            a /= 3;
        }
    }
    int ternary2dec(vector<int>& t)
    {
        int n = t.size();
        int res = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            res = res * 3 + t[i];
        }
        return res;
    }
    int singleNumber(vector<int>& nums)
    {
        vector<int> t(21, 0);
        for(auto& x : nums)
        {
            dec2Ternary(x, t);
        }
        return ternary2dec(t);
    }
};