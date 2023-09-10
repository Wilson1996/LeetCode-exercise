long long fast_pow(long long x, long long m, long long mod) {
    long long res = 1;
    while (m) {
        if (m & 1) {
            res *= x;
            res %= mod;
        }
        m >>= 1;
        x = x * x % mod;
    }
    return res;
}