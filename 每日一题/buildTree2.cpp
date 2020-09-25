/*
* @Author: wilson_t
* @Date:   2020-09-25 09:41:35
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-25 09:43:50
*/
/*********************************************************
* 题目[中等]：
根据一棵树的中序遍历与后序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
例如，给出
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
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
//递归
class Solution {
    unordered_map<int, int> mp;
public:
    TreeNode* build(vector<int>& in, vector<int>& po,
                    int l1, int r1, int l2, int r2) {
        if(l1 == r1) return new TreeNode(in[l1]);
        else if(l1 > r1) return nullptr;
        int rootVal = po[r2];
        TreeNode* root = new TreeNode(rootVal);
        int inPos = mp[rootVal];
        int poPos = l2 + inPos - l1;
        root->left = build(in, po, l1, inPos - 1, l2, poPos - 1);
        root->right = build(in, po, inPos + 1, r1, poPos, r2 - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 0) return nullptr;
        mp.clear();
        for(int i = 0; i < n; ++i) mp[inorder[i]] = i;
        return build(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};

//迭代
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }
        auto root = new TreeNode(postorder[postorder.size() - 1]);
        auto s = stack<TreeNode*>();
        s.push(root);
        int inorderIndex = inorder.size() - 1;
        for (int i = int(postorder.size()) - 2; i >= 0; i--) {
            int postorderVal = postorder[i];
            auto node = s.top();
            if (node->val != inorder[inorderIndex]) {
                node->right = new TreeNode(postorderVal);
                s.push(node->right);
            } else {
                while (!s.empty() && s.top()->val == inorder[inorderIndex]) {
                    node = s.top();
                    s.pop();
                    inorderIndex--;
                }
                node->left = new TreeNode(postorderVal);
                s.push(node->left);
            }
        }
        return root;
    }
};