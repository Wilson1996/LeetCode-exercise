/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-16 18:09:55
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-16 18:31:45
*/

/**************************************************************
* 题目[简单]：
实现一种算法，删除单向链表中间的某个节点（除了第一个和最后一个节点，不一定是中间节点），
假定你只能访问该节点。 

示例：
输入：单向链表a->b->c->d->e->f中的节点c
结果：不返回任何数据，但该链表变为a->b->d->e->f
**************************************************************/
#include <iostream>

using namespace std;

// Definition for singly - linked list.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	friend ostream& operator<<(ostream& os, ListNode* head)
	{
		ListNode* iter = head;
		while(iter != NULL)
		{
			os << iter->val << "->";
			iter = iter->next;
		}
		os << "NULL" << endl;
		return os;
	}
};

class Solution
{
public:
	static void deleteNode(ListNode* node)
	{
		if(node == NULL)
			return;
		ListNode* post = node->next;
		node->val = post->val;
		node->next = post->next;
		// delete post;		//动态内存需要回收
	}
};

int main(int argc, char* argv[])
{
	ListNode nodes[5] = {1, 2, 3, 4, 5};
	ListNode* head = &nodes[0];
	for (int i = 1; i < 5; ++i)
	{
		nodes[i - 1].next = &nodes[i];
	}
	cout << head;
	Solution::deleteNode(&nodes[2]);
	cout << head;
	return 0;
}