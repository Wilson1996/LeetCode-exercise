/*
* @Author: wilson_t
* @Date:   2020-11-18 20:35:15
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-18 20:36:13
*/
/**
* 题目[中等]：
给定一个二叉树，找到其中最大的二叉搜索树（BST）子树，并返回该子树的大小。其中，最大指的是子树节点数最多的。
二叉搜索树（BST）中的所有节点都具备以下属性：
左子树的值小于其父（根）节点的值。
右子树的值大于其父（根）节点的值。

注意:
子树必须包含其所有后代。
进阶:
你能想出 O(n) 时间复杂度的解法吗？

示例 1：
输入：root = [10,5,15,1,8,null,7]
输出：3
解释：本例中最大的 BST 子树是高亮显示的子树。返回值是子树的大小，即 3 。

示例 2：
输入：root = [4,2,7,2,3,5,null,2,null,null,null,null,null,1]
输出：2

提示：
树上节点数目的范围是 [0, 104]
-104 <= Node.val <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-bst-subtree
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
class Solution {
    int res;
public:
    vector<int> dfs(TreeNode* cur) {
        if(cur->left == nullptr && cur->right == nullptr) return {cur->val, cur->val, 1};
        else if(cur->left == nullptr) {
            vector<int> rr = dfs(cur->right);
            if(rr[2] == -1 || cur->val >= rr[0]) return {0, 0, -1};
            else {
                res = max(res, rr[2] + 1);
                return {cur->val, rr[1], rr[2] + 1};
            }
        } else if(cur->right == nullptr) {
            vector<int> lr = dfs(cur->left);
            if(lr[2] == -1 || cur->val <= lr[1]) return {0, 0, -1};
            else {
                res = max(res, lr[2] + 1);
                return {lr[0], cur->val, lr[2] + 1};
            }
        } else {
            vector<int> lr = dfs(cur->left);
            vector<int> rr = dfs(cur->right);
            if(lr[2] == -1 || rr[2] == -1 || cur->val >= rr[0] || cur->val <= lr[1]) return {0, 0, -1};
            else {
                res = max(res, lr[2] + rr[2] + 1);
                return {lr[0], rr[1], lr[2] + rr[2] + 1};
            }
        }
    }
    int largestBSTSubtree(TreeNode* root) {
        res = 1;
        if(root) dfs(root);
        else return 0;
        return res;
    }
};