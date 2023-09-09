/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-03 11:19:15
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-03 12:18:37
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>>& mat, int k)
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> res(m);
        int res_sum = 0;
        for(int i = 0; i < m; ++i)
        {
            res[i] = mat[i][0];
            res_sum += res[i];
        }
        if(k == 1) return res_sum;
        map<int, pair<int, int>> buffer;
        for(int i = 0; i < m; ++i)
        {
            buffer[mat[i][1]] = make_pair(i, 1);
        }
        for(int i = 1; i < k; ++i)
        {
            int r = buffer.begin()->second.first;
            int c = buffer.begin()->second.second;
            res_sum += ((buffer.begin())->first - res[r]);
            res[r] = nums[r][c];
            buffer.erase(buffer.begin());
            if(c < n - 1)
            {
                buffer[mat[r][c + 1]] = make_pair(r, c + 1);
            }
        }
        return res_sum;
    }
};

class Solution2
{
public:
    int sum(vector<vector<int>>& mat, const vector<int>& index)
    {
        int res = 0;
        for(int i = 0; i < (int)index.size(); i += 1) res += mat[i][index[i]];
        return res;
    }
    int kthSmallest(vector<vector<int>>& mat, int k)
    {
        set<pair<int, vector<int>>> sp;
        int m = mat.size(), n = mat[0].size();
        sp.insert({sum(mat, vector<int>(m, 0)), vector<int>(m, 0)});
        int ans = 0;
        for(int i = 0; i < k; i += 1)
        {
            auto p = *sp.begin();
            sp.erase(sp.begin());
            ans = p.first;
            auto v = p.second;
            for(int i = 0; i < m; i += 1)
                if(v[i] + 1 < n)
                {
                    v[i] += 1;
                    sp.insert({sum(mat, v), v});
                    v[i] -= 1;
                }
        }
        return ans;
    }
};