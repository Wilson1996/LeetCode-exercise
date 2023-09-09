const int mod = 1'000'000'007;
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& next) {
        int n = next.size();
        vector<vector<long long>> f(n, vector<long long>(2, 0));
        f[0][1] = 0;
        f[0][0] = 1;
        for(int i = 1; i < n; ++i) {
            f[i][1] = (f[i - 1][0] + 1) % mod;
            f[i][0] = ((f[i][1] + f[i][1] - f[next[i]][1] + 1) % mod + mod) % mod;
        }

        return (f[n - 1][1]) % mod;
    }
};
