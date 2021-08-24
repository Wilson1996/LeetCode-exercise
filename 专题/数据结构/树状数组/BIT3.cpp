/*
* @Author: wilson_t
* @Date:   2021-08-09 21:47:10
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-08-10 00:06:20
*/
#include <bits/stdc++.h>
using namespace std;

// 区间修改+区间查询
const int maxn = 1000005;
long long c_a[maxn], c_b[maxn];
int n, q;

int lowbit(int x) {
    return x & (-x);
}

void update(int i, long long x) {
    long long p = i;
    while(i <= n) {
        c_a[i] += x;
        c_b[i] += x * p;
        i += lowbit(i);
    }
}

void update_range(int l, int r, int x) {
    update(l, x);
    update(r + 1, -x);
}

long long ask(long long p) {
    long long res = 0;
    for(int i = p; i > 0; i -= lowbit(i)) {
        res += (p + 1) * c_a[i] - c_b[i];
    }
    return res;
}

long long ask_range(int l, int r) {
    return ask(r) - ask(l - 1);
}

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    int a, op, l, r, x;
    for(int i = 1; i <= n; ++i) {
        cin >> a;
        update_range(i, i, a);
    }
    for(int i = 0; i < q; ++i) {
        cin >> op;
        if(op == 1) {
            cin >> l >> r >> x;
            update_range(l, r, x);
        } else {
            cin >> l >> r;
            cout << ask_range(l, r) << "\n";
        }

    }
    return 0;
}