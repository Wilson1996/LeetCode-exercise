/*
* @Author: wilson_t
* @Date:   2020-10-03 20:22:22
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-04 00:19:24
*/
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arr, vector<int>& load) {
        vector<int> res;
        int n = arr.size();
        vector<int> server(k, 0);
        vector<int> cnt(k, 0);
        for(int i = 0; i < n; ++i) {
            int idx = i % k;
            if(server[idx] == 0 || arr[i] > server[idx]) {
                server[idx] = arr[i] + load[i];
                cnt[idx]++;
            } else {
                for(int j = idx + 1; j != idx; ++j) {
                    if(j >= k) j = 0;
                    if(server[j] == 0 || arr[i] > server[j]) {
                        server[j] = arr[i] + load[i];
                        cnt[j]++;
                        break;
                    }
                }
            }
        }
        int mx = 0;
        for(auto& x : cnt) {
            if(x > mx) mx = x;
        }
        return mx;
    }
};