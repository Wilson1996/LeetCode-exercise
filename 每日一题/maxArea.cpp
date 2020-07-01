/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-18 10:43:47
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-18 10:49:59
*/
/*********************************************************
* 题目[中等]：
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。

图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例：
输入：[1,8,6,2,5,4,8,3,7]
输出：49
*********************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int maxArea(vector<int>& height)
    {
        int l = 0, r = height.size() - 1;
        int mArea = 0;
        while(l < r)
        {
            int thisArea = min(height[l], height[r]) * (r - l);
            if(thisArea > mArea)  mArea = thisArea;
            if(height[l] > height[r])
                --r;
            else
                ++l;
        }
        return mArea;
    }
};

int main(int argc, char* argv[])
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << Solution::maxArea(height) << endl;
    return 0;
}