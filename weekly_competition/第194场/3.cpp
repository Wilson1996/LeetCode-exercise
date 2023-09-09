/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-21 10:29:46
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-21 12:11:01
*/
class Solution
{
public:
    vector<int> avoidFlood(vector<int>& rains)
    {
        int n = rains.size();
        vector<int> inComing(n, -1);
        vector<int> res(n, -1);
        int idx = 0;
        for(int i = 1; i < n; ++i)
        {
            if(rains[i] != 0)
            {
                for(int j = idx; j < i; ++j)
                {
                    inComing[j] = i;
                }
            }
        }
        unordered_set<int> ms;
        for(int i = 0; i < n; ++i)
        {
        	if(rains[i] == 0)
        	{

        	}
        	else
        	{
        		if(ms.find(rains[i]) != ms.end())
        			return {};
        		ms.insert(rains[i]);
        	}
        }
    }
};

using PII = pair<int, int>;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> nxt(n);
        unordered_map<int, int> pos;
        int def = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (rains[i] > 0) {
                if (pos.count(rains[i])) {
                    nxt[i] = pos[rains[i]];
                }
                else {
                    nxt[i] = n;
                }
                pos[rains[i]] = i;
                def = rains[i];
            }
        }
        
        priority_queue<PII> q;
        vector<int> ans;
        unordered_set<int> inside;
        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                if (inside.count(rains[i])) {
                    return {};
                }
                if (nxt[i] != n) {
                    q.emplace(-nxt[i], rains[i]);
                    inside.insert(rains[i]);
                }
                ans.push_back(-1);
            }
            else {
                if (q.empty()) {
                    ans.push_back(def);
                }
                else {
                    auto [u, v] = q.top();
                    q.pop();
                    ans.push_back(v);
                    inside.erase(v);
                }
            }
        }
        return ans;
    }
};
