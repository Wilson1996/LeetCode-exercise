/*
* @Author: wilson_t
* @Date:   2021-01-06 12:35:35
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-06 12:45:37
*/

const double eps = 1e-6;
class Solution {
public:
    unordered_map<string, int> mp;
    double g[25][25];
    int n;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        set<string> st;
        for(auto& v : equations) {
            st.insert(v[0]);
            st.insert(v[1]);
        }
        int id = 0;
        mp.clear();
        for(auto& s : st) {
            mp[s] = id++;
        }
        n = mp.size();
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) g[i][j] = -1.0;
        for(int i = 0; i < equations.size(); ++i) {
            auto& v = equations[i];
            g[mp[v[0]]][mp[v[1]]] = values[i];
            g[mp[v[1]]][mp[v[0]]] = 1 / values[i];
        }
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(i == j) continue;
                    if(fabs(g[i][j] + 1) < eps) {
                        if(fabs(g[i][k] + 1) >= eps && fabs(g[k][j] + 1) >= eps) {
                            g[i][j] = g[i][k] * g[k][j];
                        }
                    }
                }
            }
        }
        // for(int i = 0; i < n; ++i) {
        //     for(int j = 0; j < n; ++j)
        //         printf("%lf ", g[i][j]);
        //     printf("\n");
        // }
        vector<double> res(queries.size());
        for(int i = 0; i < queries.size(); ++i) {
            auto& v = queries[i];
            if(mp.find(v[0]) == mp.end() || mp.find(v[1]) == mp.end()) res[i] = -1.0;
            else if(v[0] == v[1]) res[i] = 1.0;
            else res[i] = g[mp[v[0]]][mp[v[1]]];
        }
        return res;
    }
};