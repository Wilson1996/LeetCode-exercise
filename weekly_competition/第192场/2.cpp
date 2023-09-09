/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-07 10:40:00
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-07 12:13:40
*/
#include <bits/stdc++.h>
using namespace std;


int mid;
class cmp
{
public:
    bool operator()(const int& a, const int& b)
    {
        if((abs(a - mid) == abs(b - mid))) return a < b;
        return abs(a - mid) < abs(b - mid);
    }
};
class Solution
{
public:
    vector<int> getStrongest(vector<int>& arr, int k)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        mid = arr[(n - 1) / 2];
        // cout << mid << endl;
        priority_queue<int, vector<int>, cmp> Q;
        for(auto& x : arr)
            Q.push(x);
        vector<int> res;
        while(k--)
        {
            res.push_back(Q.top());
            Q.pop();
        }
        return res;
    }
};

//from liouzhou_101
class Solution2 {
public:
    vector<int> getStrongest(vector<int>& a, int k) {
        int n = a.size();
        vector<int> b = a;
        sort(b.begin(), b.end());
        int m = b[(n-1)/2];
        vector<int> p(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        sort(p.begin(), p.end(), [&](int i, int j)
             {
                 return abs(a[i]-m) > abs(a[j]-m) || abs(a[i]-m) == abs(a[j]-m) && a[i] > a[j];
             });
        vector<int> ret;
        for (int i = 0; i < k; ++i) ret.push_back(a[p[i]]);
        return ret;
    }
};

int main(int argc, char* argv[])
{
	Solution soluter;
	vector<int> arr = {-7,22,17,3};
	vector<int> res = soluter.getStrongest(arr, 2);
	for(auto& x : res)
	{
		cout << x << ", ";
	}
	cout << endl;
	return 0;
}