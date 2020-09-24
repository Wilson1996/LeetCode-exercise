/*
* @Author: wilson_t
* @Date:   2020-09-24 09:23:54
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-24 09:54:14
*/
/*********************************************************
* 题目[简单]：
给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
假定 BST 有如下定义：
结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree
*********************************************************/
//暴力O(n)空间复杂度解法
using PII = pair<int, int>;
struct cmp {
    bool operator()(const PII& l, const PII& r) {
        return l.second < r.second;
    }
};

class Solution {
    unordered_map<int, int> mp;
public:
    void dfs(TreeNode* root) {
        if(root == NULL) return;
        dfs(root->left);
        dfs(root->right);
        mp[root->val]++;
    }
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        mp.clear();
        vector<int> res;
        priority_queue<PII, vector<PII>, cmp> pq;
        dfs(root);
        for(auto& x : mp) {
            pq.emplace(x);
        }
        int cnt = pq.top().second;
        res.emplace_back(pq.top().first);
        pq.pop();
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(cur.second == cnt) {
                res.emplace_back(cur.first);
            } else {
                break;
            }
        }
        return res;
    }
};

//优化空间复杂度解法
class Solution {
    vector<int> res;
    int pre, mxCnt, curCnt;
public:
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        inorder(root->left);
        if(root->val == pre) {
            curCnt++;
        } else {
            curCnt = 1;
        }
        if(curCnt == mxCnt) {
            res.emplace_back(root->val);
        } else if(curCnt > mxCnt) {
            res.clear();
            mxCnt = curCnt;
            res.emplace_back(root->val);
        }
        pre = root->val;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        res.clear();
        pre = INT_MIN;//
        mxCnt = 1;
        curCnt = 1;
        inorder(root);
        return res;
    }
};