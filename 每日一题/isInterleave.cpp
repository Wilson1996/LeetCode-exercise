/*
* @Author: wilson_t
* @Date:   2020-07-18 11:31:56
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-07-18 11:33:56
*/
/*
* 题目[困难]:
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if(m+n != s3.size()) return false;
        vector<vector<bool>> f(m+1, vector<bool>(n+1, false));
        f[0][0] = true;
        for(int i = 1; i <= m; ++i){
            f[i][0] = f[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        for(int j = 1; j <= n; ++j){
            f[0][j] = f[0][j-1] && (s2[j-1] == s3[j-1]);
        }
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                f[i][j] = (f[i][j-1] && s2[j-1] == s3[i+j-1]) 
                    || (f[i-1][j] && s1[i-1] == s3[i+j-1]);
            }
        }
        return f[m][n];
    }
};