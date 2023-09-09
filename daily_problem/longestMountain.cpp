/*
* @Author: wilson_t
* @Date:   2020-10-25 00:59:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-25 01:00:12
*/
/*********************************************************
* 题目[中等]：
我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：
B.length >= 3
存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
（注意：B 可以是 A 的任意子数组，包括整个数组 A。）
给出一个整数数组 A，返回最长 “山脉” 的长度。
如果不含有 “山脉” 则返回 0。
 
示例 1：
输入：[2,1,4,7,3,2,5]
输出：5
解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。

示例 2：
输入：[2,2,2]
输出：0
解释：不含 “山脉”。

提示：
0 <= A.length <= 10000
0 <= A[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-mountain-in-array
*********************************************************/
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size(), res = 0;
        for(int i = 0; i < n; ) {
            while(i + 1 < n && A[i] >= A[i + 1]) ++i;
            int start = i;
            ++i;
            while(i + 1 < n && A[i] < A[i + 1]) {
                ++i;
            }
            if(i + 1 >= n) break;
            if(A[i] == A[i + 1]) continue;
            while(i + 1 < n && A[i] > A[i + 1]) ++i;
            res = max(res, i - start + 1);
        }
        return res >= 3 ? res : 0;
    }
};