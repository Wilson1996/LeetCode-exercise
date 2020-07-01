/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-26 11:07:21
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-27 10:53:55
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
	//超时....
    static vector<int> findDiagonalOrder(vector<vector<int>>& nums)
    {
        vector<int> result;
        int rows = nums.size();
        int maxCol = 0;
        //上三角
        for(int i = 0; i < rows; ++i)
        {
            int r = i;
            for(int j = 0; j <= i; ++j)
            {
                if(j < nums[r].size())
                    result.push_back(nums[r][j]);
                --r;
                if(r < 0)
                    break;
            }
            if(nums[i].size() > maxCol)
                maxCol = nums[i].size();
        }
        cout << "maxCol: " << maxCol << endl;
        //下三角
        for(int j = 1; j < maxCol; ++j)
        {
            int c = j;
            int _lowi = (maxCol - rows + 1) > j ? 0 : (j - maxCol + rows);
            for(int i = rows - 1; i >= _lowi; --i)
            {
                if(c < nums[i].size())
                    result.push_back(nums[i][c]);
                ++c;
                if(c >= maxCol)
                    break;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    // vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> nums = {{6}, {8}, {6, 1, 6, 16}};
    // vector<vector<int>> nums = {{1, 2, 3, 4, 5}, {6, 7}, {8}, {9, 10, 11}, {12, 13, 14, 15, 16}};
    // vector<vector<int>> nums = {{1,2,3,4,5,6}};
    for(auto& row : nums)
    {
        cout << "size: " << row.size() << "   ";
        for(auto& x : row)
        {
            cout << x << ", ";
        }
        cout << endl;
    }
    vector<int> result = Solution::findDiagonalOrder(nums);
    for(auto x : result)
        cout << x << ", ";
    cout << endl;
    return 0;
}