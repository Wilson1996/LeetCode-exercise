/*
* @Author: wilson_t
* @Date:   2020-10-03 20:22:22
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-04 17:58:08
*/
/*
给你两个非负整数数组 rowSum 和 colSum ，其中 rowSum[i] 是二维矩阵中第 i 行元素的和， 
colSum[j] 是第 j 列元素的和。换言之你不知道矩阵里的每个元素，但是你知道每一行和每一列的和。
请找到大小为 rowSum.length x colSum.length 的任意 非负整数 矩阵，且该矩阵满足 rowSum 和 colSum 的要求。
请你返回任意一个满足题目要求的二维矩阵，题目保证存在 至少一个 可行矩阵。

提示：
1 <= rowSum.length, colSum.length <= 500
0 <= rowSum[i], colSum[i] <= 108
sum(rows) == sum(columns)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-valid-matrix-given-row-and-column-sums
*/
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
        int m = rs.size(), n = cs.size();
        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                res[i][j] = min(rs[i], cs[j]);
                rs[i] -= res[i][j];
                cs[j] -= res[i][j];
            }
        }
        return res;
    }
};