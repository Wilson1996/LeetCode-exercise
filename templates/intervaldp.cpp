//典型的区间dp问题
int f[1005][1005]; //先手能拿到的分值的最大差值！！！
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        for(int i = 0; i < n; ++i) f[i][i] = 0;
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; ++i) presum[i + 1] = presum[i] + stones[i];
        auto getSum = [&](int l, int r) {
            return presum[r + 1] - presum[l];
        };
        /*******************************************************/
        for(int len = 2; len <= n; ++len) {
            for(int l = 0; l <= n - len; ++l) {
                int r = l + len - 1;
                f[l][r] = max(getSum(l + 1, r) - f[l + 1][r], getSum(l, r - 1) - f[l][r - 1]);
            }
        }
        /*******************************************************/
        return f[0][n - 1];
    }
};