/*
* @Author: wilson_t
* @Date:   2020-12-07 09:50:06
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-07 09:51:16
*/
/*
* 题目[中等]：
有一个二维矩阵 A 其中每个元素的值为 0 或 1 。
移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。
在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。
返回尽可能高的分数。

示例：
输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
输出：39
解释：
转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 
提示：
1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] 是 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/score-after-flipping-matrix
*/
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<int> nums(n, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                nums[i] = (nums[i] << 1) + A[i][j];
            }
        }
        for(int i = 0; i < n; ++i) {
            int nx = (~nums[i]) & ((1 << m) - 1);
            if(nx > nums[i]) {
                nums[i] = nx;
            }
        }
        for(int j = m - 1; j >= 0; --j) {
            int cntOne = 0;
            for(int i = 0; i < n; ++i) {
                if(nums[i] & (1 << j)) ++cntOne;
            }
            if(cntOne < (n - cntOne)) {
                for(int i = 0; i < n; ++i) {
                    nums[i] ^= (1 << j);
                }
            }
        }
        int res = 0;
        for(int x : nums) {
            res += x;
            // cout << x << " ";
        }
        return res;
    }
};

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int ret = m * (1 << (n - 1));

        for (int j = 1; j < n; j++) {
            int nOnes = 0;
            for (int i = 0; i < m; i++) {
                if (A[i][0] == 1) {
                    nOnes += A[i][j];
                } else {
                    nOnes += (1 - A[i][j]); // 如果这一行进行了行反转，则该元素的实际取值为 1 - A[i][j]
                }
            }
            int k = max(nOnes, m - nOnes);
            ret += k * (1 << (n - j - 1));
        }
        return ret;
    }
};
