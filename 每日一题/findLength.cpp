/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-07-01 00:11:49
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-07-01 00:29:45
*/
/*********************************************************
* 题目[中等]：
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例 1:
输入:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出: 3
解释:
长度最长的公共子数组是 [3, 2, 1]。

说明:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLength(vector<int>& A, vector<int>& B)
    {
        int m = A.size();
        int n = B.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = A[0] == B[0] ? 1 : 0;
        int res = dp[0][0];
        for(int i = 1; i < m; ++i)
        {
            dp[i][0] = A[i] == B[0] ? 1 : 0;
            res = max(res, dp[i][0]);
        }
        for(int j = 1; j < n; ++j)
        {
            dp[0][j] = A[0] == B[j] ? 1 : 0;
            res = max(res, dp[0][j]);
        }
        
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(A[i] == B[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }
};
int main(int argc, char* argv[])
{
	vector<int> A = {1,2,3,2,1};
	vector<int> B = {3,2,1,4,7};
	Solution soluter;
	cout << soluter.findLength(A, B) << endl;
	return 0;
}