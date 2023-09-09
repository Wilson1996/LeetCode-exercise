/*
* @Author: wilson_t
* @Date:   2020-08-08 22:26:18
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-09 20:21:53
*/
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size()) return false;
        if(s == t) return k >= 0;
        int n = s.size();
        int times[26] = {0};
        long long step = 0;
        for(int i = 0; i < n; ++i) {
            step = (t[i] + 26 - s[i]) % 26;
            if(step == 0) continue;
            int tmp = step;
            step += times[step] * 26;
            if(step > k) {
                // cout << step <<endl;
                return false;
            }
            times[tmp]++;
        }
        // cout << step <<endl;
        return true;
    }
};