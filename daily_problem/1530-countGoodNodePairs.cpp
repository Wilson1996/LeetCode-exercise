/*
* @Author: wilson_t
* @Date:   2021-02-08 01:43:01
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-02-11 15:46:40
*/
/*
* 题目[中等]：
给你二叉树的根节点 root 和一个整数 distance 。
如果二叉树中两个 叶 节点之间的 最短路径长度 小于或者等于 distance ，那它们就可以构成一组 好叶子节点对 。
返回树中 好叶子节点对的数量 。

提示：
tree 的节点数在 [1, 2^10] 范围内。
每个节点的值都在 [1, 100] 之间。
1 <= distance <= 10
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
    int res, dist;
public:
    //a structrue: restore the leaf nodes set and their depth;
    //O(n^2) time complexity is acceptable.
    vector<int> dfs(TreeNode* cur) {
        if(cur->left == nullptr && cur->right == nullptr) return {0};
        vector<int> ls, rs;
        if(cur->left) ls = dfs(cur->left);
        if(cur->right) rs = dfs(cur->right);
        for(int x : ls) {
            for(int y : rs) {
                if(x + y + 2 <= dist) ++res;
            }
        }
        vector<int> res;
        for(int x : ls) {
            if(x + 1 >= dist) continue;
            res.emplace_back(x + 1);
        }
        for(int x : rs) {
            if(x + 1 >= dist) continue;
            res.emplace_back(x + 1);
        }
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        res = 0;
        dist = distance;
        if(root) dfs(root);
        return res;
    }
};