/*
* @Author: wilson_t
* @Date:   2020-08-16 13:26:42
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-16 13:27:45
*/
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        for(int i = 2; i < n; ++i) {
            if((arr[i - 2] & 1) && (arr[i - 1] & 1) && (arr[i] & 1))
                return true;
        }
        return false;
    }
};