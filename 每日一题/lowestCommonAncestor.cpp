/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-10 08:52:14
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-27 00:27:22
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
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

namespace Solution1 {
class Solution {
public:
    bool dfs(vector<TreeNode*>& S, TreeNode* target) {
        TreeNode* cur = S.back();
        if(cur == target) return true;
        if(cur->left != NULL) {
            S.push_back(cur->left);
            if(dfs(S, target)) return true;
            S.pop_back();
        }
        if(cur->right != NULL) {
            S.push_back(cur->right);
            if(dfs(S, target)) return true;
            S.pop_back();
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        vector<TreeNode*> sP;
        vector<TreeNode*> sQ;
        sP.push_back(root);
        sQ.push_back(root);
        dfs(sP, p);
        dfs(sQ, q);
        int i = 0;
        int minLen = min(sP.size(), sQ.size());
        while(i < minLen && sP[i] == sQ[i]) ++i;
        return sP[i - 1];
    }
};
class Solution {
public:
    bool dfs(TreeNode* cur, TreeNode* target, vector<TreeNode*>& path) {
        if(cur == NULL) return false;
        path.emplace_back(cur);
        if(cur == target) return true;
        if(dfs(cur->left, target, path)) return true;
        if(dfs(cur->right, target, path)) return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p, path_q;
        dfs(root, p, path_p);
        dfs(root, q, path_q);
        int i = 0;
        while(i < path_p.size() && i < path_q.size() && path_p[i] == path_q[i]) ++i;
        return path_p[i - 1];
    }
};

}

namespace Solution2 {
class Solution {//所有的递归的返回值有4种可能性，NULL、p、q、公共祖先
    TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {//当遍历到叶结点后就会返回NULL
            return root;
        }
        if (root == p || root == q) {//当找到p或者q的是时候就会返回pq
            return root;/*当然，值得一提的是，如果公共祖先是自己（pq），并不需要寻找另外
                     一个，我们在执行前序遍历会先找上面的，后找下面的，我们会直接返回公共祖先。*/
        }
        TreeNode* left = LowestCommonAncestor(root->left, p, q);//返回的结点进行保存，可能是NULL
        TreeNode* right = LowestCommonAncestor(root->right, p, q);//也可能是pq，还可能是公共祖先
        if (left != NULL && right != NULL) {
            return root;//如果左右都存在，就说明pq都出现了，这就是，公共祖先，此时不用考虑公共祖先是自己的情况，因为上面已经做过判断了。
        } else if (left != NULL) {//否则我们返回已经找到的那个值（存储在left，与right中），p或者q
            return left;//还有一种可能就是，由下面返回的公共祖先，并将这个值一路返回到最表层
        } else if (right != NULL) {
            return right;
        }
        return NULL;
    }
}
}