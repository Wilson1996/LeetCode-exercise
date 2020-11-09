/*
* @Author: wilson_t
* @Date:   2020-11-09 19:58:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-09 20:04:17
*/
class Solution {
public:
    int countVowelStrings(int n) {
        int f[55][5];
        for(int i = 0; i < n; ++i) for(int j = 0; j < 5; ++j) f[i][j] = 0;
        for(int j = 0; j < 5; ++j) f[0][j] = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < 5; ++j) {
                for(int k = 0; k <= j; ++k) {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
        int res = 0;
        for(int j = 0; j < 5; ++j) {
            res += f[n - 1][j];
        }
        return res;
    }
};



class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};
