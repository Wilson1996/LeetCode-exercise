/*
* @Author: wilson_t
* @Date:   2021-08-09 16:32:45
* @Last Modified by:   wilson_t
* @Last Modified time: 2022-04-28 22:01:35
*/
#include <bits/stdc++.h>
using namespace std;

class Bit {
    vector<int> cv;
    int cn;
public:
    Bit(int size) : cn(size), cv(size+1, 0) {}

    int lowbit(int x){
        return x & (-x);
    }

    void update(int i, int x){
        while(i <= cn){
            cv[i] += x;
            i += lowbit(i);
        }
    }

    int query(int i){
        int sum = 0;
        while(i > 0){
            sum += cv[i];
            i -= lowbit(i); 
        }
        return sum;
    }
};

// 单点修改+区间查询
const int maxn = 1000005;
long long c[maxn];
int n, q;

int lowbit(int x) {
    return x & (-x);
}

void update(int i, int x) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
}

long long ask(int i) {
    long long sum = 0;
    while (i > 0) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    cin >> n >> q;
    int op, x, y, a;

    for (int i = 1; i <= n; ++i) c[i] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        update(i, a);
    }
    for (int i = 0; i < q; ++i) {
        cin >> op >> x >> y;
        if (op == 1) {
            update(x, y);
        } else if (op == 2) {
            cout << ask(y) - ask(x - 1) << "\n";
        }
    }

    return 0;
}