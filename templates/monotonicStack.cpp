/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> sk;
        for(int i = 0; i < n; ++i) {
            while(!sk.empty() && heights[sk.top()] >= heights[i])
                sk.pop();
            left[i] = sk.empty() ? -1 : sk.top();
            sk.push(i);
        }
        sk = stack<int>();
        for(int i = n - 1; i >= 0; --i) {
            while(!sk.empty() && heights[sk.top()] >= heights[i])
                sk.pop();
            right[i] = sk.empty() ? n : sk.top();
            sk.push(i);
        }
        for(int i = 0; i < n; ++i) {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n, n);

        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};
