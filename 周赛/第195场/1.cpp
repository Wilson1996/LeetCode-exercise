/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-28 09:48:22
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-28 11:19:12
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        unordered_set<long> ms;
        int x_cur = 0;
        int y_cur = 0;
        ms.insert((long)0);
        for(auto c : path)
        {
            if(c == 'N') ++y_cur;
            else if(c == 'S') --y_cur;
            else if(c == 'E') ++x_cur;
            else if(c == 'W') --x_cur;   
            long tmp = (long)x_cur;
            tmp = (tmp << 32) | (long)y_cur;
            if(ms.find(tmp) != ms.end()) return true;
            ms.insert(tmp);
        }
        return false;
    }
};
int main(int argc, char* argv[])
{
    // string path = "NESWW";
    // Solution soluter;
    // cout << soluter.isPathCrossing(path) << endl;
    cout << (-10)%7 <<endl;
    cout << (-7)%7 <<endl;
    return 0;
}