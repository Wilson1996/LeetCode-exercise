/*
* @Author: wilson_t
* @Date:   2020-07-25 22:28:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-07-25 23:59:23
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9+7;
        int n = arr.size();
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; ++i){
            prefix[i+1] = prefix[i] + arr[i];
        }
        int odd = 0;
        int even = 0;
        long res = 0;
        for(int i = 1; i <=n; ++i){
            if(prefix[i]&1){
                ++res;
                res += even;
                res %= MOD;
                ++odd;
            }else{
                res += odd;
                res %= MOD;
                ++even;
            }
        }
        return res;
    }
};