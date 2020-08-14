/*
* @Author: wilson_t
* @Date:   2020-08-14 14:28:28
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-14 14:50:50
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n <= 1) return 0;
        int res = 0;
        vector<int> f(n, 0);        //f[i]:以i结尾的最长合格子串
        stack<int> sk;
        vector<int> pairs(n, -1);   //右括号与之配对的左括号索引
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                sk.push(i);
            } else {
                if(!sk.empty()) {
                    pairs[i] = sk.top();
                    sk.pop();
                }
            }
        }
        for(int i = 1; i < n; ++i) {
            if(s[i] == '(') {
                f[i] = 0;
            } else {
                int idx = pairs[i];
                if(idx == -1) {
                    f[i] = 0;
                } else if(idx == 0) {
                    f[i] = (i - idx + 1);
                    if(f[i] > res) res = f[i];
                } else {
                    f[i] = f[idx - 1] + (i - idx + 1);
                    if(f[i] > res) res = f[i];
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution soluter;
    cout << soluter.longestValidParentheses(")()())") << endl;
    return 0;
}