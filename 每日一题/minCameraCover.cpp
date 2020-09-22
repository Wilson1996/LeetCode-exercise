/*
* @Author: wilson_t
* @Date:   2020-09-22 21:34:01
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-22 21:50:30
*/
/****************************************************************
* 题目[困难]：
给定一个二叉树，我们在树的节点上安装摄像头。
节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
计算监控树的所有节点所需的最小摄像头数量。

示例 1：
输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。

示例 2：
输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。

提示：
给定树的节点数的范围是 [1, 1000]。
每个节点的值都是 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-cameras
****************************************************************/

//记忆化递归, 比较暴力
class Solution {
    map<pair<TreeNode*, int>, int> mp;
public:
    //status
    //0: 没有被监视
    //1: 该处有摄像头
    //2: 不是摄像头，但是被监视到
    int dfs(TreeNode* cur, int status) {
        if(cur == nullptr) return 0;
        auto key = make_pair(cur, status);
        if(mp.find(key) != mp.end()) return mp[key];
        int res = 0;
        if(status == 0) {
            res = dfs(cur->left, 2) + dfs(cur->right, 2) + 1;
            if(cur->right != nullptr) res = min(res, dfs(cur->left, 0) + dfs(cur->right, 1) + 1);
            if(cur->left != nullptr) res = min(res, dfs(cur->left, 1) + dfs(cur->right, 0) + 1);
        } else if(status == 1) {
            res = dfs(cur->left, 2) + dfs(cur->right, 2);
        } else {
            res = min(1 + dfs(cur->left, 2) + dfs(cur->right, 2), dfs(cur->left, 0) + dfs(cur->right, 0));
        }
        // printf("%d, %d, %d\n", cur->val, status, res);
        return mp[key] = res;
    }
    int minCameraCover(TreeNode* root) {
        mp.clear();
        return dfs(root, 0);
    }
};

//树形dp，用status状态记录，比较巧妙
//状态 a：root必须放置摄像头的情况下，覆盖整棵树需要的摄像头数目。
//状态 b：覆盖整棵树需要的摄像头数目，无论root是否放置摄像头。
//状态 c：覆盖两棵子树需要的摄像头数目，无论节点root本身是否被监控到。
//a = lc + rc + 1;
//b = min(a, min(la + rb, ra + lb));
//c = min(a, lb + rb);
struct Status {
    int a, b, c;
};

class Solution {
public:
    Status dfs(TreeNode* root) {
        if (!root) {
            return {INT_MAX / 2, 0, 0};
        }
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        int a = lc + rc + 1;
        int b = min(a, min(la + rb, ra + lb));
        int c = min(a, lb + rb);
        return {a, b, c};
    }

    int minCameraCover(TreeNode* root) {
        auto [a, b, c] = dfs(root);
        return b;
    }
};


//贪心，每次贪心的选择当前节点的状态
class Solution {
    int res;
public:
    //status
    //0: 没有被监视
    //1: 该处有摄像头
    //2: 不是摄像头，但是被监视到
    int dfs(TreeNode* cur) {
        if(cur == nullptr) return 2;
        int ls = dfs(cur->left), rs = dfs(cur->right);
        int status = 0;
        if(ls == 0 || rs == 0) {
            ++res;
            status =  1;
        } else if(ls == 1 || rs == 1) {
            status =  2;
        } else if(ls == 2 && rs == 2) {
            status = 0;
        }
        return status;
    }
    int minCameraCover(TreeNode* root) {
        res = 0;
        int status =  dfs(root);
        if(status == 0) res++;
        return res;
    }
};
