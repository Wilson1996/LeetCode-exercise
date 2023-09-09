/*
* @Author: wilson_t
* @Date:   2020-11-09 19:58:30
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-09 20:01:47
*/
using ll = long long;
const int mod = 1e9 + 7;
int cv[100005];
class Solution {
    int cn;
public:
    int lowbit(int x) {
        return x & (-x);
    }

    void update(int i, int x) {
        while(i <= cn) {
            cv[i] += x;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += cv[i];
            i -= lowbit(i);
        }
        return sum;
    }
    int createSortedArray(vector<int>& a) {
        int n = a.size();
        ll res = 0;
        int mx = *max_element(a.begin(), a.end());
        cn = mx;
        memset(cv, 0, sizeof(int) * (cn + 1));
        for(int i = 0; i < n; ++i) {
            int& x = a[i];
            int l = query(x - 1), r = i - query(x);
            res += min(l, r);
            res %= mod;
            update(x, 1);
        }
        return res % mod;
    }
};