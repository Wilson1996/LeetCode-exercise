/*
* @Author: wilson_t
* @Date:   2021-01-24 14:07:01
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-24 14:07:07
*/
class Solution {
public:
    int minCharacters(string a, string b) {
        int cntA[26] = {0}, cntB[26] = {0};
        for(char c : a) cntA[c - 'a']++;
        for(char c : b) cntB[c - 'a']++;
        int res = INT_MAX;
        for(int i = 1; i < 26; ++i) {
            int tot = 0;
            for(int j = i; j < 26; ++j) tot += cntA[j];
            for(int j = 0; j < i; ++j) tot += cntB[j];
            res = min(res, tot);
            tot = 0;
            for(int j = i; j < 26; ++j) tot += cntB[j];
            for(int j = 0; j < i; ++j) tot += cntA[j];
            res = min(res, tot);
        }
        for(int i = 0; i < 26; ++i) {
            int tot = 0;
            for(int j = 0; j < 26; ++j) if(j != i) tot += cntA[j];
            for(int j = 0; j < 26; ++j) if(j != i) tot += cntB[j];
            res = min(res, tot);
        }
        return res;
    }
};