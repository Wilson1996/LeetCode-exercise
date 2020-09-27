/*
* @Author: wilson_t
* @Date:   2020-09-26 22:22:53
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-26 22:24:36
*/
/*
* 题目[中等]：
给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。
返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。

示例 1：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
输出：[7,4,1]
解释：
所求结点为与目标结点（值为 5）距离为 2 的结点，
值分别为 7，4，以及 1

注意，输入的 "root" 和 "target" 实际上是树上的结点。
上面的输入仅仅是对这些对象进行了序列化描述。
 
提示：
给定的树是非空的。
树上的每个结点都具有唯一的值 0 <= node.val <= 500 。
目标结点 target 是树上的结点。
0 <= K <= 1000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree
*/

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
    vector<int> res;
    TreeNode* parent[505];
    bool vis[505];
public:
    void getNode(TreeNode* cur, int dist) {
        if(cur == NULL) return;
        if(vis[cur->val]) return;
        vis[cur->val] = true;
        if(dist == 0) {
            res.emplace_back(cur->val);
            return;
        }
        getNode(cur->left, dist - 1);
        getNode(cur->right, dist - 1);
        getNode(parent[cur->val], dist - 1);
    }

    int getDist(TreeNode* cur, TreeNode* target) {
        if(cur == target) return 0;
        if(cur == NULL) return INT_MIN;
        int ld = getDist(cur->left, target);
        if(ld >= 0) {
            parent[cur->left->val] = cur;
            return ld + 1;
        }
        int rd = getDist(cur->right, target);
        if(rd >= 0) {
            parent[cur->right->val] = cur;
        }
        return rd + 1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        res.clear();
        for(int i = 0; i <= 500; ++i) parent[i] = NULL;
        for(int i = 0; i <= 500; ++i) vis[i] = false;
        int root2T = getDist(root, target);
        getNode(target, K);
        return res;
    }
};