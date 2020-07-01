/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-24 11:10:36
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-28 20:03:15
*/
/*********************************************************
* 题目[困难]：
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。

示例 1:
输入: [7,5,6,4]
输出: 5
*********************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    int result;
public:
    void mergeCount(vector<int>& nums, int l, int mid, int r)
    {
        vector<int> tmp1;
        vector<int> tmp2;
        for(int i = 0; i < mid - l; ++i) tmp1.push_back(nums[l + i]);
        for(int i = 0; i < r - mid; ++i) tmp2.push_back(nums[mid + i]);
        // int maxLen = max(tmp1.size(), tmp2.size());
        int index = l;
        for(int i = 0, j = 0; i < tmp1.size() || j < tmp2.size(); )
        {
            if(i >= tmp1.size()) {nums[index++] = tmp2[j++];}
            else if(j >= tmp2.size()) {nums[index++] = tmp1[i++];}
            else
            {
                if(tmp1[i] <= tmp2[j])
                    nums[index++] = tmp1[i++];
                else
                {
                    nums[index++] = tmp2[j++];
                    result += 1;
                }
            }
        }
    }
    void mergeCountSort(vector<int>& nums, int l, int r)
    {
        cout << "------------------" << endl;
        if(l < r)
        {
            int mid = (l + r) / 2;
            mergeCountSort(nums, l, mid);
            mergeCountSort(nums, mid, r);
            mergeCount(nums, l, mid, r);
        }
    }
    int reversePairs(vector<int>& nums)
    {
        result = 0;
        mergeCountSort(nums, 0, nums.size());
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {7, 5, 6, 4};
    Solution soluter;
    cout << soluter.reversePairs(nums) << endl;
    return 0;
}