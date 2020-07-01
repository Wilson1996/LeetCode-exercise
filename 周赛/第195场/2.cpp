/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-28 09:48:29
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-28 11:21:13
*/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k, 0);
        int n = arr.size();
        for(auto& x : arr)
        {
            int tmp = x % k;
            if(tmp < 0) tmp+= k;
            ++mp[tmp];
        }
        for(int i = 1; i < k / 2; ++i)
        {
            if(mp[i] != mp[k-i]) return false;
        }
        return mp[0] % 2 == 0;
    }
};