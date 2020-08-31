/*
* @Author: wilson_t
* @Date:   2020-08-31 10:58:11
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-31 10:58:18
*/
class Solution {
    int n;
    vector<bool> vis;
public:
    void dfs(vector<vector<int>>& rooms, int cur) {
        vis[cur] = true;
        for(auto& nxt : rooms[cur]) {
            if(!vis[nxt]) {
                dfs(rooms, nxt);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        vis = vector<bool>(n, false);
        dfs(rooms, 0);
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) return false;
        }
        return true;
    }
};