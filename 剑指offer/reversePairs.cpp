/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-24 11:03:53
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-24 11:47:04
*/
/*********************************************************
* 题目[困难]：
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。

示例 1:
输入: [7,5,6,4]
输出: 5

限制：
0 <= 数组长度 <= 50000
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int res;
public:
    void merge(vector<int>& nums, int l, int mid, int r)
    {
        if(mid <= l || r <= mid) return;
        vector<int> left;
        vector<int> right;
        for(int i = l; i < mid; ++i) left.push_back(nums[i]);
        for(int i = mid; i < r; ++i) right.push_back(nums[i]);

        int i = 0, j = 0, idx = l;
        int n1 = left.size(), n2 = right.size();
        while(i < n1 && j < n2)
        {
            if(left[i] <= right[j])
            {
                nums[idx++] = left[i++];
            }
            else
            {
                res += (n1-i);
                nums[idx++] = right[j++];
            }
        }
        if(i == n1)
        {
            while(j < n2)
            {
                nums[idx++] = right[j++];
            }
        }
        else
        {
            while(i < n1)
            {
                nums[idx++] = left[i++];
                // res+=n2;
            }
        }
    }
    void mergeSort(vector<int>& nums, int l, int r)
    {
        if(l >= r-1) return;
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid, r);
        merge(nums, l, mid, r);
    }
    int reversePairs(vector<int>& nums)
    {
        res = 0;
        mergeSort(nums, 0, nums.size());
        return res;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {10,11,9,2,3,7,8,6,5,4,1};
    Solution soluter;
    cout << soluter.reversePairs(nums) << endl;
    return 0;
}