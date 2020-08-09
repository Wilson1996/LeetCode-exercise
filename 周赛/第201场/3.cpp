/*
* @Author: wilson_t
* @Date:   2020-08-09 20:23:23
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-09 20:26:59
*/
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int res = 0;
        int start = 0;
        mp[0] = 0;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            if(mp.find(sum - target) != mp.end() && mp[sum - target] >= start) {
                ++res;
                start = i + 1;
            }
            mp[sum] = i + 1;
        }
        return res;
    }
};