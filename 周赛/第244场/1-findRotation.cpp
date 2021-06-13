/*
* @Author: wilson_t
* @Date:   2021-06-06 17:53:46
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-06 17:57:49
*/
/*
给你两个大小为 n x n 的二进制矩阵 mat 和 target 。现 以 90 度顺时针轮转 矩阵 mat 中的元素 若干次 ，
如果能够使 mat 与 target 一致，返回 true ；否则，返回 false 。

提示：
n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] 和 target[i][j] 不是 0 就是 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/determine-whether-matrix-can-be-obtained-by-rotation
 */
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n / 2; ++j) {
                swap(mat[i][j], mat[i][n - 1 - j]);
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; ++i) {
            rotate(mat);
            if(mat == target) return true;
        }
        return false;
    }
};