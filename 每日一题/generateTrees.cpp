/*
* @Author: wilson_t
* @Date:   2021-02-06 10:16:28
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-02-06 11:32:16
*/
/*
* 题目[中等]：
给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

示例：
输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 
提示：
0 <= n <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii
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
//Catalan: C(2n, n)/(n+1)
//n = 8时, 共有1430个
class Solution {
    int n;
public:
    TreeNode* clone(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* r = new TreeNode(root->val);
        r->left = clone(root->left);
        r->right = clone(root->right);
        return r;
    }

    vector<TreeNode*> dfs(int low, int high) {
        if(low > high) return {nullptr};
        vector<TreeNode*> res;
        for(int i = low; i <= high; ++i) {
            vector<TreeNode*> leftRes = dfs(low, i - 1);
            vector<TreeNode*> rightRes = dfs(i + 1, high);
            for(auto _left : leftRes) {
                for(auto _right : rightRes) {
                    TreeNode* now = new TreeNode(i);
                    //if _left andd _right are not cloned, some nodes are common used.
                    now->left = _left;
                    now->right = _right;
                    // now->left = clone(_left);
                    // now->right = clone(_right);
                    res.emplace_back(now);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int _n) {
        this->n = _n;
        return dfs(1, n);
    }
};