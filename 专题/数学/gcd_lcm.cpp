/*
* @Author: wilson_t
* @Date:   2021-01-17 20:06:34
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-17 20:07:39
*/
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    cout << gcd(6,9) << "\n";
    cout << gcd(9,6) << "\n";
    cout << lcm(6,9) << "\n";
    return 0;
}