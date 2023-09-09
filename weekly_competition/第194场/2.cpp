/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-21 10:29:39
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-21 11:20:06
*/
class Solution
{
public:
    vector<string> getFolderNames(vector<string>& names)
    {
        int n = names.size();
        vector<string> res(n);
        unordered_set<string> ms;
        for(int i = 0; i < n; ++i)
        {
            auto& name = names[i];
            if(ms.find(name) == ms.end())
            {
                ms.insert(name);
                res[i] = name;
            }
            else
            {
                if(name.back() == ')')
                {
                    while(name.back() != '(')
                        name.pop_back();
                    name.pop_back();
                }
                int l = 1, r = 5e4 + 1;
                while(l < r)
                {
                    int mid = (l + r) / 2;
                    if(ms.find(name + "(" + to_string(mid) + ")") == ms.end())
                    {
                        r = mid;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                res[i] = name + "(" + to_string(l) + ")";
                ms.insert(res[i]);
            }
        }
        return res;
    }
};

class Solution
{
public:
    vector<string> getFolderNames(vector<string>& names)
    {
        int n = names.size();
        vector<string> res(n);
        unordered_map<string, int> ms;
        for(int i = 0; i < n; ++i)
        {
            auto& name = names[i];
            if(ms.find(name) == ms.end())
            {
                ms[name] = 1;
                res[i] = name;
            }
            else
            {
                for(int l = ms[name]; l <= 5e4+1; ++l)
                {
                    string tmp = name + "(" + to_string(l) + ")";
                    if(ms.find(tmp) == ms.end())
                    {
                        res[i] = tmp;
                        ms[tmp] = 1;
                        ms[name] = l + 1;
                        break;
                    }
                }
            }
        }
        return res;
    }
};