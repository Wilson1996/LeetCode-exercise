/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-28 10:34:16
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-28 18:43:38
*/
/*********************************************************
* 题目[中等]：
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]

示例 2：
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]

限制：
2 <= nums <= 10000
*********************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    static vector<int> singleNumbers(vector<int>& nums)
    {
        int a = 0, b = 0, AB = 0;
        for(int x : nums)
            AB ^= x;
        int div = 1;
        while((div & AB) == 0)
            div <<= 1;
        for(int x : nums)
        {
            if(div & x)
                a ^= x;
            else
                b ^= x;
        }
        return vector<int> {a, b};
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1, 2, 10, 4, 1, 4, 3, 3};
    vector<int> result = Solution::singleNumbers(nums);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}