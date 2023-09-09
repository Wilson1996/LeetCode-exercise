/*
* @Author: wilson_t
* @Date:   2020-12-22 21:27:01
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-27 20:07:37
*/
//乘法逆元
using ll = long long;
const int mod = 1'000'000'007;
const int maxn = 200005;
ll fac[maxn], inv[maxn], facInv[maxn];
void calc_fac_facInv() {
    fac[0] = inv[0] = facInv[0] = 1;
    fac[1] = inv[1] = facInv[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        fac[i] = (long long)fac[i - 1] * i % mod;
        inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;
        facInv[i] = (long long)facInv[i - 1] * inv[i] % mod;
    }
}
struct INIT {
    INIT() {
        calc_fac_facInv();
    }
} __init__;

//C(n, k) % mod = (ll)fac[n] * facInv[k] % mod * facInv[n-k] % mod;
//费马小定理： a/b (=) a*x(mod M) ==> x=b^(M-2) (M为质数时)