/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-13 20:59:21
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-13 22:35:31
*/
class Solution
{
public:
    vector<int> finalPrices(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i)
        {
            int j;
            for(j = i + 1; j < n; ++j)
            {
                if(prices[j] <= prices[i])
                    break;
            }
            if(j < n) res[i] = prices[i] - prices[j];
            else res[i] = prices[i];
        }
        return res;
    }
};