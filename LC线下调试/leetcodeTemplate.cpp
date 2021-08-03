#include <bits/stdc++.h>
#include "LCStructInput.h"
#include "debug.h"
using namespace std;

// class Solution {
// public:
//     int solve(vector<int>& nums) {

//         return 0;
//     }
// };

class Solution {
    int vis[10005];
public:
    inline int trans(string& s) {
        int res = 0;
        for(char c : s) {
            res = res * 10 + c - '0';
        }
        return res;
    }
    int openLock(vector<string>& dead, string target) {
        int n = dead.size();
        unordered_set<int> st;
        for(string& s : dead) {
            st.insert(trans(s));
        }
        int t = trans(target);
        if(st.count(t) || st.count(0)) return -1;
        memset(vis, 0, sizeof(vis));
        queue<string> q;
        q.push("0000");
        vis[0] = 1;
        int step = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string now = q.front();
                cout << now << "\n";
                q.pop();
                int int_now = trans(now);
                if(int_now == t) return step;
                for(int i = 0; i < 4; ++i) {
                    char ori = now[i];
                    now[i]++;
                    if(now[i] > '9') now[i] = '0';
                    int_now = trans(now);
                    if((!vis[int_now]) && (!st.count(int_now))) {
                        vis[int_now] = 1;
                        q.push(now);
                    }
                    now[i] = ori;
                    now[i]--;
                    if(now[i] < '0') now[i] = '9';
                    int_now = trans(now);
                    if((!vis[int_now]) && (!st.count(int_now))) {
                        vis[int_now] = 1;
                        q.push(now);
                    }
                    now[i] = ori;
                }
            }
            ++step;
        }
        return -1;
    }
};
int main() {
    freopen("in.txt", "rb", stdin);
    Solution sol;
    LCFormat lc;
    // vector<int> v;
    // lc.read(v);
    // Debug() << v << "\n";
    // ListNode* vHead = lc.makeList(v);
    // lc.print(vHead);

    // ListNode* head = lc.readList();
    // TreeNode* root = lc.readTree();
    // lc.print(head);
    // lc.print(root);
    // lc.preOrder(root);
    // lc.inOrder(root);
    // lc.postOrder(root);

    // vector<vector<int>> vv;
    // lc.read(vv);
    // Debug() << vv << "\n";

    // vector<int> nums;
    // vector<vector<int>> grid;

    // lc.read(nums);
    // auto res = sol.solve(nums);
    // Debug() << res << "\n";
    //
    vector<string> v;
    lc.read(v);
    Debug() << v << "\n";
    string target;
    lc.read(target);
    Debug() << target << "\n";
    cout << sol.openLock(v, target) << endl;

    return 0;
}