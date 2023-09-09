/*
* @Author: wilson_t
* @Date:   2020-11-09 19:58:29
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-09 20:00:16
*/
class Solution {
public:
    int minDeletions(string s) {
        int cnt[26] = {0};
        for(char c : s) cnt[c - 'a']++;
        sort(cnt, cnt + 26);
        int cur = cnt[25], res = 0;
        for(int i = 25; i >= 0; --i) {
            if(cnt[i] > cur) res += (cnt[i] - cur);
            cur = max(0, min(cur, cnt[i]) - 1);
        }
        return res;
    }
};