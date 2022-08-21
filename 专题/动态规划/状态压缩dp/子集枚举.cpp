/*
* @Author: wilson_t
* @Date:   2022-06-01 23:09:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2022-06-01 23:27:00
*/

// 子集预处理
for(int i=2; i<lim; ++i) {
    int pos = __builtin_ctz(i);
    f[i] = a[pos] + f[i ^ (1 << pos)];
}

// 子集枚举
void enumeration() {
    int S = 0x2212;
    for(int sub = S; sub; sub= (sub - 1)& S) {
    }
}