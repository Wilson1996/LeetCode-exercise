/*
* @Author: wilson_t
* @Date:   2021-08-09 13:43:44
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-08-09 13:45:04
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using int64 = long long;
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


const bool READ_BLANK = true;
// read line including blank line
inline bool readline(string& s, bool get_blank) {
    return static_cast<bool>(getline(get_blank ? (cin) : (cin >> ws), s));
}

// read integers without number
inline void read(vector<int>& v) {
    int number;
    while (cin >> number) {
        v.push_back(number);
        if (cin.get() == '\n')
            break;
    }
}

// read lines including blank line with line number
void read(vector<string>& vs, int n) {
    string s;
    // cin.ignore(100, '\n');
    for(int i = 0; i < n; i++) {
        readline(s, READ_BLANK);
        vs.emplace_back(s);
    }
}

// read lines including blank line without line number
void read(vector<string>& vs) {
    string s;
    // cin.ignore(100, '\n');
    while(readline(s, READ_BLANK)) {
        vs.emplace_back(s);
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