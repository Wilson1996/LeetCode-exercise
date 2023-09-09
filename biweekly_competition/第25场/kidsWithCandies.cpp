/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-02 22:36:30
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-02 22:41:10
*/
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        int len = candies.size();
        if(len == 0)
            return vector<bool>();
        vector<bool> res(len, false);
        int maxNum = 0;
        for (int i = 0; i < len; ++i)
        {
            if(candies[i] > maxNum)
                maxNum = candies[i];
        }
        for(int i = 0; i < len; ++i)
        {
            if(extraCandies + candies[i] >= maxNum)
                res[i] = true;
        }
        return res;
    }
};