/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-24 23:34:48
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-24 23:40:48
*/
/**********************************************************
* 题目[简单]：
整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。

示例1:
 输入：A = 29 （或者0b11101）, B = 15（或者0b01111）
 输出：2

示例2:
 输入：A = 1，B = 2
 输出：2

提示:
A，B范围在[-2147483648, 2147483647]之间
**********************************************************/
#include <iostream>

using namespace std;

class Solution
{
public:
    static int convertInteger(int A, int B)
    {
        int C = A ^ B;
        int result = 0;
        int len_bits = sizeof(int) * 8;
        for(int i = 0; i < len_bits; ++i)
        {
            if(C & 1) {++result;}
            C >>= 1;
        }
        // while(C != 0)
        // {
        //     C &= (C - 1);
        //     ++result;
        // }
        return result;
    }
};

int main(int argc, char* argv[])
{
    cout << Solution::convertInteger(29, 15) << endl;
    return 0;
}