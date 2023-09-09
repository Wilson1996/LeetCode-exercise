#include <bits/stdc++.h>
using namespace std;
//分解质因数
typedef pair<int, int> pii;
vector<pii> decomposePrime(int n) {
    vector<pii> res;
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            int cnt = 0;
            while(n % i == 0) {
                n /= i;
                ++cnt;
            }
            res.emplace_back(i, cnt);
        }
    }
    if(n > 1) {
        res.emplace_back(n, 1);
    }
    return res;
}


int main() {
    vector<pii> res = decomposePrime(100);
    for(auto [num, cnt] : res) {
        printf("%d: %d\n", num, cnt);
    }
    return 0;
}