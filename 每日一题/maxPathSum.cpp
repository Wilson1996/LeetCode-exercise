/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-21 09:51:08
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-21 10:29:07
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    unordered_map<TreeNode*, int> left;
    unordered_map<TreeNode*, int> right;
    long res;
public:
    int helper(TreeNode* root)
    {
        if(root == NULL) return 0;
        int l, r;
        if(left.find(root->left) != left.end()) l = left[root->left];
        else
        {
            l = helper(root->left);
        }
        if(right.find(root->right) != right.end()) r = right[root->right];
        else
        {
            r = helper(root->right);
        }
        l = l > 0 ? l + root->val : root->val;
        r = r > 0 ? r + root->val : root->val;
        left[root] = l;
        right[root] = r;
        return max(l, r);
    }
    int maxPathSum(TreeNode* root)
    {
        left[NULL] = 0;
        right[NULL] = 0;
        res = LONG_MIN;
        helper(root);
        return res;
    }
};