/*
* @Author: wilson_t
* @Date:   2020-12-04 10:41:37
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-04 10:54:55
*/
/**
给你一个由 n 个正整数组成的数组 nums 。
你可以对数组的任意元素执行任意次数的两类操作：
如果元素是 偶数 ，除以 2
例如，如果数组是 [1,2,3,4] ，那么你可以对最后一个元素执行此操作，使其变成 [1,2,3,2]
如果元素是 奇数 ，乘上 2
例如，如果数组是 [1,2,3,4] ，那么你可以对第一个元素执行此操作，使其变成 [2,2,3,4]
数组的 偏移量 是数组中任意两个元素之间的 最大差值 。
返回数组在执行某些操作之后可以拥有的 最小偏移量 。

示例 1：
输入：nums = [1,2,3,4]
输出：1
解释：你可以将数组转换为 [1,2,3,2]，然后转换成 [2,2,3,2]，偏移量是 3 - 2 = 1

示例 2：
输入：nums = [4,1,5,20,3]
输出：3
解释：两次操作后，你可以将数组转换为 [4,2,5,5,3]，偏移量是 5 - 2 = 3

示例 3：
输入：nums = [2,10,8]
输出：3

提示：
n == nums.length
2 <= n <= 105
1 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimize-deviation-in-array
 */
using PII = pair<int, int>;
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(), cnt, res, mi, mx, nowMx;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        mi = INT_MAX, mx = 0, nowMx = 0;
        for(int x : nums) {
            mi = min(mi, x);
            mx = max(mx, x);
            if(x & 1) {
                cnt = 1;
            } else {
                cnt = 0;
                while(x % 2 == 0) {
                    cnt++;
                    x /= 2;
                }
            }
            pq.emplace(x, cnt);
            nowMx = max(nowMx, x);
        }
        res = mx - mi;
        while(pq.top().second > 0) {
            auto [val, count] = pq.top();
            pq.pop();
            int nxt = val * 2;
            pq.emplace(nxt, count - 1);
            nowMx = max(nowMx, nxt);
            res = min(res, nowMx - pq.top().first);
        }
        return res;
    }
};


//from Heltion
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int p_max = 1;
        for(int a : nums) p_max = max(p_max, a >> (__builtin_ctz(a)));
        vector<int> upper;
        int min = p_max;
        for(int a : nums) {
            if(a & 1) a <<= 1;
            if(a >= p_max) {
                a >>= __builtin_clz(p_max) - __builtin_clz(a);
                if(a < p_max) a <<= 1;
                upper.push_back(a);
            }
            min = std::min(min, a);
        }
        sort(upper.begin(), upper.end());
        int ans = upper.back() - min;
        for(int i = upper.size() - 1; upper[i] > p_max; i -= 1) {
            min = std::min(min, upper[i] >> 1);
            ans = std::min(ans, upper[i - 1] - min);
        }
        return ans;
    }
};