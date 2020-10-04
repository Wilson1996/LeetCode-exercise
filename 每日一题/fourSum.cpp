/*
* @Author: wilson_t
* @Date:   2020-10-05 00:19:31
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-05 00:20:33
*/
/*********************************************************
* 题目[中等]：
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
注意：
答案中不可以包含重复的四元组。

示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
*********************************************************/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 3; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) {
                continue;
            }
            for(int j = i + 1; j < n - 2; ++j) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) {
                    continue;
                }
                int p1 = j + 1, p2 = n - 1;
                int tmp = target - nums[i] - nums[j];
                while(p1 < p2) {
                    if(nums[p1] + nums[p2] == tmp) {
                        res.push_back({nums[i], nums[j], nums[p1], nums[p2]});
                        int pre = nums[p1];
                        while(p1 < p2 && nums[p1] == pre)
                            ++p1;
                    } else if(nums[p1] + nums[p2] > tmp) {
                        int pre = nums[p2];
                        while(p2 > p1 && nums[p2] == pre)
                            --p2;
                    } else {
                        int pre = nums[p1];
                        while(p1 < p2 && nums[p1] == pre)
                            ++p1;
                    }
                }
            }
        }
        return res;
    }
};
