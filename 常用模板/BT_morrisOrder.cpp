/*
* @Author: Williss Taan
* @Date:   2019-08-29 22:25:52
* @Last Modified by:   Wilson.T
* @Last Modified time: 2019-08-30 09:09:19
* @Description: morris遍历，时间复杂度O(N)，空间复杂度O(1)
*		## morris遍历遵循的规则（假设当前节点为cur，初始时cur就是整棵树的头结点）:
*			1、如果cur为null，则过程停止，否则继续下面的过程。
*			2、如果cur没有左子树，则让cur向右移动，即令cur=cur.right。
*			3、如果cur有左子树，则找到cur左子树上最右的节点，记为mostRight。
*			1）如果mostRight的right指针指向null，则令mostRight.right=cur，也就是让mostRight
*				的right指针指向当前节点，然后让cur向左移动，即令cur=cur.left。
*			2）如果mostRight的right指针指向cur，则令mostRight.right=null，也就是让mostRight
*				的right指针指向null，然后让cur向右移动，即令cur=cur.right。
*		## 先序遍历：
*			1、对于cur只能到达一次的节点（无左子树的节点），cur到达时直接打印。
*			2、对于cur可以到达两次的节点（有左子树的节点），cur第一次到达时打印，第二次到达时不打印。
*		## 中序遍历：
*			1、对于cur只能到达一次的节点（无左子树的节点），cur到达时直接打印。
*			2、对于cur可以到达两次的节点（有左子树的节点），cur第一次到达时不打印，第二次到达时打印。
*		## 后序遍历：
*			1、对于cur只能到达一次的节点（无左子树的节点），直接跳过，没有打印行为。
*			2、对于cur可以到达两次的任何一个节点（有左子树的节点）X，cur第一次到达时没有打印行为；当第二次
*				到达X时，逆序打印X左子树的右边界。
*			3、cur完成遍历后，逆序打印整棵树的右边界。
*/
#include <iostream>

using namespace std;

struct BTNode
{
	int val;
	BTNode* left;
	BTNode* right;
};

void morris(BTNode* root)
{
	if(root == NULL)
		return;
	BTNode* cur = root;
	BTNode* mostRight = NULL;
	while(cur != NULL)
	{
		mostRight = cur -> left;
		if(mostRight != NULL)
		{
			while(mostRight -> right != NULL && mostRight -> right != cur)
			{
				mostRight = mostRight -> right;
			}
			if(mostRight -> right == NULL)
			{
				mostRight -> right = cur;
				cur = cur -> left;
				continue;
			}
			else
			{
				mostRight -> right = NULL;
			}
		}
		cur = cur -> right;
	}
}

void morrisPre(BTNode* root)
{
	if(root == NULL)
		return;
	BTNode* cur = root;
	BTNode* mostRight = NULL;
	while(cur != NULL)
	{
		mostRight = cur -> left;
		if(mostRight != NULL)
		{
			while(mostRight -> right != NULL && mostRight -> right != cur)
			{
				mostRight = mostRight -> right;
			}
			if(mostRight -> right == NULL)
			{
				mostRight -> right = cur;
				cout << cur -> val << " ";
				cur = cur -> left;
				continue;
			}
			else
			{
				mostRight -> right = NULL;
			}
		}
		else
		{
			cout << cur -> val << " ";
		}
		cur = cur -> right;
	}
}

void morrisIn(BTNode* root)
{
	if(root == NULL)
		return;
	BTNode* cur = root;
	BTNode* mostRight = NULL;
	while(cur != NULL)
	{
		mostRight = cur -> left;
		if(mostRight != NULL)
		{
			while(mostRight -> right != NULL && mostRight -> right != cur)
			{
				mostRight = mostRight -> right;
			}
			if(mostRight -> right == NULL)
			{
				mostRight -> right = cur;
				cur = cur -> left;
				continue;
			}
			else
			{
				mostRight -> right = NULL;
			}
		}
		cout << cur -> val << " ";
		cur = cur -> right;
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

	morrisPre(root);
	cout << "前序遍历（morris）" << endl;
	morrisIn(root);
	cout << "中序遍历（morris）" << endl;
	return 0;
}