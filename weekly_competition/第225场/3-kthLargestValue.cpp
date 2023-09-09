/*
* @Author: wilson_t
* @Date:   2021-01-24 14:08:52
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-24 14:08:57
*/
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> v;
        vector<vector<int>> mat(m + 1, vector<int>(n + 1));
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                mat[i][j] = matrix[i - 1][j - 1] ^ mat[i - 1][j] ^ mat[i][j - 1] ^ mat[i - 1][j - 1];
                v.emplace_back(mat[i][j]);
            }
        }
        nth_element(v.begin(), v.begin() + v.size() - k, v.end());
        // sort(v.begin(), v.end());
        return v[v.size() - k];
    }
};