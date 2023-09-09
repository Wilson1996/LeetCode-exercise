/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-30 09:36:10
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-30 10:42:30
*/
/*********************************************************
编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 True ；不是，则返回 False 。
 
示例：
输入：19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*********************************************************/
#include <iostream>
using namespace std;
class Solution
{
public:
    int next(int n)
    {
        int res = 0;
        while(0 != n)
        {
            int tmp = n % 10;
            res += tmp * tmp;
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n)
    {
        int fast = next(n), slow = n;
        while(slow != fast)
        {
            slow = next(slow);
            fast = next(next(fast));
        }
        return slow == 1;
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    cout << soluter.isHappy(2) << endl;
    return 0;
}