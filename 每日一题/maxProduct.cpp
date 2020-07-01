/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-18 10:20:02
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-18 20:33:22
*/
/*********************************************************
* 题目[中等]：
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），
并返回该子数组所对应的乘积。

示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
*********************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp1(n + 1);
        vector<int> dp2(n + 1);
        dp1[0] = nums[0];
        dp2[0] = nums[0];
        int res = nums[0];
        for(int i = 1; i < n; ++i)
        {
            dp1[i] = max(nums[i], max(nums[i] * dp1[i - 1], nums[i] * dp2[i - 1]));
            dp2[i] = min(nums[i], min(nums[i] * dp2[i - 1], nums[i] * dp1[i - 1]));
            res = max(res, dp1[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            cout << dp1[i] << ", ";
        }
        cout << endl;
        return res;
    }
};

// class Solution
// {
// public:
//     int maxProduct(vector<int>& nums)
//     {
//         int maxF = nums[0], minF = nums[0], ans = nums[0];
//         for (int i = 1; i < nums.size(); ++i)
//         {
//             int mx = maxF, mn = minF;
//             maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
//             minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
//             ans = max(maxF, ans);
//         }
//         return ans;
//     }
// };

int main(int argc, char* argv[])
{
    Solution soluter;
    vector<int> nums = {1, 2, 3, -3, -2, -1};
    cout << soluter.maxProduct(nums) << endl;
    return 0;
}