/*
* @Author: wilson_t
* @Date:   2020-11-09 20:08:27
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-09 20:09:49
*/
class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size(), res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int diff = 0;
                for(int k = 0; k < min(m - i, n - j); ++k) {
                    if(s[i + k] != t[j + k]) {
                        ++diff;
                    }
                    if(diff == 1) {
                        ++res;
                    }
                    if(diff > 1) break;
                }
            }
        }
        return res;
    }
};