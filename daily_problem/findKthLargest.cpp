/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-29 00:03:31
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-29 00:30:29
*/
/*********************************************************
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组
排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

说明:
你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
*********************************************************/
class Solution
{
public:
	//方法一：基于partition的方式
    int randomInRange(int start, int end)
    {
        return rand() % (end - start + 1) + start;
    }
    int partition(vector<int>& data, int start, int end)
    {
        int index = randomInRange(start, end);
        swap(data[index], data[end]);
        int small = start - 1;
        for (index = start; index < end; ++index)
        {
            if(data[index] < data[end])
            {
                ++small;
                if(small != index)
                    swap(data[index], data[small]);
            }
        }
        ++small;
        swap(data[small], data[end]);
        return small;
    }
    int findKthLargest(vector<int>& nums, int k)
    {
        srand((unsigned)time(NULL));
        int n  = nums.size();
        k = n - k;
        int l = 0, r = n - 1;
        while(l <= r)
        {
            int index = partition(nums, l, r);
            if(index == k) return nums[index];
            else if(index < k)
            {
                l = index + 1;
            }
            else
            {
                r = index - 1;
            }
        }
        return nums[l];
    }
};
//方法二：小顶堆
class Solution2
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> Q;
        for(auto& x : nums)
        {
            if(Q.size() < k) Q.push(x);
            else if(x > Q.top()){
                Q.pop();
                Q.push(x);
            }
        }
        return Q.top();
    }
};