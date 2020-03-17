/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-17 13:35:43
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-17 14:49:53
*/
/*************************************************************
* 题目[简单]：
给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义
基于节点的引用，而不是基于节点的值。换句话说，如果一个链表的第k个节
点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。

示例 1：
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8

注意：
如果两个链表没有交点，返回 null 。
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*************************************************************/
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
	/*方法一：使用辅助栈：空间复杂度O(n)
	*/

	/*方法二：得到两个链表的长度
	*/
	static ListNode* getIntersectionNode_1(ListNode* headA, ListNode* headB)
	{
		int len_A = 0;
		int len_B = 0;
		ListNode* pA = headA;
		ListNode* pB = headB;
		while(pA != NULL || pB != NULL)
		{
			if(pA != NULL)
			{
				++len_A;
				pA = pA->next;
			}
			if(pB != NULL)
			{
				++len_B;
				pB = pB->next;
			}
		}
		ListNode* pLong, *pShort;
		int len_long, len_short;
		if(len_A >= len_B)
		{
			pLong = headA;
			pShort = headB;
			len_long = len_A;
			len_short = len_B;
		}
		else
		{
			pLong = headB;
			pShort = headA;
			len_long = len_B;
			len_short = len_A;
		}
		for(int i = 0; i < len_long - len_short; ++i)
		{
			pLong = pLong->next;
		}
		while(pLong != pShort)
		{
			pLong = pLong->next;
			pShort = pShort->next;
		}
		return pLong;
	}
	/*方法三：[双指针，最优] 使用两个指针分别指向headA和headB，当一个指针先到达末尾时，
			就让它指向另一个指针的头部，如果相遇的话就是交点；
			否则的话两个指针都走了两个链表的长度，返回null。
	*/
	static ListNode* getIntersectionNode_2(ListNode* headA, ListNode* headB)
	{
		if(headA == NULL || headB == NULL)
			return NULL;
		ListNode* pA = headA;
		ListNode* pB = headB;
		while(pA != pB)
		{
			pA = (pA == NULL) ? headB : pA->next;
			pB = (pB == NULL) ? headA : pB->next;
		}
		return pA;
	}
};

int main(int argc, char* argv[])
{
	ListNode nodes[6] = {0, 1, 2, 3, 4, 5};
	for(int i = 0; i < 4; ++i)
	{
		nodes[i].next = &nodes[i + 1];
	}
	nodes[5].next = &nodes[2];
	ListNode* headA = &nodes[0];
	ListNode* headB = &nodes[5];
	cout << headA << endl;
	cout << headB << endl;
	ListNode* result = Solution::getIntersectionNode_2(headA, headB);
	cout << result -> val << endl;
	return 0;
}