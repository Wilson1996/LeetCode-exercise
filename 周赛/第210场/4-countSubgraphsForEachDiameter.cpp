/*
* @Author: wilson_t
* @Date:   2020-10-11 18:31:08
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-11 18:32:13
*/
class Solution {
    int fa[20];
    int depth[20];
public:
    int find(int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    void join(int x, int y) {
        int p1 = find(x);
        int p2 = find(y);
        if(p1 != p2) {
            if(p1 > p2) swap(p1, p2);
            fa[p2] = p1;
        }
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> dist(n - 1, 0);
        for(int i = 0; i < n; ++i) {
            fa[i] = i;
            depth[i] = 0;
        }
        // for(int i = 0; i < )
        int m = 1 << n;
        for(int i = 0; i < m; ++i) {
            if(__builtin_popcount(i) < 2) continue;
            int pre = 0;
            bool ok = true;
            for(int j = 0; j < n; ++j) {
                if(i & (1 << j)) {
                    if(j > 0 && find(pre) != find(j)) {
                        ok = false;
                        break;
                    }
                    pre = j;
                }
            }
            if(!ok) continue;

        }
        return dist;
    }
};