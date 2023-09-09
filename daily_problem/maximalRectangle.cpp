/*
* @Author: wilson_t
* @Date:   2020-10-09 23:53:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-09 23:53:12
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if(mat.size() == 0 || mat[0].size() == 0) return 0;
        int n = mat.size(), m = mat[0].size();
        //f[i][j][0]、f[i][j][1]: 以i、j结尾的最大矩形的长和宽
        vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(m + 1, vector<int>(2, 0)));
        int res = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; i <= m; ++j) {
                f[i][j][0] = min(f[i][j - 1][0], f[i - 1][j - 1][0]);
                f[i][j][1] = min(f[i - 1][j][1], f[i - 1][j - 1][1]);
                res = max(res, f[i][j][0] * f[i][j][1]);
            }
        }
        return res;
    }
};