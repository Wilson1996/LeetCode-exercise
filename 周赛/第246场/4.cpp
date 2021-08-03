/*
* @Author: wilson_t
* @Date:   2021-06-20 10:24:42
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-20 12:25:12
*/
const int maxn = 100005;
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& qs) {
        int n = nums.size();
        int m = qs.size();
        int mx = 0;
        for(int x : nums) mx = max(mx, x);
        vector<vector<int> > pre(n + 1, vector<int>(mx + 1, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= mx; ++j) pre[i + 1][j] = pre[i][j];
            pre[i + 1][nums[i]]++;
        }

        vector<int> res(m);
        vector<int> cnt(mx + 1, 0);
        for(int i = 0; i < m; ++i) {
            int L = qs[i][0], R = qs[i][1];
            for(int j = 0; j <= mx; ++j) {
                cnt[j] = pre[R + 1][j] - pre[L][j];
            }
            int j = 0;
            int now = 200;
            while(j <= mx && cnt[j] == 0) ++j;
            if(j <= mx) {
                int last = j;
                j++;
                for(; j <= mx; ++j) {
                    if(cnt[j] > 0) {
                        now = min(now, j - last);
                        last = j;
                    }
                }
            }
            if(now < 200) res[i] = now;
            else res[i] = -1;
        }
        return res;
    }
};