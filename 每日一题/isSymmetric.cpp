/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-31 00:30:31
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-31 00:40:55
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
public:
    bool isSymmetric(TreeNode* r1, TreeNode* r2)
    {
        if(r1 == NULL && r2 == NULL) return true;
        if(r1 == NULL|| r2 == NULL || (r1->val != r2->val)) return false;
        return isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left);
    }
    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL) return true;
        return isSymmetric(root->left, root->right);
    }
};