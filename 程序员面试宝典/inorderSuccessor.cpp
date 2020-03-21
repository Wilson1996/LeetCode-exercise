/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-21 15:58:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-21 16:45:32
*/
/**********************************************************
* 题目[中等]：
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。
如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:
输入: root = [2,1,3], p = 1
  2
 / \
1   3
输出: 2

示例 2:
输入: root = [5,3,6,2,4,null,null,1], p = 6
      5
     / \
    3   6
   / \
  2   4
 /
1
输出: null
**********************************************************/
#include <iostream>
#include <stack>

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
	static TreeNode* treeMinimum(TreeNode* x)
	{
		while(x->left != NULL)
			x = x->left;
		return x;
	}
	static TreeNode* treeMaximum(TreeNode* x)
	{
		while(x->right != NULL)
			x = x->right;
		return x;
	}
	//方法一：使用辅助栈
	static TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
	{
		if(p->right != NULL)
			return treeMinimum(p->right);
		stack<TreeNode*> SK;
		TreeNode* curr = root;
		while(curr != p)
		{
			SK.push(curr);
			if(curr != NULL)
			{
				curr = p->val < curr->val ? curr->left : curr->right;
			}
			else
				break;
		}
		TreeNode* pre;
		while(!SK.empty())
		{
			pre = curr;
			curr = SK.top();
			SK.pop();
			if(!(curr != NULL && pre == curr->right))
				return curr;
		}
		return NULL;
	}

	//方法二：递归
	static TreeNode* inorderSuccessor2(TreeNode* root, TreeNode* p)
	{
		if (!root)
		{
			return NULL;
		}
		if (root->val <= p->val)
		{
			return inorderSuccessor(root->right, p);
		}
		else
		{
			TreeNode* leftRet = inorderSuccessor(root->left, p);
			if (!leftRet)
			{
				return root;
			}
			else
			{
				return leftRet;
			}
		}
	}
};

int main(int argc, char* argv[])
{
	TreeNode nodes[6] = {1, 2, 3, 4, 5, 6};
	TreeNode* root = &nodes[4];
	root->left = &nodes[2];
	root->right = &nodes[5];
	nodes[2].left = &nodes[1];
	nodes[2].right = &nodes[3];
	nodes[1].left = &nodes[0];
	TreeNode* res = Solution::inorderSuccessor2(root, &nodes[5]);
	res ? cout << res->val << endl : cout << "no successor!" << endl;
	return 0;
}
/*
      5
     / \
    3   6
   / \
  2   4
 /
1
*/