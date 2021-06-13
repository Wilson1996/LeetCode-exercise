/*
* @Author: wilson_t
* @Date:   2021-06-03 12:48:51
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-03 12:48:58
*/

/*
给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。

示例 1:
输入: nums = [0,1]
输出: 2
说明: [0, 1] 是具有相同数量0和1的最长连续子数组。

示例 2:
输入: nums = [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
 
提示：
1 <= nums.length <= 105
nums[i] 不是 0 就是 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contiguous-array
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        //[j, i]
        //2(pre[i+1] - pre[j]) = i+1 -j
        //2pre[i+1] - (i+1) = 2pre[j] - j;
        unordered_map<int, int> mp;
        int pre = 0, res = 0;
        mp[0] = 0;
        for(int i = 0; i < n; ++i) {
            pre += nums[i];
            int now = 2 * pre - (i + 1);
            if(mp.count(now)) {
                res = max(res, i + 1 - mp[now]);
            } else {
                mp[now] = i + 1;
            }
        }
        return res;
    }
};