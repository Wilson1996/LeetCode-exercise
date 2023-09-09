/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-27 00:05:24
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-28 09:17:04
*/
/*********************************************************
* 题目[中等]：
给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。

示例：
输入：A = [4,5,0,-2,-3,1], K = 5
输出：7
解释：
有 7 个子数组满足其元素之和可被 K = 5 整除：
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 
提示：
1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000
*********************************************************/
class Solution
{
public:
    int subarraysDivByK(vector<int>& A, int K)
    {
        int res = 0;
        unordered_map<int, int> MP;
        MP[0] = 1;
        int pre = 0;
        for (auto& x : A)
        {
            pre += x;
            int tmp = (pre % K + K) % K;;
            if(MP.find(tmp) != MP.end()) res += MP[tmp];
            ++MP[tmp];
        }
        return res;
    }
    // int subarraysDivByK(vector<int>& A, int K)
    // {
    //     int res = 0;
    //     int n = A.size();
    //     vector<int> dp(n, 0);
    //     dp[0] = A[0];
    //     if(dp[0] % K == 0) ++res;
    //     for(int i = 1; i < n; ++i)
    //     {
    //         dp[i] = dp[i - 1] + A[i];
    //         for(int j = 0; j < i; ++j)
    //         {
    //             if((dp[i] - dp[j]) % K == 0)
    //                 ++res;
    //         }
    //     }
    //     return res;
    // }
};