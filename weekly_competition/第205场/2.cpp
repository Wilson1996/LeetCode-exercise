/*
* @Author: wilson_t
* @Date:   2020-09-06 12:49:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-11 17:00:46
*/
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<long long, int> s1, s2;
        for(auto& x : nums1) s1[(long long)x * x]++;
        for(auto& x : nums2) s2[(long long)x * x]++;
        int res = 0;
        for(int j = 0; j < n1; ++j) {
            for(int k = j + 1; k < n1; ++k) {
                long long key = (long long)nums1[j] * nums1[k];
                if(s2.find(key) != s2.end()) res += s2[key];
            }
        }
        for(int j = 0; j < n2; ++j) {
            for(int k = j + 1; k < n2; ++k) {
                long long key = (long long)nums2[j] * nums2[k];
                if(s1.find(key) != s1.end()) res += s1[key];
            }
        }
        return res;
    }
};