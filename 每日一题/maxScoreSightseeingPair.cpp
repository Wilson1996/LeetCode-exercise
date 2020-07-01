/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-17 00:20:31
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-17 01:01:26
*/
/*********************************************************
* 题目[中等]：
给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。
一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。
返回一对观光景点能取得的最高分。

示例：
输入：[8,1,5,2,6]
输出：11
解释：i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
 
提示：
2 <= A.length <= 50000
1 <= A[i] <= 1000
*********************************************************/
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int>& A)
    {
        int n = A.size();
        if(n == 2) return A[0] + A[1] - 1;
        vector<int> f1(n);
        vector<int> f2(n);
        f1[0] = 0;
        for(int i = 1; i < n; ++i)
        {
            f1[i] = max(f1[i - 1], A[i - 1]) - 1;
        }
        f2[n - 1] = 0;
        for(int i = n - 2; i >= 0; --i)
        {
            f2[i] = max(f2[i + 1], A[i + 1]) - 1;
        }
        int res = -1e9;
        for(int i = 0; i < n; ++i)
        {
            res = max(res, max(f1[i], f2[i]) + A[i]);
        }
        return res;
    }
    int maxScoreSightseeingPair(vector<int>& A)
    {
        int n = A.size();
        if(n == 2) return A[0] + A[1] - 1;
        vector<int> f1(n);
        f1[0] = 0;
        int res = f1[0] + A[0];
        for(int i = 1; i < n; ++i)
        {
            f1[i] = max(f1[i - 1], A[i - 1]) - 1;
            res = max(res, f1[i] + A[i]);
        }
        return res;
    }
};