/*
* @Author: wilson_t
* @Date:   2020-08-23 13:17:44
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-23 13:21:00
*/
/*
给你一个数组 arr ，该数组表示一个从 1 到 n 的数字排列。有一个长度为 n 的二进制字符串，该字符串上的所有位最初都设置为 0 。
在从 1 到 n 的每个步骤 i 中（假设二进制字符串和 arr 都是从 1 开始索引的情况下），二进制字符串上位于位置 arr[i] 的位将会设为 1 。
给你一个整数 m ，请你找出二进制字符串上存在长度为 m 的一组 1 的最后步骤。一组 1 是一个连续的、由 1 组成的子串，且左右两边不再有可以延伸的 1 。
返回存在长度 恰好 为 m 的 一组 1  的最后步骤。如果不存在这样的步骤，请返回 -1 。

提示：
n == arr.length
1 <= n <= 10^5
1 <= arr[i] <= n
arr 中的所有整数 互不相同
1 <= m <= arr.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-latest-group-of-size-m
*/
class Solution {
    int n;
    vector<int> parent;
    vector<int> cnt;
public:
    int find(int idx) {
        if(parent[idx] == -1) {
            parent[idx] = idx;
            return idx;
        }
        if(idx == parent[idx]) {
            return idx;
        }
        parent[idx] = find(parent[idx]);
        return parent[idx];
    }
    void join(int x1, int x2) {
        int r1 = find(x1);
        int r2 = find(x2);
        if(r1 != r2) {
            parent[r1] = r2;
            cnt[r2] += cnt[r1];
            cnt[r1] = 0;
        }
    }
    int findLatestStep(vector<int>& arr, int m) {
        n = arr.size();
        vector<bool> has(n, false);
        parent = vector<int>(n, -1);
        cnt = vector<int>(n, 0);
        int res = 0;
        int mCnt = 0;
        for(int i = 0; i < n; ++i) {
            int idx = arr[i] - 1;
            parent[idx] = idx;
            cnt[idx] = 1;
            if(idx > 0 && parent[idx - 1] != -1) {
                if(cnt[find(idx - 1)] == m) mCnt--;
                join(idx - 1, idx);
            }
            if(idx < n - 1 && parent[idx + 1] != -1) {
                if(cnt[find(idx + 1)] == m) mCnt--;
                join(idx + 1, idx);
            }
            if(cnt[find(idx)] == m) {
                ++mCnt;
            }
            if(mCnt > 0) {
                has[i] = true;
            }
        }
        int i = n - 1;
        for(; i >= 0; --i) {
            if(has[i]) break;
        }
        if(i < 0) return -1;
        return i + 1;
    }
};