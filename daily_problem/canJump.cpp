/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-17 00:12:37
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-17 00:46:53
*/
/*********************************************************
* 题目[中等]：
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。

示例 1:
输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。

示例 2:
输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
*********************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //dfs时间复杂度高，会超时
    static bool dfs(vector<int>& nums, int cur)
    {
        if(nums[cur] >= (nums.size() - 1 - cur))
            return true;
        for(int i = 1; i <= nums[cur]; ++i)
        {
            if(dfs(nums, cur + i))
                return true;
        }
        return false;
    }

    static bool canJump(vector<int>& nums)
    {
        return dfs(nums, 0);
    }

    static bool canJump2(vector<int>& nums)
    {
        int mostFar = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i <= mostFar)
            {
                mostFar = max(mostFar, i + nums[i]);
                if(mostFar >= nums.size() - 1)
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {2, 3, 1, 1, 4};
    // vector<int> nums = {3, 2, 1, 0, 4};
    Solution::canJump2(nums) ? cout << "true" << endl : cout << "false" << endl;
    return 0;
}