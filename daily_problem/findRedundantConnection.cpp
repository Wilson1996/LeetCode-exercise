/*
* @Author: wilson_t
* @Date:   2020-09-13 23:52:42
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-13 23:53:31
*/
class Solution {
    int fa[1005];
public:
    int find(int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    bool join(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if(fx == fy) return false;
        if(fx > fy) swap(fx, fy);
        fa[fy] = fx;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = 0; i <= n; ++i) fa[i] = i;
        for(auto& e : edges) {
            if(!join(e[0], e[1])) return e;
        }
        return {};
    }
};