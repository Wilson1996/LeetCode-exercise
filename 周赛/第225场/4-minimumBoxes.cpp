/*
* @Author: wilson_t
* @Date:   2021-01-24 14:09:26
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-25 12:33:12
*/
using ll = long long;
const int N = 2000;
int level[N] = {0};
struct Init {
    Init() {
        level[1] = 1;
        for(int i = 2; i < N; ++i) {
            level[i] = level[i - 1] + i;
        }
    }
} _init_level;
class Solution {
public:
    int minimumBoxes(int n) {
        ll tot = 0;
        int i = 1;
        for( ; i < N; ++i) {
            tot += level[i];
            if(tot > n) break;
        }
        int mxLevel = i - 1;
        tot -= level[i];
        if(tot == n) return level[mxLevel];
        int remain = n - tot, res = level[mxLevel];
        int nn = ceil((sqrt(8 * remain + 1) - 1) / 2);
        res += nn;
        return res;
    }
};