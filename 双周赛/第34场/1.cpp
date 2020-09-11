/*
* @Author: wilson_t
* @Date:   2020-09-06 12:49:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-11 17:02:15
*/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        int n = mat.size();
        for(int i = 0; i < n; ++i) {
            res += mat[i][i];
        }
        for(int i = 0; i < n; ++i) {
            res += mat[i][n - i - 1];
        }
        if(n & 1) res -= mat[n / 2][n / 2];
        return res;
    }
};