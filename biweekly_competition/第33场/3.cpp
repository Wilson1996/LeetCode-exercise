/*
* @Author: wilson_t
* @Date:   2020-08-23 12:56:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-23 13:14:06
*/
/*
给你一个与 nums 大小相同且初始值全为 0 的数组 arr ，请你调用以上函数得到整数数组 nums 。
请你返回将 arr 变成 nums 的最少函数调用次数。
答案保证在 32 位有符号整数以内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-numbers-of-function-calls-to-make-target-array
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, m = 0;
        for(int x : nums) {
            int n = 0;
            while(x) {
                if(x & 1) {
                    x -= 1;
                    ans += 1;
                } else {
                    x /= 2;
                    n += 1;
                }
            }
            m = max(m, n);
        }
        return ans + m;
    }
};