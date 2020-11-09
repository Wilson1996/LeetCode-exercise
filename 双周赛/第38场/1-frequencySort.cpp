/*
* @Author: wilson_t
* @Date:   2020-11-09 20:08:27
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-09 20:08:39
*/
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int cnt[205] = {0};
        for(int x : nums) cnt[x + 100]++;
        sort(nums.begin(), nums.end(), [&](int x, int y) {
            x += 100, y += 100;
            if(cnt[x] != cnt[y]) return cnt[x] < cnt[y];
            return x > y;
        });
        return nums;
    }
};