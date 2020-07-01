/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-14 09:38:43
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-14 10:39:38
*/
class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(auto& x : arr) ++mp[x];
        vector<int> tmp;
        for(auto& x : mp)
        {
            tmp.push_back(x.second);
        }
        int _size = tmp.size();
        sort(tmp.begin(), tmp.end());
        int idx = 0;
        while(k > 0)
        {
            if(tmp[idx] > k)
                return _size - idx;
            else
            {
                k -= tmp[idx].first;
            }
            ++idx;
        }
        return 0;
    }
};