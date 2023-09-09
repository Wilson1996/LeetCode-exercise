/*
* @Author: wilson_t
* @Date:   2021-02-07 21:55:21
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-02-07 22:46:58
*/
/***************
* 题目[困难]：
给定的整数数组 A ，我们要将 A数组 中的每个元素移动到 B数组 或者 C数组中。（B数组和C数组在开始的时候都为空）
返回true ，当且仅当在我们的完成这样的移动后，可使得B数组的平均值和C数组的平均值相等，并且B数组和C数组都不为空。

示例:
输入: 
[1,2,3,4,5,6,7,8]
输出: true
解释: 我们可以将数组分割为 [1,4,5,8] 和 [2,3,6,7], 他们的平均值都是4.5。

注意:
A 数组的长度范围为 [1, 30].
A[i] 的数据范围为 [0, 10000].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-with-same-average
****************/
const double eps = 1e-6;
class Solution {
public:
    inline bool dEq(double x, double y) {
        return fabs(x - y) < eps;
    }
    bool splitArraySameAverage(vector<int>& A) {
        //(A[0]+...+A[n-1])/n = (B[0]+...+B[k-1])/k = avg
        //(A[0]+...+A[n-1])*k = (B[0]+...+B[k-1])*n
        int n = A.size();
        if(n < 2) return false;
        double avg = (double)accumulate(A.begin(), A.end(), 0) / n;
        vector<double> AA(n);
        //for each num in A, minus their average value.
        for(int i = 0; i < n; ++i) AA[i] = (double)A[i] - avg;
        sort(AA.begin(), AA.end());
        //find a subset whose sum is 0 in AA.
        //DAC
        int mid = n / 2, r = n - mid;
        vector<double> ls(1 << mid);
        vector<double> rs(1 << r);
        ls[0] = rs[0] = 0;
        for(int i = 1; i < (1 << mid); ++i) {
            for(int j = 0; j < mid; ++j) {
                if(i & (1 << j)) {
                    ls[i] = ls[i ^ (1 << j)] + AA[j];
                    if(dEq(ls[i], 0)) return true;
                    break;
                }
            }
        }
        int fullSetCnt = 0;
        double lfullSet = ls[(1 << mid) - 1];
        for(double x : ls) if(dEq(x, lfullSet)) ++fullSetCnt;
        sort(ls.begin(), ls.end());
        for(int i = 1; i < (1 << r); ++i) {
            for(int j = 0; j < r; ++j) {
                if(i & (1 << j)) {
                    rs[i] = rs[i ^ (1 << j)] + AA[j + mid];
                    if(dEq(rs[i], 0)) return true;
                    break;
                }
            }
        }
        for(int i = 1; i < (1 << r); ++i) {
            double x = rs[i];
            auto it = lower_bound(ls.begin(), ls.end(), -x);
            if(it != ls.end() && dEq(*it, -x)) {
                if(i != ((1 << r) - 1) || !dEq(-x, lfullSet) || fullSetCnt > 1) return true;
            }
            if(it != ls.begin()) {
                it = prev(it);
                if(it != ls.end() && dEq(*it, -x)) {
                    if(i != ((1 << r) - 1) || !dEq(-x, lfullSet) || fullSetCnt > 1) return true;
                }
            }
        }
        return false;
    }
};