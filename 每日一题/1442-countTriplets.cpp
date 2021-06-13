/*
* @Author: wilson_t
* @Date:   2021-05-18 13:00:57
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-05-18 13:02:34
*/
/*
给你一个整数数组 arr 。
现需要从数组中取三个下标 i、j 和 k ，其中 (0 <= i < j <= k < arr.length) 。
a 和 b 定义如下：
a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
注意：^ 表示 按位异或 操作。
请返回能够令 a == b 成立的三元组 (i, j , k) 的数目。
 
示例 1：
输入：arr = [2,3,1,6,7]
输出：4
解释：满足题意的三元组分别是 (0,1,2), (0,2,2), (2,3,4) 以及 (2,4,4)

示例 2：
输入：arr = [1,1,1,1,1]
输出：10

示例 3：
输入：arr = [2,3]
输出：0

示例 4：
输入：arr = [1,3,5,7,9]
输出：3

示例 5：
输入：arr = [7,11,12,9,5,2,7,17,22]
输出：8
 
提示：
1 <= arr.length <= 300
1 <= arr[i] <= 10^8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor
 */

// O(n^2)算法
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0;
        int pre = 0;
        for(int j = 1; j < n; ++j) {
            int Xor = 0;
            for(int k = j; k < n; ++k) {
                Xor ^= arr[k];
                if(mp.count(Xor ^ pre ^ arr[j - 1])) res += mp[Xor ^ pre ^ arr[j - 1]];
            }
            pre ^= arr[j - 1];
            mp[pre]++;
        }
        return res;
    }
};

// O(n)算法
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt, total;
        int ans = 0, s = 0;
        for (int k = 0; k < n; ++k) {
            int val = arr[k];
            if (cnt.count(s ^ val)) {
                ans += cnt[s ^ val] * k - total[s ^ val];
            }
            ++cnt[s];
            total[s] += k;
            s ^= val;
        }
        return ans;
    }
};

