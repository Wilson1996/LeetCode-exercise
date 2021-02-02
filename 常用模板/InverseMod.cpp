/*
* @Author: wilson_t
* @Date:   2020-12-22 21:27:01
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-22 21:42:51
*/
//乘法逆元
using ll = long long;
const int mod = 1000000007;
const int maxn = 200005;
void calc_fac_facInv() {
    ll fac[maxn], inv[maxn], facInv[maxn];
    fac[0] = inv[0] = facInv[0] = 1;
    fac[1] = inv[1] = facInv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fac[i] = (long long)fac[i - 1] * i % mod;
        inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;
        facInv[i] = (long long)facInv[i - 1] * inv[i] % mod;
    }
}
//C(n, k) % mod = (ll)fac[n] * facInv[k] % mod * facInv[n-k] % mod; 