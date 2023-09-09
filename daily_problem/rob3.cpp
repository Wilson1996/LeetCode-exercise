/*
* @Author: wilson_t
* @Date:   2020-08-05 09:59:16
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-09 20:31:21
*/
/*********************************************************
* 题目[中等]：
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
*********************************************************/
class Solution {
private:
    unordered_map<TreeNode*, int> mp;
public:
    int getdp(TreeNode* root) {
        if(root == NULL)return 0;
        if(mp.find(root) != mp.end()) return mp[root];
        int res1 = root->val;
        if(root->left) {
            res1 += getdp(root->left->left);
            res1 += getdp(root->left->right);
        }
        if(root->right) {
            res1 += getdp(root->right->left);
            res1 += getdp(root->right->right);
        }
        mp[root] = max(res1, getdp(root->left) + getdp(root->right));
        return mp[root];
    }
    int rob(TreeNode* root) {
        mp.clear();
        return getdp(root);
    }
};

class Solution {
public:
    //first: 包括root的最大值，second：不包括root的最大值
    pair<int, int> dfs(TreeNode* root) {
        if(!root) return {0, 0};
        pair<int, int> lr = dfs(root->left);
        pair<int, int> rr = dfs(root->right);
        return make_pair(root->val + lr.second + rr.second, max(lr.first, lr.second) + max(rr.first, rr.second));
    }
    int rob(TreeNode* root) {
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }
};