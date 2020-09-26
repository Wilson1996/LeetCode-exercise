/*
* @Author: wilson_t
* @Date:   2020-09-26 00:29:43
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-26 00:30:38
*/
/*********************************************************
* 题目[中等]：
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
*********************************************************/
class Solution {
    vector<vector<int>> res;
    vector<int> path;
public:
    void dfs(TreeNode* cur, int sum) {
        path.emplace_back(cur->val);
        if(cur->left == nullptr && cur->right == nullptr) {
            if(sum == cur->val) res.emplace_back(path);
        } else {
            if(cur->left != nullptr) dfs(cur->left, sum - cur->val);
            if(cur->right != nullptr) dfs(cur->right, sum - cur->val);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};
        res.clear();
        path.clear();
        dfs(root, sum);
        return res;
    }
};