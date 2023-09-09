/*
* @Author: wilson_t
* @Date:   2021-03-11 00:59:22
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-03-11 00:59:33
*/
using ll = long long;
class Solution {
public:
    inline int getPrio(char c) {
        if(c == '+' || c == '-') return 1;
        else if(c == '*' || c == '/') return 2;
        return 0;
    }
    inline bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    inline bool isOp(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    inline int calc(int x, int y, char op) {
        if(op == '+') return x + y;
        else if(op == '-') return x - y;
        else if(op == '/') return x / y;
        else if(op == '*') return x * y;
        return 0;
    }

    int calculate(string s) {
        stack<ll> nums;
        stack<char> ops;
        int n = s.size(), i = 0;
        while(i < n) {
            if(isOp(s[i])) {
                int nowPrio = getPrio(s[i]);
                while(!ops.empty() && ops.top() != '(' && getPrio(ops.top()) >= nowPrio) {
                    int y = nums.top();
                    nums.pop();
                    int x;
                    if(nums.empty()) x = 0;
                    else {
                        x = nums.top();
                        nums.pop();
                    }
                    nums.push(calc(x, y, ops.top()));
                    ops.pop();
                }
                ops.push(s[i]);
                ++i;
            } else if(s[i] == '(') {
                ops.push(s[i]);
                ++i;
            } else if(s[i] == ')') {
                while(!ops.empty() && ops.top() != '(') {
                    int y = nums.top();
                    nums.pop();
                    int x;
                    if(nums.empty()) x = 0;
                    else {
                        x = nums.top();
                        nums.pop();
                    }
                    nums.push(calc(x, y, ops.top()));
                    ops.pop();
                }
                ops.pop();
                ++i;
            } else if(s[i] == ' ') {
                ++i;
            } else {
                ll now = 0;
                while(i < n && isDigit(s[i])) {
                    now = now * 10 + s[i] - '0';
                    ++i;
                }
                nums.push(now);
            }
        }
        while(!ops.empty()) {
            int y = nums.top();
            nums.pop();
            int x;
            if(nums.empty()) x = 0;
            else {
                x = nums.top();
                nums.pop();
            }
            nums.push(calc(x, y, ops.top()));
            ops.pop();
        }
        return nums.top();
    }
};