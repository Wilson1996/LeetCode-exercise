#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mul(ll a, ll b, ll mod) {
    ll res = 0;
    while(b > 0) {
        if(b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll eg = exgcd(b, a % b, x, y);
    ll tp = x;
    x = y;
    y = tp - a / b * y;
    return eg;
}

class Solution {
public:
    /**
     * @param num: the given array
     * @param rem: another given array
     * @return: The minimum positive number of conditions to meet the conditions
     */
    int remainderTheorem(vector<int>& num, vector<int>& rem) {
        ll x, y, k;
        ll M = num[0], ans = rem[0]; //第一个方程的解特判
        int n = rem.size();
        for(int i = 1; i < n; i++) {
            ll a = M, b = num[i], c = (rem[i] - ans % b + b) % b; //ax≡c(mod b)
            ll eg = exgcd(a, b, x, y), bg = b / eg;
            if(c % eg != 0) return -1; //判断是否无解，然而这题其实不用

            x = mul(x, c / eg, bg);
            ans += x * M; //更新前k个方程组的答案
            M *= bg; //M为前k个m的lcm
            ans = (ans % M + M) % M;
        }
        return (ans % M + M) % M;
    }
};

int main() {
    vector<int> num = {3, 4, 5, 11};
    vector<int> rem = {2, 3, 1, 7};
    Solution sol;
    cout << sol.remainderTheorem(num, rem) << "\n";
    return 0;
}