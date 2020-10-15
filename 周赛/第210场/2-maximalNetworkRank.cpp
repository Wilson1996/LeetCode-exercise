/*
* @Author: wilson_t
* @Date:   2020-10-11 18:59:28
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-11 18:59:36
*/
class Solution {
    int g[105][105];
    int deg[105];
    int res;
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) g[i][j] = 0;
        memset(deg, 0, n * sizeof(int));
        res = 0;
        for(auto& ro : roads) {
            g[ro[0]][ro[1]] = g[ro[1]][ro[0]] = 1;
            deg[ro[0]]++;
            deg[ro[1]]++;
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int rank = deg[i] + deg[j];
                if(g[i][j]) rank--;
                res = max(res, rank);
            }
        }
        return res;
    }
};