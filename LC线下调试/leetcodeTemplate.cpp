#include <bits/stdc++.h>
#include "LCStructInput.h"
#include "debug.h"
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums) {

        return 0;
    }
};

int main() {
    freopen("in.txt", "rb", stdin);
    Solution sol;
    LCFormat lc;
    vector<int> v;
    lc.read(v);
    Debug() << v << "\n";
    ListNode* vHead = lc.makeList(v);
    lc.print(vHead);

    ListNode* head = lc.readList();
    TreeNode* root = lc.readTree();
    lc.print(head);
    lc.print(root);
    lc.preOrder(root);
    lc.inOrder(root);
    lc.postOrder(root);

    vector<vector<int>> vv;
    lc.read(vv);
    Debug() << vv << "\n";

    // vector<int> nums;
    // vector<vector<int>> grid;

    // lc.read(nums);
    // auto res = sol.solve(nums);
    // Debug() << res << "\n";

    return 0;
}