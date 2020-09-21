/*
* @Author: wilson_t
* @Date:   2020-09-21 17:12:23
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-21 17:13:44
*/
/*********************************************************
* 题目[简单]：
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，
使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

例如：
输入: 原始二叉搜索树:
              5
            /   \
           2     13
输出: 转换为累加树:
             18
            /   \
          20     13

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
*********************************************************/
class Solution {
    int curSum = 0;
public:
    void InvMidTraverse(TreeNode* cur) {
        if(!cur) return;
        InvMidTraverse(cur->right);
        cur->val += curSum;
        curSum = cur->val;
        InvMidTraverse(cur->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        curSum = 0;
        InvMidTraverse(root);
        return root;
    }
};