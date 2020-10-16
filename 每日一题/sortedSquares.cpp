/*
* @Author: wilson_t
* @Date:   2020-10-16 10:16:00
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-16 10:16:41
*/
/*********************************************************
* 题目[简单]：
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

示例 1：
输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]

示例 2：
输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]
 
提示：
1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A 已按非递减顺序排序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array
*********************************************************/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size(), bound = 0;
        vector<int> res(n);
        while(bound < n - 1) {
            if(abs(A[bound]) < abs(A[bound + 1])) break;
            ++bound;
        }
        // printf("%d,%d\n", bound, A[bound]);
        int l = bound, r = bound + 1, x, y, idx = 0;
        while(l >= 0 || r < n) {
            if(l >= 0 && r < n) {
                if(abs(A[l]) <= abs(A[r])) {
                    res[idx++] = A[l] * A[l];
                    --l;
                } else {
                    res[idx++] = A[r] * A[r];
                    ++r;
                }
            } else if(l >= 0) {
                res[idx++] = A[l] * A[l];
                --l;
            } else {
                res[idx++] = A[r] * A[r];
                ++r;
            }
        }

        return res;
    }
};