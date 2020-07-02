/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-07-02 00:09:46
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-07-02 10:09:19
*/
/*********************************************************
* 题目[中等]：
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。

示例：
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
返回 13。
 
提示：
你可以假设 k 的值永远是有效的，1 ≤ k ≤ n^2 。
*********************************************************/
class Solution
{
public:
    //排序
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        vector<int> M;
        M.reserve(n * n);
        for(auto& m : matrix)
        {
            for(auto& x : m) M.emplace_back(x);
        }
        sort(M.begin(), M.end());
        return M[k - 1];
    }
};

//二分查找
class Solution2
{
public:
    bool check(vector<vector<int>>& matrix, int k, int mid)
    {
        int n = matrix.size();
        int i = n - 1, j = 0;
        int num = 0;
        while(i >= 0 && j < n)
        {
            if(matrix[i][j] <= mid)
            {
                num += (i + 1);
                ++j;
            }
            else
            {
                --i;
            }
        }
        return num >= k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1], mid;
        while(l < r)
        {
            mid = l + ((r - l) >> 1);
            if(check(matrix, k, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};
