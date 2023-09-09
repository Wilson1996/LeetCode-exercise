/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-17 00:10:55
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-17 00:16:24
*/
class Solution
{
public:
    int maxPower(string s)
    {
        int energy = 1;
        char pre = s[0];
        int pre_i = 0;
        int i;
        for(i = 1; i < s.length(); ++i)
        {
            if(s[i] != pre)
            {
                if(i - pre_i > energy) energy = i - pre_i;
                pre_i = i;
                pre = s[i];
            }
        }
        if(i - pre_i > energy) energy = i - pre_i;
        return energy;
    }
};