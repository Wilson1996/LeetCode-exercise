/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-23 10:21:46
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-23 10:32:15
*/
/****************************************************************
* 题目[简单]：
给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。

示例 1：
输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

示例 2：
输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。

提示：
给定链表的结点数介于 1 和 100 之间。
****************************************************************/
#include <iostream>
#include <vector>

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
	//快慢指针
	static ListNode* middleNode(ListNode* head)
	{
		if(head == NULL)
			return NULL;
		ListNode* fast, *slow;
		fast = slow = head;
		while(fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};

int main(int argc, char* argv[])
{
	ListNode nodes[6] = {1,2,3,4,5,6};
	ListNode* head = &nodes[0];
	for(int i = 0; i < 6 - 1; ++i)
	{
		nodes[i].next = &nodes[i+1];
	}
	nodes[5].next = NULL;
	cout << Solution::middleNode(head) << endl;
	return 0;
}