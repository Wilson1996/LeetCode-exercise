/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-19 09:58:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-19 10:40:03
*/
/**********************************************************
* 题目[中等]：
实现一个函数，检查一棵二叉树是否为二叉搜索树。

示例 1:
输入:
    2
   / \
  1   3
输出: true

示例 2:
输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
**********************************************************/
#include <iostream>
#include <stack>
#include <climits>

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
	//按照中序遍历的思想
	static bool isValidBST(TreeNode* root)
	{
		if(root == NULL || (root->left == NULL && root->right == NULL))
        	return true;
		int preVal = INT_MIN;
		stack<TreeNode*> SK;
		TreeNode* curr = root;
		bool isInited = false;
		while(!SK.empty() || curr != NULL)
		{
			while(curr != NULL)
			{
				SK.push(curr);
				curr = curr->left;
			}
			TreeNode* node = SK.top();
			SK.pop();
			if(!isInited)
			{
				isInited = true;
				preVal = node->val;
			}
			else
			{
				//如果根节点是INT_MIN, 这里会出错，所以前面要那样处理
				if(preVal >= node->val)
					return false;
				else
				{
					preVal = node->val;
				}
			}
			curr = node->right;
		}
		return true;
	}
};

int main(int argc, char* argv[])
{
	TreeNode nodes[3] = {1,2,3};
	TreeNode* root = &nodes[1];
	root->left = &nodes[0];
	root->right = &nodes[2];

	// TreeNode nodes[5] = {1,3,4,5,6};
	// TreeNode* root = &nodes[3];
	// root->left = &nodes[0];
	// root->right = &nodes[2];
	// nodes[2].left = &nodes[1];
	// nodes[2].right = &nodes[4];

	// TreeNode nodes[2] = {1,1};
	// TreeNode* root = &nodes[0];
	// root->left = &nodes[1];

	// TreeNode nodes[2] = {INT_MIN, INT_MAX};
	// TreeNode* root = &nodes[0];
	// root->right = &nodes[1];
	Solution::isValidBST(root) ? cout << "true" << endl : cout << "false" << endl;
	cout << INT_MIN << endl;
	cout << INT_MAX << endl;
	return 0;
}