/*
* @Author: wilson_t
* @Date:   2020-09-06 12:49:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-11 17:36:47
*/
const int MOD = 1e9 + 7;
long long f[105][205];
class Solution {
public:
    int countRoutes(vector<int>& a, int st, int fi, int fuel) {
        int n = a.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= fuel; ++j)
                f[i][j] = 0;
        f[st][0] = 1;
        for (int j = 0; j <= fuel; ++j) {
            for (int i = 0; i < n; ++i) {
                for (int k = 0; k < n; ++k)
                    if (i != k)
                        if (j + abs(a[i] - a[k]) <= fuel) (f[k][j + abs(a[i] - a[k])] += f[i][j]) %= MOD;
            }
        }
        int res = 0;
        for (int j = 0; j <= fuel; ++j)
            (res += f[fi][j]) %= MOD;
        return res;
    }
};