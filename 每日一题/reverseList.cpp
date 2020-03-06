/*
* @Author: WillissTaan(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-06 11:52:41
* @Last Modified by:   Wilson.T
* @Last Modified time: 2020-03-06 12:03:37
*/

/****************************************************************
 * 题目[简单]：
 * 反转一个单链表。
 * 
 * 示例:
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 ****************************************************************/

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //迭代
    static ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* pre = NULL;
        ListNode* curr = head;
        while(curr != NULL)
        {
            ListNode* temp = curr -> next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
    //递归
 
};

int main(int argc, char* argv[])
{
	ListNode nodes[5] = {1,2,3,4,5};
	ListNode* head = &nodes[0];
	for(int i = 0; i < 5 - 1; ++i)
	{
		nodes[i].next = &nodes[i+1];
	}
	nodes[4].next = NULL;
	ListNode* newList = Solution::reverseList(head);
	ListNode* temp = newList;
	while(temp != NULL)
	{
		cout << temp->val << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
	return 0;
}