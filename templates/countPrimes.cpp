/*
 * @Author: wilson_t
 * @Date:   2020-11-02 22:21:37
 * @Last Modified by:   wilson_t
 * @Last Modified time: 2020-12-22 22:03:26
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e6 + 5;
bool isPrime[maxn];
//素数筛

class Solution {
 public:
  int countPrimes(int n) {
    for (int i = 0; i < n; ++i) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    int res = 0;
    for (int i = 2; i < n; ++i) {
      if (isPrime[i]) {
        ++res;
        for (int j = 2 * i; j < n; j += i) {
          isPrime[j] = false;
        }
      }
    }
    return res;
  }
};

// 线性筛
void solve(int n)) {
  vector<int> is_prime(n + 1, 0);
  vector<int> vis(n + 1, 0);
  vector<int> primes;
  int cnt = 0;
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) {
      is_prime[cnt++] = i;
    }
    for (int j = 0; j < cnt; ++j) {
      if (1ll * i * is_prime[j] > n) break;
      vis[i * is_prime[j]] = 1;
      if (i % is_prime[j] == 0) {
        break;
      }
    }
  }
  for (int i = 0; i < cnt; ++i) {
    primes.push_back(is_prime[i]);
  }
}
int main(int argc, char* argv[]) {
  int n = 1 << 10;
  Solution().countPrimes(n);
  for (int i = 2; i < n; ++i) {
    // if(isPrime[i]) printf("%d, ", i);
  }
  printf("\n");
}