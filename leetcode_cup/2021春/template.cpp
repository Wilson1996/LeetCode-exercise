#include <bits/stdc++.h>
#include "debug.h"
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, long long>;
using pll = pair<long long, long long>;
using pli = pair<long long, int>;

inline void speedio() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

const int d4x[] = {1, 0, -1, 0};
const int d4y[] = {0, 1, 0, -1};
const int d8x[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int d8y[] = {0, 1, 0, -1, 1, -1, 1, -1};

struct Edge {
    int from, to;
    double dist;
    Edge(int f, int t, double d) : from(f), to(t), dist(d) {}

    bool operator<(const Edge& r)const {
        return dist < r.dist;
    }
    bool operator>(const Edge& r)const {
        return dist > r.dist;
    }
};

const int maxn = 200005;
int a[maxn];
int f[maxn];
int T, N;

inline void readline(string& s) {
    getline(cin >> ws, s);
}

inline void read(vector<int>& v) {
    int number;
    while (cin >> number) {
        v.push_back(number);
        if (cin.get() == '\n')
            break;
    }
}

void solve(int c) {
    int res = 0;

    cout << "Case #" << c << ": " << res << "\n";
}

int main() {
    speedio();
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    // cout.setf(ios::fixed);
    // cout.precision(10);

    cin >> T;
    for(int c = 1; c <= T; ++c) {
        solve(c);
    }

    return 0;
}