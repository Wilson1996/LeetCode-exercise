/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-17 00:08:36
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-17 00:16:39
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    int result = 0;
public:
    void dfs(TreeNode* root, int pre_max)
    {
        if(root == NULL) return;
        if(root->val >= pre_max)
        {
            ++result;
            pre_max = root->val;
        }
        if(root->left) dfs(root->left, pre_max);
        if(root->right) dfs(root->right, pre_max);
    }
    int goodNodes(TreeNode* root)
    {
        dfs(root, -10e4);
        return result;
    }
};