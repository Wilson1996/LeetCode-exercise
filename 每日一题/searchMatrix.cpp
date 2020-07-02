/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-07-02 10:12:06
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-07-02 10:21:17
*/
class Solution {
public:
	//剪治
	//从左下角和右上角出发都可以
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        int i = m - 1, j = 0;
        while(i >= 0 && j < n)
        {
        	if(matrix[i][j] < target){
        		++j;
        	}else if(matrix[i][j] > target){
        		--i;
        	}else{
        		return true;
        	}
        }
        return false;
    }
};