/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-31 10:34:52
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-31 12:21:18
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& V)
    {
        const int MOD = 1e9 + 7;
        H.push_back(0);
        H.push_back(h);
        V.push_back(0);
        V.push_back(w);
        sort(H.begin(), H.end());
        sort(V.begin(), V.end());
        int n = H.size();
        int m = V.size();
        int rowMax = 0;
        for(int i = 1; i < n; ++i)
        {
            rowMax = max(rowMax, H[i] - H[i - 1]);
        }
        int colMax = 0;
        for(int j = 1; j < m; ++j)
        {
            colMax = max(colMax, V[j] - V[j - 1]);
        }
        return ((long long)rowMax * colMax) % MOD;
    }
};

int main(int argc, char* argv[])
{
    int h = 5;
    int w = 4;
    vector<int> horizontalCuts = {1, 2, 4};
    vector<int> verticalCuts = {1, 3};
    Solution soluter;
    cout << soluter.maxArea(h, w, horizontalCuts, verticalCuts) << endl;
    return 0;
}