/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-22 08:32:18
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-22 09:02:15
*/
/*********************************************************
* 题目[中等]：
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*********************************************************/
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
    TreeNode* helper(vector<int>& preorder, int index, vector<int>& inorder, int l, int r)
    {
        if(l >= r || index < 0 || index >= preorder.size())	return NULL;
        int rootV = preorder[index];
        TreeNode* root = new TreeNode(rootV);
        int i = l;
        while(inorder[i] != rootV)
            ++i;
        root->left = helper(preorder, index + 1, inorder, l, i);
        root->right = helper(preorder, index + i - l + 1, inorder, i + 1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return helper(preorder, 0, inorder, 0, inorder.size());
    }
};