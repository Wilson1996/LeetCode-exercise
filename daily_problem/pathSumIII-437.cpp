/*
* @Author: wilson_t
* @Date:   2020-11-17 22:11:59
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-17 22:12:43
*/
/**
* 题目[中等]：
给定一个二叉树，它的每个结点都存放着一个整数值。
找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:
1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-iii
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
    unordered_map<int, int> preSum;
    int res, target;
public:
    void dfs(TreeNode* cur, int sum) {
        if(preSum.find(sum - target) != preSum.end()) {
            res += preSum[sum - target];
        }
        preSum[sum]++;
        if(cur->left) dfs(cur->left, sum + cur->left->val);
        if(cur->right) dfs(cur->right, sum + cur->right->val);
        preSum[sum]--;
    }
    int pathSum(TreeNode* root, int sum) {
        res = 0;
        target = sum;
        preSum.clear();
        preSum[0] = 1;
        if(root) {
            dfs(root, root->val);
        }
        return res;
    }
};