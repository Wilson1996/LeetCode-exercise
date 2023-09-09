/*
* @Author: wilson_t
* @Date:   2020-10-03 20:24:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-04 18:00:51
*/
/*
如果一棵二叉树满足下述几个条件，则可以称为 奇偶树 ：
二叉树根节点所在层下标为 0 ，根的子节点所在层下标为 1 ，根的孙节点所在层下标为 2 ，依此类推。
偶数下标 层上的所有节点的值都是 奇 整数，从左到右按顺序 严格递增
奇数下标 层上的所有节点的值都是 偶 整数，从左到右按顺序 严格递减
给你二叉树的根节点，如果二叉树为 奇偶树 ，则返回 true ，否则返回 false 。

提示：
树中节点数在范围 [1, 105] 内
1 <= Node.val <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/even-odd-tree
*/
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        int level = 0;
        while(!q.empty()) {
            int size = q.size(), pre;
            int mod = level % 2;
            if(mod == 0) {
                pre = INT_MIN;
            } else {
                pre = INT_MAX;
            }
            for(int i = 0; i < size; ++i) {
                TreeNode* cur = q.front();
                q.pop();

                if(mod == cur->val % 2) return false;
                if(mod == 0 && cur->val <= pre) return false;
                if(mod == 1 && cur->val >= pre) return false;

                pre = cur->val;

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            ++level;
        }
        return true;
    }
};