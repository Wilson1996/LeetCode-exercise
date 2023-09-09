/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-04 22:34:22
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-04 23:34:07
*/
/*********************************************************
* 题目[困难]：
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

示例:
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*********************************************************/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
	static int trap(vector<int>& height)
	{
		int ans = 0, current = 0;
	    stack<int> st;
	    while (current < height.size()) {
	        while (!st.empty() && height[current] > height[st.top()]) {
	            int top = st.top();
	            st.pop();
	            if (st.empty())
	                break;
	            int distance = current - st.top() - 1;
	            int bounded_height = min(height[current], height[st.top()]) - height[top];
	            ans += distance * bounded_height;
	        }
	        st.push(current++);
	    }
	    return ans;
	}
};

int main(int argc, char* argv[])
{
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << Solution::trap(height) << endl;
	return 0;
}