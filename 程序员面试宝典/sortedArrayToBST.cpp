/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-13 09:49:29
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-13 10:08:42
*/
/************************************************************
* 题目[简单]：
给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。

示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

          0
         / \
       -3   9
       /   /
     -10  5
************************************************************/
#include <iostream>
#include <vector>

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
    TreeNode* toBST(vector<int>& nums, int start, int end)
    {
        // if(start > end)
        //     return NULL;
        if(start == end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = toBST(nums, start, mid);
        root->right = toBST(nums, mid + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return toBST(nums, 0, nums.size());
    }
    void inorderTraversal(TreeNode* root)
    {
        if(root == NULL)
            return;
        inorderTraversal(root->left);
        cout << root->val << ", ";
        inorderTraversal(root->right);
    }
    void destroyTree(TreeNode* root)
    {
        if(root == NULL)
            return;
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
    int size(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return size(root->left) + size(root->right) + 1;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution soluter;
    TreeNode* root = soluter.sortedArrayToBST(nums);
    cout << "size of tree: " << soluter.size(root) << endl;
    soluter.inorderTraversal(root);
    soluter.destroyTree(root);
    return 0;
}