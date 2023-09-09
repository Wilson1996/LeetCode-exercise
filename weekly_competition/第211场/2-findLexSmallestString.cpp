/*
* @Author: wilson_t
* @Date:   2020-10-19 23:12:43
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-19 23:14:04
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string process(string s, int a) {
        string res = s, src = s;
        do{
            for(int i = 1; i < s.size(); i += 2) {
                s[i] += a;
                if(s[i] > '9') s[i] -= 10;
            }
            res = min(res, s);
        }while(src != s);
        return res;
    }
    string findLexSmallestString(string s, int a, int b) {
        string res = s, src = s;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            res = min(res, process(src, a));
            src = src.substr(n - b) + src.substr(0, n - b);
            if(src == s) break;
        }
        return res;
    }
};

int main(){
    // cout << Solution().findLexSmallestString("5525", 9, 2) << "\n";
    cout << Solution().findLexSmallestString("74", 5, 1) << "\n";
    return 0;
}