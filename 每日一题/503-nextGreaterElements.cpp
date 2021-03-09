/*
* @Author: wilson_t
* @Date:   2021-03-07 15:09:57
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-03-07 15:10:49
*/
/*
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。
数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，
这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

示例 1:
输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数；
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
注意: 输入数组的长度不会超过 10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-ii
 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> AA(2 * n);
        vector<int> next(2 * n, -1);
        for(int i = 0; i < n; ++i) AA[i] = AA[i + n] = nums[i];
        stack<int> sk;
        for(int i = 2 * n - 1; i >= 0; --i) {
            while(!sk.empty() && AA[sk.top()] <= AA[i]) {
                sk.pop();
            }
            next[i] = sk.empty() ? -1 : AA[sk.top()];
            sk.push(i);
        }
        vector<int> res(n);
        for(int i = 0; i < n; ++i) {
            if(next[i] != -1) res[i] = next[i];
            else res[i] = next[i + n];
        }
        return res;
    }
};


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> stk;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                ret[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ret;
    }
};
