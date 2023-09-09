/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-25 11:24:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-25 19:38:58
*/
/*********************************************************
* 题目[困难]：
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回滑动窗口中的最大值。
 
进阶：
你能在线性时间复杂度内解决此题吗？

示例:
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7]
解释:
  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 
提示：
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length
*********************************************************/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

namespace So1
{
    class Solution
    {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k)
        {
            vector<int> res;
            deque<int> window;
            for (int i = 0; i < nums.size(); i++)
            {
                if (!window.empty() && window.front() == i - k) window.pop_front();
                while (!window.empty() && nums[i] > nums[window.back()]) window.pop_back();
                window.push_back(i);
                if (i >= k - 1) res.push_back(nums[window.front()]);
            }
            return res;
        }
    };
};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> res;
        deque<int> window;
        deque<int> maxBuffer;
        int n = nums.size();
        int secondMax = -1e9;
        for(int i = 0; i < n; ++i)
        {
            if(window.size() < k)
            {
                window.push_back(nums[i]);
                if(maxBuffer.empty() || nums[i] > maxBuffer.back())
                    maxBuffer.push_back(nums[i]);
                else if(nums[i] > secondMax)
                    secondMax = nums[i];
            }
            else
            {
                res.push_back(maxBuffer.back());
                int tmp = window.front();
                window.pop_front();
                if(tmp == maxBuffer.front())
                    maxBuffer.pop_front();
                window.push_back(nums[i]);
                if(maxBuffer.empty())
                {
                    maxBuffer.push_back(secondMax);
                    secondMax = nums[i - 1];
                }
                if(nums[i] > maxBuffer.back())
                    maxBuffer.push_back(nums[i]);
                else if(nums[i] > secondMax)
                    secondMax = nums[i];
            }
        }
        res.push_back(maxBuffer.back());
        return res;
    }
};
int main(int argc, char* argv[])
{
    Solution soluter;
    vector<int> nums = {1, 3, 1, 2, 0, 5, 0, 3, 2, 1, 5, 6};
    int k = 3;
    vector<int> res = soluter.maxSlidingWindow(nums, k);
    for(auto& x : res)
    {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}