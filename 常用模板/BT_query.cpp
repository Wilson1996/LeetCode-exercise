/*
* @Author: Williss Taan
* @Date:   2019-08-23 23:24:51
* @Last Modified by:   Wilson.T
* @Last Modified time: 2019-08-30 10:47:29
*/
#include <iostream>
#include <stack>
#include <deque>

using namespace std;

struct BTNode
{
	int val;
	BTNode* left;
	BTNode* right;
};

void BT_generate(int nodes[], BTNode** proot)
{

}

/**************************************************/
//前序遍历
//递归方法：
void preOrder_traversal(BTNode* root)
{
	if(root == NULL)
		return;
	cout << root -> val << " ";
	preOrder_traversal(root -> left);
	preOrder_traversal(root -> right);
}
//迭代方法
void preOrder_traversal2(BTNode* root)
{
	if(root == NULL)
		return;
	stack<BTNode*> stack_BTNode;
	stack_BTNode.push(root);
	while(!(stack_BTNode.empty()))
	{
		BTNode* cur = stack_BTNode.top();
		stack_BTNode.pop();
		cout << cur -> val << " ";

		if(cur -> right != NULL)
			stack_BTNode.push(cur -> right);
		if(cur -> left != NULL)
			stack_BTNode.push(cur -> left);
	}
}

/**************************************************/
//中序遍历（递归方法）
void inOrder_traversal(BTNode* root)
{
	if(root == NULL)
		return;
	inOrder_traversal(root -> left);
	cout << root -> val << " ";
	inOrder_traversal(root -> right);
}
//迭代方法
void inOrder_traversal2(BTNode* root)
{
	if(root == NULL)
		return;
	stack<BTNode*> stack_BTNode;
	BTNode* cur = root;
	while(!(stack_BTNode.empty()) || cur != NULL)
	{
		while(cur != NULL)
		{
			stack_BTNode.push(cur);
			cur = cur -> left;
		}
		BTNode* node = stack_BTNode.top();
		stack_BTNode.pop();
		cout << node -> val << " ";

		cur = node -> right;
	}
}

/**************************************************/
//后序遍历（递归方法）
void postOrder_traversal(BTNode* root)
{
	if(root == NULL)
		return;
	postOrder_traversal(root -> left);
	postOrder_traversal(root -> right);
	cout << root -> val << " ";
}
//迭代
void postOrder_traversal2(BTNode* root)
{
	if(root == NULL)
		return;
	stack<BTNode*> s1;
	stack<BTNode*> s2;
	s1.push(root);
	while(!s1.empty())
	{
		root = s1.top();
		s1.pop();
		s2.push(root);
		if(root -> left != NULL)
			s1.push(root -> left);
		if(root -> right != NULL)
			s1.push(root -> right);
	}
	while(!s2.empty())
	{
		cout << s2.top() -> val << " ";
		s2.pop();
	}
}

/**************************************************/
//宽度优先搜索
void bfs_traversal(BTNode* root)
{
	if(root == NULL)
		return;
	deque<BTNode*> dequeTreeNode;

	dequeTreeNode.push_back(root);
	while(dequeTreeNode.size())
	{
		BTNode *pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		cout << pNode -> val << " ";
		if(pNode -> left)
			dequeTreeNode.push_back(pNode -> left);
		if(pNode -> right)
			dequeTreeNode.push_back(pNode -> right);
	}
}

int main(int argc, char const *argv[])
{
	BTNode *root;
	BTNode nodes[7];
	root = &nodes[0];
	nodes[0].val = 10;
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];
	nodes[1].val = 6;
	nodes[1].left = &nodes[3];
	nodes[1].right = &nodes[4];
	nodes[2].val = 14;
	nodes[2].left = &nodes[5];
	nodes[2].right = &nodes[6];
	nodes[3].val = 4;
	nodes[3].left = NULL;
	nodes[3].right = NULL;
	nodes[4].val = 8;
	nodes[4].left = NULL;
	nodes[4].right = NULL;
	nodes[5].val = 12;
	nodes[5].left = NULL;
	nodes[5].right = NULL;
	nodes[6].val = 16;
	nodes[6].left = NULL;
	nodes[6].right = NULL;

	preOrder_traversal(root);
	cout << "前序遍历（递归）" << endl;
	preOrder_traversal2(root);
	cout << "前序遍历（迭代）" << endl;
	inOrder_traversal(root);
	cout << "中序遍历（递归）" << endl;
	inOrder_traversal2(root);
	cout << "中序遍历（迭代）" << endl;
	postOrder_traversal(root);
	cout << "后序遍历（递归）" << endl;
	postOrder_traversal2(root);
	cout << "后序遍历（迭代）" << endl;
	bfs_traversal(root);
	cout << "层序遍历（广度优先）" << endl;
	return 0;
}
