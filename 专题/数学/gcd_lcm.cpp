/*
* @Author: wilson_t
* @Date:   2021-01-17 20:06:34
* @Last Modified by:   wilson_t
* @Last Modified time: 2022-02-10 11:35:54
*/
#include <iostream>
using namespace std;

// 欧几里得算法
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
// 更相减损法
int gcd(int a, int b) { // 更相减损法
    while (true) {
        if (a > b) a -= b;
        else if (a < b) b -= a;
        else return a;
    }
}
// Stein
int gcd(int a, int b) { // stein
    if (a == 0 || b == 0) return max(a, b);
    if (a % 2 == 0 && b % 2 == 0) return 2 * gcd(a >> 1, b >> 1);
    else if (a % 2 == 0) return gcd(a >> 1, b);
    else if (b % 2 == 0) return gcd(a, b >> 1);
    else return gcd(abs(a - b), min(a, b));
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    cout << gcd(6, 9) << "\n";
    cout << gcd(9, 6) << "\n";
    cout << lcm(6, 9) << "\n";
    return 0;
}