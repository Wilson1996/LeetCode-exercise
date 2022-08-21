/*
* @Author: wilson_t
* @Date:   2022-05-29 09:23:01
* @Last Modified by:   wilson_t
* @Last Modified time: 2022-05-29 09:25:10
*/
// 线性同余随机数生成器
// R_{i+1} = (A x R_i + B) mod P
#include <iostream>
using namespace std;

struct myrand {
    int A, B, P, x;

    myrand(int A, int B, int P) {
        this->A = A;
        this->B = B;
        this->P = P;
    }

    int next() {
        return x = (A * x + B) % P;    // 生成随机序列的下一个随机数
    }
};

myrand rnd(3, 5, 97);  // 初始化一个随机数生成器

int main() {
    for(int i = 0; i < 100; ++i) {
        int x = rnd.next();
        cout << x << endl;
    }
    return 0;
}