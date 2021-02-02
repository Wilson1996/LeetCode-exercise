/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-30 09:11:58
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-10 19:54:22
*/
/*********************************************************
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了k次。
请找出那个只出现一次的数字。
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

//这种做法不能处理负数
class Solution
{
private:
    int base;
public:
    void dec2base(int a, vector<int>& t)
    {
        int idx = 0;
        while(a != 0)
        {
            t[idx++] += a % base;
            a /= base;
        }
    }
    int base2dec(vector<int>& t)
    {
        int n = t.size();
        int res = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            res = res * base + (t[i] % base);
        }
        return res;
    }
    int singleNumber(vector<int>& nums, int k)
    {
        base = k;
        vector<int> t(21, 0);
        for(auto& x : nums)
        {
            dec2base(x, t);
        }
        return base2dec(t);
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {9, -1, 7, 9, 7, 9, 7, 9, 7, 9, 7, 10, 10, 10, 10, 10};
    Solution soluter;
    int res = soluter.singleNumber(nums, 5);
    cout << res << endl;
    return 0;
}