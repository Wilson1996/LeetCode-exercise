/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-22 10:12:48
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-22 10:45:47
*/
/*********************************************************
* 题目[中等]：
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:
输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
*********************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> result;
        if(root == NULL)
        	return result;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int _size = Q.size();
            TreeNode* tmp;
            for(int i = 0; i < _size; ++i)
            {
                tmp = Q.front();
                Q.pop();
                if(tmp->left != NULL)	Q.push(tmp->left);
                if(tmp->right != NULL)	Q.push(tmp->right);
            }
            result.push_back(tmp->val);
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
	return 0;
}