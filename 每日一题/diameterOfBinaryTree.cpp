/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-10 11:49:55
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-10 13:30:05
*/
/****************************************************************
* 题目[中等]：
* 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意
* 两个结点路径长度中的最大值。这条路径可能穿过根结点。
* 示例 :
* 给定二叉树

          1
         / \
        2   3
       / \
      4   5
* 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
* 注意：两结点之间的路径长度是以它们之间边的数目表示。
* 树结构通常使用递归思维
****************************************************************/
#include <iostream>

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
private:
	int result;
	int depth(TreeNode* node)
	{
		if(node == NULL)
			return 0;
		int L = depth(node->left);
		int R = depth(node->right);
		result = max(result, L + R + 1);
		return max(L, R) + 1;
	}
public:
	int diameterOfBinaryTree(TreeNode* root)
	{
		result = 1;
		int D = depth(root);
		cout << "D = " << D << endl;
		return result - 1;
	}
};

int main(int argc, char* argv[])
{
	TreeNode nodes[5] = {1, 2, 3, 4, 5};
	TreeNode* root = &nodes[0];
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];
	nodes[1].left = &nodes[3];
	nodes[1].right = &nodes[4];
	Solution soluter;
	cout << "diameter of binary tree: " << soluter.diameterOfBinaryTree(root) << endl;
	return 0;
}