/*
* @Author: wilson_t
* @Date:   2020-08-03 00:33:15
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-03 00:34:06
*/
/*
你有两个 有序 且数组内元素互不相同的数组 nums1 和 nums2 。

一条 合法路径 定义如下：
选择数组 nums1 或者 nums2 开始遍历（从下标 0 处开始）。
从左到右遍历当前数组。
如果你遇到了 nums1 和 nums2 中都存在的值，那么你可以切换路径到另一个数组对应数字处继续遍历（但在合法路径中重复数字只会被统计一次）。
得分定义为合法路径中不同数字的和。

请你返回所有可能合法路径中的最大得分。

由于答案可能很大，请你将它对 10^9 + 7 取余后返回。
*/
//超时
class Solution {
public:
    long f[10000005];
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1000000007;
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for(int i = 0; i < n1; ++i) {
            mp1[nums1[i]] = i;
        }
        for(int i = 0; i < n2; ++i) {
            mp2[nums2[i]] = i;
        }
        int maxNum = max(nums1[n1 - 1], nums2[n2 - 1]);
        // vector<int>
        memset(f, 0, (maxNum + 1)*sizeof(int));
        // memset(f, 0, sizeof(f));
        for(int i = 1; i <= maxNum; ++i) {
            bool isIn1 = (mp1.find(i) != mp1.end());
            bool isIn2 = (mp2.find(i) != mp2.end());
            if(isIn1) {
                int low = mp1[i] - 1 < 0 ? 0 : nums1[mp1[i] - 1];
                f[i] = (long)f[low] + (long)nums1[mp1[i]];
            }
            if(isIn2) {
                int low = mp2[i] - 1 < 0 ? 0 : nums2[mp2[i] - 1];
                f[i] = max((long)f[low] + (long)nums2[mp2[i]], (long)f[i]);
            }
        }
        return max(f[nums1[n1 - 1]], f[nums2[n2 - 1]]) % MOD;
    }
};