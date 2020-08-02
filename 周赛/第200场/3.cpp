/*
* @Author: wilson_t
* @Date:   2020-08-03 00:32:28
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-03 00:34:49
*/
/*
给你一个 n x n 的二进制网格 grid，每一次操作中，你可以选择网格的 相邻两行 进行交换。
一个符合要求的网格需要满足主对角线以上的格子全部都是 0 。
请你返回使网格满足要求的最少操作次数，如果无法使网格符合要求，请你返回 -1 。
主对角线指的是从 (1, 1) 到 (n, n) 的这些格子。
*/
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rowZero(n, 0);
        for(int i = 0; i < n; ++i) {
            int zeroCnt = 0;
            for(int j = n - 1; j >= 0; --j) {
                if(grid[i][j] == 0) {
                    ++zeroCnt;
                } else {
                    break;
                }
            }
            rowZero[i] = zeroCnt;
        }
        int res = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(rowZero[i] + i >= n - 1) {
                continue;
            }
            int endIndex = i;
            for(; endIndex < n; ++endIndex) {
                if(rowZero[endIndex] + i >= n - 1) {
                    break;
                }
            }
            if(endIndex == n) return -1;
            for(int j = endIndex; j > i; --j) {
                if(rowZero[j - 1] < rowZero[j]) {
                    int tmp = rowZero[j - 1];
                    rowZero[j - 1] = rowZero[j];
                    rowZero[j] = tmp;
                    ++res;
                }
                bool isValid = true;
                for(int k = 0; k < n - 1; ++k) {
                    if(rowZero[k] + k < n - 1) {
                        isValid = false;
                        break;
                    }
                }
                if(isValid) {
                    return res;
                }
            }
        }
        // for(int i = 0; i < n-1; ++i){
        //     if(rowZero[i] + i < n-1)
        //         return -1;
        // }
        return res;
    }
};