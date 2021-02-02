using ll = long long;
class Solution {
public:
    ll fastPower(ll x, int n, ll mod) {
        ll res = 1;
        if(n <= 0) return res;
        while(n) {
            if(n & 1) {
                res *= x;
                res %= mod;
            }
            x = x * x;
            x %= mod;
            n >>= 1;
        }
        return res % mod;
    }
    string longestDupSubstring(string s) {
        int n = s.size();
        int pos = 0;
        const int base = 31;
        const ll mod = 1LL << 31;
        //Kabin-Karp匹配
        auto check = [&](int len) {
            ll h = fastPower(base, len - 1, mod);
            if(len == 0) return false;
            unordered_map<ll, int> mp;
            ll p = 0;
            for(int i = 0; i < len; ++i) {
                p = p * base + (s[i] - 'a');
                p %= mod;
            }
            mp[p] = 0;
            for(int i = 1; i < n - len + 1; ++i) {
                p = (base * ((p - h * (s[i - 1] - 'a') % mod + mod) % mod) % mod + s[i + len - 1] - 'a') % mod;
                // if(p<0)printf("p is neg\n");
                if(mp.find(p) != mp.end()) {
                    bool flag = true;
                    //这里的验算是必要的，因为可能会出现反例
                    for(int j = 0; j < len; ++j) {
                        if(s[mp[p] + j] != s[i + j]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        pos = mp[p];
                        return true;
                    }
                }
                mp[p] = i;
            }
            return false;
        };
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if(check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if(l > 0) {
            return s.substr(pos, l);
        } else return "";
    }
};