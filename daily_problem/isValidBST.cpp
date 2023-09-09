/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-29 18:56:25
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-29 20:22:00
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
	//边界有问题
    bool isValidBST(TreeNode* root, int lowbound, int highbound)
    {
        if(root == NULL) return true;
        if(root->val <= lowbound) return false;
        if(root->val >= highbound) return false;
        return isValidBST(root->left, lowbound, root->val) && isValidBST(root->right, root->val, highbound);
    }
    bool isValidBST(TreeNode* root)
    {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};