/*
 * @Descripttion: 
 * @version: 
 * @Author: WillissTaan(Wilson.T@sjtu.edu.cn)
 * @Date: 2020-03-06 15:12:11
 * @Last Modified by: WillissTaan
 * @Last Modified Time: Do not edit
 */
/****************************************************************************
 * 题目[中等]：
 * 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
 * 每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？
 * 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 * 
 * 示例 1：
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1
 * 
 * 示例 2:
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
 * 
 * 提示：
 * 2 <= n <= 58
 * 贪心思想
 ****************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    static int cuttingRope(int n) 
    {
        int multi = 1;
        if(n <= 3)
            return n-1;
        else if(n == 4)
            return 4;
        while(n > 4)
        {
            multi*= 3;
            n-=3;
        }
        if(n == 4)
            multi *= 4;
        else
        {
            multi *= n;
        }
        return multi;
    }
};

int main(int argc, char * argv[])
{
    cout << Solution::cuttingRope(9) << endl;
    return 0;
}