/*
* @Author: WillissTaan(Wilson.T@sjtu.edu.cn)
* @Date:   2020-10-15 00:41:34
* @Last Modified by:   Wilson.T
* @Last Modified time: 2020-10-15 00:42:27
*/
/*********************************************************
* 题目[中等]：
对于一棵深度小于 5 的树，可以用一组三位十进制整数来表示。
对于每个整数：
百位上的数字表示这个节点的深度 D，1 <= D <= 4。
十位上的数字表示这个节点在当前层所在的位置 P， 1 <= P <= 8。位置编号与一棵满二叉树的位置编号相同。
个位上的数字表示这个节点的权值 V，0 <= V <= 9。
给定一个包含三位整数的升序数组，表示一棵深度小于 5 的二叉树，请你返回从根到所有叶子结点的路径之和。

样例 1:
输入: [113, 215, 221]
输出: 12
解释: 
这棵树形状如下:
    3
   / \
  5   1

路径和 = (3 + 5) + (3 + 1) = 12.

样例 2:
输入: [113, 221]
输出: 4
解释: 
这棵树形状如下: 
    3
     \
      1

路径和 = (3 + 1) = 4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-iv
*********************************************************/
const int maxSize = 1 << 5;
class Solution {
    int tree[maxSize], leafCnt[maxSize];
public:
    int pathSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        memset(tree, -1, sizeof(tree));
        memset(leafCnt, 0, sizeof(leafCnt));
        for(int i = n - 1; i >= 0; --i) {
            int idx = (1 << (nums[i] / 100 - 1)) + ((nums[i] % 100) / 10) - 1;
            if(tree[idx * 2] == -1 && tree[idx * 2 + 1] == -1) { //leaf
                tree[idx] = nums[i] % 10;
                leafCnt[idx] = 1;
                res += tree[idx];
            } else {
                tree[idx] = nums[i] % 10;
                leafCnt[idx] = leafCnt[idx * 2] + leafCnt[idx * 2 + 1];
                res += tree[idx] * leafCnt[idx];
            }
        }
        return res;
    }
};