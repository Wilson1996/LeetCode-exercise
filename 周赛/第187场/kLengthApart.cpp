/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-03 10:41:32
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-03 12:11:18
*/
class Solution
{
public:
    bool kLengthApart(vector<int>& nums, int k)
    {
        int l = 0, r = 0;
        bool findLeft = false;
        for(int r = 0; r < nums.size(); ++r)
        {
            if(!findLeft && nums[r] == 1)
            {
                findLeft = true;
                l = r;
            }
            else if(findLeft && nums[r] == 1)
            {
                if(r - l <= k)
                    return false;
                l = r;
            }
        }
        return true;
    }
};
