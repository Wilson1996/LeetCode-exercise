/*
* @Author: wilson_t
* @Date:   2020-08-31 23:37:51
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-12 18:45:23
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int C[N][N];

//C(n,m) = C(n-1,m-1) + C(n-1,m)
void generate(int n) {
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            // C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] = C[i - 1][j - 1] + C[i][j-1];
        }
    }
}

//C(n,k) = (n-k+1)/k*C(n,k-1)

int main(int argc, char* argv[]) {
    generate(1000);
    cout << C[5][2] << endl;

    return 0;
}