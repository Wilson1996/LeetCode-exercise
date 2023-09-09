/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-14 11:04:47
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-14 11:27:47
*/
/*********************************************************
* 题目[中等]：
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。
它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶：
如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

示例：
输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7
*********************************************************/
#include <iostream>
#include <stack>

using namespace std;

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
	void deleteNode(ListNode* head)
	{
		while (head != NULL)
		{
			ListNode* tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		stack<int> S1;
		stack<int> S2;
		while(l1 != NULL || l2 != NULL)
		{
			if(l1 != NULL)
			{
				S1.push(l1->val);
				l1 = l1->next;
			}
			if(l2 != NULL)
			{
				S2.push(l2->val);
				l2 = l2->next;
			}
		}
		int carry = 0;
		ListNode* head = NULL;
		while(!S1.empty() || !S2.empty())
		{
			int sum = carry;
			if(!S1.empty())
			{
				sum += S1.top();
				S1.pop();
			}
			if(!S2.empty())
			{
				sum += S2.top();
				S2.pop();
			}
			carry = sum / 10;
			ListNode* newNode = new ListNode(sum % 10);
			newNode->next = head;
			head = newNode;
		}
		if(0 != carry)
		{
			ListNode* newNode = new ListNode(carry);
			newNode->next = head;
			head = newNode;
		}
		return head;
	}
};

int main(int argc, char* argv[])
{
	Solution soluter;
	ListNode nodes[7] = {1, 2, 3, 4, 5, 6, 7};
	ListNode* l1 = &nodes[6];
	l1->next = &nodes[1];
	nodes[1].next = &nodes[3];
	nodes[3].next = &nodes[2];
	ListNode* l2 = &nodes[4];
	nodes[4].next = &nodes[5];
	nodes[5].next = &nodes[0];
	ListNode* head = soluter.addTwoNumbers(l1, l2);
	cout << head;
	soluter.deleteNode(head);
	return 0;
}