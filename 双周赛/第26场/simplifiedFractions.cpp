/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-17 00:09:18
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-17 08:13:32
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int _gcd(int a, int b)
{
    return a == 0 ? b : _gcd(b % a, a);
}
class Solution
{
public:
    static vector<string> simplifiedFractions(int n)
    {
        vector<string> res;
        unordered_set<double> MS;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 1; j < i; ++j)
            {
                if(MS.find(double(j) / i) == MS.end())
                {
                    res.push_back(to_string(j) + "/" + to_string(i));
                    MS.insert(double(j) / i);
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    vector<string> res = Solution::simplifiedFractions(5);
    for(auto& x: res)
    {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}