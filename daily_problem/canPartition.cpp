/*
* @Author: wilson_t
* @Date:   2020-10-11 00:27:39
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-11 00:51:42
*/
/********************************
* 题目[中等]：
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:
每个数组中的元素不会超过 100
数组的大小不会超过 200

示例 1:
输入: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].
 
示例 2:
输入: [1, 2, 3, 5]
输出: false
解释: 数组不能分割成两个元素和相等的子集.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
********************************/
#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size(), lsum, rsum;
//         for(int i = 0; i < n - 1; ++i) lsum += nums[i];
//         rsum = nums[n - 1];
//         vector<bool> mark(n, false);
//         mark[n - 1] = true;
//         while(lsum >= rsum) {
//             if(lsum == rsum) return true;
//             for(int i = 0; i < n; ++i) {
//                 if()
//                 }
//         }
//         return false;
//     }
// };

// class Solution {
//     int n;
// public:
//     bool dfs(vector<int>& nums, int start, int target) {
//         if(target == 0) return true;
//         for(int i = start; i < n && nums[i] <= target; ++i) {
//             if(dfs(nums, i + 1, target - nums[i])) return true;
//         }
//         return false;
//     }
//     bool canPartition(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         n = nums.size();
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if(sum & 1) return false;
//         int target = sum / 2;
//         return dfs(nums, 0, target);
//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int target = sum / 2;
        vector<vector<bool>> f(n, vector<bool>(target + 1, 0));
        for (int j = 0; j <= target; ++j) {
            f[0][j] = nums[0] == target ? true : false;
        }
        for(int i = 0; i < n; ++i) {
            f[i][0] = true;
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j <= target; ++j) {
                f[i][j] = f[i - 1][j];
                if(nums[i] <= j) {
                    f[i][j] = f[i][j] || f[i - 1][j - nums[i]];
                }
            }
        }
        return f[n - 1][target];
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {3, 4, 5, 9, 11};
    cout << Solution().canPartition(nums) << endl;
    return 0;
}

