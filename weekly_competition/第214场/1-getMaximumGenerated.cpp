/*
* @Author: wilson_t
* @Date:   2020-11-09 19:58:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-09 19:59:27
*/
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n <= 1) return n;
        vector<int> v(n + 1);
        v[0] = 0, v[1] = 1;
        int res = 1;
        for(int i = 2; i <= n; ++i) {
            if(i & 1) v[i] = v[i / 2] + v[i / 2 + 1];
            else v[i] = v[i / 2];
            res = max(res, v[i]);
        }
        return res;
    }
};