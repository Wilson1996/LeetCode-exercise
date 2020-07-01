/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-29 09:25:07
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-29 10:24:22
*/
/*********************************************************
* 题目[困难]：
给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。
如果不存在这样的下标 index，就请返回 -1。

何为山脉数组？如果数组 A 是一个山脉数组的话，那它满足如下条件：
首先，A.length >= 3
其次，在 0 < i < A.length - 1 条件下，存在 i 使得：
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
你将 不能直接访问该山脉数组，必须通过 MountainArray 接口来获取数据：
MountainArray.get(k) - 会返回数组中索引为k 的元素（下标从 0 开始）
MountainArray.length() - 会返回该数组的长度
 
注意：
对 MountainArray.get 发起超过 100 次调用的提交将被视为错误答案。
此外，任何试图规避判题系统的解决方案都将会导致比赛资格被取消。

示例 1：
输入：array = [1,2,3,4,5,3,1], target = 3
输出：2
解释：3 在数组中出现了两次，下标分别为 2 和 5，我们返回最小的下标 2。

示例 2：
输入：array = [0,1,2,4,2,1], target = 3
输出：-1
解释：3 在数组中没有出现，返回 -1。
 
提示：
3 <= mountain_arr.length() <= 10000
0 <= target <= 10^9
0 <= mountain_arr.get(index) <= 10^9
*********************************************************/
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int getPeek(MountainArray& arr, int l, int r)
    {
        if(r - l == 1)
            return l;
        else if(r - l == 2)
        {
            int h_l = arr.get(l);
            int h_r = arr.get(r-1);
            return h_l > h_r ? l : r-1;
        }
        if(l < r)
        {
            int mid = (l + r) / 2;
            int h_mid = arr.get(mid);
            // int h_mid_1 = arr.get(mid - 1);
            int h_l = arr.get(mid-1);
            int h_r = arr.get(mid+1);
            if(h_mid >= h_l && h_mid >= h_r)
                return mid;
            else if(mid - 1 >= 0 && h_mid > h_l)
            {
                return getPeek(arr, mid + 1, r);
            }
            else
                return getPeek(arr, l, mid);
        }
        return l;
    }
    int binSearch(int target, MountainArray& arr, int l, int r, bool isUp)
    {
        if(l < r)
        {
            int mid = (l + r) / 2;
            int h_mid = arr.get(mid);
            if(target == h_mid)
                return mid;
            else if((isUp && target < h_mid) || (!isUp && target > h_mid))
                return binSearch(target, arr, l, mid, isUp);
            else
                return binSearch(target, arr, mid + 1, r, isUp);
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray& mountainArr)
    {
        int peek = getPeek(mountainArr, 0, mountainArr.length());
        // cout << "peek: " << peek << endl;
        if(mountainArr.get(peek) == target)
            return peek;
        int pos = binSearch(target, mountainArr, 0, peek, true);
        if(-1 != pos)
            return pos;
        else
            return binSearch(target, mountainArr, peek + 1, mountainArr.length(), false);
    }
};
