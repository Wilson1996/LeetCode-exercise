/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-08 17:50:53
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-08 23:26:12
*/
/*********************************************************
* 题目[中等]：
给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
class Node {
    public int val;
    public List<Node> neighbors;
}

提示：
节点数不超过 100 。
每个节点值 Node.val 都是唯一的，1 <= Node.val <= 100。
无向图是一个简单图，这意味着图中没有重复的边，也没有自环。
由于图是无向的，如果节点 p 是节点 q 的邻居，那么节点 q 也必须是节点 p 的邻居。
图是连通图，你可以从给定节点访问到所有节点。
*********************************************************/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<int, Node*> mp;
public:
    Node* cloneGraph(Node* node)
    {
        if(node == nullptr) return nullptr;
        if(mp.find(node->val) != mp.end()) return mp[node->val];
        Node* newNode = new Node(node->val, node->neighbors);
        mp[node->val] = newNode;
        int n = node->neighbors.size();
        for(int i = 0; i < n; ++i)
        {
            newNode->neighbors[i] = cloneGraph(node->neighbors[i]);
        }
        return newNode;
    }
};