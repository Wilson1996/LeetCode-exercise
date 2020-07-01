/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-03 10:32:21
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-03 10:40:24
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>>& paths)
    {
        unordered_map<string, string> Paths;
        for(auto& path : paths)
        {
            Paths[path[0]] = path[1];
        }
        auto iter = Paths.begin();
        string curCity = iter->first;
        while(Paths.find(curCity) != Paths.end())
        {
            curCity = Paths[curCity];
        }
        return curCity;
    }
};