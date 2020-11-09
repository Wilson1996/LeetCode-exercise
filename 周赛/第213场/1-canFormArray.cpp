/*
* @Author: wilson_t
* @Date:   2020-11-09 19:58:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-09 20:03:32
*/
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size(), m = pieces.size();
        int i = 0;
        bool vis[105];
        memset(vis, 0, sizeof(vis));
        while(i < n) {
            bool find = false;
            for(int j = 0; j < m; ++j) {
                if(vis[j]) continue;
                if(pieces[j][0] == arr[i]) {
                    vis[j] = true;
                    for(int k = 0; k < pieces[j].size(); ++k) {
                        if(arr[i + k] != pieces[j][k]) return false;
                    }
                    i += pieces[j].size();
                    find = true;
                }
            }
            if(!find) return false;
        }
        return true;
    }
};