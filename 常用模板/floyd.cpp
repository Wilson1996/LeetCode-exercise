/*
* @Author: wilson_t
* @Date:   2020-12-20 11:12:12
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-20 12:58:29
*/

void floyd() {
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
}