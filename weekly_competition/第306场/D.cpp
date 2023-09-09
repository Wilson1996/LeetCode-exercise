#include <bits/stdc++.h>
using namespace std;
// int memo[10][1 << 11];
class Solution {
    long long n;
    int len;
    string num;
    vector<vector<int>> memo;
    set<int> st;
public:
    long long dfs(int cur, int vis, long long now) {
        // if (memo[cur][vis]) return 0;
        if (now > n) return 0;
        if (cur >= len) {
            return 0;
        }
        
        long long res = 0;
        if (cur == 0) {
            for (int i = 1; i < 10; ++i) {
                if (vis & (1 << i)) continue;
                long long nxt = now * 10 + i;
                if (nxt <= n) {
                    res++;
                    st.insert(nxt);
                    res += dfs(cur + 1, vis | (1 << i), nxt);
                }
            }
        } else {
            for (int i = 0; i < 10; ++i) {
                if (vis & (1 << i)) continue;
                long long nxt = now * 10 + i;
                if (nxt <= n) {
                    res++;
                    st.insert(nxt);
                    res += dfs(cur + 1, vis | (1 << i), nxt);
                }
            }
        }
        memo[cur][vis] = 1;
        return res;
    }
    int countSpecialNumbers(int n) {
        this->n = n;
        num = to_string(n);
        len = num.size();
        // memset(memo, 0, sizeof(memo));
        memo = vector<vector<int>>(10, vector<int>(1 << 11, 0));
        int res = dfs(0, 0, 0);
        ofstream ofs("out_2.txt", std::ios::binary | std::ios::out);
        for (int x : st) {
            ofs << x << "\n";
        }
        ofs.close();
        return res;
    }
};
/*
233
180
*/

int main() {
    Solution sol;
    cout << sol.countSpecialNumbers(233) << "\n";
    return 0;
}