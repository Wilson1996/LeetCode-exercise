/*
* @Author: wilson_t
* @Date:   2020-10-12 09:49:14
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-12 09:54:04
*/
/*********************************************************
* 题目[简单]：
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

示例：
输入：

   1
    \
     3
    /
   2

输出：
1
解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 
提示：
树中至少有 2 个节点。
本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
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
class Solution {
    int res;
    TreeNode* pre;
public:
    void recurr(TreeNode* cur) {
        if(cur->left) recurr(cur->left);
        if(pre) res = min(res, cur->val - pre->val);
        pre = cur;
        if(cur->right) recurr(cur->right);
    }
    int getMinimumDifference(TreeNode* root) {
        res = INT_MAX;
        pre = nullptr;
        recurr(root);
        return res;
    }
};