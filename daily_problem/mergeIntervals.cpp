/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-16 09:36:16
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-16 11:27:54
*/
/*********************************************************
* 题目[中等]：
给出一个区间的集合，请合并所有重叠的区间。

示例 1:
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2:
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*********************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& A, vector<int>& B)
{
    if(A[0] != B[0])
        return A[0] < B[0];
    else
        return A[1] < B[1];
}
class Solution
{
public:
    static vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;
        result.reserve(intervals.size());
        if(intervals.empty())
            return result;
        sort(intervals.begin(), intervals.end(), compare);
        // for(auto& interval : intervals)
        // {
        // 	for(auto& x : interval)
        // 		cout << x <<", ";
        // 	cout << endl;
        // }
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i)
        {
            int L1 = result.back()[0];
            int R1 = result.back()[1];
            int L2 = intervals[i][0];
            int R2 = intervals[i][1];
            if(L2 <= R1 && R2 > R1)
                result.back()[1] = R2;
            else if(L2 > R1)
                result.push_back(intervals[i]);
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> intervals = {{2, 6}, {1, 3}, {15, 18}, {8, 10}, {1, 4}, {2, 3}, {5,20},{25,30}};
    // vector<vector<int>> intervals = {{1, 4}, {2, 3}};
    // vector<vector<int>> intervals = {{1,6},{1,3},{15,18},{8,10}};
    vector<vector<int>> result = Solution::merge(intervals);
    for(auto& interval : result)
    {
        for(auto& x : interval)
            cout << x << ", ";
        cout << endl;
    }
    return 0;
}

