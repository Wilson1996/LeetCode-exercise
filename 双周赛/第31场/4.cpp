/*
* @Author: wilson_t
* @Date:   2020-07-25 22:28:34
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-07-26 15:27:20
*/
#include <bits/stdc++.h>
using namespace std;

//会超时
// class Solution {
// public:
//     int minNumberOperations(vector<int>& target) {
//         int n = target.size();
//         multimap<int, int> mp;
//         for(int i = 0; i < n; ++i){
//             mp.insert({target[i], i});
//         }
//         vector<int> copy = target;
//         int res = 0;
//         for(auto it = mp.rbegin(); it != mp.rend(); ++it){
//             if(copy[it->second] == 0) continue;
//             res += copy[it->second];
//             copy[it->second] = 0;
//             for(int i = it->second+1; i < n; ++i){
//                 if(copy[i] == 0) break;
//                 copy[i] = max(0, target[i] - target[i-1]+copy[i-1]);
//             }
//             for(int i = it->second-1; i >= 0; --i){
//                 if(copy[i] == 0) break;
//                 copy[i] = max(0, target[i] - target[i+1]+copy[i+1]);
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int minNumberOperations(vector<int>& target) {
//         int n = target.size();
//         vector<pair<int, int>> mp;
//         for(int i = 0; i < n; ++i){
//             mp.push_back({target[i], i});
//         }
//         sort(mp.begin(), mp.end());
//         vector<int> copy = target;
//         int res = 0;
//         for(auto it = n-1; it >= 0; --it){
//             int index = mp[it].second;
//             if(copy[index] == 0) continue;
//             res += copy[index];
//             copy[index] = 0;
//             for(int i = index+1; i < n; ++i){
//                 if(copy[i] == 0) break;
//                 int tmp = target[i] - target[i-1]+copy[i-1];
//                 if(tmp > 0) copy[i] = tmp;
//                 else copy[i] = 0;
//             }
//             for(int i = index-1; i >= 0; --i){
//                 if(copy[i] == 0) break;
//                 int tmp = target[i] - target[i+1]+copy[i+1];
//                 if(tmp > 0) copy[i] = tmp;
//                 else copy[i] = 0;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = target[0];
        for (int i = 1; i < n; ++i) {
            ans += max(target[i] - target[i - 1], 0);
        }
        return ans;
    }
};