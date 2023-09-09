/*
* @Author: wilson_t
* @Date:   2020-10-27 12:55:49
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-27 12:55:55
*/
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> res(m, false);
        auto check = [&](int start, int end) {
            vector<int> v(nums.begin() + start, nums.begin() + end + 1);
            sort(v.begin(), v.end());
            int gap = v[1] - v[0];
            for(int i = 2; i < v.size(); ++i) {
                if(v[i] - v[i - 1] != gap) return false;
            }
            return true;
        };
        for(int i = 0; i < m; ++i) {
            if(check(l[i], r[i])) res[i] = true;
        }
        return res;
    }
};