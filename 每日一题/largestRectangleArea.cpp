/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-30 11:58:34
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-30 15:49:29
*/
/*********************************************************
* 题目[困难]：
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。

以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

示例:
输入: [2,1,5,6,2,3]
输出: 10
*********************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	//单调栈
	//该题的核心是以heights[i]为高度的最大面积寻找出来，然后比较得到全局最大面积。
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        int res = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> sk;
        for(int i = 0; i < n; ++i)
        {
            while(!sk.empty() && heights[sk.top()] >= heights[i])
                sk.pop();
            left[i] = sk.empty() ? -1 : sk.top();
            sk.push(i);
        }
        sk = stack<int>();
        for(int i = n - 1; i >= 0; --i)
        {
            while(!sk.empty() && heights[sk.top()] >= heights[i])
                sk.pop();
            right[i] = sk.empty() ? n : sk.top();
            sk.push(i);
        }
        for(int i = 0; i < n; ++i)
        {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
	Solution soluter;
	vector<int> heights = {2,1,5,6,2,3};
	cout << soluter.largestRectangleArea(heights) << endl;
	return 0;
}

/*
单调栈问题：「力扣」第 84、42、739、496、316、901、402、581 题。（可能还有）
*/