/*
* @Author: wilson_t
* @Date:   2021-08-09 20:17:49
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-08-10 00:12:12
*/
#include <bits/stdc++.h>
using namespace std;

// 区间修改+单点查询
// 差分数组
const int maxn = 1000005;
long long diff[maxn];
int n, q;

int lowbit(int x) {
    return x & (-x);
}

void update(int i, int x) {
    while(i <= n) {
        diff[i] += x;
        i += lowbit(i);
    }
}

// [l,r]
void update_range(int l, int r, int x) {
    update(l, x);
    update(r + 1, -x);
}

long long ask(int i) {
    long long now = 0;
    while(i > 0) {
        now += diff[i];
        i -= lowbit(i);
    }
    return now;
}

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    int a, op;
    for(int i = 1; i <= n; ++i) {
        cin >> a;
        update_range(i, i, a);
    }
    for(int i = 0; i < q; ++i) {
        cin >> op;
        if(op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            update_range(l, r, x);
        } else {
            int idx;
            cin >> idx;
            cout << ask(idx) << "\n";
        }
    }
    return 0;
}
