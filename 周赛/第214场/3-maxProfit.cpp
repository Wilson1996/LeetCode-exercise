/*
* @Author: wilson_t
* @Date:   2020-11-09 19:58:29
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-09 20:01:00
*/
const int mod = 1e9 + 7;
using ll = long long;
class Solution {
public:
    ll getSum(int low, int high) {
        return (ll)(high - low + 1) * (low + high) / 2;
    }
    int maxProfit(vector<int>& a, int num) {
        a.push_back(0);
        sort(a.begin(), a.end());
        ll res = 0, cnt = 0, n = a.size();
        for(int i = n - 1; i > 0; --i) {
            int count = (n - i) * (a[i] - a[i - 1]);
            if(count < num) {
                res += getSum(a[i - 1] + 1, a[i]) * (n - i);
                num -= count;
            } else {
                int low = int((double)a[i] - (double)num / (n - i));
                int tmp = (n - i) * (a[i] - low - 1);
                res += getSum(low + 2, a[i]) * (n - i) + (ll)(num - tmp) * (low + 1);
                // printf("%d %d %d %d\n",num, low, tmp, getSum(low+2, a[i])*(n-i) + (num-tmp)*(low+1));
                break;
            }
        }

        return res % mod;
    }
};