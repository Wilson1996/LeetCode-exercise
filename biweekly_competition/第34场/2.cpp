/*
* @Author: wilson_t
* @Date:   2020-09-06 12:49:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-11 17:08:27
*/
class Solution {
public:
    int numWays(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        int cnt = 0;
        for(auto c : s) if(c == '1') ++cnt;
        if(cnt % 3 != 0) return 0;
        if(cnt == 0) {
            return ((long long)(n - 1) * (n - 2) / 2) % MOD;
        }
        cnt /= 3;
        int sum = 0, num1 = 0, num2 = 0;
        for(auto c : s) {
            if(c == '1') sum++;
            if(sum == cnt) num1++;
            else if(sum == (cnt << 1)) num2++;
        }
        return ((long long)num1 * num2) % MOD;
    }
};