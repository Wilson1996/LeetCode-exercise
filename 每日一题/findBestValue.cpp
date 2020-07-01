/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-14 00:18:39
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-14 01:14:26
*/
/*********************************************************
* 题目[中等]：
给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，
使得将数组中所有大于 value 的值变成 value 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。
如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。
请注意，答案不一定是 arr 中的数字。

示例 1：
输入：arr = [4,9,3], target = 10
输出：3
解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。

示例 2：
输入：arr = [2,3,5], target = 10
输出：5

示例 3：
输入：arr = [60864,25176,27249,21296,20204], target = 56803
输出：11361
 
提示：
1 <= arr.length <= 10^4
1 <= arr[i], target <= 10^5
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

//思路：嵌套二分查找
class Solution
{
public:
    int findBestValue(vector<int>& arr, int target)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> pre(n + 1, 0);
        pre[0] = 0;
        for(int i = 1; i <= n; ++i) pre[i] = arr[i - 1] + pre[i - 1];
        int l = 0, r = arr.back() + 1;
        int lastDis = 1e9;
        int lastRes = 1e9;
        while(l < r)
        {
            int mid  = (l + r) / 2;
            auto low = lower_bound(arr.begin(), arr.end(), mid);
            int tmpSum = pre[low - arr.begin()] + (arr.end() - low) * mid;
            int diff = abs(tmpSum - target);
            if(diff < lastDis || (diff == lastDis && mid < lastRes))
            {
                lastDis = diff;
                lastRes = mid;
            }
            if(tmpSum == target) return mid;
            else if(tmpSum < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return lastRes;
    }
};