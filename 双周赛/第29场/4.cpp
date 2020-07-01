/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-28 00:03:15
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-28 00:03:21
*/
class Solution {
private:
    int G[16][16];
    int indegree[16];
    int n;
    int k;
    vector<int> topoOrder;
    int res;
public:
    void topoSort()
    {
        queue<int> Q;
        for(int i = 1; i <= n; ++i)
        {
            if(indegree[i] == 0) Q.push(i);
        }
        topoOrder.emplace_back(Q.size());
        int kk = Q.size();
        while(kk > 0){
            ++res;
            kk -= k;
        }
        if(kk < 0) kk = -kk;
        while(!Q.empty()){
            int tmp = kk;
            int _size = Q.size();
            for(int _ = 0; _ < _size; ++_)
            {
                int cur = Q.front();
                Q.pop();
                for(int i = 1; i <= n; ++i)
                {
                    if(G[cur][i] == 0) continue;
                    --indegree[i];
                    if(indegree[i] == 0) 
                    {
                        if(kk > 0){
                            --kk;
                        }
                        Q.push(i);
                    }
                }
            }
            topoOrder.emplace_back(Q.size());
            kk = Q.size() - (tmp - kk);
            while(kk > 0){
                ++res;
                kk -= k;
            }
            if(kk < 0) kk = -kk;
        }
        while(kk > 0){
            ++res;
            kk -= k;
        }
    }
    int minNumberOfSemesters(int _n, vector<vector<int>>& dep, int _k) {
        n = _n;
        k = _k;
        memset(indegree, 0, sizeof(indegree));
        memset(G, 0, sizeof(G));
        for(auto& d : dep){
            G[d[0]][d[1]] = 1;
            ++indegree[d[1]];
        }
        res = 0;
        topoSort();
        
        // int res = 0;
        // for(auto kk : topoOrder)
        // {
        //     while(kk > 0)
        //     {
        //         ++res;
        //         kk -= k;
        //     }
        // }
        return res;
    }
};