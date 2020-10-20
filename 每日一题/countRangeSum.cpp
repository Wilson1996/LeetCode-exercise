/*
* @Author: wilson_t
* @Date:   2020-10-20 01:41:57
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-20 09:56:23
*/
/*
* 题目[困难]：
给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
说明:
最直观的算法复杂度是 O(n2) ，请在此基础上优化你的算法。

示例:
输入: nums = [-2,5,-1], lower = -2, upper = 2,
输出: 3
解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-of-range-sum
*/
using ll = long long;
class Solution {
    vector<int> cv;
    int cn;
public:
    int lowbit(int x) {
        return x & (-x);
    }

    void update(int i, int x) {
        while(i <= cn) {
            cv[i] += x;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += cv[i];
            i -= lowbit(i);
        }
        return sum;
    }

    int countRangeSum(vector<int>& nums, int low, int up) {
        int n = nums.size(), res = 0;
        ll sum = 0;
        set<ll> ms;
        ms.insert(0);
        unordered_map<ll, int> mp;
        //树状数组离散化
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            ms.insert(sum);
            ms.insert(sum - low);
            ms.insert(sum - up);
        }
        int rank = 1;
        for(auto& x : ms) {
            mp[x] = rank++;
        }
        cn = mp.size();
        cv = vector<int>(cn + 1, 0);
        sum = 0;
        update(mp[0], 1);
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            res += (query(mp[sum - low]) - query(mp[sum - up] - 1));
            update(mp[sum], 1);
        }
        return res;
    }
};