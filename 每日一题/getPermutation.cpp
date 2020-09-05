/*
* @Author: wilson_t
* @Date:   2020-09-05 10:26:09
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-05 10:26:19
*/
class Solution {
    int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
public:
    string getPermutation(int n, int k) {
        string res = "";
        res.resize(n);
        vector<char> ch(n);
        for(int i = 0; i < n; ++i) ch[i] = '0' + i + 1;
        k -= 1;
        int cnt = 0;
        for(int i = n - 1; i >= 0; --i) {
            int idx = k / fact[i];
            res[cnt++] = ch[idx];
            k %= fact[i];
            ch.erase(ch.begin() + idx);
        }
        return res;
    }
};