/*
* @Author: wilson_t
* @Date:   2020-08-20 15:02:48
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-20 15:05:20
*/
/*********************************************************
* 题目[中等]：
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
还有一个 random 指针指向链表中的任意节点或者 null。

提示：
-10000 <= Node.val <= 10000
Node.random 为空（null）或指向链表中的节点。
节点数目不超过 1000 。
*********************************************************/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        mp[NULL] = NULL;
        Node* it = head;
        while(it != NULL) {
            mp[it] = new Node(it->val);
            it = it->next;
        }
        it = head;
        while(it != NULL) {
            mp[it]->next = mp[it->next];
            mp[it]->random = mp[it->random];
            it = it->next;
        }
        return mp[head];
    }
};