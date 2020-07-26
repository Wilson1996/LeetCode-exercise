/*
* @Author: wilson_t
* @Date:   2020-07-25 22:28:25
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-07-25 23:39:17
*/
class Solution {
    int f[100005][26];
public:
    int numSplits(string s) {
        int n = s.size();
        memset(f, 0, (n+1)*26*sizeof(int));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < 26; ++j){
                f[i+1][j] = f[i][j];
            }
            f[i+1][s[i]-'a'] = f[i][s[i]-'a'] + 1;
        }
        int res = 0;
        for(int i = 1; i < n; ++i){
            int ldiff = 0, rdiff = 0;
            for(int j = 0; j < 26; ++j){
                if(f[i][j] != 0) ++ldiff;
                if(f[n][j] - f[i][j] != 0) ++rdiff;
            }
            if(ldiff == rdiff) ++res;
        }
        return res;
    }
};