/*
* @Author: wilson_t
* @Date:   2020-08-08 22:26:09
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-09 20:21:27
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        int num = 0;
        for(int j = 1; j < arr[0]; ++j) {
            ++cnt;
            num = j;
            if(cnt == k)
                return num;
        }
        for(int i = 1; i < n; ++i) {
            for(int j = arr[i - 1] + 1; j < arr[i]; ++j) {
                ++cnt;
                num = j;
                if(cnt == k)
                    return num;
            }
        }
        for(int j = arr[n - 1] + 1; ; ++j) {
            ++cnt;
            num = j;
            if(cnt == k)
                return num;
        }
    }
};