/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-27 20:58:56
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-23 14:10:07
*/
/*********************************************************
找出不大于N的最大的2的幂指数
*********************************************************/
#include <iostream>

using namespace std;

int findN(int n) {
    int len = sizeof(int) * 8;
    for(int i = 1; i <= len / 2; i *= 2) {
        n |= n >> i;
    }
    return (n >> 1) + 1;
}

int main(int argc, char* argv[]) {
    cout << hex << findN(7) << endl;
    return 0;
}