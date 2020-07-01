/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-10 10:32:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-10 10:37:31
*/
class Solution
{
public:
    vector<string> buildArray(vector<int>& target, int n)
    {
        int len = target.size();
        int j = 1;
        vector<string> res;
        for(int i = 0; i < len; ++i)
        {
            while(j <= n && j != target[i])
            {
                res.push_back("Push");
                res.push_back("Pop");
                ++j;
            }
            res.push_back("Push");
            ++j;
        }
        return res;
    }
};