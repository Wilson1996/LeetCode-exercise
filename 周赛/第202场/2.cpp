/*
* @Author: wilson_t
* @Date:   2020-08-16 13:26:52
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-16 13:28:23
*/
class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        vector<int> v(n);
        for(int i = 0; i < n; ++i) {
            v[i] = (i << 1) + 1;
        }
        int mid = (v[(n - 1) / 2] + v[n / 2]) / 2;
        for(int i = 0; i < (n >> 1); ++i) {
            res += (mid - v[i]);
        }
        return res;
    }
};