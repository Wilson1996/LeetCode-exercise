#include <bits/stdc++.h>
#include "debug.h"
using namespace std;

using ll = long long;
class Solution {
    vector<int> res;
    int n;
public:
    bool dfs(const string& s, int cur) {
        // Debug() << "cur=" << cur << ", res=" << res << "\n";
        if(cur >= n) {
            return true;
        }
        if(res.size() < 2) {
            if(s[cur] == '0') {
                res.emplace_back(0);
                if(dfs(s, cur + 1)) return true;
                res.pop_back();
            } else {
                ll num = 0;
                int mxLen = min((n - cur) / 2, 10);
                for(int i = cur; i < cur + mxLen; ++i) {
                    num = num * 10 + (s[i] - '0');
                    if(num > INT_MAX) break;
                    res.emplace_back(num);
                    if(dfs(s, i + 1)) return true;
                    res.pop_back();
                }
            }
        } else {
            ll num = 0;
            int sz = res.size(), i = cur;
            if(s[cur] == '0' && res[sz-1] + res[sz-2] == 0) {
                res.emplace_back(0);
                if(dfs(s, cur+1)) return true;
                res.pop_back();
            } else {
                while(i < n) {
                    num = num * 10 + (s[i] - '0');
                    if(num > INT_MAX) break;
                    ++i;
                    if(num == (ll)res[sz - 1] + res[sz - 2]) {
                        break;
                    }
                }
                if(num == (ll)res[sz - 1] + res[sz - 2]) {
                    res.emplace_back(num);
                    if(dfs(s, i)) return true;
                    res.pop_back();
                }
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string S) {
        n = S.size();
        //只需要枚举回溯前两个数字
        res.resize(0);
        dfs(S, 0);
        return res;
    }
};

int main(int argc, char* argv[]) {
    Debug() << Solution().splitIntoFibonacci("214748364721474836422147483641") << "\n";
    return 0;
}