/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-21 10:29:32
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-21 10:39:07
*/
class Solution
{
public:
    int xorOperation(int n, int start)
    {
        vector<int> nums(n);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            nums[i] = start + 2 * i;
            res ^= nums[i];
        }
        return res;
    }
};