/*
* @Author: wilson_t
* @Date:   2020-09-06 12:49:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-11 17:01:31
*/
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0;
        int n = s.size();
        for(int i = 1; i < n; ++i) {
            if(s[i] == s[i - 1]) {
                int co = cost[i - 1], mx = cost[i - 1];
                while(i < n && s[i] == s[i - 1]) {
                    co += cost[i];
                    mx = max(mx, cost[i]);
                    ++i;
                }
                res += (co - mx);
            }
        }
        return res;
    }
};